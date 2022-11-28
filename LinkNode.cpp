//�������ʵ�֣�34min�� 
#include<stdio.h>
#include<malloc.h>

typedef int ElemType;

typedef struct LNode
{
 ElemType data;  //���Ԫ��ֵ
 struct LNode *next; //ָ���̽��
}LinkNode;    ///������������LinkNode
//β�巨����������
//��һ�ձ�ʼ���ζ�ȡ����a��Ԫ�أ����ɽ��s�����β������һ��ָ��r,ʹ��ʼ��ָ��ǰ����ı�β
void CreateList(LinkNode *&L,ElemType a[],int n)
{
 LinkNode *s,*r;
 L=(LinkNode *)malloc(sizeof(LinkNode));
 r=L;
 for(int i=0;i<n;i++)
 {
  s = (LinkNode *)malloc(sizeof(LinkNode)); //Ϊ��������ݴ�����㣬��ָ��sָ��
  s->data = a[i];
  r->next = s;
  r=s;
 }
 r->next = NULL;
}
//������Ա�
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
//�����Ա�ĳ���
//��Pָ��ͷ��㣬n�����ۼƽ��ĸ���
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
//��������Ԫ��
//�ҵ���i-1�������Pָ����������i-1�������ڣ���ֵΪe�Ľ�㣨��sָ�򣩲����p��ָ���ĺ���
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
  s = (LinkNode *)malloc(sizeof(LinkNode)); //�����½��s
  s->data = e;        //��e����s��ֵ
  s->next = p->next;       //�����s���뵽p�ĺ���
  p->next = s;
  return true;
 }
}
//��Ԫ�ز���
int LocateElem(LinkNode *L,ElemType e)
{
 int i=1;
 LinkNode *p=L->next;       //Pָ���׽�㣬i��Ϊ1(�׽������Ϊ1)
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
//ɾ������Ԫ��
//�ҵ���i-1�������Pָ����������i-1��������,Ҳ���ں�̽��(��qָ��)����ɾ��q��ָ���
bool ListDelete(LinkNode *&L,int i,ElemType &e)
{
 int j = 0;
 LinkNode *p = L,*q;        //pָ��ͷ��㣬j��Ϊ0(ͷ�������Ϊ0)
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
  p->next = q->next;       //��������ɾ��q���
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
 printf("������10������Ԫ�أ�");
 for(i=0;i<10;i++)
 {
  scanf("%d",&a[i]);
 }
 CreateList(L,a,10);
 printf("����%d\n",ListLength(L));
 printf("LinkNode�е�Ԫ��Ϊ��");
 DispList(L);
 printf("��������Ҫ����Ԫ�ص�λ�ú�ֵ��");
 scanf("%d%d",&i,&e);
 ListInsert(L,i,e);
 printf("����%d\n",ListLength(L));
 printf("LinkNode�е�Ԫ��Ϊ��");
 DispList(L);
 printf("��������Ҫ���ҵ�Ԫ��ֵ��");
 scanf("%d",&e);
 printf("%d���ڵ�λ���ǣ�%d\n",e,LocateElem(L,e));
 printf("��������Ҫɾ��Ԫ�ص���ţ�");
 scanf("%d",&i);
 ListDelete(L,i,e);
 printf("LinkNode�е�Ԫ��Ϊ��");
 DispList(L);
 printf("����%d\n",ListLength(L));

 return 0;
}
