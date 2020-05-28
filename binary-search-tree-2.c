/*
 * Binary Search Tree #2
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

/* for stack */
#define MAX_STACK_SIZE		20
Node* stack[MAX_STACK_SIZE];
int top = -1;

Node* pop();
void push(Node* aNode);

/* for queue */
#define MAX_QUEUE_SIZE		20
Node* queue[MAX_QUEUE_SIZE];
int front = -1;
int rear = -1;

Node* deQueue();
void enQueue(Node* aNode);


int initializeBST(Node** h);

/* functions that you have to implement */
void recursiveInorder(Node* ptr);	  /* recursive inorder traversal */
void iterativeInorder(Node* ptr);     /* iterative inorder traversal */
void levelOrder(Node* ptr);	          /* level order traversal */
int insert(Node* head, int key);      /* insert a node to the tree */
int deleteNode(Node* head, int key);  /* delete the node for the key */
int freeBST(Node* head); /* free all memories allocated to the tree */

/* you may add your own defined functions if necessary */






int main()
{
	char command;
	int key;
	Node* head = NULL;

	do{
		printf("\n\n");
		printf("----------------------------------------------------------------\n");
		printf("                   Binary Search Tree #2                        \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize BST       = z                                       \n");
		printf(" Insert Node          = i      Delete Node                  = d \n");
		printf(" Recursive Inorder    = r      Iterative Inorder (Stack)    = t \n");
		printf(" Level Order (Queue)  = l      Quit                         = q \n");
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
		case 'i': case 'I':
			printf("Your Key = ");
			scanf("%d", &key);
			insert(head, key);
			break;
		case 'd': case 'D':
			printf("Your Key = ");
			scanf("%d", &key);
			deleteNode(head, key);
			break;

		case 'r': case 'R':
			recursiveInorder(head->left);
			break;
		case 't': case 'T':
			iterativeInorder(head->left);
			break;

		case 'l': case 'L':
			levelOrder(head->left);
			break;
		
		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q');

	return 1;
}

int initializeBST(Node** h) {

	/* if the tree is not empty, then remove all allocated nodes from the tree*/
	if(*h != NULL)
		freeBST(*h);

	/* create a head node */
	*h = (Node*)malloc(sizeof(Node));
	(*h)->left = NULL;	/* root */
	(*h)->right = *h;
	(*h)->key = -9999;

	top = -1;

	front = rear = -1;

	return 1;
}



void recursiveInorder(Node* ptr)
{
	if(ptr) {
		recursiveInorder(ptr->left);
		printf(" [%d] ", ptr->key);
		recursiveInorder(ptr->right);
	}
}

/**
 * textbook: p 224
 */
void iterativeInorder(Node* node)
{
    int top =-1;

	Node stack[MAX_STACK_SIZE];
	for(;;)
	{
		for(;node;node = node->left)
		{
			push(node);
		}
		node = pop();

		if(!node)
		{
			break;
		}
		printf(" [%d] ", node->key);

		node = node->right;
	}

}

/**
 * textbook: p 225
 */
void levelOrder(Node* ptr)
{
    int front = 0;
	int rear = 0;

	Node* queue[MAX_QUEUE_SIZE];

	if(!ptr)
		return ;
	
	enQueue(ptr);

	for(;;)
	{
		ptr = deQueue();
		if(ptr)
		{
			printf(" [%d] ", ptr->key);
			if(ptr->left)
			{
				enQueue(ptr->left);
			}
			if(ptr->right)
			{
				enQueue(ptr->right);
			}
		}
		else 
		{
			break;
		}
	}
}


int insert(Node* head, int key)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->key = key;
	newNode->left = NULL;
	newNode->right = NULL;

	if (head->left == NULL) {
		head->left = newNode;
		return 1;
	}

	/* head->left is the root */
	Node* ptr = head->left;

	Node* parentNode = NULL;
	while(ptr != NULL) {

		/* if there is a node for the key, then just return */
		if(ptr->key == key) return 1;

		/* we have to move onto children nodes,
		 * keep tracking the parent using parentNode */
		parentNode = ptr;

		/* key comparison, if current node's key is greater than input key
		 * then the new node has to be inserted into the right subtree;
		 * otherwise the left subtree.
		 */
		if(ptr->key < key)
			ptr = ptr->right;
		else
			ptr = ptr->left;
	}

	/* linking the new node to the parent */
	if(parentNode->key > key)
		parentNode->left = newNode;
	else
		parentNode->right = newNode;
	return 1;
}

