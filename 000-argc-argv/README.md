# 000 : argc, argv

main 함수의 기본 인자로는 argc와 argv가 있는데, argc는 문자열 배열 argv의 크기를 값으로 입력받는다.

    int main(
             int argc,
             char** argv
			 )


    int main(
	         int argc,
			 char* argv[]
			 )


위 두가지 형태중 어느 것을 사용해도 된다.

**argv[0]**는 실행하는 프로그램의 파일명이다.

아래와 같이 테스트해본다.

    $ ./a.out a b c d e
	$ mv a.out args_test
	$ ./args_test a b c d e
