#include<stdio.h>

struct student1   //구조체 student1 선언
{        
    char lastName;      
    int studentId;      
    char grade;        
};

typedef  struct {   //struct + 변수이름 => student2 로 쓰기 위해 typedef명령어 사용 
    char lastName;
    int studentId;
    char grade;
}student2;

int main()
{
    struct student1 st1 = {'A', 100, 'A'};  // student1의 멤버변수들을 각각 초기화

    printf("st1.lastName    = %c\n"  , st1.lastName);    //. 연산자를 사용하여 변수 st1의 멤버 lastName 의 값을 출력, lastName은 char형이기 때문에 %c형식지정자를 사용
    printf("st1.studentId  = %d\n", st1.studentId );     //. 연산자를 사용하여 변수 st1의 멤버 studentId 의 값을 출력, studentId는 int형이기 때문에 %d 형식지정자를 사용
    printf("st1.grade      =%c\n",st1.grade);            //. 연산자를 사용하여 변수 st1의 멤버 grade의 값을 출력, grade는 char형이기 때문에 %c 형식지정자를 사용
 
    student2 st2 = {'B', 200, 'B'};                      //student2 형 st2변수 각각의 멤버변수를 초기화

    printf("\nst2.lastName = %c\n", st2.lastName);       //. 연산자를 사용하여 변수 st2의 멤버 lastName 의 값을 출력, lastName은 char형이기 때문에 %c형식지정자를 사용
    printf("st2.studentId  = %d\n", st2.studentId);      //. 연산자를 사용하여 변수 st2의 멤버 studentId 의 값을 출력, studentId는 int형이기 때문에 %d 형식지정자를 사용
    printf("st2.grade      = %c\n",st2.grade);           //. 연산자를 사용하여 변수 st2의 멤버 grade 의 값을 출력, grade는 char형이기 때문에 %c형식지정자를 사용

    student2 st3;                                        //stduent2 st3 선언

    st3=st2;                                             //st2의 값을 st3에 대입

    printf("\nst3.lastName = %c\n", st3.lastName);     //. 연산자를 사용하여 변수 st3의 멤버 lastName 의 값을 출력, 변수 st2의 값을 대입한것이기 때문에 문자 B 출력
    printf("st3.studentId  = %d\n",st3.studentId);     //. 연산자를 사용하여 변수 st3의 멤버 studentId 의 값을 출력, 변수 st2의 값을 대입한 것이기 때문에 숫자 200출력
    printf("st3.grade = %c\n",st3.grade);              //. 연산자를 사용하여 변수 st3의 멤버 grade 의 값을 출력, 변수 st2의 값을 대입한것이기 때문에 문자 B 출력

    printf("\n -----[urban engineering  2019032012 Limhyunjung]-----\n");


    /* equality test */

    /*   if(st3==st2)
        printf("equal\n");
    else 
        printf("not equal\n");   */

    return 0;

}