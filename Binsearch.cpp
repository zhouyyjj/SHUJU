//�۰���ҷ������ַ���(15min)
#include<stdio.h>
int BinSearch(int arr[],int len,int key) 
{
	int low=0; //�����ʼ��С
	int high=len-1;//�����ʼ���
	int mid;  //�����м�ֵ
	while(low<=high)
	{
		mid=(low+high)/2;//���м�ֵ
		if(key==arr[mid]) //�ж�min��key�Ƿ����
			return mid;    
		else if(key>arr[mid])//���key>mid  ��������Ϊ[mid+1,high]
			low=mid+1;
		else //���key<mid  ��������Ϊ[low,mid-1]
			high=mid-1;
	}
	return -1;//�����������Ŀ��ֵkey���򷵻� -1 ��
}
int main()
{
	int arr[]={1,2,3,4,5,6,7,8,9,10,11};//����Ҫ������arr��������
	printf("%d \n",BinSearch(arr,(sizeof(arr)/sizeof(arr[0])),7));
	return 0;
}
 