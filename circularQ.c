#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 4

typedef char element;    //������ �̸��� char ���� element�� ����

typedef struct 
{   
	element queue[MAX_QUEUE_SIZE];
	int front, rear;
	int number; // ���� ������ ���� 
}QueueType;   //����ü �̸��� QueuType���� ����


QueueType *createQueue();    
int freeQueue(QueueType *cQ);
int isEmpty(QueueType *cQ);
int isFull(QueueType *cQ);
void enQueue(QueueType *cQ, element item);
void deQueue(QueueType *cQ, element* item);
void printQ(QueueType *cQ);
void debugQ(QueueType *cQ);

element getElement();

int freeQueue(QueueType  *cQ)         //�����޸� �Ҵ� ����
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

     int number = ((cQ->rear) - (cQ->front)) +1;   //��������� ���� = rear�� ���� front�� ���� + 1

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
			number +=1;    // ť�� ���� �ϳ��� �Է¹����� ���� ť�� �����ϰ� �ִ� ������ ���� �����Ѵ�. �̸� ��Ÿ���� ���� ���.
			break;
		case 'd': case 'D':
			deQueue(cQ,&data); 
			number -= 1;   //ť�� ���� �ϳ��� ������ �� ���� ť�� �����ϰ� �ִ� ������ ���� �����Ѵ�. �̸� ��Ÿ���� ���� ���.
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

    freeQueue(cQ); //�����Ҵ� ���� 

	return 1;
}


QueueType *createQueue()      //ť ���� �Լ�
{
	QueueType *cQ;   
	cQ = (QueueType *)malloc(sizeof(QueueType));  //malloc()�� ���� �������� �޸𸮸� �Ҵ�޾� �ּҸ� ��ȯ�޴´�. 
	cQ->front = 0;   //(*cQ).front = 0
	cQ->rear = 0;    //(*cQ).rear = 0
	return cQ;
}

element getElement()     //�޴������Լ� 
{
	element item; //������ item ����
	printf("Input element = "); 
	scanf(" %c", &item);
	return item;
}


/* complete the function */
int isEmpty(QueueType *cQ)      //ť�� �������� Ȯ���ϴ� �Լ� 
{  
	cQ->number = ((cQ->rear) - (cQ->front)) +1;  // ���� ť�� �����ϰ� �ִ� ������ ���� 
	if(cQ->number == 0)  //ť�� ���Ұ� ������
	 {
		 printf("ť�� �����Դϴ�.\n");
	     return 1;
	 } 
	
	else 
	   return 0;
}
	

/* complete the function */
int isFull(QueueType *cQ)    
{
  	 cQ->number = ((cQ->rear) - (cQ->front)) +1; //���� ť�� �����ϰ� �ִ� ������ ���� 


   if(cQ->number == MAX_QUEUE_SIZE +1)  //ť�� �����ϴ� ���Ұ� MAX_QUEUE_SIZE(4)���϶�
     {
	 printf("ť�� ������ �����ϴ�.\n");
	 return 1;
	 } 
   else 
    {
	  printf("ť�� ������ �����ֽ��ϴ�.\n");
	  return 0;
	} 
	 // ť ���� ���

   
}


/* complete the function */
void enQueue(QueueType *cQ, element item)     //ť�� ����
{   
	/* ��ó�� �˻� - ť�� ������ �ִ��� ������ */
	if(isFull(cQ))
	   return isFull(cQ);  

	else
	{
	 cQ->rear = (cQ -> rear) + 1  ;  // rear�� ���Ұ� �߰��Ǿ����Ƿ� 1 ���
	 cQ->queue[(cQ->rear)] = item ;  // rear �ڸ��� ���Ӱ� ���� ���� �߰�
              
	 return 0;
	}
	      
}

/* complete the function */
void deQueue(QueueType *cQ, element *item)   //ť���� ���� 
{
	if(isEmpty(cQ))
	  return isEmpty(cQ);

	else
	{   
		*item = cQ->queue[(cQ->front)] ; // ť�� ���Լ����̱� ������ ���� ���� ���� front ���� ���� ���� ���� �ȴ� .

		cQ->front = cQ->front + 1 ;   //���Ұ� �ϳ� ���� �Ǿ����Ƿ� front �� 1 ����
		          
		 return 0;
	}
	 
	 

}


void printQ(QueueType *cQ)  //���� ť�� ���¸� ���
{
	int i, first, last;

	first = (cQ->front + 1) % MAX_QUEUE_SIZE;
	last = (cQ->rear + 1) % MAX_QUEUE_SIZE;

	printf("Circular Queue : [");


	i = first;
	while(i != last) //ť�� ���� ����ִ� ������ ���� ��ŭ �ݺ�
	{
		printf("%3c", cQ->queue[i]);
		i = (i+1)%MAX_QUEUE_SIZE;

	}
	printf(" ]\n");
}


void debugQ(QueueType *cQ)   //MAX_QUEUE_SIZE���� �̷���� ť�� ��� �ڸ��� Ȯ�����ִ� �Լ�
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
	// (*cQ).front �� (*cQ).rear�� ����ϴ� ���� 
}

