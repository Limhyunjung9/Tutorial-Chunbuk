#include<stdio.h>
#include<stdlib.h> //malloc()을 사용하기 위해 stdlib.h를 열어줌

void main()
{
    int list[5]; // 요소가 5개인 정수형 배열 선언
    int *plist[5] ={NULL,}; // int형 포인터를 담고있는 plist선언 후 NULL값으로 초기화.

    plist[0] = (int*)malloc(sizeof(int)); // 힙 영역에서 integer형만큼의 byte를 plist[0]에 할당.

    list[0] =1; //list[0] 값을 1로 초기화
    list[1]=100; //list[1]값을 100으로 선언

    *plist[0]=200; //plist[0]이 가리키는 값을 200으로 선언


    printf("value of list[0]        = %d\n",list[0]); //list[0]의 값 출력
    printf("address of list[0]      = %p\n",&list[0]); //list[0]의 주소 출력
    printf("value of list           = %p\n", list); //list의 값 출력(배열의 이름=배열 첫번째 요소의 주소, 즉 18줄과 19줄의 출력결과는 같음)
    printf("address of list (&list) = %p\n",&list);//list의 주소 출력


    printf("-----------------------------------------\n\n");

    //list + 1 = &(list[1])   \  *(list + 1 ) = (list[1]) 두 가지 개념을 이용해 아래 4줄 출력

    printf("value of list[1]        =%d\n", list[1]); //list[1]의 값 출력 = 위에서 100으로 초기화 한 값 출력
    printf("address of list[1]      =%p\n", &list[1]); //list[1]의 주소 출력 = list + 1
    printf("value of *(list+1)      =%d\n", *(list +1));  //*(list+1)이 가리키는 값 출력 = list[1]
    printf("address of list+1       =%p\n", list+1); //list[1]의 주소 출력과 같은 말 = list + 1의 값 


    printf("-----------------------------------------\n\n");

    printf("value of *plist[0]  =%d\n", *plist[0]); // plist[0]이 가리키는 값 출력 = 200
    printf("&plist[0]           =%p\n", &plist[0]); // plist[0]의 주소 출력 
    printf("&plist              =%p\n",&plist);     //plist의 주소 출력
    printf("plist               =%p\n", plist);    //plist의 값 출력 (배열의 이름 = 배열의 첫번째 요소의 주소)
    printf("plist[0]            =%p\n",plist[0]);   //plist[0]의 값 출력 , malloc()으로 힙영역의 4bytes짜리 메모리의 주소 
    printf("plist[1]            =%p\n",plist[1]);   //plist[1]의 값 출력 ,위에서 NULL로 초기화하였기 때문에 계속 NULL
    printf("plist[2]            =%p\n",plist[2]);   //plist[2]의 값 출력 ,위에서 NULL로 초기화하였기 때문에 계속 NULL
    printf("plist[3]            =%p\n",plist[3]);   //plist[3]의 값 출력 ,위에서 NULL로 초기화하였기 때문에 계속 NULL
    printf("plist[4]            =%p\n",plist[4]);   //plist[4]의 값 출력 ,위에서 NULL로 초기화하였기 때문에 계속 NULL

    printf("\n -----[urban engineering  2019032012 Limhyunjung]-----\n");
    

    free(plist[0]); //malloc()함수를 사용했기 때문에 free()함수 사용.



}