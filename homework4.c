#include<stdio.h>
#include<stdlib.h>    //rand()�� ����ϱ� ���� �ʿ��ϴ�.
#include<time.h>      //rand()�� ����ϱ� ���� �ʿ��ϴ�.

int **create_matrix(int row, int col)
{
    /* check pre conditions ��ó�� �˻� */
    if(row <=0 || col <=0)
        {
         printf(" ����� ��� ���� 1 �̻��� ������ �Է����ּ���. \n ");
         return NULL;
        }

        int **matrix;                                    //2���� �迭�̱� ������ ���������Ͱ� �ʿ��ϴ�.

        matrix = (int**)malloc(row * sizeof(int*));      //2���� �迭�� ��� ���� ���еǾ� �޸𸮸� �����ϱ� ������ ���������Ͱ� �ʿ��ϴ�.
        
        for(int i=0; i<row; i++)                         //�Է¹��� ���� �� ��ŭ �ݺ��� �����Ѵ�.
        {
            matrix[i] = (int *)malloc(col * sizeof(int)); //�� �࿡ ���� ������ �޸� �Ҵ��� ���� �ʿ��ϴ�.
            for(int j =0; j<col; j++)                   //�Է¹��� ���� �� ��ŭ �ݺ��� �����Ѵ�.
            {
                matrix[i][j] = 0;     //rand()�� ���� �־��ֱ� ���� 0���� ��� �ʱ�ȭ���ش�.
            }
        }
        return matrix;

    /* check post conditions ��ó�� �˻� */
    if(matrix==NULL)
    {
        printf("������ �߻��Ͽ����ϴ�.\n ");
        return matrix;
      
    }
}

int free_matrix(int **matrix, int row, int col)   //�����Ҵ��Լ��� ������Ű�� �Լ� ���� 
{
    for (int i=0; i<row; i++)
       {
           free(matrix[i]);     //��� ������ ���� ���� ���� ���� �����ϰ� �ִ� �޸𸮸� ������Ų��.
       }
       free(matrix);  //�� �� ���������Ͱ� �����ϰ� �ִ� ������ ������ �����Ҵ��� �����Ѵ�.

       return 0;
}

int print_matrix(int **matrix, int row, int col)   //��� ��� �Լ�
{
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            printf("%5d", matrix[i][j]);    //5ĭ�� ����� ����� ����Ѵ�.
            
        }
        printf("\n");

    }
}

int fill_data(int **matrix, int row, int col)   //��Ŀ� �������� ���� �־��ִ� �Լ�
{
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            matrix[i][j] = rand() % 20;   //1~19�� ���� �־��ֱ� ����
        }
    }
    return **matrix;
}

int transpose_matrix(int **matrix, int **matrix_t, int row, int col) //��ġ����� ���ϴ� �Լ�
{

    /* check pre conditions ��ó�� �˻� */
    if(row <=0 || col <=0)
        {
         printf(" ��� ���� 1 �̻��� ������ �Է����ּ���. \n ");
         return NULL;
        }

      
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			matrix_t[j][i] = matrix[i][j];  //��ġ����� ��� ���� �ݴ��̱� ������ i�� j�� ��ġ�� �ٲپ��ش�.
		}
	}

	return 0;
      
      /* check post coditions ��ó�� �˻� */
      if(matrix_t==NULL)
       {
           printf(" ������ �߻��߽��ϴ�. \n");
           return matrix_t;
       }
}
int addition_matrix(int **matrix_a, int **matrix_b, int **matrix_sum, int row, int col) //��� ���� �Լ�
{

     /* check pre conditions ��ó�� �˻� */
    if(row <=0 || col <=0)
        {
         printf(" ��� ���� 1 �̻��� ������ �Է����ּ���. \n ");
         return NULL;
        }

    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            matrix_sum[i][j]= matrix_a[i][j] + matrix_b[i][j]; //��� A + B 
        }
    }
     return 0;

    /* check post conditions ��ó�� �˻� */
    if(matrix_sum == NULL)
    {
        printf(" ��� ���� �� ������ �߻��Ͽ����ϴ�.\n");
        return matrix_sum;
    }
}

