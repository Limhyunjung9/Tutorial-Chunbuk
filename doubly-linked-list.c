
/*
 *  doubly-linked-list.c
 *
 *  Doubly Linked List
 *
 *  Data Structures
 *  Department of Computer Science
 *  at Chungbuk National University
 *
 */



#include<stdio.h>
#include<stdlib.h>
 /* 필요한 헤더파일 추가 if necessary */


typedef struct Node {
	int key;
	struct Node* llink;   //왼쪽 노드의 주소를 가리키고 있는 포인터
	struct Node* rlink;   //오른쪽 노드의 주소를 가리키고 있는 포인터
} listNode;



typedef struct Head {
	struct Node* first;   
}headNode;

/* 함수 리스트 */

/* note: initialize는 이중포인터를 매개변수로 받음
		 singly-linked-list의 initialize와 차이점을 이해 할것 */
int initialize(headNode** h);

/* note: freeList는 싱글포인터를 매개변수로 받음
		- initialize와 왜 다른지 이해 할것
		- 이중포인터를 매개변수로 받아도 해제할 수 있을 것 */
int freeList(headNode* h);

int insertNode(headNode* h, int key);
int insertLast(headNode* h, int key);
int insertFirst(headNode* h, int key);
int deleteNode(headNode* h, int key);
int deleteLast(headNode* h);
int deleteFirst(headNode* h);
int invertList(headNode* h);

void printList(headNode* h);


