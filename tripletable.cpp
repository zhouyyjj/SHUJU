//��Ԫ���1h25min�� 
#include "stdio.h"
#define MAXSIZE 16//������Ԫ��
#define m 4
#define n 4
typedef int DataType;
typedef struct{
    int i,j;
	DataType v; 
}triple;
typedef struct{
	triple data[MAXSIZE];
	int rows,cols,nums;
}tripletable;
//������Ԫ��
Creat_tb(tripletable &t,int A[m][n]){
	int x=0;
	t.rows=m;
	t.cols=n;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(A[i][j]!=0)
			{
				t.data[x].v=A[m][n];
				t.data[x].i=i;
				t.data[x].j=j;
				x++;
			}
		}
	}
	t.nums=x;//����Ԫ�صĸ���
}
void Print_tb(tripletable t)
{
	for(int k=0;k<t.nums;k++)
	{
		printf("%d\t%d\t%d\n",t.data[k].i,t.data[k].j,t.data[k].v);
	}
}
//��Ԫ�����
tripletable Add_td(tripletable a,tripletable b,tripletable &c)
{
	c.rows=a.rows;
	c.cols=a.cols;
	int pa=0,pb=0,pc=0;
	while(pa<a.nums&&pb<b.nums)//ͬʱɨ����Ԫ��A��B
	{
		if((a.data[pa].i=b.data[pb].i)&&
			(a.data[pa].j=b.data[pb].j)&&
			a.data[pa].v+b.data[pb].v!=0)
		{//ab�����к���ͬ����֮�Ͳ�Ϊ�� 
			c.data[pc].i=a.data[pa].i;
			c.data[pc].j=a.data[pa].j;
            c.data[pc].v=a.data[pa].v+b.data[pb].v;
			pa++;pb++;pc++;
		}
		else if((a.data[pa].i<b.data[pb].i)||
			(a.data[pa].i==b.data[pb].i&&
			a.data[pa].j<b.data[pb].j)) 
		{//a���к�С��b���кţ�����a���кź�b���к���ͬ��a���к�С��b���к�
			c.data[pc].i=a.data[pa].i;
			c.data[pc].j=a.data[pa].j;
            c.data[pc].v=a.data[pa].v;
			pc++;pa++;		
			
		}else{//a���кŴ���b���к�
			c.data[pc].i=b.data[pa].i;
			c.data[pc].j=b.data[pa].j;
            c.data[pc].v=b.data[pa].v;
			pc++;pb++;			
		}
	}
	while(pa<a.nums){//a����ʣ��
		c.data[pc].i=a.data[pa].i;
		c.data[pc].j=a.data[pa].j;
		c.data[pc].v=a.data[pa].v;
		pc++;pa++;		
		
	}
	while(pb<b.nums){//b����ʣ�� 
		c.data[pc].i=b.data[pa].i;
		c.data[pc].j=b.data[pa].j;
		c.data[pc].v=b.data[pa].v;
		pc++;pb++;			
		
	}
	c.nums=pc;
	return c;
}

//ת��

tripletable transmatrix(tripletable a,tripletable &d)
{ /* ��ϡ�����aת�ã����ͨ������������ */
	int p,q,col;
	d.rows=a.cols;
	d.cols=a.rows;
	d.nums=a.nums; /* ��ʼ�� */ 
	if(d.nums){ /*��a��ÿһ������Ԫ��ת����b����Ӧλ�� */
		q=0;
		for(col=0;col<a.cols;col++)
			for(p=0;p<a.nums;p++)
				if(a.data[p].j==col){
					d.data[q].i=col;
					d.data[q].j=a.data[p].i;
					d.data[q].v=a.data[p].v;
					q++;
				} 
	}
	return d;
}
int main(){
	int a[m][n]={{1,0,3,0},{0,1,0,0},{0,0,1,0},{0,0,1,1}};
	int b[m][n]={{3,0,0,0},{0,4,0,0},{0,0,1,0},{0,0,0,2}};
	tripletable A,B;
	
	//������Ԫ��A,B 
	Creat_tb(A,a);
	Creat_tb(B,b);
	//��ӡ��Ԫ���
	printf("��Ԫ���A: \n");
	Print_tb(A);
	printf("��Ԫ���B: \n");
	Print_tb(B);
	//A��ת��
	tripletable  D;
	transmatrix(A,D);
	printf("��Ԫ���Aת�ú� \n");
	Print_tb(D);
	//A��B���ӷ�
	tripletable C;
	Add_td(A,B,C);
	printf("��Ԫ���C: \n");
	Print_tb(C);
	return 0;	
}
