//单链表的实现（34min） 
#include<stdio.h>
#include<malloc.h>

typedef int ElemType;

typedef struct LNode
{
 ElemType data;  //存放元素值
 struct LNode *next; //指向后继结点
}LinkNode;    ///单链表结点类型LinkNode
//尾插法建立单链表
//从一空表开始依次读取数组a中元素，生成结点s插入表尾，借用一个指针r,使其始终指向当前链表的表尾
void CreateList(LinkNode *&L,ElemType a[],int n)
{
 LinkNode *s,*r;
 L=(LinkNode *)malloc(sizeof(LinkNode));
 r=L;
 for(int i=0;i<n;i++)
 {
  s = (LinkNode *)malloc(sizeof(LinkNode)); //为插入的数据创建结点，由指针s指向
  s->data = a[i];
  r->next = s;
  r=s;
 }
 r->next = NULL;
}
//输出线性表
void DispList(LinkNode *L)
{
 LinkNode *p = L->next;
 while(p!=NULL)
 {
  printf("%d ",p->data);
  p = p->next;
 }
 printf("\n");
}
//求线性表的长度
//让P指向头结点，n用来累计结点的个数
int ListLength(LinkNode *L)
{
 int n = 0;
 LinkNode *p = L;
 while(p->next!=NULL)
 {
  n++;
  p = p->next;
 }
 return n;
}
//插入数据元素
//找到第i-1个结点由P指向它。若第i-1个结点存在，将值为e的结点（由s指向）插入的p所指结点的后面
bool ListInsert(LinkNode *&L,int i,ElemType e)
{
 int j = 0;
 LinkNode *p = L,*s;
 if(i<0)
  return false;
 while(j<i-1 && p!=NULL)
 {
  j++;
  p = p->next;
 }
 if(p==NULL)
  return false;
 else
 {
  s = (LinkNode *)malloc(sizeof(LinkNode)); //创建新结点s
  s->data = e;        //将e赋予s的值
  s->next = p->next;       //将结点s插入到p的后面
  p->next = s;
  return true;
 }
}
//按元素查找
int LocateElem(LinkNode *L,ElemType e)
{
 int i=1;
 LinkNode *p=L->next;       //P指向首结点，i置为1(首结点的序号为1)
 while(p!=NULL && p->data!=e)
 {
  p = p->next;
  i++;
 }
 if(p==NULL)
  return 0;
 else
  return i;
}
//删除数据元素
//找到第i-1个结点由P指向它。若第i-1个结点存在,也存在后继结点(由q指向)，则删除q所指结点
bool ListDelete(LinkNode *&L,int i,ElemType &e)
{
 int j = 0;
 LinkNode *p = L,*q;        //p指向头结点，j置为0(头结点的序号为0)
 if(i<=0)
  return false;
 while(j<i-1&&p!=NULL)
 {
  j++;
  p = p->next;
 }
 if(p==NULL)
  return false;
 else
 {
  q=p->next;
  if(q==NULL)
   return false;
  e=q->data;
  p->next = q->next;       //从链表中删除q结点
  free(q);
  return true;
 }
}
int main(void)
{
 ElemType e;
 ElemType i;
 ElemType a[10];
 LinkNode * L;
 L = (LinkNode *)malloc(sizeof(LinkNode));
 L->next=NULL; 
 printf("请输入10个整形元素：");
 for(i=0;i<10;i++)
 {
  scanf("%d",&a[i]);
 }
 CreateList(L,a,10);
 printf("表长：%d\n",ListLength(L));
 printf("LinkNode中的元素为：");
 DispList(L);
 printf("请输入需要插入元素的位置和值：");
 scanf("%d%d",&i,&e);
 ListInsert(L,i,e);
 printf("表长：%d\n",ListLength(L));
 printf("LinkNode中的元素为：");
 DispList(L);
 printf("请输入需要查找的元素值：");
 scanf("%d",&e);
 printf("%d所在的位置是：%d\n",e,LocateElem(L,e));
 printf("请输入需要删除元素的序号：");
 scanf("%d",&i);
 ListDelete(L,i,e);
 printf("LinkNode中的元素为：");
 DispList(L);
 printf("表长：%d\n",ListLength(L));

 return 0;
}
