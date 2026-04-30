# 모든 빈 폴더에 .gitkeep 파일 생성
find . -type d -empty -not -path '*/.*' -exec touch {}/.gitkeep \;