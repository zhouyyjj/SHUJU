#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAXLEN 255

typedef struct{
 char ch[MAXLEN];
 int length;
}SString;

bool SubString(SString *Sub,SString S,int pos,int len){
 if(pos+len-1>S.length){
  return false;
 }
 for(int i=pos;i<pos+len;i++){
  Sub->ch[i-pos+1] = S.ch[i];
 }
 Sub->length = len;
 return true;
}

int StrCompare(SString S,SString T){
 for(int i=0;i<=S.length&&i<T.length;i++){
  if(S.ch[i]!=T.ch[i]){
   return S.ch[i] - T.ch[i];
  }
 }
 //ɨ�赽�����ַ�����ͬ���򳤶ȳ��Ĵ�����
 return S.length - T.length;
}

int Index(SString S,SString T){
 int i = 1,n = S.length,m = T.length;
 SString Sub; //�����ݴ��Ӵ�
 while(i<=n-m+1){
  SubString(&Sub,S,i,m);
  if(StrCompare(Sub,T)!=0){
   ++i;
  }else{
   return i; //�����Ӵ��������е�λ��
  }
 }
 return 0; //S�в�������T��ȵ��Ӵ�
}
//�ַ�����ֵ����
void assign(SString *S){
 printf("�������ַ�����\n"); 
 char x;
 int i = 1;
 scanf("%c",&x);
 while(x!='\n'){
  S->ch[i] = x;
  i ++;
  scanf("%c",&x);
 }
 S->length = i-1;
}
//��ӡ�ַ���
void printString(SString S){
 for(int i=1;i<=S.length;i++){
  printf("%c",S.ch[i]);
 }
 printf("\n");
}
int main(){
 SString S,T;
 assign(&S);
 assign(&T);
 printf("���Ӵ�������\n");
 SString Sub;
 SubString(&Sub,S,2,3);
 printString(Sub);
 printf("�Ƚϲ�����\n");
 printf("S����T���Ƿ���ȣ�%d\n",StrCompare(S,T));
 printf("��λ������\n");
 printf("����λ��:%d",Index(S,T));
 return 0;
}
