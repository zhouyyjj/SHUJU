#include <stdio.h>
void perm(int list[], int k,int n) {
 int i,t;
 if(k==n) {
  for(i=0;i<=n;i++) {
   printf("%d",list[i]);
   }
  printf("\n");
 }
 for(i=k;i<=n;i++){
  {t=list[k]; list[k]=list[i]; list[i]=t;}
  perm(list,k+1,n);
  {t=list[i]; list[i]=list[k]; list[k]=t;}
 }
}
int main() {
 int arr[] = {1,2,3,4};
 perm(arr,0,3);
 return 0;
}
