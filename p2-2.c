#include<stdio.h>

void print1 (int *ptr, int rows); //함수 원형 정의

int main()
{

     int one[] = {0,1,2,3,4};   //요소가 5개인 배열 선언

     printf("one      =%p\n",  one);      //one의 값 출력 = 배열의 첫번째 요소의 주소 
     printf("&one     =%p\n", &one);      //one의 주소 출력 = 배열의 첫번째 요소의 주소
     printf("&one[0]  =%p\n", &one[0]);   //one[0]의 주소 출력 
     printf("\n");

     print1(&one[0],5); 
      // print1 함수 실행
      //&one[0]에 i를 더한 값과 그 값이 가리키는 값을 출력, i는 0부터 4이고, 주소는 크기 1당 4bytes씩 증가함.

     printf("\n -----[urban engineering  2019032012 Limhyunjung]-----\n");


     return 0;   
 
}

void print1(int *ptr, int rows)  //매개변수로 포인터 ptr과 rows변수를 갖고 있음 
{
    /* print out a one-dimensional array using a pointer */

    int i;
    printf("Address \t Contents \n");   
   
    for(i=0; i<rows; i++)    
        printf("%p  \t   %5d\n" , ptr + i, *(ptr + i)); //ptr은 주소를 담고있는데 integer형이므로 1씩 증가할 때 4bytes씩 증가한다.
     printf("\n"); 
}
