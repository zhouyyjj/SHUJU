//图的深度遍历和广度遍历（ 
#include<stdio.h>
#include<stdlib.h>
#define MaxVerNum 30//最大顶点个数
//CreateALGraph
typedef int InfoType;
typedef char VertexType;
typedef struct node{//表节点
 int adjvex;//邻接点域，一般是放顶点对应的序号或在表头向量中的下标
 InfoType info;//与边（或弧）相关的信息
 struct node *next;//指向下一个邻接点的指针域
}EdgeNode;
typedef struct vnode{//顶点节点
 VertexType vertex;//顶点域
 EdgeNode *firstedge;//边表头指针
}VertexNode;
typedef struct{
 VertexNode adjlist[MaxVerNum];//邻接表
 int n,e;//顶点数和边数
}ALGraph;//ALGraph是以邻接表方式存储的图类型

//建立有向图的邻接表存储
void CreateALGraph(ALGraph *G){
 int i,j,k;
 EdgeNode *p;
 printf("请输入顶点数和边数：\n");
 scanf("%d,%d,",&(G->n),&(G->e));//读入顶点数和边数
 getchar();//接受回车
 printf("请输入顶点表：\n");
 for(i=0;i<G->n;i++){//建立有n个顶点的顶点表
  scanf("%c",&(G->adjlist[i].vertex));//读入顶点信息
  G->adjlist[i].firstedge=NULL;//顶点的边表头指针设为空
 }
 getchar();//接受回车
 printf("请输入边<Vi,Vj>：\n");
 for(k=0;k<G->e;k++){//建立边表
  scanf("%d,%d",&i,&j);//读入边<Vi,Vj>的顶点对应序号
  p=(EdgeNode*)malloc(sizeof(EdgeNode));//生成新边表节点p
  p->adjvex=j;//邻接点序号为j
  p->next=G->adjlist[i].firstedge;//将新边表节点p插入顶点
  G->adjlist[i].firstedge=p;
 }
}//CreateALGraph

//深度优先遍历算法
#define MaxVertecNum 30
#define false 0
#define true 1
int visited[MaxVerNum];

void Visit(int v,ALGraph G){
 printf("%c   ",G.adjlist[v].vertex);
}

void DFS(ALGraph G,int v){//从第v个顶点出发深度优先遍历图G
 EdgeNode *p;
 int w;
 Visit(v,G);visited[v]=true;//访问第v个节点，并把访问标志置true
 for(p=G.adjlist[v].firstedge;p;p=p->next){
  w=p->adjvex;
  if(!visited[w])
   DFS(G,w);//对v尚未访问的顶点w递归调用DFS
 }
}

void DFStraverse(ALGraph G){
 int v;
 for(v=0;v<G.n;v++)
  visited[v]=false;//标志向量初始化
 for(v=0;v<G.n;v++)
  if(!visited[v])
   DFS(G,v);
}//DFS

//广度优先遍历
typedef int DataType;
typedef struct{
 DataType data[MaxVerNum];//队列的存储空间
 int front;//队头指针，通过元素所处位置来表示
 int rear;//队尾指针
}SeqQueue, *PSeqQueue;

//队列初始化
PSeqQueue Init_SeqQueue(){
 PSeqQueue Q;
 Q=(PSeqQueue)malloc(sizeof(SeqQueue));
 if(Q){
  Q->front=0;
  Q->rear=0;
 }
 return Q;
}

 //判断队空
int Empty_SeqQueue(PSeqQueue Q){
 if(Q&&Q->front==Q->rear)
  return(1);
 else
  if(!Q)return(-1);
  else return(0);
}

//入队
int InSeqQueue(PSeqQueue Q,DataType x){
 if((Q->rear+1)%MaxVerNum==Q->front){
  printf("队满");//队满不能入队
  return -1;
 }
 else{
  Q->rear=(Q->rear+1)%MaxVerNum;
  Q->data[Q->rear]=x;
  return 1;
 }
}

//出队
int Out_SeqQueue(PSeqQueue Q,DataType *x){
 if(Empty_SeqQueue(Q)){
  printf("队空");//队空不能出队
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
//按广度优先非递归遍历图G。使用辅助队列Q和访问标志数组visited
 int u,w;
 EdgeNode *p;
 PSeqQueue Q;
 Q=Init_SeqQueue();//置空的队列Q
 Visit(v,G);
 visited1[v]=true;//访问v
 Init_SeqQueue();//v入队列
 while(!Empty_SeqQueue(Q)){
  Out_SeqQueue(Q,&u);//出队
  for(p=G.adjlist[u].firstedge;p;p=p->next){
   w=p->adjvex;
   if(!visited1[w]){
    Visit(w,G);
    visited1[w]=true;
    Init_SeqQueue();//u的未被访问的邻接顶点w入队列
   }
  }
 }
}//BFS

void BFStraverse(ALGraph G){
 int v;
 for(v=0;v<G.n;v++)
  visited1[v]=false;//标志向量初始化
 for(v=0;v<G.n;v++)
  if(!visited1[v])
   BFS(G,v);//v从未被访问过，从v开始BFS
}

main(){
 ALGraph G;
 CreateALGraph(&G);
 printf("深度优先遍历：\n");
 DFStraverse(G);
 printf("\n");
 printf("广度优先遍历：\n");
 BFStraverse(G);
}