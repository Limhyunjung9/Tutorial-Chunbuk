/* ��������Ʈ�� ����Ͽ� �׷��� ���� */

#include<stdio.h>
#include<stdlib.h> //�����Ҵ��� �ϱ� ���� 

#define MAX_VERTEX   20   // = headNode ���� �ִ� 20������ ��������
int visited[MAX_VERTEX];

/* ����ü ���� */

typedef struct Vertex
{
    int num;                //vertex number
    struct Vertex* link;    //link to a next adjacent vertex
}Vertex;


typedef struct VertexHead  //linked list of all adjacent vertices
{
    Vertex* head;
}VertexHead;

typedef struct Graph  //list of all vertices : vlist[MAX_VERTEX]
{
    VertexHead* vlist; 
}Graph;

/* �Լ����� ���� */

void createGraph(VertexHead** h);          /* empty graph cration */
void destroyGraph(VertexHead** h);         /* deallocationg all allocated memory */
       
int insertVertex(VertexHead* h,int A);        /* vertex insertion */
void deleteVertex(VertexHead* h, int A);        /* vertex deletion */

int insertEdge(VertexHead* h, int A, int B);          /* new edge creation between two vertices */
void deleteEdge(VertexHead* h, int A, int B);          /* edge removal */

void depthFS(VertexHead* h, int v);             /* depth first search using stack */
void breadthFS(VertexHead* h, int v);           /* breadth first search using queue  */
void printGraph(VertexHead* h);         /* printing graph with vertices and edges */

/* stack */
int stack[MAX_VERTEX];  
int top =-1;

int pop();
void push(int A);

/* queue */
int queue[MAX_VERTEX];
int front = -1;
int rear = -1;

int dequeue();
void enQueue(int A);



/* �����Լ� */
int main()
{

	printf("\n -----[urban engineering  2019032012 Limhyunjung]-----\n\n\n");

	char command;
	int key;


    VertexHead* h = NULL;  
	Vertex* A = NULL;      
	Vertex* B = NULL;      

	int a,b,v;             
	int n;                 

	do {
		printf("----------------------------------------------------------------\n");
		printf("                             graph                              \n");
		printf("----------------------------------------------------------------\n");
		printf(" createGraph   = c           destory Graph = d \n");
		printf(" insertVertex  = i           deleteVertex  = e\n");
		printf(" insertEdge    = g           deleteEdge    = t\n");
		printf(" depthFS       = f           breadthFS     = b\n");
     	printf(" printGraph    = p                            \n ");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);
switch (command) {
		case 'c': case 'C':
			createGraph(&h);
			break;
		case 'd': case 'D':
			destroyGraph(h);
			break;
		case 'i': case 'I':
			printf("Vertex number = ");
			scanf("%d", &key);
			insertVertex(h,a);
			break;
		case 'e': case 'E':
			printf("Vertex number = ");
			scanf("%d", &key);
			deleteVertex(h,a);
			break;
		case 'g': case 'G':
			printf("Vertex = ");
			scanf("%d  %d", &key, &key);
			insertEdge(h,A,B);
			insertEdge(h,B,A);
			break;
		case 't': case 'T':
			printf("Vertex = ");
		
			scanf("%d   %d", &key, &key);
			deleteEdge(h,a,b);
			deleteEdge(h,b,a);
			break;
		case 'f': case 'F':
			depthFS(h,v);
			break;
		case 'b': case 'B':
			breadthFS(h,v);
			break;
		case 'p': case 'P':
			printGraph(h);
			break;
		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	} while (command != 'q' && command != 'Q');

	return 1;
}



void createGraph(VertexHead** h)   //�׷����� �ʱ�ȭ�ϴ� �Լ�
{
   if (*h != NULL) //�׷����� �����ϴ� ���
   {    
      destroyGraph(*h); //�׷����� �����ϸ� �ı����ش�.
   }

   *h= (VertexHead*)malloc(sizeof(VertexHead)*MAX_VERTEX);  //headNode���� MAX_VERTEX��ŭ ����ִ� h�迭�� ����

   /* �迭�� ��� headNode���� NULL�� �ʱ�ȭ */ 
   for (int i = 0; i < MAX_VERTEX; i++) 
   {      
	    (*h)[i].head = NULL; 
   }

   return *h;
}

void destroyGraph(VertexHead** h) //�����Ҵ� ���� �Լ�
{
	if(h == NULL) //�׷����� �ƹ��͵� ���� ���
	{
		printf("�׷����� �ƹ��͵� �������� �ʽ��ϴ�. \n");
		return ;
	}
	else //�׷����� ���� �����Ͽ� ������ ���� �߻��� ���
	{
	   for(int i=0; i< MAX_VERTEX; i++)
	    {
		   free((*h)[i].head);
	    }

	}
}

int insertVertex(VertexHead* h,int A) //�Է¹��� ���ڸ� num���� ���� ������ �����ϴ� �Լ� 
{
	Vertex* v = h[A].head;  //���A��° �迭�� �ش��ϴ� ���� v ����
	Vertex* tmp  = NULL;    

	tmp = (Vertex *)malloc(sizeof(Vertex));
	tmp -> num = 1;
	tmp -> link = NULL;

	if(v == NULL) //�Է��� ������ ���ٸ�
	{
		v  = tmp;
		v->num = A;

	}
	
	return v;
}

void deleteVertex(VertexHead* h, int A)  //������ �����ϴ� �Լ�
{
	/* �׷������� �����ϴ� ������ ������ Ȯ���ϱ� ���� �κ� */
	int n=0;
	
	for(int i=0; i<MAX_VERTEX; i++)
	{
		if ((h)[i].head != NULL)
		{
			n++;
		}
	}
	return n;

	/* �׷����� �ƿ� ������ �������� �ʴ� ��� */
	if(n = 0 )
	{
		printf("������ �� �����ϴ�. \n");
		return ;
	}
	else
	{
		(h)[A].head = 0;
	}
	
}


