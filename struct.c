#include<stdio.h>

struct student1   //����ü student1 ����
{        
    char lastName;      
    int studentId;      
    char grade;        
};

typedef  struct {   //struct + �����̸� => student2 �� ���� ���� typedef��ɾ� ��� 
    char lastName;
    int studentId;
    char grade;
}student2;

int main()
{
    struct student1 st1 = {'A', 100, 'A'};  // student1�� ����������� ���� �ʱ�ȭ

    printf("st1.lastName    = %c\n"  , st1.lastName);    //. �����ڸ� ����Ͽ� ���� st1�� ��� lastName �� ���� ���, lastName�� char���̱� ������ %c���������ڸ� ���
    printf("st1.studentId  = %d\n", st1.studentId );     //. �����ڸ� ����Ͽ� ���� st1�� ��� studentId �� ���� ���, studentId�� int���̱� ������ %d ���������ڸ� ���
    printf("st1.grade      =%c\n",st1.grade);            //. �����ڸ� ����Ͽ� ���� st1�� ��� grade�� ���� ���, grade�� char���̱� ������ %c ���������ڸ� ���
 
    student2 st2 = {'B', 200, 'B'};                      //student2 �� st2���� ������ ��������� �ʱ�ȭ

    printf("\nst2.lastName = %c\n", st2.lastName);       //. �����ڸ� ����Ͽ� ���� st2�� ��� lastName �� ���� ���, lastName�� char���̱� ������ %c���������ڸ� ���
    printf("st2.studentId  = %d\n", st2.studentId);      //. �����ڸ� ����Ͽ� ���� st2�� ��� studentId �� ���� ���, studentId�� int���̱� ������ %d ���������ڸ� ���
    printf("st2.grade      = %c\n",st2.grade);           //. �����ڸ� ����Ͽ� ���� st2�� ��� grade �� ���� ���, grade�� char���̱� ������ %c���������ڸ� ���

    student2 st3;                                        //stduent2 st3 ����

    st3=st2;                                             //st2�� ���� st3�� ����

    printf("\nst3.lastName = %c\n", st3.lastName);     //. �����ڸ� ����Ͽ� ���� st3�� ��� lastName �� ���� ���, ���� st2�� ���� �����Ѱ��̱� ������ ���� B ���
    printf("st3.studentId  = %d\n",st3.studentId);     //. �����ڸ� ����Ͽ� ���� st3�� ��� studentId �� ���� ���, ���� st2�� ���� ������ ���̱� ������ ���� 200���
    printf("st3.grade = %c\n",st3.grade);              //. �����ڸ� ����Ͽ� ���� st3�� ��� grade �� ���� ���, ���� st2�� ���� �����Ѱ��̱� ������ ���� B ���

    printf("\n -----[urban engineering  2019032012 Limhyunjung]-----\n");


    /* equality test */

    /*   if(st3==st2)
        printf("equal\n");
    else 
        printf("not equal\n");   */

    return 0;

}