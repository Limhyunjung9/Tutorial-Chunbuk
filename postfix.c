/*
 * postfix.c
 *
 *  2020 Data Structures, Homework #5
 *  Department of Computer Science at Chungbuk National University
 */


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_STACK_SIZE 10
#define MAX_EXPRESSION_SIZE 20

/* stack ������ �켱����, lparen =0 ���� ���� */
typedef enum
{ 
       
	lparen = 0,  /* ( ���� ��ȣ */
	rparen = 9,  /* ) ������ ��ȣ */
	times = 7,   /* * ���� */
	divide = 6,  /* / ������ */
	plus = 5,    /* +  ���� */
	minus = 4,   /* - �E�� */
	operand = 1 /* �ǿ����� */
  
} precedence;


char infixExp[MAX_EXPRESSION_SIZE];   	/* infix expression�� �����ϴ� �迭  */
char postfixExp[MAX_EXPRESSION_SIZE];	/* postfix�� ����� ���ڿ��� �����ϴ� �迭 */
char postfixStack[MAX_STACK_SIZE];	/* postfix�� ��ȯ�� ���� �ʿ��� ���� */
int evalStack[MAX_STACK_SIZE];		/*����� ���� �ʿ��� ���� */

int postfixStackTop = -1;  /* postfixStack�� top */
int evalStackTop = -1;	   /* evalStack�� top */

int evalResult = 0;	   /* ��� ����� ���� */

void postfixPush(char x)
{
    postfixStack[++postfixStackTop] = x;
}

char postfixPop()
{
    char x;
    if(postfixStackTop == -1)
        return NULL;
    else
    {
    	x = postfixStack[postfixStackTop--];
    }
    return x;
}


void evalPush(int x)
{
    evalStack[++evalStackTop] = x;
}

int evalPop()
{
    if(evalStackTop == -1)
        return -1;
    else
        return evalStack[evalStackTop--];
}


/**
 * infix expression�� �Է¹޴´�.
 * infixExp���� �Էµ� ���� �����Ѵ�.
 */
void getInfix()
{
    printf("Type the expression >>> ");
    scanf("%s",infixExp);
}

precedence getToken(char symbol)         
//priiority �Լ��� ����ϱ� ���� ��ȣ-> ��ǻ�Ͱ� �˾Ƶ���ϴ� �Լ� 
{
	switch(symbol) 
    {
	case '(' : return lparen;
	case ')' : return rparen;
	case '+' : return plus;
	case '-' : return minus;
	case '/' : return divide;
	case '*' : return times;
	default : return operand;
	}

}

precedence getPriority(char x) //�����ڵ��� �켱������ ���ϴ� �Լ�
{
	return getToken(x); 
}

/**
 *�����ϳ��� ���޹޾�, postfixExp�� �߰�
 */
void charCat(char* c)
{
	if (postfixExp == '\0')
		strncpy(postfixExp, c, 1);  
	else
		strncat(postfixExp, c, 1);
}

/**
 * infixExp�� ���ڸ� �ϳ��� �о�鼭 stack�� �̿��Ͽ� postfix�� �����Ѵ�.
 * ����� postfix�� postfixExp�� ����ȴ�.
 */
