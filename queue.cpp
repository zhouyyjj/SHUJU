//���е�ʵ�֣�12min�� 
#include<stdio.h>
#define MAXSIZE 10
int A[MAXSIZE];//����һ��ȫ�����������Ŷ�Ԫ��
int front = -1;
int rear = -1; //�ӿ�ʱ��������Ϊ-1��
//��Ӳ���
 void Enqueue(int x){
  //������֧�����
  if(rear ==MAXSIZE-1){
   printf("Error:Queue is Full ");
    return ;
   }
   A[++rear] = x;
  
 }
 //���Ӳ���
 void Dequeue(){
  if((rear ==-1)&& front ==-1){
   printf("Error:Queue is Empty");
   return ;
  }
  else if(rear == front&&(rear!=-1)){//����ֻ��һ��Ԫ�� 
   rear = -1;
   front = -1;
   
  }
  else{
   front  = front+1;
  }   
 } 
 // ���ض�βֵ
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
