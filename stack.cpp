#include<stdio.h>
#define MAX_SIZE 101//宏定义数组的大小 101 
int A[MAX_SIZE];//创建一个全局的整型数组 
int top=-1;//空栈，虚构索引-1 
void Push(int x){
 if(top==MAX_SIZE -1){
  printf("Error:stack overflow\n");
  return ;
 }
 // top ++;
 //A[top]=x; 
 A[++top]=x;//自增发生在赋值之前 
}
void Pop(){
 if (top==-1){
  printf("Error:No element to pop\n");
  return;
 }
 top--;
}
int Top(){
 return A[top];//直接返回top索引处的值。 
}
void Print(){
 int i;
 printf("Stack: ");
 for(i=0;i<=top;i++){
  printf("%d ",A[i]);
 }
 printf("\n");
}
int main(){
 Push(2);Print();
 Push(5);Print();
 Push(10);Print();
 Pop();Print();
 Push(12);Print();
}
