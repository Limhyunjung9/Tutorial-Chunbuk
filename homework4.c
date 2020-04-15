#include<stdio.h>
#include<stdlib.h>    //rand()를 사용하기 위해 필요하다.
#include<time.h>      //rand()를 사용하기 위해 필요하다.

int **create_matrix(int row, int col)
{
    /* check pre conditions 전처리 검사 */
    if(row <=0 || col <=0)
        {
         printf(" 행렬의 행과 열을 1 이상의 정수로 입력해주세요. \n ");
         return NULL;
        }

        int **matrix;                                    //2차원 배열이기 때문에 이중포인터가 필요하다.

        matrix = (int**)malloc(row * sizeof(int*));      //2차원 배열은 행과 열로 구분되어 메모리를 차지하기 때문에 이중포인터가 필요하다.
        
        for(int i=0; i<row; i++)                         //입력받은 행의 수 만큼 반복을 실행한다.
        {
            matrix[i] = (int *)malloc(col * sizeof(int)); //각 행에 따른 열들의 메모리 할당을 위해 필요하다.
            for(int j =0; j<col; j++)                   //입력받은 열의 수 만큼 반복을 실행한다.
            {
                matrix[i][j] = 0;     //rand()로 값을 넣어주기 전에 0으로 모두 초기화해준다.
            }
        }
        return matrix;

    /* check post conditions 후처리 검사 */
    if(matrix==NULL)
    {
        printf("오류가 발생하였습니다.\n ");
        return matrix;
      
    }
}

int free_matrix(int **matrix, int row, int col)   //동적할당함수를 해제시키는 함수 정의 
{
    for (int i=0; i<row; i++)
       {
           free(matrix[i]);     //댐블링 현상을 막기 위해 먼저 행이 차지하고 있는 메모리를 해제시킨다.
       }
       free(matrix);  //그 후 실제데이터가 존재하고 있는 나머지 영역의 동적할당을 해제한다.

       return 0;
}

int print_matrix(int **matrix, int row, int col)   //행렬 출력 함수
{
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            printf("%5d", matrix[i][j]);    //5칸씩 띄워서 행렬을 출력한다.
            
        }
        printf("\n");

    }
}

int fill_data(int **matrix, int row, int col)   //행렬에 랜덤으로 값을 넣어주는 함수
{
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            matrix[i][j] = rand() % 20;   //1~19의 값만 넣어주기 위해
        }
    }
    return **matrix;
}

int transpose_matrix(int **matrix, int **matrix_t, int row, int col) //전치행렬을 구하는 함수
{

    /* check pre conditions 전처리 검사 */
    if(row <=0 || col <=0)
        {
         printf(" 행과 열을 1 이상의 정수로 입력해주세요. \n ");
         return NULL;
        }

      
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			matrix_t[j][i] = matrix[i][j];  //전치행렬은 행과 열이 반대이기 떄문에 i와 j의 위치를 바꾸어준다.
		}
	}

	return 0;
      
      /* check post coditions 후처리 검사 */
      if(matrix_t==NULL)
       {
           printf(" 오류가 발생했습니다. \n");
           return matrix_t;
       }
}
int addition_matrix(int **matrix_a, int **matrix_b, int **matrix_sum, int row, int col) //행렬 덧셈 함수
{

     /* check pre conditions 전처리 검사 */
    if(row <=0 || col <=0)
        {
         printf(" 행과 열을 1 이상의 정수로 입력해주세요. \n ");
         return NULL;
        }

    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            matrix_sum[i][j]= matrix_a[i][j] + matrix_b[i][j]; //행렬 A + B 
        }
    }
     return 0;

    /* check post conditions 후처리 검사 */
    if(matrix_sum == NULL)
    {
        printf(" 계산 과정 중 오류가 발생하였습니다.\n");
        return matrix_sum;
    }
}

