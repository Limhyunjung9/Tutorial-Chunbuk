/*
 * Binary Search Tree #1
 *
 * Data Structures
 *
 * Department of Computer Science
 * at Chungbuk National University
 *
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int key;
	struct node *left;
	struct node *right;
} Node;

int initializeBST(Node** h);

/* functions that you have to implement */
void inorderTraversal(Node* ptr);	  /* recursive inorder traversal */
void preorderTraversal(Node* ptr);    /* recursive preorder traversal */
void postorderTraversal(Node* ptr);	  /* recursive postorder traversal */
int insert(Node* head, int key);  /* insert a node to the tree */
int deleteLeafNode(Node* head, int key);  /* delete the leaf node for the key */
Node* searchRecursive(Node* ptr, int key);  /* search the node for the key */
Node* searchIterative(Node* head, int key);  /* search the node for the key */
int freeBST(Node* head); /* free all memories allocated to the tree */

/* you may add your own defined functions if necessary */


int main()
{
    printf("\n -----[urban engineering  2019032012 Limhyunjung]-----\n\n\n");

	char command;
	int key;
	Node* head = NULL;
	Node* ptr = NULL;	/* temp */

	do{
		printf("\n\n");
		printf("----------------------------------------------------------------\n");
		printf("                   Binary Search Tree #1                        \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize BST       = z                                       \n");
		printf(" Insert Node          = n      Delete Node                  = d \n");
		printf(" Inorder Traversal    = i      Search Node Recursively      = s \n");
		printf(" Preorder Traversal   = p      Search Node Iteratively      = f\n");
		printf(" Postorder Traversal  = t      Quit                         = q\n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);

		switch(command) {
		case 'z': case 'Z':
			initializeBST(&head);
			break;
		case 'q': case 'Q':
			freeBST(head);
			break;
		case 'n': case 'N':
			printf("Your Key = ");
			scanf("%d", &key);
			insert(head, key);
			break;
		case 'd': case 'D':
			printf("Your Key = ");
			scanf("%d", &key);
			deleteLeafNode(head, key);
			break;
		case 'f': case 'F':
			printf("Your Key = ");
			scanf("%d", &key);
			ptr = searchIterative(head, key);
			if(ptr != NULL)
				printf("\n node [%d] found at %p\n", ptr->key, ptr);
			else
				printf("\n Cannot find the node [%d]\n", key);
			break;
		case 's': case 'S':
			printf("Your Key = ");
			scanf("%d", &key);
			ptr = searchRecursive(head->left, key);
			if(ptr != NULL)
				printf("\n node [%d] found at %p\n", ptr->key, ptr);
			else
				printf("\n Cannot find the node [%d]\n", key);
			break;

		case 'i': case 'I':
			inorderTraversal(head->left);
			break;
		case 'p': case 'P':
			preorderTraversal(head->left);
			break;
		case 't': case 'T':
			postorderTraversal(head->left);
			break;
		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q');

	return 1;
}

int initializeBST(Node** h) 
{

	/* if the tree is not empty, then remove all allocated nodes from the tree*/
	if(*h != NULL)
		freeBST(*h);

	/* create a head node */
	*h = (Node*)malloc(sizeof(Node));
	(*h)->left = NULL;	/* root */
	(*h)->right = *h;
	(*h)->key = -9999;

	return 1;
}



void inorderTraversal(Node* ptr) //중위순회함수 (LVR)
{
    if(ptr == NULL )
	{
		return ;
	}
	
		inorderTraversal(ptr->left);//L

		printf("[ %d ]\t", ptr->key);//V

		inorderTraversal(ptr->right);//R


}

void preorderTraversal(Node* ptr) //전위순회함수 (VLR)
{
    if(ptr == NULL) //위에서 ptr을 head->left로 받았기때문에 head노드 외에 노드가 없는 경우를 의미한다.
	{
		return ;
	}

		printf("[ %d ]\t", ptr->key);//V

		preorderTraversal(ptr->left);//L
		preorderTraversal(ptr->right);//R

}

void postorderTraversal(Node* ptr) // 후위순회함수 (LRV)
{
   if(ptr == NULL )
	{
		return ;
	}
		postorderTraversal(ptr->left); //L
		postorderTraversal(ptr->right);//R
		
		printf("[ %d ]\t",ptr->key);//V
	
}


int insert(Node* head, int key) //tree에 노드 삽입하는 함수
{
	
	Node *newnode = (Node *)malloc(sizeof(Node)); //동적할당으로 새로운 노드 할당

	newnode->key = key;
	newnode->right = NULL;
	newnode->left = NULL;

	Node *A = head->left ;
	Node *B = head->left ;
	Node *root = head->left ;

	if(head->left == NULL) //head노드만 존재하는 경우 
	{
		head->left = newnode;
	
		return 0;		
	}
    else  //head노드 외에 노드가 존재하는 경우
	{
		while( A != NULL ) //A를 단말노드까지 이동시키며 해당되는 key를 찾는 과정
		{
			B = A; 

			if(A->key > key) //부모노드보다 key값이 작으면 부모노드의 왼쪽트리에 위치한다.
			{
				A = A->left;
			
			}
			else if(A->key <key) //부모노드보다 key값이 크다면 부모노드의 오른쪽에 위치한다.
			{
				A = A->right;

			}
			else //해당되는 key를 찾았으므로 while문을 벗어난다.
			break;
 
		}
	    /* 부모노드의 key값과 입력한 key값을 비교하여 왼쪽 또는 오른쪽에 위치하도록 하는 과정  */
		if(key < B->key) 
		{
			B->left = newnode;
			return 0;
		
		}
		else if(key > B->key)
		{
			B ->right  = newnode;
			return 0;
		}

		return 0;

	}
	

}
int deleteLeafNode(Node* head, int key)
{
	
	Node *A = head->left;
	Node *B = NULL;

	while(head->left != NULL && A->key != key)  //head외에 노드가 존재하고 root의 key가 지정한 key와 다를 때 동안 반복해서 key를 갖는 노드를 찾는 함수
	{
		B = A;

		if(key < B->key )
		{
			A = B->left;	

		}
		else if(key > B->key)
		{
			A = B->right;

		}
		
	}
	/* 이미 위에서 입력한 kqy값을 가지는 노드를 찾는 과정을 거쳤다.  */
	if(head->left == NULL) 
	{
		printf("삭제할 노드는 존재하지 않습니다. \n");
		return 0;

	}
    
	if(A->left == NULL && A->right == NULL) //단말노드일 때
	{
		if(B != NULL)
		{
			if(B->left == A)
			{
				B->left = NULL;
			}
			else 
			{
				B->right = NULL;
			}

		}
		else 
		{
			head->left = NULL;
		}
	}
	
	return 0;   

}

Node* searchRecursive(Node* ptr, int key) //재귀/스택을 이용해 결과를 얻는 방법
{
    if(!ptr) //초기상태인 경우
	{
		return NULL;
	}
	/* head 노드 외에 적어도 노드 한개가 존재하는 경우 */
	if(ptr -> key == key) 
	{
		return ptr;
	}
	else if(ptr->key > key)
	{
		searchRecursive(ptr->left, key);
	}
	else 
	{
		searchRecursive(ptr->right ,key);
	}
}

Node* searchIterative(Node* head, int key) //반복문을 이용하여 결과를 얻는 방법
{
	Node *A = head->left; //위의 switch문에서 ptr을 head로 받았기 때문에 head->left로 바꾸어 준다.

	while(A)
	{
		if(A->key == key)
		{
			return A;
		}
		else if(A->key > key)
		{
			A = A->left;
		}
		else 
		{
			A = A->right ;
		}
	}
	
	return NULL;

}


int freeBST(Node* head)
{
	if(head == NULL) //head가 NULL이면 동적할당 해제할 노드가 존재하지 않는다.
	{
		return 1;
	}
	else 
	{
		freeBST(head->left);
		freeBST(head->right);

		free(head);

		return 0;
	}
	
}
