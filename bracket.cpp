#include<stdio.h>
#include<malloc.h>
#define MAXSIZE 100

typedef char DataType;
typedef struct{
	DataType data[MAXSIZE];
	int top;
}SeqStack,*PSeqStack;

//初始化空栈
PSeqStack Init_SeqStack(void)
{
	PSeqStack S;
	S=(PSeqStack)malloc(sizeof(SeqStack));
	if(S)
		S->top=-1;
	return S;
}

//判栈空
int Empty_SeqStack(PSeqStack S)
{
	if(S->top=-1)
		return 1;
	else
		return 0;
}

//入栈
int Push_SeqStack(PSeqStack S,DataType x)
{
	if(S->top==MAXSIZE-1)
		return 0;
	else
	{
		S->top++;
		S->data[S->top]=x;
		return 1;
	}
}

//出栈
int Pop_SeqStack(PSeqStack S,DataType *x)
{
	if(Empty_SeqStack(S))
		return 0;
	else
	{
		*x=S->data[S->top];
		S->top--;
		return 1;
	}
}

//判别一个算术表达式的圆括号是否匹配正确
void pair(char str[])
{
	PSeqStack S;
	char ch,ch1;
	int k=0;
	S=Init_SeqStack();
	while((ch=str[k])!='\0')
	{
		if(ch=='(')
			Push_SeqStack(S,ch);
		else if(ch==')')
		{
			if(Empty_SeqStack(S))
			{
				printf("圆括号不配对");
				return;
			}
			else Pop_SeqStack(S,&ch1);
		}
		k++;
	}
	if(Empty_SeqStack(S))
		printf("圆括号匹对");
	else
		printf("圆括号不配对");
}

int main()
{
	char str[100];
	printf("please input:");
	gets(str);
	pair(str);
}
