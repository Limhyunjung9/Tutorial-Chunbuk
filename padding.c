#include<stdio.h>

struct student {                //구조체 student 생성
    char lastName[13];    
    int studnetId ;
    short grade;
};

int main()
{

    struct student pst;           //struct student 형 변수 pst 선언
 
    printf("size of student = %ld\n", sizeof(struct student));  
     //struct student형의 크기 출력 , 구조체는 멤버변수 중 가장 큰 자료형의 크기의 배수로 정렬된다. 따라서 int형 크기 4bytes의 배수로 정렬된다.)
     //(char는 1bytes고 배열요소가 13개이므로 13bytes인데 4의 배수를 따라가야한다.) 16 +(int) 4 + (short => 2 인데 2가 더 생김 ) 4 = 16 + 4 + 4= 24
    printf("size of int  = %ld\n",  sizeof(int));                //integer의 크기 출력 (32bit=4bytes)
    printf("size of short = %ld\n",  sizeof(short));             //short의 크기 출력 (16bit = 2bytes)

    printf("\n -----[urban engineering  2019032012 Limhyunjung]-----\n");


    return 0; 
}