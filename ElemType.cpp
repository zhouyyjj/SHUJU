//���Ա��˳��洢�ṹ�����к�ʱ28min�� 
#include<stdio.h>
#include<malloc.h>
#define MAX 1024
typedef char ElemType;
typedef struct {
 ElemType data[MAX];
 int length;
} SqList;
//��ʼ��˳���
void InitList(SqList *&L) {
 L=(SqList *)malloc(sizeof(SqList));
 L->length=0;
}
//����˳���
void DestroyList(SqList *&L) {
 free(L);
}
//���˳���
void DispList(SqList *L) {
 int i;
 for(i=0; i<L->length; i++) {
  printf("%c ",L->data[i]);
 }
 printf("\n");
}
//����Ԫ��
void ListInsert(SqList *&L,int i,ElemType e) {
 int j;
 if(i<1||i>L->length+1||L->length==MAX)//����λ�������Ա�Χ������Ա�Ϊ��ʱ���ܲ���,���� 
  return ;
 i--;
 for(j=L->length; j>i; j--) {//�Ӻ���ǰһ���κ���һλ 
  L->data[j]=L->data[j-1];
 }
 L->data[i]=e;
 L->length++;
}
//���س���
int ListLength(SqList *L) {
 return(L->length);
}
// �ж��Ƿ�Ϊ��
bool ListElempty(SqList *L) {
 return(L->length==0);
}
//ɾ������Ԫ��
void ListDelete(SqList *&L,int i,ElemType *e) {
 int j;
 if(L->length==0||i<1||i>L->length+1)//�ձ�Ͳ������Ա�Χ�ڲ���ɾ��,���� 
  return ;
 i--;
 for(j=i; j<L->length-1; j++)
  L->data[j]=L->data[j+1];//��ɾ��λ�ø���,����������ǰ�ƶ� 
 L->length--;
}
// ��Ԫ��ֵ����
int LocateElem(SqList *L,ElemType e) {
 int i=0;
 if(L->length==0||L->length<=i)//�ձ��ܲ���,���� 
  return 0;
 for(i=0; i<L->length; i++) {//ɨ����ͬ���� 
  if(L->data[i]==e)
   break;
 }
 return i+1;
}
//��λ�ò��� 
void GetElem(SqList *L,int i,ElemType *e)
{
 if(i<1||i>L->length||L->length==0)
  return ;
 *e=L->data[i-1];
}
int main() {
 SqList *L;
 ElemType e;
 InitList(L);
 ListInsert(L,1,'a');
 ListInsert(L,2,'b');
 ListInsert(L,3,'c');
 ListInsert(L,4,'d');
 ListInsert(L,5,'e');
 DispList(L);
  printf("\n˳���L�ĳ���:%d\n",ListLength(L));
  if( ListElempty(L)==1)
  printf("\n�����Ա�Ϊ��!\n");
 else
  printf("\n�����Ա�Ϊ�ǿ�!\n");
 GetElem(L,3,&e);
 printf("\n˳���L�ĵ�����Ԫ��Ϊ:%c \n",e);
 printf("\nԪ��a��λ��:%d\n",LocateElem(L,'a'));
 printf("�ڵ��ĸ�λ�ó���Ԫ��f���˳���Ϊ:\n");
 ListInsert(L,4,'f');
 DispList(L);
 printf("ɾ��L�ĵ�����Ԫ�غ�˳���LΪ:\n");
 ListDelete(L,3,&e);
 DispList(L);
 printf("�ͷ�˳���L\n");
 DestroyList(L);
 if( ListElempty(L)==1)
  printf("\n�����Ա�Ϊ��!\n");
 else
  printf("\n�����Ա�Ϊ�ǿ�!\n");
 return 0;
}
