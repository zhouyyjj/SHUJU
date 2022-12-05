//创建平衡二叉树（1.5h）
#include<stdio.h>
#include<stdlib.h>

struct TreeNode
{
	char data;
	struct TreeNode *lchild,*rchild;
};
//先序遍历
void PreNode(struct TreeNode *root)
{
	if(!root)
	{
		return;
	}
	printf("%c ",root -> data);
	PreNode(root -> lchild);
	PreNode(root -> rchild);
}
//中序遍历
void MidNode(struct TreeNode *root)
{
	if(!root)
	{
		return;
	}
	MidNode(root -> lchild);
	printf("%c ",root -> data);
	MidNode(root -> rchild);
}
//后序遍历
void LastNode(struct TreeNode *root)
{
	if(!root)
	{
		return;
	}
	LastNode(root -> lchild);
	LastNode(root -> rchild);
	printf("%c ",root -> data);
}
//摧毁树
void DstrotyTree(struct TreeNode *root)
{
	if(!root)
	{
		return;
	}
	DstrotyTree(root -> lchild);
	DstrotyTree(root -> rchild);
	free(root);
}
//递归求树高
int GetTreeHeight(struct TreeNode *root)
{
	if(!root)
	{
		return 0;
	}
	int Lheight  = GetTreeHeight(root -> lchild);
	int Rheight = GetTreeHeight(root -> rchild);
	return (Lheight > Rheight ? Lheight : Rheight ) + 1;
}
//平衡二叉树 右旋（顺时针）
struct TreeNode *AVL_Right(struct TreeNode *p)
{
	struct TreeNode *q = p -> lchild;
	p -> lchild = q -> rchild;
	q -> rchild = p;
	return q;
}
//平衡二叉树 左旋（逆时针）
struct TreeNode *AVL_Left(struct TreeNode *p)
{
	struct TreeNode *q = p -> rchild;
	p -> rchild = q -> lchild;
	q -> lchild = p;
	return q;
}
//平衡二叉树 左旋右旋（逆时针，顺时针）
struct TreeNode *AVL_Left_Right(struct TreeNode *p)
{
	p -> lchild = AVL_Left(p -> lchild);
	return AVL_Right(p);
	
}
//平衡二叉树 右旋左旋（顺时针，逆时针）
struct TreeNode *AVL__Right__Left(struct TreeNode *p)
{
	p -> rchild = AVL_Left(p -> rchild);
	return AVL_Left(p);
}
//递归添加节点
struct TreeNode *AVL_DiGui_AddNode(struct TreeNode *root,struct TreeNode *p)
{
	//插入节点
	if(!root)
	{
		return p;
	}
	if(root -> data > p -> data)//左边
	{
		root -> lchild = AVL_DiGui_AddNode(root -> lchild,p);
	}
	else if(root -> data < p -> data)//右边
	{
		root -> rchild = AVL_DiGui_AddNode(root -> rchild,p);
	}
	else//相等
	{
		return root;
	}
	//平衡
	if(abs(GetTreeHeight(root -> lchild) - GetTreeHeight(root -> rchild)) > 1)
	{
		if(root -> data > p -> data)//左边
		{
			if(root -> lchild -> data > p -> data)//左左
			{
				root = AVL_Right(root);
			}
			else if(root -> lchild -> data < p -> data)//左右
			{
				root = AVL_Left_Right(root);
			}
		}
		else if(root -> data < p -> data)//右边
		{
			if(root -> rchild -> data < p -> data)//右右
			{
				root = AVL_Left(root);
			}
			else if(root -> rchild -> data > p -> data)//右左
			{
				root = AVL__Right__Left(root);
			}
		}
	}
	return root;
}
//创建平衡二叉树
struct TreeNode *CreatTree(char *str)
{
	struct TreeNode *root = NULL; 
	while(*str)
	{
		struct TreeNode *p = malloc(sizeof(*p));
		p -> data = *str;
		p -> lchild = p -> rchild = NULL;
		root = AVL_DiGui_AddNode(root,p);
		str++;
	}
	return root;
}

int main()
{
	char str[128];
	scanf("%s",str);
	struct TreeNode * root = CreatTree(str);//创建平衡二叉树
	printf("先序：");
	PreNode(root);//先序
	printf("\n");
	printf("中序：");
	MidNode(root);//中序
	printf("\n");
	printf("后序：");
	LastNode(root);//后序
	printf("\n");
	int height = GetTreeHeight(root);//递归求树高
	printf("Tree_Height = %d\n",height);
	DstrotyTree(root);//摧毁树
	return 0;
}