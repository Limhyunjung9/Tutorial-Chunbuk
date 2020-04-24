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

/* stack 내에서 우선순위, lparen =0 가장 낮음 */
typedef enum
{ 
       
	lparen = 0,  /* ( 왼쪽 괄호 */
	rparen = 9,  /* ) 오른쪽 괄호 */
	times = 7,   /* * 곱셈 */
	divide = 6,  /* / 나눗셈 */
	plus = 5,    /* +  덧셈 */
	minus = 4,   /* - 뺼셈 */
	operand = 1 /* 피연산자 */
  
} precedence;


char infixExp[MAX_EXPRESSION_SIZE];   	/* infix expression을 저장하는 배열  */
char postfixExp[MAX_EXPRESSION_SIZE];	/* postfix로 변경된 문자열을 저장하는 배열 */
char postfixStack[MAX_STACK_SIZE];	/* postfix로 변환을 위해 필요한 스택 */
int evalStack[MAX_STACK_SIZE];		/*계산을 위해 필요한 스택 */

int postfixStackTop = -1;  /* postfixStack용 top */
int evalStackTop = -1;	   /* evalStack용 top */

int evalResult = 0;	   /* 계산 결과를 저장 */

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
 * infix expression을 입력받는다.
 * infixExp에는 입력된 값을 저장한다.
 */
void getInfix()
{
    printf("Type the expression >>> ");
    scanf("%s",infixExp);
}

precedence getToken(char symbol)         
//priiority 함수를 사용하기 위해 기호-> 컴퓨터가 알아듣게하는 함수 
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

precedence getPriority(char x) //연산자들의 우선순위를 비교하는 함수
{
	return getToken(x); 
}

/**
 *문자하나를 전달받아, postfixExp에 추가
 */
void charCat(char* c)
{
	if (postfixExp == '\0')
		strncpy(postfixExp, c, 1);  
	else
		strncat(postfixExp, c, 1);
}

/**
 * infixExp의 문자를 하나씩 읽어가면서 stack을 이용하여 postfix로 변경한다.
 * 변경된 postfix는 postfixExp에 저장된다.
 */
void toPostfix()
{
    int number ; // infix형 계산 식에 존재하는 문자열의 개수 
    number = strlen(infixExp);

	/* infixExp의 문자 하나씩을 읽기 위한 포인터 */
	char *exp = infixExp;
	char x; /* 문자하나를 임시로 저장하기 위한 변수 */

	/* exp를 증가시켜가면서, 문자를 읽고 postfix로 변경 */
   
    for(int i=0; i<number; i++)   //infx형 계산식이 다 없어질 때 까지 반복 
    {
  

       if(getToken(*exp) == operand)       // infix형의 계산식을 하나씩 읽을 때 그것이 피연산자일 경우 
       {
           charCat(exp);                   //postfixexp로
       }
       else if(getToken(*exp) != operand) // infix형의 계산식을 하나씩 읽을 때 그것이 피연산자가 아닐경우 = 연산자일 경우
       
        {
            if(x=='(')                  //괄호는 세트이기때문에 따로 if 문을 써서 사용한다.

                 postfixPush(*exp);      //오른쪽 괄호가 나오지않았기 때문에 왼쪽괄호는 다른 연산자들 처럼  postfixStack 에 들어간다. 
            
            else if(*exp = ')')        //오른쪽 괄호가 나오면 왼쪽 괄호가 나올때 까지 연산자들을 postfixExp 로 옮긴다. 
                {
                    while(postfixStack[postfixStackTop] !='(')     // 왼쪽 괄호가 나올때 까지 반복 
                       {   
                          
                          charCat(postfixStack[postfixStackTop]);  // postfixStack의 Top을 postfixExp로 옮긴다. 
                       }  

                       if(postfixStack[postfixStackTop] == '(')  // postfixStackTop이 왼쪽 괄호일 경우 
                          postfixPop('(');                       //왼쪽 괄호를 제거한다.
                }
                
            else
            {
             if(getPriority(*exp)>=getPriority(postfixStack[postfixStackTop]))   
             // 입력 연산자가 스택의 탑에 있는 연산자보다 우선순위가 높으면 스택에 삽입한다.
                     postfixPush(*exp);

            
             else 
                postfixPop(postfixStackTop);  
                postfixPush(*exp);
            }

        
        }
    }
}


          
     
void debug()   //infix형 계산식 , postfix로 변환된 계산식, 계산 결과를 제공하는 함수 
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

void evaluation()     //postfix형으로 변환된 식을 계산해주는 함수 
{
    /* postfixExp, evalStack을 이용한 계산 */
	int number; //postfix형 계산식에 포함된 피연산자의 수와 연산자의 수를 더한것.
    number = strlen(postfixExp);   //postfix로 변환된 식의 문자열의 개수를 변수 number에 넣어준다.

	char *exp = postfixExp;   //
	char x; //postfixExp에 저장된 식을 하나씩 보기 위해 선언
    int op1, op2; // 피연산자 (연산자 앞 두개의 피연산자)

    for(int i=1; i<number; i++) //문자열의 개수만큼 반복 
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
    evalResult = evalPop();   //결과를 저장한다. 
}


int main()
{
      printf("\n\n --------[urban engineering  2019032012 Limhyunjung]--------\n\n\n");
      printf("infix로 입력되는 수식은 한 자리수만 가능합니다(0~9). \n");
      
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