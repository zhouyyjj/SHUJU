//队列的实现（12min） 
#include<stdio.h>
#define MAXSIZE 10
int A[MAXSIZE];//定义一个全局整型数组存放队元素
int front = -1;
int rear = -1; //队空时将索引置为-1；
//入队操作
 void Enqueue(int x){
  //队满则不支持入队
  if(rear ==MAXSIZE-1){
   printf("Error:Queue is Full ");
    return ;
   }
   A[++rear] = x;
  
 }
 //出队操作
 void Dequeue(){
  if((rear ==-1)&& front ==-1){
   printf("Error:Queue is Empty");
   return ;
  }
  else if(rear == front&&(rear!=-1)){//队列只有一个元素 
   rear = -1;
   front = -1;
   
  }
  else{
   front  = front+1;
  }   
 } 
 // 返回队尾值
 int Rear(){
  return A[rear];
 } 
 void Print(){
  int i;
  printf("queue:  ");
  for(i=front+1;i<=rear;i++){
   printf("%d  ",A[i]);
  }
  printf("\n");
 }
 int main(){
  Enqueue(1);
  Enqueue(2);
  Enqueue(3);
  Print();
  Dequeue();
  Dequeue();
  printf("now the queue is: ");
  Print();
 }
