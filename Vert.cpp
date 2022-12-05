//ͼ����ȱ����͹�ȱ����� 
#include<stdio.h>
#include<stdlib.h>
#define MaxVerNum 30//��󶥵����
//CreateALGraph
typedef int InfoType;
typedef char VertexType;
typedef struct node{//��ڵ�
 int adjvex;//�ڽӵ���һ���ǷŶ����Ӧ����Ż��ڱ�ͷ�����е��±�
 InfoType info;//��ߣ��򻡣���ص���Ϣ
 struct node *next;//ָ����һ���ڽӵ��ָ����
}EdgeNode;
typedef struct vnode{//����ڵ�
 VertexType vertex;//������
 EdgeNode *firstedge;//�߱�ͷָ��
}VertexNode;
typedef struct{
 VertexNode adjlist[MaxVerNum];//�ڽӱ�
 int n,e;//�������ͱ���
}ALGraph;//ALGraph�����ڽӱ�ʽ�洢��ͼ����

//��������ͼ���ڽӱ�洢
void CreateALGraph(ALGraph *G){
 int i,j,k;
 EdgeNode *p;
 printf("�����붥�����ͱ�����\n");
 scanf("%d,%d,",&(G->n),&(G->e));//���붥�����ͱ���
 getchar();//���ܻس�
 printf("�����붥���\n");
 for(i=0;i<G->n;i++){//������n������Ķ����
  scanf("%c",&(G->adjlist[i].vertex));//���붥����Ϣ
  G->adjlist[i].firstedge=NULL;//����ı߱�ͷָ����Ϊ��
 }
 getchar();//���ܻس�
 printf("�������<Vi,Vj>��\n");
 for(k=0;k<G->e;k++){//�����߱�
  scanf("%d,%d",&i,&j);//�����<Vi,Vj>�Ķ����Ӧ���
  p=(EdgeNode*)malloc(sizeof(EdgeNode));//�����±߱�ڵ�p
  p->adjvex=j;//�ڽӵ����Ϊj
  p->next=G->adjlist[i].firstedge;//���±߱�ڵ�p���붥��
  G->adjlist[i].firstedge=p;
 }
}//CreateALGraph

//������ȱ����㷨
#define MaxVertecNum 30
#define false 0
#define true 1
int visited[MaxVerNum];

void Visit(int v,ALGraph G){
 printf("%c   ",G.adjlist[v].vertex);
}

void DFS(ALGraph G,int v){//�ӵ�v���������������ȱ���ͼG
 EdgeNode *p;
 int w;
 Visit(v,G);visited[v]=true;//���ʵ�v���ڵ㣬���ѷ��ʱ�־��true
 for(p=G.adjlist[v].firstedge;p;p=p->next){
  w=p->adjvex;
  if(!visited[w])
   DFS(G,w);//��v��δ���ʵĶ���w�ݹ����DFS
 }
}

void DFStraverse(ALGraph G){
 int v;
 for(v=0;v<G.n;v++)
  visited[v]=false;//��־������ʼ��
 for(v=0;v<G.n;v++)
  if(!visited[v])
   DFS(G,v);
}//DFS

//������ȱ���
typedef int DataType;
typedef struct{
 DataType data[MaxVerNum];//���еĴ洢�ռ�
 int front;//��ͷָ�룬ͨ��Ԫ������λ������ʾ
 int rear;//��βָ��
}SeqQueue, *PSeqQueue;

//���г�ʼ��
PSeqQueue Init_SeqQueue(){
 PSeqQueue Q;
 Q=(PSeqQueue)malloc(sizeof(SeqQueue));
 if(Q){
  Q->front=0;
  Q->rear=0;
 }
 return Q;
}

 //�ж϶ӿ�
int Empty_SeqQueue(PSeqQueue Q){
 if(Q&&Q->front==Q->rear)
  return(1);
 else
  if(!Q)return(-1);
  else return(0);
}

//���
int InSeqQueue(PSeqQueue Q,DataType x){
 if((Q->rear+1)%MaxVerNum==Q->front){
  printf("����");//�����������
  return -1;
 }
 else{
  Q->rear=(Q->rear+1)%MaxVerNum;
  Q->data[Q->rear]=x;
  return 1;
 }
}

//����
int Out_SeqQueue(PSeqQueue Q,DataType *x){
 if(Empty_SeqQueue(Q)){
  printf("�ӿ�");//�ӿղ��ܳ���
  return -1;
 }
 else{
  Q->front=(Q->front+1)%MaxVerNum;
  *x=Q->data[Q->front];
  return 1;
 }
}
int visited1[MaxVerNum];
void BFS(ALGraph G,int v){
//��������ȷǵݹ����ͼG��ʹ�ø�������Q�ͷ��ʱ�־����visited
 int u,w;
 EdgeNode *p;
 PSeqQueue Q;
 Q=Init_SeqQueue();//�ÿյĶ���Q
 Visit(v,G);
 visited1[v]=true;//����v
 Init_SeqQueue();//v�����
 while(!Empty_SeqQueue(Q)){
  Out_SeqQueue(Q,&u);//����
  for(p=G.adjlist[u].firstedge;p;p=p->next){
   w=p->adjvex;
   if(!visited1[w]){
    Visit(w,G);
    visited1[w]=true;
    Init_SeqQueue();//u��δ�����ʵ��ڽӶ���w�����
   }
  }
 }
}//BFS

void BFStraverse(ALGraph G){
 int v;
 for(v=0;v<G.n;v++)
  visited1[v]=false;//��־������ʼ��
 for(v=0;v<G.n;v++)
  if(!visited1[v])
   BFS(G,v);//v��δ�����ʹ�����v��ʼBFS
}

main(){
 ALGraph G;
 CreateALGraph(&G);
 printf("������ȱ�����\n");
 DFStraverse(G);
 printf("\n");
 printf("������ȱ�����\n");
 BFStraverse(G);
}