int subtraction_matrix(int **matrix_a, int **matrix_b, int **matrix_sub, int row, int col) //��� ���� �Լ�
{

    /* check pre conditions ��ó�� �˻� */
    if(row <=0 || col <=0)
        {
         printf(" ��� ���� 1 �̻��� ������ �Է����ּ���. \n ");
         return NULL;
        }


     for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            matrix_sub[i][j]= matrix_a[i][j] - matrix_b[i][j];  //��� A- B 
        }
    }
    return 0;

    /* check post conditions ��ó�� �˻� */
    if(matrix_sub == NULL)
    {
        printf(" ��� ���� �� ������ �߻��Ͽ����ϴ�.\n");
        return matrix_sub;
    
    }

}
int multiply_matrix(int **matrix_a, int **matrix_t, int **matrix_axt, int row, int col) //��� ���� �Լ�
 {

     /* check pre conditions ��ó�� �˻� */
    if(row <=0 || col <=0)
        {
         printf(" ��� ���� 1 �̻��� ������ �Է����ּ���. \n ");
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
			for (int k = 0; k < row; k++) //��� ���� �� �� ����� ���� �� ����� ���� ���ƾ��Ѵ�. �� ���� k�� ǥ��.
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

     printf(" ����� ��� ���� �Է����ּ��� : ");
     scanf("%d %d", &row, &col);

      /* check pre conditions ��ó�� �˻� */
    if(row <=0 || col <=0)
        {
        
         printf(" ����� ��� ���� 1 �̻��� ������ �Է����ּ���. \n ");
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

     srand(time(NULL));    //�� ���ึ�� A,B ��Ŀ� ���� ���� �ٲ��ֱ� ���� �ʿ��ϴ�.

      /* �����޸� �Ҵ� ����� ���� ��� ���� */
     matrix_a = create_matrix(row, col);
     matrix_b = create_matrix(row, col);
     matrix_sum = create_matrix(row,col);
     matrix_sub = create_matrix(row,col);
     matrix_axt = create_matrix(row,col);

     /* ��ġ����� ���� ��Ŀ� ���� ��� ���� �ݴ��̱� ������ if���� ������ �����޸��Ҵ� ������� ����  */
     if(row == col)
     {
         matrix_t = create_matrix(row,col); 
     }
     else 
     {
         matrix_t = create_matrix(col,row);
     }

     /* ��� A �� B�� �������� �� ���� */
     fill_data(matrix_a, row, col);
     fill_data(matrix_b, row, col);
     
     printf("�Է¹��� ��� ���� �̿��� ����� ��� \n\n");

     printf("��� A ���  \n");
     print_matrix(matrix_a, row, col);
          
     printf("��� B ��� \n");
     print_matrix(matrix_b, row, col);

     printf("��� A��B�� ���� ��� \n");
     addition_matrix(matrix_a, matrix_b,matrix_sum, row,col);
     print_matrix(matrix_sum,row,col);
    
     printf("��� A�� B�� ���� ��� \n");
     subtraction_matrix(matrix_a,matrix_b, matrix_sub,row,col);
     print_matrix(matrix_sub, row,col);

     printf("��� A�� ��ġ��� T ��� \n");
     transpose_matrix(matrix_a,matrix_t,row,col);
     print_matrix(matrix_t,col,row);

     printf("��� A�� A�� ��ġ��� T�� ���� ��� ��� \n :");   
     if (row != col)
           { 
               printf("A �� T ����� ��� ���� ��ġ���� �ʾ� ���� �߻�.\n");
	           printf("\n");
               return NULL;
	       } 
        
	else
    {
		multiply_matrix(matrix_a, matrix_t, matrix_axt, row, col);
		print_matrix(matrix_axt, row, col);
                
	}
     /* �޸� ���� */
     free_matrix(matrix_a , row, col);
     free_matrix(matrix_b , row, col);
     free_matrix(matrix_sum , row, col);
     free_matrix(matrix_sub , row, col);
     free_matrix(matrix_axt , row, col);

     /* ��ġ����� ��� ���� �����̵Ǵ� ��Ŀ� ���� �ݴ��̱� ������ ��쿡 ���� ������ �޸����� */
     if(row==col)
     { 
         free_matrix(matrix_t,row,col);   
     }
     else
     {
         free_matrix(matrix_t,col,row);
     }

      
     /* main()�Լ� ��ó�� �˻� */
     if(matrix_a!=NULL || matrix_b != NULL || matrix_sum != NULL || matrix_t != NULL || matrix_sub != NULL || matrix_axt != NULL)  // ��� �� ���� ���� ��
     {
         return 0;
     }      
     else //������ ������
         return NULL;
        
      
} 