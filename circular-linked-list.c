/*
 *  doubly circular linked list
 *
 *  Data Structures
 *
 *  Department of Computer Science
 *  at Chungbuk National University
 *
 */



#include<stdio.h>
#include<stdlib.h>
/* 필요한 헤더파일 추가 */

typedef struct Node {
	int key;
	struct Node* llink;
	struct Node* rlink;
} listNode;

/* 함수 리스트 */
int initialize(listNode** h);
int freeList(listNode* h);
int insertLast(listNode* h, int key);
int deleteLast(listNode* h);
int insertFirst(listNode* h, int key);
int deleteFirst(listNode* h);
int invertList(listNode* h);

int insertNode(listNode* h, int key);
int deleteNode(listNode* h, int key);

void printList(listNode* h);



int main()
{

	printf("\n -----[urban engineering  2019032012 Limhyunjung]-----\n\n\n");


	char command;
	int key;
	listNode* headnode=NULL;

	do{
		printf("----------------------------------------------------------------\n");
		printf("                  Doubly Circular Linked List                   \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize    = z           Print         = p \n");
		printf(" Insert Node   = i           Delete Node   = d \n");
		printf(" Insert Last   = n           Delete Last   = e\n");
		printf(" Insert First  = f           Delete First  = t\n");
		printf(" Invert List   = r           Quit          = q\n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);

		switch(command) {
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

	}while(command != 'q' && command != 'Q');

	return 1;
}


int initialize(listNode** h) {

	/* headNode가 NULL이 아니면, freeNode를 호출하여 할당된 메모리 모두 해제 */
	if(*h != NULL)
		freeList(*h);

	/* headNode에 대한 메모리를 할당하여 리턴 */
	*h = (listNode*)malloc(sizeof(listNode));
	(*h)->rlink = *h;
	(*h)->llink = *h;
	(*h)->key = -9999;
	return 1;
}

/* 메모리 해제 */
int freeList(listNode* h)
{
     if(h->rlink ==h)
    {
        free(h);
        return 0;
    }
    else 
    {
        listNode *A = h->rlink ;
        listNode *B = h->rlink;

        while(A->rlink != NULL && A != h)
        {
            B = A;
            A =A->rlink;

            free(B);

            return 0;            
        }
        free(h);
    }

	return 0;

	
}



void printList(listNode* h) {
	int i = 0;
	listNode* p;

	printf("\n---PRINT\n");

	if(h == NULL) {
		printf("Nothing to print....\n");
		return;
	}

	p = h->rlink;

	while(p != NULL && p != h) {
		printf("[ [%d]=%d ] ", i, p->key);
		p = p->rlink;
		i++;
	}
	printf("  items = %d\n", i);


	/* print addresses */
	printf("\n---checking addresses of links\n");
	printf("-------------------------------\n");
	printf("head node: [llink]=%p, [head]=%p, [rlink]=%p\n", h->llink, h, h->rlink);

	i = 0;
	p = h->rlink;
	while(p != NULL && p != h) {
		printf("[ [%d]=%d ] [llink]=%p, [node]=%p, [rlink]=%p\n", i, p->key, p->llink, p, p->rlink);
		p = p->rlink;
		i++;
	}

}



/**
 * list에 key에 대한 노드하나를 추가
 */
int insertLast(listNode* h, int key) 
{
    
	listNode * newnode = (listNode *)malloc(sizeof(listNode));
    listNode *last ;

    newnode-> key= key;
    newnode ->rlink = NULL;
    newnode-> llink = NULL;

    if(h == NULL) //리스트가 공백일 때
    {
        printf("리스트에 노드가 존재하지 않습니다. \n");
        return 0;

        h->rlink = newnode;
        last = newnode;
        newnode->rlink = h;
        newnode->llink = h;
        h->llink = newnode;

        return 0;
        
    }
    else //리스트에 노드가 존재할 때
    {
       listNode *A = h->rlink;
       listNode *B = h->rlink;

       while(A->rlink != h)
       {
          B= A;
          A= A->rlink;
       }

        last = A;

        newnode->rlink =last->rlink;
        h->llink = newnode;
        
        last->rlink = newnode;
        newnode->llink = last;

        return 0;      


    }
    
   
   return 1;

}


/**
 * list의 마지막 노드 삭제
 */
int deleteLast(listNode* h) 
{
    
     listNode *A = h->rlink ;
     listNode *B = h->rlink;
     listNode *last;

     if(h->rlink == h || h == NULL)
     {
         printf("삭제할 노드가 존재하지 않습니다. \n");

         return 0;
     }
     else 
     {
     while(A->rlink != h)
     {
         B=A;
         A = A->rlink;
     }
     last = A;

     B->rlink = h;
     h->llink = last->llink;

     last->llink = NULL;
     last->rlink = NULL;
 
     free(last);


     }
	
   
     
	return 1;
}


/**
 * list 처음에 key에 대한 노드하나를 추가
 */
int insertFirst(listNode* h, int key) 
{
    
	if(h==NULL)
	{
		printf("head노드가 존재하지 않습니다 .\n");

		return 0;
	}
	
	listNode *newnode = (listNode *)malloc(sizeof(listNode));
	newnode->key = key;
	newnode->rlink = NULL;
	newnode->llink = NULL;
	
	listNode *A = h->rlink ;
	listNode *B = h->rlink ;

	if(h->rlink == h)
	{

		h->rlink = newnode; 
		newnode->llink = h;
		h->llink = newnode;
		newnode->rlink = h;

		return 0;

	}
	else 
	{
		newnode->rlink = h->rlink ;
		newnode->rlink->llink = newnode;
		newnode->llink = h;
		h->rlink = newnode;

		return 0;	
	}

	return 1;
}

/**
 * list의 첫번째 노드 삭제
 */
int deleteFirst(listNode* h) 
{
    if(h == NULL)
	{
		printf("리스트에 head노드가 존재하지 않습니다. \n");
		return 0;
	}
	
	listNode *A = h->rlink ;

	if(h->rlink == h)
	{
		printf("리스트에 노드가 존재하지 않습니다. \n");
	    
		return 0;
	}
	else 
	{
		if(A->rlink == h)
		{
			h->rlink = h;
			h->llink = h;

			A->rlink = NULL;
			A->llink = NULL;

			free(A);

            return 0;	
		}
		else 
		{
            h->rlink = A->rlink ;
			A->rlink->llink = h;

			A->rlink = NULL;
			A->llink = NULL;

			free(A);

			return 0;		

		}
	}

	return 1;

}


/**
 * 리스트의 링크를 역순으로 재 배치
 */
int invertList(listNode* h) 
{
    
    if(h==NULL)
	{
		printf("리스트에 head노드가 존재하지 않습니다. \n");

		return 0;
	}
	
    listNode *A = h->rlink;
	listNode *B = NULL;
	listNode *C = NULL;

	while (A != h)  //노드가 존재하지 않을 때 까지 반복한다.
	{
		B = C;
		C = A;
		A = A->rlink;
		C->rlink = C->llink;
		C->llink = A;
	}
    
	listNode *D = B->rlink ;

	A->rlink = C;
	A->llink = D;

	return 0;
}



/* 리스트를 검색하여, 입력받은 key보다 큰값이 나오는 노드 바로 앞에 삽입 */
int insertNode(listNode* h, int key) 
{
	if(h == NULL)
	{
		printf("head노드가 존재하지 않습니다. \n");
		return 0;
	}
	
	listNode *newnode = (listNode *)malloc(sizeof(listNode));

	newnode->key = key;
	newnode->rlink = NULL;
	newnode->llink = NULL;


    listNode *A = h->rlink ;
	listNode *B = h->rlink ;

    if(h->rlink == h)
	{
		h->rlink = newnode;
		h->llink = newnode;
		newnode->rlink = h;
		newnode->llink = h;

		return 0;

	}
	else 
	{
		if(A->key >= key)
		{
			newnode->rlink = h->rlink;
			newnode->rlink->llink = newnode;
			newnode->llink = h;
			newnode->llink->rlink = newnode;

			return 0;
		}
		else
		{
			while(A->rlink != h)
			{
                B= A;
				A = A->rlink;
				
				if(A->key >= key)
				{
                   
				   newnode->rlink = B->rlink ;
				   newnode->rlink->llink = newnode;
				   newnode->llink = B;
				   newnode->llink->rlink = newnode;
				   
				   return 0;

				}
			}
			newnode->rlink = A->rlink;
			newnode->rlink->llink = newnode;
			newnode->llink = A;
			newnode->llink->rlink =newnode;

			return 0;
			
		}
		
	}
	return 0;
}


/**
 * list에서 key에 대한 노드 삭제
 */
int deleteNode(listNode* h, int key) 
{
	if(h == NULL)
	{
		printf("리스트에 삭제할 노드가 존재하지 않습니다. \n");
		return 0;
	}

	listNode *A = h->rlink ;
	listNode *B = h->rlink ;

	if(h->rlink == h) //head노드만 존재하는 경우
	{
		printf("head노드외에 노드가 존재하지 않습니다. \n");

		return 0;
	}
	else  //head노드외에 다른 노드가 존재하는 경우
	{  
		if(A->key==key) // 첫번째 노드가 삭제되는 대상인 경우
		{
			if(A->rlink == h) //head노드 뒤 노드가 한개만 존재하는 경우
			{
				h->rlink = h;
				h->llink = h;

				A->rlink = NULL;
				A->llink = NULL;

				free(A);
				return 0;
			}
			else //head노드 뒤 노드가 2개이상 존재하는 경우
			{
				h->rlink = A->rlink ;
				A->rlink->llink = h;

				A->rlink = NULL;
				A->llink = NULL;

				free(A);

				return 0;
			}
		}
		else //삭제되는 노드가 중간 또는 마지막에 위치한 경우
		{
			while(A != NULL)
			{
				B = A;
				A = A->rlink ;

				if(A->key == key)
				{
					if(A->rlink != h) //삭제되는 노드가 중간에 위치하는 노드일 경우
					{
						B->rlink = A->rlink;
						A->rlink->llink = B;

						A->rlink = NULL;
						A->llink = NULL;

						free(A);
						return 0;

					}
					else 
					{
						B->rlink = A->rlink;
						A->rlink->llink = B;

						A->rlink = NULL;
						A->llink = NULL;

						free(A);
						
						return 0;
					}
					

				}
			}
		
         
		
		}

		
		
	}
	return 0;
}
