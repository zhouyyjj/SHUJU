//线性表的顺序存储结构（运行耗时28min） 
#include<stdio.h>
#include<malloc.h>
#define MAX 1024
typedef char ElemType;
typedef struct {
 ElemType data[MAX];
 int length;
} SqList;
//初始化顺序表
void InitList(SqList *&L) {
 L=(SqList *)malloc(sizeof(SqList));
 L->length=0;
}
//销毁顺序表
void DestroyList(SqList *&L) {
 free(L);
}
//输出顺序表
void DispList(SqList *L) {
 int i;
 for(i=0; i<L->length; i++) {
  printf("%c ",L->data[i]);
 }
 printf("\n");
}
//插入元素
void ListInsert(SqList *&L,int i,ElemType e) {
 int j;
 if(i<1||i>L->length+1||L->length==MAX)//插入位置在线性表范围外或线性表为满时不能插入,返回 
  return ;
 i--;
 for(j=L->length; j>i; j--) {//从后往前一依次后移一位 
  L->data[j]=L->data[j-1];
 }
 L->data[i]=e;
 L->length++;
}
//返回长度
int ListLength(SqList *L) {
 return(L->length);
}
// 判断是否为空
bool ListElempty(SqList *L) {
 return(L->length==0);
}
//删除数据元素
void ListDelete(SqList *&L,int i,ElemType *e) {
 int j;
 if(L->length==0||i<1||i>L->length+1)//空表和不在线性表范围内不能删除,返回 
  return ;
 i--;
 for(j=i; j<L->length-1; j++)
  L->data[j]=L->data[j+1];//将删除位置覆盖,后面依次往前移动 
 L->length--;
}
// 按元素值查找
int LocateElem(SqList *L,ElemType e) {
 int i=0;
 if(L->length==0||L->length<=i)//空表不能查找,返回 
  return 0;
 for(i=0; i<L->length; i++) {//扫描相同跳出 
  if(L->data[i]==e)
   break;
 }
 return i+1;
}
//按位置查找 
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
  printf("\n顺序表L的长度:%d\n",ListLength(L));
  if( ListElempty(L)==1)
  printf("\n此线性表为空!\n");
 else
  printf("\n此线性表为非空!\n");
 GetElem(L,3,&e);
 printf("\n顺序表L的第三个元素为:%c \n",e);
 printf("\n元素a的位置:%d\n",LocateElem(L,'a'));
 printf("在第四个位置出入元素f后的顺序表为:\n");
 ListInsert(L,4,'f');
 DispList(L);
 printf("删除L的第三个元素后顺序表L为:\n");
 ListDelete(L,3,&e);
 DispList(L);
 printf("释放顺序表L\n");
 DestroyList(L);
 if( ListElempty(L)==1)
  printf("\n此线性表为空!\n");
 else
  printf("\n此线性表为非空!\n");
 return 0;
}