int subtraction_matrix(int **matrix_a, int **matrix_b, int **matrix_sub, int row, int col) //행렬 뺄셈 함수
{

    /* check pre conditions 전처리 검사 */
    if(row <=0 || col <=0)
        {
         printf(" 행과 열을 1 이상의 정수로 입력해주세요. \n ");
         return NULL;
        }


     for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            matrix_sub[i][j]= matrix_a[i][j] - matrix_b[i][j];  //행렬 A- B 
        }
    }
    return 0;

    /* check post conditions 후처리 검사 */
    if(matrix_sub == NULL)
    {
        printf(" 계산 과정 중 오류가 발생하였습니다.\n");
        return matrix_sub;
    
    }

}
int multiply_matrix(int **matrix_a, int **matrix_t, int **matrix_axt, int row, int col) //행렬 곱셈 함수
 {

     /* check pre conditions 전처리 검사 */
    if(row <=0 || col <=0)
        {
         printf(" 행과 열을 1 이상의 정수로 입력해주세요. \n ");
         return NULL;
        }	
	


	for (int i = 0; i < row; ++i)
     {
		for (int j = 0; j < col; ++j) 
        {
			matrix_axt[i][j] = 0;
		}
	}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			for (int k = 0; k < row; k++) //행렬 곱셈 시 앞 행렬의 열과 뒷 행렬의 행이 같아야한다. 그 수를 k로 표현.
			{
				matrix_axt[i][j] += ( matrix_a[i][k] * matrix_t[k][j]);

			}
		}
	}
    return 0;

} 

int main()
{

    printf("\n\n --------[urban engineering  2019032012 Limhyunjung]--------\n\n\n");


    int row,col;

     printf(" 행렬의 행과 열을 입력해주세요 : ");
     scanf("%d %d", &row, &col);

      /* check pre conditions 전처리 검사 */
    if(row <=0 || col <=0)
        {
        
         printf(" 행렬의 행과 열을 1 이상의 정수로 입력해주세요. \n ");
         scanf("%d %d", &row, &col);
         printf("\n");

         return NULL;

        }

     int **matrix_t;
     int **matrix_a;
     int **matrix_b;
     int **matrix_sum;
     int **matrix_sub;
     int **matrix_axt;

     srand(time(NULL));    //매 실행마다 A,B 행렬에 들어가는 값을 바꿔주기 위해 필요하다.

      /* 동적메모리 할당 방식을 통해 행렬 생성 */
     matrix_a = create_matrix(row, col);
     matrix_b = create_matrix(row, col);
     matrix_sum = create_matrix(row,col);
     matrix_sub = create_matrix(row,col);
     matrix_axt = create_matrix(row,col);

     /* 전치행렬은 원래 행렬에 대해 행과 열이 반대이기 때문에 if절로 나누어 동적메모리할당 방식으로 생성  */
     if(row == col)
     {
         matrix_t = create_matrix(row,col); 
     }
     else 
     {
         matrix_t = create_matrix(col,row);
     }

     /* 행렬 A 와 B에 랜덤으로 값 대입 */
     fill_data(matrix_a, row, col);
     fill_data(matrix_b, row, col);
     
     printf("입력받은 행과 열을 이용해 행렬을 출력 \n\n");

     printf("행렬 A 출력  \n");
     print_matrix(matrix_a, row, col);
          
     printf("행렬 B 출력 \n");
     print_matrix(matrix_b, row, col);

     printf("행렬 A와B의 덧셈 출력 \n");
     addition_matrix(matrix_a, matrix_b,matrix_sum, row,col);
     print_matrix(matrix_sum,row,col);
    
     printf("행렬 A와 B의 뺄셈 출력 \n");
     subtraction_matrix(matrix_a,matrix_b, matrix_sub,row,col);
     print_matrix(matrix_sub, row,col);

     printf("행렬 A의 전치행렬 T 출력 \n");
     transpose_matrix(matrix_a,matrix_t,row,col);
     print_matrix(matrix_t,col,row);

     printf("행렬 A와 A의 전치행렬 T의 곱한 결과 출력 \n :");   
     if (row != col)
           { 
               printf("A 와 T 행렬의 행과 열이 일치하지 않아 오류 발생.\n");
	           printf("\n");
               return NULL;
	       } 
        
	else
    {
		multiply_matrix(matrix_a, matrix_t, matrix_axt, row, col);
		print_matrix(matrix_axt, row, col);
                
	}
     /* 메모리 해제 */
     free_matrix(matrix_a , row, col);
     free_matrix(matrix_b , row, col);
     free_matrix(matrix_sum , row, col);
     free_matrix(matrix_sub , row, col);
     free_matrix(matrix_axt , row, col);

     /* 전치행렬은 행과 열이 기준이되는 행렬에 대해 반대이기 때문에 경우에 따라 나누어 메모리해제 */
     if(row==col)
     { 
         free_matrix(matrix_t,row,col);   
     }
     else
     {
         free_matrix(matrix_t,col,row);
     }

      
     /* main()함수 후처리 검사 */
     if(matrix_a!=NULL || matrix_b != NULL || matrix_sum != NULL || matrix_t != NULL || matrix_sub != NULL || matrix_axt != NULL)  // 결과 중 오류 없을 때
     {
         return 0;
     }      
     else //오류가 있을때
         return NULL;
        
      
} 