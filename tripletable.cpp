//三元组表（1h25min） 
#include "stdio.h"
#define MAXSIZE 16//定义三元组
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
//创建三元组
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
	t.nums=x;//非零元素的个数
}
void Print_tb(tripletable t)
{
	for(int k=0;k<t.nums;k++)
	{
		printf("%d\t%d\t%d\n",t.data[k].i,t.data[k].j,t.data[k].v);
	}
}
//三元组相加
tripletable Add_td(tripletable a,tripletable b,tripletable &c)
{
	c.rows=a.rows;
	c.cols=a.cols;
	int pa=0,pb=0,pc=0;
	while(pa<a.nums&&pb<b.nums)//同时扫描三元组A和B
	{
		if((a.data[pa].i=b.data[pb].i)&&
			(a.data[pa].j=b.data[pb].j)&&
			a.data[pa].v+b.data[pb].v!=0)
		{//ab的行列号相同，且之和不为零 
			c.data[pc].i=a.data[pa].i;
			c.data[pc].j=a.data[pa].j;
            c.data[pc].v=a.data[pa].v+b.data[pb].v;
			pa++;pb++;pc++;
		}
		else if((a.data[pa].i<b.data[pb].i)||
			(a.data[pa].i==b.data[pb].i&&
			a.data[pa].j<b.data[pb].j)) 
		{//a的行号小于b的行号，或者a的行号和b的行号相同且a的列号小于b的列号
			c.data[pc].i=a.data[pa].i;
			c.data[pc].j=a.data[pa].j;
            c.data[pc].v=a.data[pa].v;
			pc++;pa++;		
			
		}else{//a的行号大于b的行号
			c.data[pc].i=b.data[pa].i;
			c.data[pc].j=b.data[pa].j;
            c.data[pc].v=b.data[pa].v;
			pc++;pb++;			
		}
	}
	while(pa<a.nums){//a中有剩余
		c.data[pc].i=a.data[pa].i;
		c.data[pc].j=a.data[pa].j;
		c.data[pc].v=a.data[pa].v;
		pc++;pa++;		
		
	}
	while(pb<b.nums){//b中有剩余 
		c.data[pc].i=b.data[pa].i;
		c.data[pc].j=b.data[pa].j;
		c.data[pc].v=b.data[pa].v;
		pc++;pb++;			
		
	}
	c.nums=pc;
	return c;
}

//转置

tripletable transmatrix(tripletable a,tripletable &d)
{ /* 将稀疏矩阵a转置，结果通过函数名返回 */
	int p,q,col;
	d.rows=a.cols;
	d.cols=a.rows;
	d.nums=a.nums; /* 初始化 */ 
	if(d.nums){ /*把a中每一个非零元素转换到b中相应位置 */
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
	
	//创建三元组A,B 
	Creat_tb(A,a);
	Creat_tb(B,b);
	//打印三元组表
	printf("三元组表A: \n");
	Print_tb(A);
	printf("三元组表B: \n");
	Print_tb(B);
	//A的转置
	tripletable  D;
	transmatrix(A,D);
	printf("三元组表A转置后： \n");
	Print_tb(D);
	//A和B做加法
	tripletable C;
	Add_td(A,B,C);
	printf("三元组表C: \n");
	Print_tb(C);
	return 0;	
}
