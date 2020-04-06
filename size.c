#include<stdio.h>
#include<stdlib.h>

void main()
{

      int **x;           //integer형 이중포인터 선언

      printf("sizeof(x)    = %lu\n",  sizeof(x));    // x값 출력 (x는 주소를 저장하고있음, 컴퓨터가 32bit기 때문에 4bytes 출력)
      printf("sizeof(*x)   = %lu\n", sizeof(*x));    // *x값 출력 (*x는 주소를 저장하고있음, 컴퓨터가 32bit기 때문에 4bytes 출력)
      printf("sizeof(**x)) = %lu\n", sizeof(**x));   // **x값 출력 (**x는 integer형의 변수를 저장하고 있음 )

      printf("\n -----[urban engineering  2019032012 Limhyunjung]-----\n");

}  