int insertEdge(VertexHead* h, int A, int B) //�Ű������� �Է¹��� �� ������ num���� ���� �������� �������� �������ִ� �Լ�
{
    
	Vertex* q  = h[A].head;
	Vertex* tmp = NULL;

	q = (Vertex *)malloc(sizeof(Vertex));
	tmp = (Vertex *)malloc(sizeof(Vertex));

	tmp->num = B;
	tmp->link = NULL;

	if(q == NULL)
	{
		printf("������ �� �����ϴ�. \n");
		return ;
	}
	else 
	{
		q->link = tmp;
		tmp->link = q->link;
	}

	

}


void deleteEdge(VertexHead* h, int A, int B)  //A�� B�� num���� ���� �� ���� ������ ������ �����ϴ� �Լ�
{
	
	Vertex* Q = ((h)[A].head)->link;
	Vertex* W = NULL;

	if (h == NULL) //headVertex���� ��尡 �������� ���� ��
	{
		printf("������ ��尡 �������� �ʽ��ϴ�. \n");
	}
	/* ������ ��尡

	1. ó���� ��ġ�� ���
	2. �߰��� ��ġ�� ���
	3. �������� ��ġ�� ���

	�� ����� �����Ͽ���.
	*/
	else
	{   /* ������ ��尡 ��� ������ ��ġ�ϴ� ����� �� */
		if (Q->num == B)
		{
			((h)[A].head)->link = Q->link;
			free(Q);
		}
		else
		{
			while (Q->num != B)
			{
				Q = Q->link;
				W = Q;
				if (Q->num == B)
				{
					{
						if (Q->link != NULL)
						{
							W->link = Q->link;
							free(Q);
						}
						else
						{
							W->link == NULL;
							free(Q);
						}
					}
					break;
				}
			}
		}
	}
	return 0;
}
/*
void depthFS(VertexHead* h, int v)
{
	
}
*/
void breadthFS(VertexHead*h, int v)
{

}

/* void depthFS(VertexHead* h, int v) //���� �켱 Ž�� ( v = �湮�� ������ vertex ��ȣ ) & stack �̿�
{
	
	int n=0;
	
	for(int i=0; i<MAX_VERTEX; i++)
	{
		if ((h)[i].head != NULL)
		{
			n++;
		}
	}
	return n;
	Vertex* w;

	visited[v] = 1;
	printf(" %d ", v);

	for(w = (h)[v].head; w; w = w->link)
	{
		if(! visited [w->num])
		{
			depthFS(h, w->num);
		}
	}

}

*/
void depthFS(VertexHead* h, int v)
{
	int visited[MAX_VERTEX]; //�湮�� ����ϱ� ���� ����
	Vertex* w;

	push(v);

	//1�� ���� ������ ������ �湮�� ���̰�, 0(NULL)�� ���� ������ ������ �湮���� ������ ��Ÿ����.
	visited[v] = 1; //���� v�� �湮�ߴٰ� ���
	printf("[ %d ]", v);

    while(top != -1) //������ ������ �ƴ� ��츦 �������� �Ͽ� �ݺ�������
	{
		w = h[v].head;
		while(w)
		{
			if(visited[w->num] == NULL)
			{
				push(w->num);
				visited[w->num] = 1; //�湮���� ���
				printf("[ %d ]", w->num);

				v = w->num;
				w = h[v].head;
			}
			else //w�� �̹� �湮�ߴ� �����̾��� ���
			{
				w = w->link;
			}
		}
		/* ���̻� Ž���� �� ������尡 ���� ��� */
		v = pop();

	}

}
/*
void breadthFS(VertexHead* h, int v) //A = �湮�� ������ Vertex number
{
	/*
	int n=0;
	
	for(int i=0; i<MAX_VERTEX; i++)
	{
		if ((h)[i].head != NULL)
		{
			n++;
		}
	}

	int visited[MAX_VERTEX]; 
	int queue[MAX_VERTEX];
	int front = rear;
	int x;

	enqueue(v);
	printf(" �湮�� vertex : %d \n",v);

	while(front != rear)
	{
		v = dequeue();

		for(x=v; x<n; x++) 
		{
			if(!visited[x] && (h)[x].head == 1)
			{
				(h)[x].head = 1;
				enqueue(x);
				printf("�湮�� vertex : %d \n",x);
			}
		}
	}
}
*/


void printGraph(VertexHead* h)  //�׷����� ���踦 ����ϴ� �Լ�
{

 
    Vertex* a ;


    printf(" ��������Ʈ \n");

    for(int i=0; i<MAX_VERTEX; i++)
    {
 	    printf("\n VertexHead [ %d ]  ", i);
		a = (h)[i].head;

		while(a)
		{
			printf("  ->  %d", a->num);
			a = a->link;
		}

		
    }
    printf("\n");
	
    
}


/* ���� ������ ���� �ʿ��� �Լ� */
int pop()  
{
	int A = 0;

	if(top != -1)
	{
		A = stack[top --];
	}
	else 
	{
		return ;
	}
}

void push(int A) 
{
	if(top < MAX_VERTEX -1)
	{
		stack[++top] = A;
	}

}


/* ť ������ ���� �ʿ��� �Լ� */
int deQueue() 
{
    int A = 0;

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

void enQueue(int A)
{
	if(rear == MAX_VERTEX -1)
	{
		return;
	}
	
	if(front == -1)
	{
		front++;
	}
	rear ++;
	queue[rear] = A ;
}