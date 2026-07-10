BOMB LAB  
```
0000000000400ee0 <phase_1>:
  400ee0:	48 83 ec 08          	sub    $0x8,%rsp
  400ee4:	be 00 24 40 00       	mov    $0x402400,%esi
  400ee9:	e8 4a 04 00 00       	call   401338 <strings_not_equal>
  400eee:	85 c0                	test   %eax,%eax
  400ef0:	74 05                	je     400ef7 <phase_1+0x17>
  400ef2:	e8 43 05 00 00       	call   40143a <explode_bomb>
  400ef7:	48 83 c4 08          	add    $0x8,%rsp
  400efb:	c3                   	ret
```
# 코드의도
1. 입력받은 문자열과 프로그램 내부에 문자열을 비교한다.
2. 두 문자열이 다르다면 explode 프로시저를 만나게됨으로 프로그램이 종료됨. 만약 두 문자열이 같다면 곧 바로 ret하고 흐름은 defused 프로시저로 넘어간다.

# 해결방법
strings_not_equal 프로시저의 인자 2개가 무엇인지 확인(하나는 유저의 입력값 in reg name rdi, 나머지는 프로그램 내부 문자열 in reg name rsi)한다.
프로그램 내부의 문자열은 `mov 0x402400, %esi` 명령어를 통해 0x402400번지에 있다는걸 알수있다.

## GDB 출력값
`print (char*)$esi`의 출력값: "Border relations with Canada have never been better."

## 정답
**Border relations with Canada have never been better.**


