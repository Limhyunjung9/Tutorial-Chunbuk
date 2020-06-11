/*
 * hw5-sorting.c
 *
 *  Created on: May 22, 2019
 *
 *  Homework 5: Sorting & Hashing
 *  Department of Computer Science at Chungbuk National University
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ARRAY_SIZE			13	/* prime number */
#define MAX_HASH_TABLE_SIZE 	MAX_ARRAY_SIZE

/* 필요에 따라 함수 추가 가능 */
int initialize(int **a);
int freeArray(int *a);
void printArray(int *a);

int selectionSort(int *a);
int insertionSort(int *a);
int bubbleSort(int *a);
int shellSort(int *a);
/* recursive function으로 구현 */
int quickSort(int *a, int n);


/* hash code generator, key % MAX_HASH_TABLE_SIZE */
int hashCode(int key);

/* array a에대 한 hash table을 만든다. */
int hashing(int *a, int **ht);

/* hash table에서 key를 찾아 hash table의 index return */
int search(int *ht, int key);


int main()
{
	char command;
	int *array = NULL;
	int *hashtable = NULL;
	int key = -1;
	int index = -1;

    printf("\n -----[urban engineering  2019032012 Limhyunjung]-----\n\n\n");


	srand(time(NULL));

	do{
		printf("----------------------------------------------------------------\n");
		printf("                        Sorting & Hashing   \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize       = z           Quit             = q\n");
		printf(" Selection Sort   = s           Insertion Sort   = i\n");
		printf(" Bubble Sort      = b           Shell Sort       = l\n");
		printf(" Quick Sort       = k           Print Array      = p\n");
		printf(" Hashing          = h           Search(for Hash) = e\n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);

		switch(command) {
		case 'z': case 'Z':
			initialize(&array);
			break;
		case 'q': case 'Q':
			freeArray(array);
			break;
		case 's': case 'S':
			selectionSort(array);
			break;
		case 'i': case 'I':
			insertionSort(array);
			break;
		case 'b': case 'B':
			bubbleSort(array);
			break;
		case 'l': case 'L':
			shellSort(array);
			break;
		case 'k': case 'K':
			printf("Quick Sort: \n");
			printf("----------------------------------------------------------------\n");
			printArray(array);
			quickSort(array, MAX_ARRAY_SIZE);
			printf("----------------------------------------------------------------\n");
			printArray(array);

			break;

		case 'h': case 'H':
			printf("Hashing: \n");
			printf("----------------------------------------------------------------\n");
			printArray(array);
			hashing(array, &hashtable);
			printArray(hashtable);
			break;

		case 'e': case 'E':
			printf("Your Key = ");
			scanf("%d", &key);
			printArray(hashtable);
			index = search(hashtable, key);
			printf("key = %d, index = %d,  hashtable[%d] = %d\n", key, index, index, hashtable[index]);
			break;

		case 'p': case 'P':
			printArray(array);
			break;
		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q');

	return 1;
}

int initialize(int** a)
{
	int *temp = NULL;

	/* array가 NULL인 경우 메모리 할당 */
	if(*a == NULL) {
		temp = (int*)malloc(sizeof(int) * MAX_ARRAY_SIZE);
		*a = temp;  /* 할당된 메모리의 주소를 복사 --> main에서 배열을 control 할수 있도록 함*/
	} else
		temp = *a;

	/* 랜덤값을 배열의 값으로 저장 */
	for(int i = 0; i < MAX_ARRAY_SIZE; i++)
		temp[i] = rand() % MAX_ARRAY_SIZE;

	return 0;
}

int freeArray(int *a) //배열을 free 해주는 함수
{
	if(a != NULL) //배열이 존재하는 경우
		free(a);
	return 0;
}

void printArray(int *a)  //정렬되지 않은 배열을 print하는 함수
{
	if (a == NULL) // 배열이 존재하지 않을 경우
	{
		printf("nothing to print.\n");
		return;
	}

	for(int i = 0; i < MAX_ARRAY_SIZE; i++) //배열 요소 수만큼 배열 index 출력 
		printf("a[%02d] ", i);

	printf("\n");

	for(int i = 0; i < MAX_ARRAY_SIZE; i++) // 배열 요소 수 만큼 각 index에 해당하는 값 출력 
		printf("%5d ", a[i]);

	printf("\n");
}


int selectionSort(int *a)   //선택 정렬 함수, 부가적인 메모리는 필요없는 정렬방식 
{
	int min;          // 정렬이 되지 않은 부분에서 제일 앞의 요소와 그 요소의 뒷 부분에서의 가장 작은 값을 가진 요소를 가리키는 min을 선언
	int minindex;     // 정렬이 되지 않은 부분에서 최솟값을 key로 가지고 있는 요소의 index 
	int i, j;         //반복문을 실행하기 위해 선언

	printf("Selection Sort: \n");
	printf("----------------------------------------------------------------\n");

	printArray(a);   // 정렬할 배열을 불러옴 

	for (i = 0; i < MAX_ARRAY_SIZE; i++) 
	{
		minindex = i;  //제일 처음 요소를 mixindex로 정해둔다.
		min = a[i];    //minindex를 요소 number로 가지고 있는 key값 

		for(j = i+1; j < MAX_ARRAY_SIZE; j++)
		{
			if (min > a[j]) // 게속해서 뒤로 진행하며 min값을 찾는 과정 
			{
				/* 원래 지정해둔 min 값과 새로 찾은 최솟값 min을 바꿔주는 과정 */
				min = a[j];
				minindex = j;
			}
		}

		/* for문에서 찾은 min과 정렬이 되지않은 부분에서의 제일 첫번째에 위치하는 값을 바꾸어 정렬하는 명령어 */
		a[minindex] = a[i];
		a[i] = min;
	}

	printf("----------------------------------------------------------------\n");
	printArray(a);
	return 0;
}

int insertionSort(int *a)       //삽입 정렬 함수 / 정렬 된 부분과 정렬되지 않은 부분,두가지 부분집합으로 구분된다 
{ 
 	int i, j, t;  // t = 임시 저장 변수

	printf("Insertion Sort: \n");
	printf("----------------------------------------------------------------\n");

	printArray(a); // 정렬할 배열을 불러옴

	for(i = 1; i < MAX_ARRAY_SIZE; i++)  //배열 요소 수만큼 반복
	{
		t = a[i]; //a[0]은 넣고자 하는 원소를 임시적으로 저장하는 장소이다.
		j = i;    

		/* 인접한 두 원소를 비교하여 정렬하는 과정 */
		while (a[j-1] > t && j > 0) //자신의 앞에 존재하는 요소가 자신보다 클 경우 바꿔주는 과정
		{
			a[j] = a[j-1]; //짝 지어진 두 요소중 앞 요소를 뒤로 옮기는 과정
			j--; 
		}
		a[j] = t; // 짝 지어진 두 요소중 뒷 요소를 앞으로 옮기는 과정 
	}

	printf("----------------------------------------------------------------\n");
	printArray(a);

	return 0;
}

int bubbleSort(int *a)     //bubble 정렬 / 맨앞부터 인접한 두 요소의 값과 비교하여 제일 큰 값을 맨뒤로 보내는 정렬 방식 
{
	int i, j, t;

	printf("Bubble Sort: \n");
	printf("----------------------------------------------------------------\n");

	printArray(a);

	for(i = 0; i < MAX_ARRAY_SIZE; i++)
	{
		for (j = 1; j < MAX_ARRAY_SIZE; j++)
		{
			if (a[j-1] > a[j]) // 배열의 맨 앞 요소부터 인접한 항과 key값을 비교하여 제일 큰 값을 맨 뒤로 보배는 과정
			{
				t = a[j-1]; // t는 두 요소의 key값을 바꿔주기 위한 임시 저장장소이다. 
				a[j-1] = a[j];
				a[j] = t;
			}
		}
	}

	printf("----------------------------------------------------------------\n");
	printArray(a);

	return 0;
}

int shellSort(int *a) //삽입정렬의 단점을 보완하기 위한 정렬 빙식 
{
	int i, j, k, h, v; 

	printf("Shell Sort: \n");
	printf("----------------------------------------------------------------\n");

	printArray(a);

    /* 요소 수의 1/2만큼을 h로 지정한 뒤 짝 지어진 두 수를 비교하여 정렬하는 과정 */
	for (h = MAX_ARRAY_SIZE/2; h > 0; h /= 2)    // h/2과정에서 x.5면 h = x
	{
		for (i = 0; i < h; i++) //h의 간격만큼 요소들을 묶는 과젇
		{
			/* j = 자신과 짝이 된 key값의 index */

			for(j = i + h; j < MAX_ARRAY_SIZE; j += h)  
			{
				/* 짝이 지어진 수를 비교하며 작은 수를 앞으로 옮기는 과정 */
				v = a[j];
				k = j;

				while (k > h-1 && a[k-h] > v)
				{
					a[k] = a[k-h];
					k -= h;
				}
				a[k] = v;
			}
		}
		// h가 1이 되면 마무리한다. 
	}
	
	printf("----------------------------------------------------------------\n");
	printArray(a);

	return 0;
}

int quickSort(int *a, int n) 
{    
	/* v = 기준 값(pivot) & t = 임시 저장소 */
	int v, t; 
	/* i = left & j = right */
	int i, j;

	if (n > 1)  /* pivot 값을 마지막으로 가리키게 한 경우 */
	{
		
		v = a[n-1]; // 마지막 data 값을 가리킨다.
		i = -1;     
		j = n - 1; //마지막의 index를 가리킨다. 

		while(1)
		{
			while(a[++i] < v);  // i를 pivot값 보다 작은 값이 나오면 한칸씩 옮기다가 큰 값이 나오면 멈추게 하는 과정
			while(a[--j] > v);  // j를 pivot값 보다 큰값이 나오면 한칸씩 옮기다가 작은 값이 나오면 멈추게 하는 과정

			if (i >= j) break; // left >= right 의 경우는 허용이 되지 않는다

			t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
		/*
		   left >= right 이므로 left와 right이 같을 경우가 발생한다
		   그 때는 left = right의 값을 pivot과 바꾸어 정렬한다.
		 */

		
		t = a[i];
		a[i] = a[n-1];
		a[n-1] = t;
        
		/*v (pivot) 값을 기준으로 분리된 부분을 앞의 과정을 다시 반복하여 정렬 */
		quickSort(a, i);
		quickSort(a+i+1, n-i-1);
	}


	return 0;
}

int hashCode(int key) //모드 연산자에 의해 결정이 된다.
{
   return key % MAX_HASH_TABLE_SIZE; 
}

int hashing(int *a, int **ht) 
{

	int *hashtable = NULL;

	/* hash table이 NULL인 경우 메모리 할당 */
	if(*ht == NULL)
	{

		hashtable = (int*)malloc(sizeof(int) * MAX_ARRAY_SIZE);

		*ht = hashtable;  /* 할당된 메모리의 주소를 복사 --> main에서 배열을 control 할수 있도록 함*/
	} else {
		hashtable = *ht;	/* hash table이 NULL이 아닌경우, table 재활용, reset to -1 */
	}
    
	/* size만큼 -1로 모두 초기화해준다.*/
	for(int i = 0; i < MAX_HASH_TABLE_SIZE; i++) 
		hashtable[i] = -1;

	/*
	이 명령어를 통해 모두 -1로 초기화된것을 확인할 수 있다 .

	for(int i = 0; i < MAX_HASH_TABLE_SIZE; i++)
		printf("hashtable[%d] = %d\n", i, hashtable[i]);
	*/

	int key = -1;
	int hashcode = -1;
	int index = -1;

	for (int i = 0; i < MAX_ARRAY_SIZE; i++)
	{
		key = a[i];
		hashcode = hashCode(key); //key값은 hashcode로 만든다. 

		/*
		key / hashcode / hashtable의 값이 올바르게 설정되어 있는지 확인하는 명령어

		printf("key = %d, hashcode = %d, hashtable[%d]=%d\n", key, hashcode, hashcode, hashtable[hashcode]);
		*/

		if (hashtable[hashcode] == -1) // 값이 들어있는지 없는지 확인하는 문장
		{
			hashtable[hashcode] = key;
		} else // 값이 존재하는 경우 / 
		{

			index = hashcode;

			while(hashtable[index] != -1) //-1이면 값이 들아가있지않은 상태이므로 -1이 아닐동안 while문을 돌려서 -1이 들어간 곳을 찾는다.
			{
				index = (++index) % MAX_HASH_TABLE_SIZE;
				/*
				printf("index = %d\n", index);
				*/
			}
			hashtable[index] = key;
		}
	}

	return 0;
}

int search(int *ht, int key)  //key를 탐색하는 함수
{
	int index = hashCode(key); 

	if(ht[index] == key)
		return index;

	while(ht[++index] != key)
	{
		index = index % MAX_HASH_TABLE_SIZE;
	}
	return index;
}
