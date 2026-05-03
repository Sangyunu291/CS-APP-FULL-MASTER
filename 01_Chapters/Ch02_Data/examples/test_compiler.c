/*
* 컴파일러가 만들어 낸 기계 수준 프로그램은 데이터 형에 관한 정보가 없다는걸 알 수 있는 프로그램.
* 프로세서는 데이터형같은거는 모른다. 그저 컴파일러가 int는 4바이트고 double은 8바이트다라는 규칙을 가지고 기계 코드를 생성한다.
* 즉 그저 int형에 맞춰 4바이트를 읽을지, double 형에 맞춰 8바이트를 읽을지 정하는 것뿐이다.
* 이를 확인하기 위해서는 test_compiler.s참조
*/

int main()
{
    int a = 5;
    int* a_pointer = &a;

    double b = 3.14;
    double* b_pointer = &b;

    *a_pointer = 10;
    *b_pointer = 6.28;
    return 0;
}