int deleteNode(Node* head, int key)
{
	Node *A = head->left;
	Node *B = NULL;

	while(head->left != NULL && A->key != key) 
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
	if(A == NULL )
	{
		printf("ã���ô� ���� �������� �ʽ��ϴ� . \n"); 
		return ;
	}

	if(head->left == NULL) 
	{
		printf("��尡 �������� �ʽ��ϴ�. \n");
		return 0;

	}

	if(A->left == NULL && A->right == NULL) //case1 : �����ϰ��� �ϴ� ��尡 �ܸ������ ���
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
	else if(A->left == NULL || A->right == NULL) //case2 : �ϳ��� �ڽ��� ���� ���� ����� ����
	{
		if(A->left == NULL && A->right != NULL) //���� �ڽ��� ���� ������ �ڽ��� �ִ� ��� 
		{
			if(B->left == A) //������ ��尡 �θ� ����� �� ���� ���� ���
			{
				B->left = A->right;

				A->right = NULL;
			
				free(A);
			}
			else if(B->right == A)//������ ��尡 �θ��庸�� ���� Ŭ ���
			{
				B->right = A->right ;

				A->right = NULL;
			
				free(A);

			}
		}
		else if(A->left != NULL && A->right == NULL)//���� �ڽ��� �ְ� ������ �ڽ��� ���� ���
		{
			if(B->right == A)
			{
				B->right = A->left ;
				A->left= NULL;

				free(A);
			}
			else if(B->left == A)
			{
				B->left = A->left;
				A->left = NULL;

				free(A);
			}
		}

	}
	else  //case 3 :  �� ���� �ڽ��� ���� non-leaf ����� ���� 
	{
		Node *C = A->right;
		Node *D = A;

		while(C->left != NULL )
		{
		   D = C;
		   C = C->left;
		}
		
		A->key = C->key;

		if(C->left==NULL && C->right == NULL)
		{
			D->left = NULL;
			free(C);
		}
		else if(C->left == NULL && C->right != NULL)
		{
			D->left = C->right ;

			C->right = NULL;
		
			free(C);
		
		}

		


		
	}
}



void freeNode(Node* ptr)
{
	if(ptr) {
		freeNode(ptr->left);
		freeNode(ptr->right);
		free(ptr);
	}
}

int freeBST(Node* head)
{

	if(head->left == head)
	{
		free(head);
		return 1;
	}

	Node* p = head->left;

	freeNode(p);

	free(head);
	return 1;
}



Node* pop()
{
	Node *A = NULL;

	if(top != -1)
	{
		A = stack[top --];
	}
	else 
	{
		return 0;
	}
}

void push(Node* aNode)
{
	if(top < MAX_STACK_SIZE -1)
	{
		stack[++top] = aNode;
	}

}



Node* deQueue()
{
    Node* A = NULL;

	if(front == rear)
	{
		if(front != -1)
		{
			A = queue[front];
			front = -1;
			rear = -1;
		}
		return A;
	}
	
	A = queue[front];
	front ++;
	
	return A;
	
}

void enQueue(Node* aNode)
{
	if(rear == MAX_QUEUE_SIZE -1)
	{
		return;
	}
	
	if(front == -1)
	{
		front++;
	}
	rear ++;
	queue[rear] = aNode ;
}