void toPostfix()
{
    int number ; // infix�� ��� �Ŀ� �����ϴ� ���ڿ��� ���� 
    number = strlen(infixExp);

	/* infixExp�� ���� �ϳ����� �б� ���� ������ */
	char *exp = infixExp;
	char x; /* �����ϳ��� �ӽ÷� �����ϱ� ���� ���� */

	/* exp�� �������Ѱ��鼭, ���ڸ� �а� postfix�� ���� */
   
    for(int i=0; i<number; i++)   //infx�� ������ �� ������ �� ���� �ݺ� 
    {
  

       if(getToken(*exp) == operand)       // infix���� ������ �ϳ��� ���� �� �װ��� �ǿ������� ��� 
       {
           charCat(exp);                   //postfixexp��
       }
       else if(getToken(*exp) != operand) // infix���� ������ �ϳ��� ���� �� �װ��� �ǿ����ڰ� �ƴҰ�� = �������� ���
       
        {
            if(x=='(')                  //��ȣ�� ��Ʈ�̱⶧���� ���� if ���� �Ἥ ����Ѵ�.

                 postfixPush(*exp);      //������ ��ȣ�� �������ʾұ� ������ ���ʰ�ȣ�� �ٸ� �����ڵ� ó��  postfixStack �� ����. 
            
            else if(*exp = ')')        //������ ��ȣ�� ������ ���� ��ȣ�� ���ö� ���� �����ڵ��� postfixExp �� �ű��. 
                {
                    while(postfixStack[postfixStackTop] !='(')     // ���� ��ȣ�� ���ö� ���� �ݺ� 
                       {   
                          
                          charCat(postfixStack[postfixStackTop]);  // postfixStack�� Top�� postfixExp�� �ű��. 
                       }  

                       if(postfixStack[postfixStackTop] == '(')  // postfixStackTop�� ���� ��ȣ�� ��� 
                          postfixPop('(');                       //���� ��ȣ�� �����Ѵ�.
                }
                
            else
            {
             if(getPriority(*exp)>=getPriority(postfixStack[postfixStackTop]))   
             // �Է� �����ڰ� ������ ž�� �ִ� �����ں��� �켱������ ������ ���ÿ� �����Ѵ�.
                     postfixPush(*exp);

            
             else 
                postfixPop(postfixStackTop);  
                postfixPush(*exp);
            }

        
        }
    }
}


          
     
void debug()   //infix�� ���� , postfix�� ��ȯ�� ����, ��� ����� �����ϴ� �Լ� 
{
	printf("\n---DEBUG\n");
	printf("infixExp =  %s\n", infixExp);
	printf("postExp =  %s\n", postfixExp);
	printf("eval result = %d\n", evalResult);

	printf("postfixStack : ");
	for(int i = 0; i < MAX_STACK_SIZE; i++)
		printf("%c  ", postfixStack[i]);

	printf("\n");

}

void reset()
{
	infixExp[0] = '\0';
	postfixExp[0] = '\0';

	for(int i = 0; i < MAX_STACK_SIZE; i++)
		postfixStack[i] = '\0';
         
	postfixStackTop = -1;
	evalStackTop = -1;
	evalResult = 0;
}

void evaluation()     //postfix������ ��ȯ�� ���� ������ִ� �Լ� 
{
    /* postfixExp, evalStack�� �̿��� ��� */
	int number; //postfix�� ���Ŀ� ���Ե� �ǿ������� ���� �������� ���� ���Ѱ�.
    number = strlen(postfixExp);   //postfix�� ��ȯ�� ���� ���ڿ��� ������ ���� number�� �־��ش�.

	char *exp = postfixExp;   //
	char x; //postfixExp�� ����� ���� �ϳ��� ���� ���� ����
    int op1, op2; // �ǿ����� (������ �� �ΰ��� �ǿ�����)

    for(int i=1; i<number; i++) //���ڿ��� ������ŭ �ݺ� 
    {
      int z=0;        
      x = exp[i];

        op1=evalPop();
        op2=evalPop();

              switch (x)
              {
              case '+':
                  z=op2 + op1;
                  evalPush(z);
                  break;
              case '-':
                z=op2-op1;
                evalPush(z);
                break;
             case '*':
                z=op2*op1;
                evalPush(z);
                break;  
             case '/':
                z=op2/op1;
                evalPush(z);
                break;
              
              default:
                  break;
              }



    }
    evalResult = evalPop();   //����� �����Ѵ�. 
}


int main()
{
      printf("\n\n --------[urban engineering  2019032012 Limhyunjung]--------\n\n\n");
      printf("infix�� �ԷµǴ� ������ �� �ڸ����� �����մϴ�(0~9). \n");
      
	char command;

	do{
		printf("----------------------------------------------------------------\n");
		printf("               Infix to Postfix, then Evaluation               \n");
		printf("----------------------------------------------------------------\n");
		printf(" Infix=i,   Postfix=p,  Eval=e,   Debug=d,   Reset=r,   Quit=q \n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);

		switch(command)
         {
		case 'i': case 'I':
			getInfix();
			break;
		case 'p': case 'P':
			toPostfix();
			break;
		case 'e': case 'E':
			evaluation();
			break;
		case 'd': case 'D':
			debug();
			break;
		case 'r': case 'R':
			reset();
			break;
		case 'q': case 'Q':
			break;
		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q');

	return 0;


}