//ϣ������40min��
#include <stdio.h>
#include <malloc.h>

void shellSort(int *a, int len); // ��������

int main(void)
{
    int i, len, * a;
    printf("������Ҫ�ŵ����ĸ�����");
    scanf("%d",&len);
    a = (int *)malloc(len * sizeof(int)); // ��̬��������
    printf("������Ҫ�ŵ�����\n");
    for (i = 0; i < len; i++) { // ����ֵ������
        scanf("%d",&a[i]);
    }   
    shellSort(a, len); // ����ϣ��������
    printf("ϣ���������к���Ϊ��\n");
    for (i = 0; i < len; i++) { // �����Ľ�������
        printf("%d\t",a[i]);
    }
    printf("\n");

    return 0;
}

void shellSort(int *a, int len)
{
    int i, j, k, tmp, gap;  // gap Ϊ����
    for (gap = len / 2; gap > 0; gap /= 2) {  // ������ʼ��Ϊ���鳤�ȵ�һ�룬ÿ�α����󲽳�����,
    	for (i = 0; i < gap; ++i) { // ���� i Ϊÿ�η���ĵ�һ��Ԫ���±� 
	        for (j = i + gap; j < len; j += gap) { //�Բ���Ϊgap��Ԫ�ؽ���ֱ�����򣬵�gapΪ1ʱ������ֱ������
	            tmp = a[j];  // ����a[j]��ֵ
	            k = j - gap;  // k��ʼ��Ϊi��ǰһ��Ԫ�أ���i���gap���ȣ�
	            while (k >= 0 && a[k] > tmp) {
	                a[k + gap] = a[k]; // ����a[i]ǰ�ұ�tmp��ֵ���Ԫ������ƶ�һλ
	                k -= gap;
	            }
	            a[k + gap] = tmp; 
	        }
	    }
    }
}
