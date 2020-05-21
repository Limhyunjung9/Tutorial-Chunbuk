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



void inorderTraversal(Node* ptr) //������ȸ�Լ� (LVR)
{
    if(ptr == NULL )
	{
		return ;
	}
	
		inorderTraversal(ptr->left);//L

		printf("[ %d ]\t", ptr->key);//V

		inorderTraversal(ptr->right);//R


}

void preorderTraversal(Node* ptr) //������ȸ�Լ� (VLR)
{
    if(ptr == NULL) //������ ptr�� head->left�� �޾ұ⶧���� head��� �ܿ� ��尡 ���� ��츦 �ǹ��Ѵ�.
	{
		return ;
	}

		printf("[ %d ]\t", ptr->key);//V

		preorderTraversal(ptr->left);//L
		preorderTraversal(ptr->right);//R

}

void postorderTraversal(Node* ptr) // ������ȸ�Լ� (LRV)
{
   if(ptr == NULL )
	{
		return ;
	}
		postorderTraversal(ptr->left); //L
		postorderTraversal(ptr->right);//R
		
		printf("[ %d ]\t",ptr->key);//V
	
}


int insert(Node* head, int key) //tree�� ��� �����ϴ� �Լ�
{
	
	Node *newnode = (Node *)malloc(sizeof(Node)); //�����Ҵ����� ���ο� ��� �Ҵ�

	newnode->key = key;
	newnode->right = NULL;
	newnode->left = NULL;

	Node *A = head->left ;
	Node *B = head->left ;
	Node *root = head->left ;

	if(head->left == NULL) //head��常 �����ϴ� ��� 
	{
		head->left = newnode;
	
		return 0;		
	}
    else  //head��� �ܿ� ��尡 �����ϴ� ���
	{
		while( A != NULL ) //A�� �ܸ������� �̵���Ű�� �ش�Ǵ� key�� ã�� ����
		{
			B = A; 

			if(A->key > key) //�θ��庸�� key���� ������ �θ����� ����Ʈ���� ��ġ�Ѵ�.
			{
				A = A->left;
			
			}
			else if(A->key <key) //�θ��庸�� key���� ũ�ٸ� �θ����� �����ʿ� ��ġ�Ѵ�.
			{
				A = A->right;

			}
			else //�ش�Ǵ� key�� ã�����Ƿ� while���� �����.
			break;
 
		}
	    /* �θ����� key���� �Է��� key���� ���Ͽ� ���� �Ǵ� �����ʿ� ��ġ�ϵ��� �ϴ� ����  */
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

	while(head->left != NULL && A->key != key)  //head�ܿ� ��尡 �����ϰ� root�� key�� ������ key�� �ٸ� �� ���� �ݺ��ؼ� key�� ���� ��带 ã�� �Լ�
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
	/* �̹� ������ �Է��� kqy���� ������ ��带 ã�� ������ ���ƴ�.  */
	if(head->left == NULL) 
	{
		printf("������ ���� �������� �ʽ��ϴ�. \n");
		return 0;

	}
    
	if(A->left == NULL && A->right == NULL) //�ܸ������ ��
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

Node* searchRecursive(Node* ptr, int key) //���/������ �̿��� ����� ��� ���
{
    if(!ptr) //�ʱ������ ���
	{
		return NULL;
	}
	/* head ��� �ܿ� ��� ��� �Ѱ��� �����ϴ� ��� */
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

Node* searchIterative(Node* head, int key) //�ݺ����� �̿��Ͽ� ����� ��� ���
{
	Node *A = head->left; //���� switch������ ptr�� head�� �޾ұ� ������ head->left�� �ٲپ� �ش�.

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
	if(head == NULL) //head�� NULL�̸� �����Ҵ� ������ ��尡 �������� �ʴ´�.
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
