#include<stdio.h>

#define MAX_SIZE 100   //MAX_SIZE 기호상수(단순 매크로) 정의

float sum(float [],int);        //함수 원형 정의
float input[MAX_SIZE], answer;  //부동 소수점형 자료형을 가진 input 배열, answer 변수 선언 
int i;                          //정수형 변수 i 선언
void main(void)                 
{
    for(i=0; i< MAX_SIZE; i++)  //MAX_SIZE(= 100) 횟수만큼 for문 반복
    {
        input[i]=i;             
    }

    /* for checking call by reference */
    printf("address of input = %p\n", input);  

    answer = sum(input,MAX_SIZE);              //answer에 함수 sum을 실행한 결과를 대입 
    printf("The sum is : %f\n", answer);       // answer 값 출력 ,answer = 0 ~ 99의 합 

    printf("\n -----[urban engineering  2019032012 Limhyunjung]-----\n");

}
float sum(float list[], int n )                
{
    printf("value of list = %p\n", list);        //list의 값 출력 = input의 주소와 같음 
    printf("address of list = %p\n\n", &list);   //list의 주소 출력

    int i;                                       //int형의 변수 i 선언
    float tempsum = 0;                           //flaot 형의 변수 tempsum을 0으로 초기화 
    for(i=0; i<n; i++)                           
       tempsum += list[i];                       //위에서 for문을 통해 input[i]=i라고 선언했기 때문에 tempsum은 0~n-1까지의 합. main()에선 n 자리에 MAX_SIZE가 오기 때문에 0~99의 합

    return tempsum;                              //tempsum 반환
}



