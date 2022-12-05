//�����������Ĵ�����ɭ��ת��������������תɭ��
#include <stdio.h>
#include <stdlib.h>
#define maxSize 100
 
//���Ķ���
typedef struct CSNode
{
	char data;
	struct CSNode *firstchild, *nextsibling;
}CSNode, *CSTree;
 
//�������Ķ���
typedef struct BTNode
{
	char data;
	struct BTNode* lchild;
	struct BTNode* rchild;
}BTNode;
 
//��ɭ�ֶ���
typedef struct
{
	CSTree ct[maxSize];
	int num;
}Forest; 
 
//�洢·������
typedef struct
{
	char path[100];
}Str;
 
//�ļ�ָ��
FILE* fp;
 
//����һ����
CSTree CreateCSTree()
{
	char ch;
	fscanf(fp, "%c", &ch);
	CSTree CT = NULL;
	if (ch != '0')
	{
		CT = (CSNode*)malloc(sizeof(CSNode));
		CT->data = ch;
		CT->firstchild = CreateCSTree();
		CT->nextsibling = CreateCSTree();
	}
	return CT;
}
 
//��ת���ɶ�����
BTNode* ExchangeToBTree(CSTree ct)
{
	if (ct == NULL)
		return NULL;
	else
	{
		BTNode * bt = (BTNode*)malloc(sizeof(BTNode));
		bt->data = ct->data;
		bt->lchild = ExchangeToBTree(ct->firstchild);
		bt->rchild = ExchangeToBTree(ct->nextsibling);
		return bt;
	}
}
 
//������ת������
CSTree ExchangeToCSTree(BTNode *bt)
{
	if (bt == NULL)
		return NULL;
	else
	{
		CSTree ct = (CSNode*)malloc(sizeof(CSNode));
		ct->data = bt->data;
		ct->firstchild = ExchangeToCSTree(bt->lchild);
		ct->nextsibling = ExchangeToCSTree(bt->rchild);
		return ct;
	}
}
 
//ɭ��ת������
BTNode* ForestToBTree(CSTree F[], int low, int high)
{
	//lowΪ��ǰָ�������highΪ��n�������±�n-1
	if (low > high)
		return NULL;
	else
	{
		BTNode* root = ExchangeToBTree(F[low]);//�������ĸ���Ϊ��һ�����ĸ���ͬʱ�������������ǵ�һ�������ڵ������ɭ��ת���ɵĶ�����
		root->rchild = ForestToBTree(F, low + 1, high);//����������������ɭ��������ת���ɵĶ�����
		return root;
	}
}
 
//������תɭ��
Forest* BTreeToForest(BTNode* root)
{
	BTNode* p = root;
 
	//ɭ�ֳ�ʼ��
	Forest* F = (Forest*)malloc(sizeof(Forest));
	BTNode* q = NULL;
 
	int i = 0;//ͳ�����ĸ���
 
	//��������ת��Ϊɭ�֣����Ĵ���
	while (p != NULL)
	{
		q = p->rchild;//����qָ����һ�����ĸ��ڵ�
		p->rchild = NULL;//����ǰ���Һ��ӵĶ��������Һ������ӶϿ�
		F->ct[i++] = ExchangeToCSTree(p);//��������ת��Ϊ��
		p = q;//��pָ����һ����
	}
 
	F->num = i;
	return F;
}
 
//�������������
void preorder(BTNode* bt)
{
	if (bt != NULL)
	{
		printf("%c", bt->data);
		preorder(bt->lchild);
		preorder(bt->rchild);
	}
}
 
//�������������
void inorder(BTNode* bt)
{
	if (bt != NULL)
	{
		inorder(bt->lchild);
		printf("%c", bt->data);
		inorder(bt->rchild);
	}
}
 
//�����������
void preorder_cstree(CSTree ct)
{
	if (ct != NULL)
	{
		printf("%c", ct->data);
		preorder_cstree(ct->firstchild);
		preorder_cstree(ct->nextsibling);
	}
}
 
//���ĺ������=���������������
void inorder_cstree(CSTree ct)
{
	if (ct != NULL)
	{
		inorder_cstree(ct->firstchild);
		printf("%c", ct->data);
		inorder_cstree(ct->nextsibling);
	}
}
 
//ɭ���������
void preorder_forest(Forest*f)
{
	int i;
	for (i = 0; i < f->num; ++i)
		preorder_cstree(f->ct[i]);
}
 
//ɭ�ֺ������
void inorder_forest(Forest*f)
{
	int i;
	for (i = 0; i < f->num; ++i)
		inorder_cstree(f->ct[i]);
}
 
int main()
{
 
	//����һ��ɭ��
	CSTree F[3];
	Str ps[3] = { "C:\\CodeBlocksProject\\cstree1.txt" ,"C:\\CodeBlocksProject\\cstree2.txt" ,"C:\\CodeBlocksProject\\cstree3.txt" };
	int length = 3;
	for (int i = 0; i < length; i++)
	{
		fp = fopen(ps[i].path, "r");
		F[i] = CreateCSTree();
		fclose(fp);
	}
 
	//ɭ��ת������
	BTNode* bt = ForestToBTree(F, 0, length - 1);
 
	//������תɭ��
	Forest* F2;
	F2 = BTreeToForest(bt);
	inorder_forest(F2);
	system("pause");
 
	return 0;
}


