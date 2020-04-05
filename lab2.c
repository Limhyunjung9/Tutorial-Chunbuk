#include<stdio.h>
int main(void)
{

         int i;
         int *ptr;
         int **dptr;


         i=1234;
          
        
        printf("[checking values before ptr = &i] \n");    
        printf("value of i == %d\n", i);                    //변수 i의 값 
        printf("address of i == %p\n", &i);                 //변수 1의 주소 출력
        printf("value of ptr == %p\n", ptr);                //ptr의 값 출력
        printf("address of ptr == %p\n", &ptr);             //ptr의 주소 출력

        ptr = &i; /* ptr is now holding the address of i */     //ptr은 변수 i의 주소를 가리키는 포인터


        printf("\n[checking values after ptr = &i] \n"); 
        printf("value of i == %d\n", i);                    //i의 값 출력
        printf("address of i == %p\n", &i);                 //변수 i의 주소 출력
        printf("value of ptr == %p\n", ptr);                //ptr의 값 출력 = i의 주소 출력
        printf("address of ptr == %p\n", &ptr);             //ptr의 주소 출력
        printf("value of *ptr == %d\n", *ptr);              //ptr이 가리키는 값 출력 = 변수 i의 값 출력

        dptr = &ptr; /* dptr is now holding the address of ptr */   // dptr은 *ptr의 주소를 가리키는 이중 포인터


        printf("\n[checking values after dptr = &ptr] \n"); 
        printf("value of i == %d\n", i);                   // 변수 i의 값 출력
        printf("address of i == %p\n", &i);                // 변수 i의 주소 출력
        printf("value of ptr == %p\n", ptr);               // ptr의 값 출력 = i의 주소 출력 = dptr이 가리키는 값 출력
        printf("address of ptr == %p\n", &ptr);            // ptr의 주소 출력 = **dptr의 값
        printf("value of *ptr == %d\n", *ptr);             // ptr이 가리키는 값 출력 = i의 값 출력 
        printf("value of dptr == %p\n", dptr);             // dptr의 값 출력 = ptr의 주소 출력
        printf("address of dptr == %p\n", &dptr);          // dptr의 주소 출력  
        printf("value of *dptr == %p\n", *dptr);           // dptr이 가리키는 값 출력 = ptr의 값 = 변수 i의 주소
        printf("value of **dptr == %d\n", **dptr);         // *(*dptr) 출력= *ptr 출력 = 변수 i의 값 출력

        *ptr = 7777; /* changing the value of *ptr */      // ptr이 가리키는 값을 7777로 초기화 = 변수 i의 값이 7777로 변경

        printf("\n[after *ptr = 7777] \n");                
        printf("value of i == %d\n", i);                   //변수 i의 값 출력 
        printf("value of *ptr == %d\n", *ptr);             //ptr이 가리키는 값 출력 = 변수 i의 값 출력 
        printf("value of **dptr == %d\n", **dptr);         // *(*dptr) 출력 = *ptr 출력 = 변수 i의 값 출력

        **dptr = 8888; /* changing the value of **dptr */    //*(*dptr)=*ptr=i=8888


        printf("\n[after **dptr = 8888] \n");             
        printf("value of i == %d\n", i);                     //변수 i의 값 출력 
        printf("value of *ptr == %d\n", *ptr);               //ptr이 가라키는 값 출력 = 변수 i의 값 
        printf("value of **dptr == %d\n", **dptr);           //*(*dptr)의 값 출력 = *ptr 출력 = 변수 i의 값 출력

        printf("-----[unrban engineering][2019032012][Lim hyunjug]-----\n");


        return 0;

    


}
    


