#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 4

typedef char element;    //문자형 이름을 char 에서 element로 변경

typedef struct 
{   
	element queue[MAX_QUEUE_SIZE];
	int front, rear;
	int number; // 현재 원소의 개수 
}QueueType;   //구조체 이름을 QueuType으로 변경


QueueType *createQueue();    
int freeQueue(QueueType *cQ);
int isEmpty(QueueType *cQ);
int isFull(QueueType *cQ);
void enQueue(QueueType *cQ, element item);
void deQueue(QueueType *cQ, element* item);
void printQ(QueueType *cQ);
void debugQ(QueueType *cQ);

element getElement();

int freeQueue(QueueType  *cQ)         //동적메모리 할당 해제
{
	if(cQ==NULL) 
	   return NULL;
	else
	   free(cQ);
	
	return 1;
}

int main(void)
{
     
     printf("\n\n --------[urban engineering  2019032012 Limhyunjung]--------\n\n\n");
     
	 

	 QueueType *cQ = createQueue();    

   	 element data;

	 char command; 

     int number = ((cQ->rear) - (cQ->front)) +1;   //현재원소의 개수 = rear의 개수 front의 개수 + 1

	do{
		printf("\n-----------------------------------------------------\n");
		printf("                     Circular Q                   \n");
		printf("------------------------------------------------------\n");
		printf(" Insert=i,  Delete=d,   PrintQ=p,   Dubug=b,   Quit=q \n");
		printf("------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);

		switch(command) 
		{
		case 'i': case 'I':
			data = getElement();
			enQueue(cQ, data); 
			number +=1;    // 큐에 숫자 하나를 입력받을때 마다 큐에 존재하고 있는 숫자의 수가 증가한다. 이를 나타내기 위해 사용.
			break;
		case 'd': case 'D':
			deQueue(cQ,&data); 
			number -= 1;   //큐에 숫자 하나를 제거할 때 마다 큐에 존재하고 있는 숫자의 수가 감소한다. 이를 나타내기 위해 사용.
			break;
		case 'p': case 'P':
			printQ(cQ);
			break;
		case 'b': case 'B':
			debugQ(cQ);
			break;
		case 'q': case 'Q':
			break;
		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q');

    freeQueue(cQ); //동적할당 해제 

	return 1;
}


QueueType *createQueue()      //큐 생성 함수
{
	QueueType *cQ;   
	cQ = (QueueType *)malloc(sizeof(QueueType));  //malloc()을 통해 동적으로 메모리를 할당받아 주소를 반환받는다. 
	cQ->front = 0;   //(*cQ).front = 0
	cQ->rear = 0;    //(*cQ).rear = 0
	return cQ;
}

element getElement()     //메뉴선택함수 
{
	element item; //문자형 item 선언
	printf("Input element = "); 
	scanf(" %c", &item);
	return item;
}


/* complete the function */
int isEmpty(QueueType *cQ)      //큐가 공백임을 확인하는 함수 
{  
	cQ->number = ((cQ->rear) - (cQ->front)) +1;  // 현재 큐에 존재하고 있는 원소의 개수 
	if(cQ->number == 0)  //큐에 원소가 없을때
	 {
		 printf("큐는 공백입니다.\n");
	     return 1;
	 } 
	
	else 
	   return 0;
}
	

/* complete the function */
int isFull(QueueType *cQ)    
{
  	 cQ->number = ((cQ->rear) - (cQ->front)) +1; //현재 큐에 존재하고 있는 원소의 개수 


   if(cQ->number == MAX_QUEUE_SIZE +1)  //큐에 존재하는 원소가 MAX_QUEUE_SIZE(4)개일때
     {
	 printf("큐에 공간이 없습니다.\n");
	 return 1;
	 } 
   else 
    {
	  printf("큐에 공간이 남아있습니다.\n");
	  return 0;
	} 
	 // 큐 상태 출력

   
}


/* complete the function */
void enQueue(QueueType *cQ, element item)     //큐에 삽입
{   
	/* 전처리 검사 - 큐에 공백이 있는지 없는지 */
	if(isFull(cQ))
	   return isFull(cQ);  

	else
	{
	 cQ->rear = (cQ -> rear) + 1  ;  // rear는 원소가 추가되었으므로 1 상승
	 cQ->queue[(cQ->rear)] = item ;  // rear 자리에 새롭게 들어온 원소 추가
              
	 return 0;
	}
	      
}

/* complete the function */
void deQueue(QueueType *cQ, element *item)   //큐에서 제거 
{
	if(isEmpty(cQ))
	  return isEmpty(cQ);

	else
	{   
		*item = cQ->queue[(cQ->front)] ; // 큐는 선입선출이기 때문에 제일 먼저 들어온 front 값이 제일 먼저 제거 된다 .

		cQ->front = cQ->front + 1 ;   //원소가 하나 삭제 되었으므로 front 값 1 증가
		          
		 return 0;
	}
	 
	 

}


void printQ(QueueType *cQ)  //현재 큐의 상태를 출력
{
	int i, first, last;

	first = (cQ->front + 1) % MAX_QUEUE_SIZE;
	last = (cQ->rear + 1) % MAX_QUEUE_SIZE;

	printf("Circular Queue : [");


	i = first;
	while(i != last) //큐애 현재 들어있는 원소의 개수 만큼 반복
	{
		printf("%3c", cQ->queue[i]);
		i = (i+1)%MAX_QUEUE_SIZE;

	}
	printf(" ]\n");
}


void debugQ(QueueType *cQ)   //MAX_QUEUE_SIZE개로 이루어진 큐의 모든 자리를 확인해주는 함수
{

	printf("\n---DEBUG\n");
	for(int i = 0; i < MAX_QUEUE_SIZE; i++)   
	{
		if(i == cQ->front) {
			printf("  [%d] = front\n", i);
			continue;
		}
		printf("  [%d] = %c\n", i, cQ->queue[i]);

	}
	printf("front = %d, rear = %d\n", cQ->front, cQ->rear); 
	// (*cQ).front 와 (*cQ).rear을 출력하는 문장 
}

