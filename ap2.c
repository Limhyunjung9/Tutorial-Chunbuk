#include<stdio.h>
#include<stdlib.h> //malloc()을 사용하기 위해 stdlib.h 열어줌 

void main()
{
    int list[5];    //요소가 5개인 배열 list선언
    int *plist[5];  //int형 포인터를 담고 있는 plist 선언


    list[0] = 10;   //list[0]을 10으로 선언  
    list[1] = 11;    //list[1]를 11로 선언

    plist[0] = (int*)malloc(sizeof(int)); // 힙 영역에서 integer형만큼의 byte를 malloc()을 통해 plist[0]에 할당.

    printf("list[0]              \t = %d\n" ,list[0]);   //list[0]의 값 출력 
    printf("address of list      \t= %p\n", list);       //list의 주소 출력 (배열의 이름 = 배열 첫번째 요소의 주소)
    printf("address of list[0]   \t= %p\n", &list[0]);   //list[0]의 주소 출력 = list의 주소
    printf("address of list + 0  \t  =%p\n", list+0);    //list+0 = list의 주소 출력 
    printf("address of list + 1  \t  =%p\n", list+1);    //list+1 = list[1]의 주소 출력, integer형 배열이 1만큼 커졌으므로 주소는 4bytes 증가
    printf("address of list + 2  \t  =%p\n", list+2);    //list+2 = list[2]의 주소 출력, 위와 마찬가지로 주소는 list[1]보다 4bytes 증가
    printf("address of list + 3  \t  =%p\n", list+3);    //list+3 = list[3]의 주소 출력, 위와 마찬가지로 주소는 list[2]보다 4bytes 증가
    printf("address of list + 4  \t  =%p\n", list+4);    //list+4 = list[4]의 주소 출력, 위와 마찬가지로 주소는 list[3]보다 4bytes 증가
    printf("address of list[4]   \t  =%p\n", &list[4]);  //list[4]의 주소 출력  = list + 4 의 값과 같음. 

    printf("\n -----[urban engineering  2019032012 Limhyunjung]-----\n");

    free(plist[0]);    //free()로 동적할당시킨 plist[0] 해제 

         printf("\n");

 
 