int main()
{
	printf("\n -----[urban engineering  2019032012 Limhyunjung]-----\n\n\n");


	char command;
	int key;
	headNode* headnode = NULL;

	do {
		printf("----------------------------------------------------------------\n");
		printf("                     Doubly Linked  List                        \n");
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
			initialize(&headnode);
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


int initialize(headNode** h) //초기화 함수 
{
    if(*h != NULL)
	{
		freeList(*h);
	}
	else 
	{
		*h = (headNode*)malloc(sizeof(headNode));

	    (*h)->first = NULL;
	}

	return 1;
}

int  freeList(headNode* h) // 동적할당 해제 함수 
{
	
	listNode *A = h->first;
	listNode *B = h->first;

	while (A != NULL)
	{
		B = A;
		A = A->rlink;
		free(B);
	}
	free(h);


	return 0;
	
}


void printList(headNode* h)   //현재 리스틑 상태 출력 함수 
{
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
		p = p->rlink;
		i++;
	}

	printf("  items = %d\n", i);
}




/**
 * list에 key에 대한 노드하나를 추가
 */
int insertLast(headNode* h, int key) // 이중 연결리스트 마지막에 양방향 노드 삽입 
{

	listNode *newnode = (listNode *)malloc(sizeof(listNode)); //동적할당으로 새로운 노드 생성

	newnode->key = key;   
	/* 아직 링크에 무엇이 담겨있는지 알수 없으므로 NULL로 초기화 */ 
	newnode->rlink = NULL;
	newnode->llink = NULL;

	listNode *A = h->first;
	listNode *B = h->first;

	if (h->first == NULL)    //head노드를 제외하고 어떠한 노드도 존재하지 않을 때
	{
		h->first = newnode;
		newnode->llink = NULL;

		return 0;
	}
	else //노드가 1개 이상 존재하고 있을 때
	{
		while (A->rlink != NULL)  //A가 마지막노드를 가리키게 하기 위해 A를 노드의 끝까지 옮기는 과정
		{  
			B = A;  //B는 A의 바로 전 노드를 가리키게끔 한다.
			A = A->rlink;
		}
		A->rlink = newnode;
		newnode->llink = A;

		newnode->rlink = NULL;

		return 0;


	}

	return 0;
}


/**
 * list의 마지막 노드 삭제
 */
int deleteLast(headNode* h)   //이중 연결 리스트 마지막 노드 삭제 
{

	/*  1. 노드가 존재하지 않을 때
		2. 노드가 존재할 때
		  (1) 헤드 노드 뒤 노드가 하나밖에 없어, 첫번째 노드를 삭제해야 하는 경우
		  (2) 삭제 해야 할 노드가 중간에 위치할 때
		  (3) 삭제 해야 할 노드가 마지막에 위치할 때
    */
	

	listNode *A = h->first;
	listNode *B = h->first;

	if (h->first == NULL) //리스트에 노드가 존재하지 않을 때
	{
		printf("리스트에 노드가 존재하지 않습니다. \n");

		return 0;
	}
	else
	{
		if (A->rlink == NULL)  //head노드 뒤 노드가 1개 존재하는데 그 노드를 삭제해야 하는 경우
		{
			h->first = NULL;
			free(A);

			return 0;
		}
		else //head노드 뒤 노드가 2개 이상인 경우
		{
			while (A->rlink != NULL)
			{   
				B = A;
				A = A->rlink;
			}

			B->rlink = NULL;
			A->llink = NULL;

			free(A);

			return 0;

		}
	}

}


/**
 * list 처음에 key에 대한 노드하나를 추가
 */
int insertFirst(headNode* h, int key)   //이중 연결 리스트의 헤드노드 다음에 노드 삽입 
{
	listNode* newnode = (listNode *)malloc(sizeof(listNode));   //삽입할 노드 동적할당 방식으로 생성
	listNode *A = h->first;   

	newnode->key = key;
	newnode->rlink == NULL;
	newnode->llink == NULL;

	if (h->first == NULL) //head노드 다음 노드가 존재하지 않을 때
	{
		h->first = newnode;
		newnode->llink = NULL;

		return 0;
	}
	else //head 노드 다음 노드가 존재할 때
	{
		newnode->rlink = h->first;
		A->llink = newnode;

		h->first = newnode;
		newnode->llink = NULL;


		return 0;
	}

	return 0;
}

/**
 * list의 첫번째 노드 삭제
 */
int deleteFirst(headNode* h) //헤드 노드 다음 노드를 삭제하는 함수 
{
	listNode *A = h->first;

	if (h->first == NULL)
	{
		printf("리스트에 삭제할 노드가 존재하지 않습니다. \n");
		return 0;
	}
	else 
	{
		if(A->rlink == NULL) //노드가 한개 였을 때
		{
           h->first = NULL;
		   free(A);
		   return 0;
		}
		else//head노드 다음 노드가 2개 이상일 때
		{
			h->first = A-> rlink;
			A->rlink->llink = NULL;
			A->rlink = NULL;

			free(A);

			return 0;

		}
	}

		
}



/**
 * 리스트의 링크를 역순으로 재 배치
 */
int invertList(headNode* h)
{

	if (h->first == NULL)  //head노드 다음 노드가 존재하지 않을 때
	{
		printf("재배열할 리스트가 존재하지 않습니다.\n");
		return 0;
	}
	listNode *A = h->first;
		
	listNode *B = NULL;
	listNode *C = NULL;

	while (A != NULL)  //노드가 존재하지 않을 때 까지 반복한다.
	{
		B = C;
		C = A;
		A = A->rlink;
		C->rlink = B;
		C->llink = A;
	}

	h->first = C;

	return 0;
}



/* 리스트를 검색하여, 입력받은 key보다 큰값이 나오는 노드 바로 앞에 삽입 */
int insertNode(headNode* h, int key)
{
	listNode *newnode = (listNode *)malloc(sizeof(listNode));

	newnode->key = key; //내가 입력한 데이터를 새로 생성할 데이터 자리에 대입
	/* 어디에 삽입될 지 결정되지 않았으므로 NULL로 초기화 */
	newnode->llink = NULL;
	newnode->rlink = NULL;

	listNode *A = h->first;

	/* 1. 헤드 뒤에 노드가 없을 때
	   2. 헤드 뒤에 노드가 있을 때
		  (1) 첫번째 노드의 key가 입력한 key 보다 클 때
		  (2) 내 key보다 큰 key를 가지고 있는 key가 중간에 위치할 때
		  (3) 내 key보다 큰 key를 가지고 있는 key가 마지막에 위치할 때
	*/

	if (h->first == NULL)
	{
		h->first = newnode;

		return 0;
	}
	else
	{  /* 첫번째 노드위치에 newnode가 들어갈 때 */
		if (A->key >= newnode->key)
		{
			h->first = newnode;

			newnode->rlink = A;
			newnode->llink = NULL;
			newnode->rlink->llink = newnode;

		}
		else // newnode 가 중간 또는 마지막에 삽입될 때
		{
			listNode *B = h->first;

			while (A->rlink != NULL)
			{
				B = A;
				A = A->rlink;
				

				if (A->key >= newnode->key) // newnode 가 중간에 삽입될 경우 
				{
					newnode->rlink = A;
					newnode->llink = B;

					newnode->llink->rlink = newnode;
					newnode->rlink->llink = newnode;
				}

			}

			A->rlink = newnode;
			newnode->llink = A;
			newnode->rlink = NULL;

			return 0;

		}
	}

	return 0;
}

/**
	 * list에서 key에 대한 노드 삭제
	 */
int deleteNode(headNode* h, int key)
{
	/* 1. 삭제할 노드가 존재하지 않을 때
	   2. 삭제할 노드가 존재할 때
		  (1) 삭제할 노드가 처음에 위치할 경우
		  - head노드 뒤 노드가 한개 일경우
		  - head노드 뒤 노드가 2개 이상일 경우
		  (2) 삭제할 노드가 중간에 위치할 경우
		  (3) 삭제할 노드가 마지막에 위치할 경우
	 */

	
	if (h->first == NULL)  //리스트에 삭제할 노드가 존재하지 않을 때
	{
		printf("리스트에 삭제할 노드가 존재하지 않습니다. \n");
		return 0;
	}

	listNode* A = h->first;
    /* 리스트에 삭제할 노드가 존재 할 때 */
	while (A != NULL)
	{
		if (A->key == key)
		{
			if (A == h->first) // 삭제 할 노드가 head노드 뒤에 위치하고 있을 때 
			{ 
				{
					listNode *A = h->first;

										
					if(h->first != NULL)
					{
						if (A->rlink == NULL) //head노드 뒤 노드가 한개일 경우
						{
							h->first = NULL;
							free(A);

							return 0;
						}
						else //head노드 뒤 노드가 2개이상 일 경우
						{
							h->first = A->rlink;
							A->rlink->llink = NULL;
							A->rlink = NULL;

							free(A);

							return 0;

						}
					}
				}
			}
			else if (A->rlink != NULL)  //삭제할 노드가 중간에 위치하고 있을 경우
			{
								
				A->llink->rlink = A->rlink;	
				A->rlink->llink = A->llink;
				
				A->rlink = NULL;
				A->llink = NULL;
				
				free(A);
				

			}
			else
			{ 
				//삭제할 노드가 마지막에 위치하고 있을 경우

				listNode *A = h->first;
				listNode *B = h->first;

               if (h->first != NULL)				
				{
					if (A->rlink == NULL)
					{
						h->first = NULL;
						free(A);

						return 0;
					}
					else
					{
						while (A->rlink != NULL)
						{
							B = A;
							A = A->rlink;
						}

						B->rlink = NULL;
						A->llink = NULL;

						free(A);

						return 0;

					}
				}
			}
			return 1;
		}

		A = A->rlink;
	}

	return 0;
}