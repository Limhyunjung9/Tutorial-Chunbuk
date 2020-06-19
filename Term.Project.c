/* 인접리스트를 사용하여 그래프 구현 */

#include<stdio.h>
#include<stdlib.h> //동적할당을 하기 위해 

#define MAX_VERTEX   20   // = headNode 또한 최대 20개까지 생성가능
int visited[MAX_VERTEX];

/* 구조체 정의 */

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

/* 함수원형 정의 */

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



/* 메인함수 */
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



void createGraph(VertexHead** h)   //그래프를 초기화하는 함수
{
   if (*h != NULL) //그래프가 존재하는 경우
   {    
      destroyGraph(*h); //그래프가 존재하면 파괴해준다.
   }

   *h= (VertexHead*)malloc(sizeof(VertexHead)*MAX_VERTEX);  //headNode들이 MAX_VERTEX만큼 들어있는 h배열을 생성

   /* 배열의 모든 headNode들을 NULL로 초기화 */ 
   for (int i = 0; i < MAX_VERTEX; i++) 
   {      
	    (*h)[i].head = NULL; 
   }

   return *h;
}

void destroyGraph(VertexHead** h) //동적할당 해제 함수
{
	if(h == NULL) //그래프에 아무것도 없는 경우
	{
		printf("그래프에 아무것도 존재하지 않습니다. \n");
		return ;
	}
	else //그래프에 무언가 존재하여 삭제할 일이 발생한 경우
	{
	   for(int i=0; i< MAX_VERTEX; i++)
	    {
		   free((*h)[i].head);
	    }

	}
}

int insertVertex(VertexHead* h,int A) //입력받은 숫자를 num으로 가진 정점을 생성하는 함수 
{
	Vertex* v = h[A].head;  //요소A번째 배열에 해당하는 정점 v 선언
	Vertex* tmp  = NULL;    

	tmp = (Vertex *)malloc(sizeof(Vertex));
	tmp -> num = 1;
	tmp -> link = NULL;

	if(v == NULL) //입력한 정점이 없다면
	{
		v  = tmp;
		v->num = A;

	}
	
	return v;
}

void deleteVertex(VertexHead* h, int A)  //정점을 삭제하는 함수
{
	/* 그래프내에 존재하는 정점의 개수를 확인하기 위한 부분 */
	int n=0;
	
	for(int i=0; i<MAX_VERTEX; i++)
	{
		if ((h)[i].head != NULL)
		{
			n++;
		}
	}
	return n;

	/* 그래프에 아예 정점이 존재하지 않는 경우 */
	if(n = 0 )
	{
		printf("삭제할 수 없습니다. \n");
		return ;
	}
	else
	{
		(h)[A].head = 0;
	}
	
}


int insertEdge(VertexHead* h, int A, int B) //매개변수로 입력받은 두 정수를 num으로 가진 정점들을 간선으로 연결해주는 함수
{
    
	Vertex* q  = h[A].head;
	Vertex* tmp = NULL;

	q = (Vertex *)malloc(sizeof(Vertex));
	tmp = (Vertex *)malloc(sizeof(Vertex));

	tmp->num = B;
	tmp->link = NULL;

	if(q == NULL)
	{
		printf("연결할 수 없습니다. \n");
		return ;
	}
	else 
	{
		q->link = tmp;
		tmp->link = q->link;
	}

	

}


void deleteEdge(VertexHead* h, int A, int B)  //A와 B를 num으로 가진 두 정점 사이의 간선을 삭제하는 함수
{
	
	Vertex* Q = ((h)[A].head)->link;
	Vertex* W = NULL;

	if (h == NULL) //headVertex다음 노드가 존재하지 않을 때
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

/* void depthFS(VertexHead* h, int v) //깊이 우선 탐색 ( v = 방문할 정점의 vertex 번호 ) & stack 이용
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
	int visited[MAX_VERTEX]; //방문을 기록하기 위해 선언
	Vertex* w;

	push(v);

	//1의 값을 가지고 있으면 방문한 것이고, 0(NULL)의 값을 가지고 있으면 방문하지 않음을 나타낸다.
	visited[v] = 1; //정점 v를 방문했다고 기록
	printf("[ %d ]", v);

    while(top != -1) //스택이 공백이 아닐 경우를 조건으로 하여 반복문설정
	{
		w = h[v].head;
		while(w)
		{
			if(visited[w->num] == NULL)
			{
				push(w->num);
				visited[w->num] = 1; //방문함을 기록
				printf("[ %d ]", w->num);

				v = w->num;
				w = h[v].head;
			}
			else //w가 이미 방문했던 정점이었을 경우
			{
				w = w->link;
			}
		}
		/* 더이상 탐색을 할 인접노드가 없는 경우 */
		v = pop();

	}

}
/*
void breadthFS(VertexHead* h, int v) //A = 방문할 정점의 Vertex number
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
	printf(" 방문한 vertex : %d \n",v);

	while(front != rear)
	{
		v = dequeue();

		for(x=v; x<n; x++) 
		{
			if(!visited[x] && (h)[x].head == 1)
			{
				(h)[x].head = 1;
				enqueue(x);
				printf("방문한 vertex : %d \n",x);
			}
		}
	}
}
*/


void printGraph(VertexHead* h)  //그래프의 관계를 출력하는 함수
{

 
    Vertex* a ;


    printf(" 인접리스트 \n");

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


/* 스택 구현을 위해 필요한 함수 */
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


/* 큐 구현을 위해 필요한 함수 */
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