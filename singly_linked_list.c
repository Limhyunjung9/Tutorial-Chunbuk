/*
 * single linked list
 *
 *  Data Structures
 *  Department of Computer Science
 *  at Chungbuk National University
 */


#include<stdio.h>
#include<stdlib.h>

 /* 필요한 헤더파일 추가 */

typedef struct Node {     //노드
	int key;
	struct Node* link;
} listNode;

typedef struct Head {    //헤드노드 
	struct Node* first;
}headNode;


/* 함수 리스트 */
headNode* initialize(headNode* h);
int freeList(headNode* h);

int insertFirst(headNode* h, int key);
int insertNode(headNode* h, int key);
int insertLast(headNode* h, int key);

int deleteFirst(headNode* h);
int deleteNode(headNode* h, int key);
int deleteLast(headNode* h);
int invertList(headNode* h);

void printList(headNode* h);

int main()
{
	char command;
	int key;
	headNode* headnode = NULL;

	do {
		printf("----------------------------------------------------------------\n");
		printf("                     Singly Linked List                         \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize    = z           Print         = p \n");
		printf(" Insert Node   = i           Delete Node   = d \n");
		printf(" Insert Last   = n           Delete Last   = e\n");
		printf(" Insert First  = f           Delete First  = t\n");
		printf(" Invert List   = r           Quit          = q\n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);

		switch (command) {
		case 'z': case 'Z':
			headnode = initialize(headnode);
			break;
		case 'p': case 'P':
			printList(headnode);
			break;
		case 'i': case 'I':
			printf("Your Key = ");
			scanf("%d", &key);
			insertNode(headnode, key);
			break;
		case 'd': case 'D':
			printf("Your Key = ");
			scanf("%d", &key);
			deleteNode(headnode, key);
			break;
		case 'n': case 'N':
			printf("Your Key = ");
			scanf("%d", &key);
			insertLast(headnode, key);
			break;
		case 'e': case 'E':
			deleteLast(headnode);
			break;
		case 'f': case 'F':
			printf("Your Key = ");
			scanf("%d", &key);
			insertFirst(headnode, key);
			break;
		case 't': case 'T':
			deleteFirst(headnode);
			break;
		case 'r': case 'R':
			invertList(headnode);
			break;
		case 'q': case 'Q':
			freeList(headnode);
			break;
		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	} while (command != 'q' && command != 'Q');

	return 1;
}

headNode* initialize(headNode* h) {   //초기화 함수

	/* headNode가 NULL이 아니면, freeNode를 호출하여 할당된 메모리 모두 해제 */
	if (h != NULL)
		freeList(h);

	/* headNode에 대한 메모리를 할당하여 리턴  */
	headNode* temp = (headNode*)malloc(sizeof(headNode));    //동적할당을 이용하여 temp노드 생성.
	temp->first = NULL;                                    
	return temp;
}

int freeList(headNode* h) {     //동적 할당 해제 함수
	/* h와 연결된 listNode 메모리 해제
	 * headNode도 해제되어야 함.
	 */
	listNode* p = h->first;

	listNode* prev = NULL;
	while (p != NULL) {
		prev = p;
		p = p->link;
		free(prev);
	}
	free(h);
	return 0;
}



/**
 * list 처음에 key에 대한 노드하나를 추가
 */ 
int insertFirst(headNode* h, int key) {    

	listNode* node = (listNode*)malloc(sizeof(listNode));
	
	node->key = key;     //생성한 노드 data부분에 매개변수 key 대입
	node->link = h->first;   //생성한 노드는 헤드노드 다음에 위치하게 된다.

	h->first = node;    

	return 0;
}

/*리스트를 검색하여, 입력받은 key보다 큰 값이 나오는 노드 바로 앞에 삽입 */
int insertNode(headNode* h, int key) 
{
	listNode* node = (listNode*)malloc(sizeof(listNode));

	node->key = key;  //생성한 노드 data부분에 매개변수로 입력받은 key를 대입한다.
	node->link = NULL;  //아직 어디를 가리킬 지 정해지지 않았으므로 NULL을 대입해준다.

	listNode *A = h->first; // 노드를 삽입할 때 필요한 노드 A, 필요한 노드를 건들 수 없는 경우에 대비하여 사용.
	
    /* 헤드뒤에 노드가 없을 때 */
	if (h->first == NULL)
	{
		h->first = node; 

	}
	/* 첫번째 노드의 key가 내가 입력한 key보다 크거나 같아서 삽입되는 위치가 head다음일 경우 */
	else if (A->key >= node->key)  
	{
		node->link = h->first;
		h->first = node;
	}
	/* 
	  이 경우는 두가지로 구분된다.
	   1. 중간에 삽입
	   2. 마지막에 삽입
	*/
	else 
	{ /* 중간에 삽입 될 경우 */
		
			while (A->link != NULL)
		{	
			listNode *B = h->first;   //필요한 노드를 건들 수 없는 경우에 대비하여 사용.
			
			A = A->link;
			B = A;

			if (A->key >= node->key)
			{
				{
					node->link = B->link;
					B->link = node;

					
				}
				break;
			}
		
		}
			A->link = node;
			node->link = NULL;
	}


	return 0;
}

/**
 * list에 key에 대한 노드하나를 리스트의 마지막에 추가
 */
int insertLast(headNode* h, int key)
{
	listNode *node = (listNode*)malloc(sizeof(listNode));
	node->key = key;
	node->link = NULL;

	listNode *A = h->first;

	if (h->first == NULL)   //리스트에 노드가 없을 때
	{
		h->first = node; //생성한 노드는 헤드 노드뒤에 위치한다.
		
	}
	else
		while (A->link != NULL)  //A노드를 리스트의 끝까지 움직이는 과정이다.
		{
			A = A->link;

			if (A->link == NULL) //노드 끝에 도달하였을 때
			{
				A->link = node;
			}

		}

}
	



/**
 * list의 첫번째 노드 삭제
 */
int deleteFirst(headNode* h)
{
	if (h->first == NULL) //리스트에 삭제할 노드가 없을 때
	{
		printf("삭제할 데이터가 없습니다 \n");
	}
	else
	{
		listNode *A = h->first;   

		h->first = A->link; 
		free(A);
	}
	return 0;
}


/**
 * list에서 key에 대한 노드 삭제
 */
int deleteNode(headNode* h, int key)
{
	listNode *A = h->first;
	listNode *trail = NULL;

	if (h->first == NULL) //head다음 노드가 존재하지 않을 때
	{
		printf("삭제할 노드가 존재하지 않습니다. \n");
	}
	/* 제거할 노드가
	
	1. 처음에 위치할 경우
	2. 중간에 위치할 경우
	3. 마지막에 위치할 경우
	
	로 나누어서 구현하였다.
	*/
	else
	{   /* 제거할 노드가 헤드 다음에 위치하는 노드일 때 */
		if (A->key == key)
		{
			h->first = A->link;
			free(A);  
		}
		else
		{
			while (A->key != key)
			{
				A = A->link;
				trail = A;
				if (A->key == key)
				{
					{
						if (A->link != NULL)
						{
							trail->link = A->link;
							free(A);
						}
						else
							trail->link == NULL;
						free(A);
					}
					break;
				}
			}
		}
	}
}

/**
 * list의 마지막 노드 삭제
 */
int deleteLast(headNode* h) 
{

	if (h->first == NULL) //헤드뒤에 노드가 존재하지 않을 때
	{
		printf("데이터가 존재하지 않습니다. \n");
	}
	else
	{
		/* 헤드뒤에 존재하는 노드가 한 개일때 */
		listNode *A = h->first;
		if (A->link == NULL)
		{
			h->first = NULL;
			free(A);
		}
		/* 노드가 2개 이상일 때 */
		else
		{
			listNode *trail = NULL;

			while (A->link != NULL)
			{
				trail = A;
				A = A->link;
			}
			trail->link == NULL;
			free(A);
		}
	}



	return 0;
}



 /**
  * 리스트를 역순을 재배치
  */

int invertList(headNode* h)
{
	/* res와 temp는 p가 이동할 수 있도록 하게 해주는 변수 */
	listNode *res = NULL;  
	listNode *temp = NULL;
	listNode *p = h->first;

    while( p!=NULL)
	{
		temp = res;
		res= p;
		p=p->link;
		res->link=temp;
	}
	return res;
}



void printList(headNode* h) {  //리스트의 상태를 출력하는 함수
	int i = 0;
	listNode* p;

	printf("\n---PRINT\n");

	if (h == NULL) {
		printf("Nothing to print....\n");
		return;
	}

	p = h->first;

	while (p != NULL) {
		printf("[ [%d]=%d ] ", i, p->key);
		p = p->link;
		i++;
	}

	printf("  items = %d\n", i);
}

