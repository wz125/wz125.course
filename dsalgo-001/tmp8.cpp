/*
ID: Moien_Podiene
LANG: C++
*/

#include <iostream>
#include <cstdlib>
#include <queue>

using namespace std;

class BinTreeNode;

class BinTreeNode
{
public:
	BinTreeNode();	//??????
	BinTreeNode(int);	//?????????(??)????
	BinTreeNode(int, BinTreeNode *, BinTreeNode *);	////?????????(??1)???????(??2,3)????
	BinTreeNode *GetLeftChild();	//????????????
	BinTreeNode *GetRightChild();	//????????????
	BinTreeNode *SetLeftChild(BinTreeNode *);	//?????????????????,???????
	BinTreeNode *SetRightChild(BinTreeNode *);	//?????????????????,???????
	int GetData();	//?????
	int SetData(int);	//?????,??????
	bool operator<(BinTreeNode);
	bool operator==(BinTreeNode);
private:
	int data;	//??????
	BinTreeNode *leftChild;
	BinTreeNode *rightChild;
};

int BinTreeNodeCompare(const void *, const void *);	//????????
int WeighCalculate(BinTreeNode *, int);	//?????????,??2?????

bool operator<(BinTreeNode, BinTreeNode);

const int MAX_NUM = 256;	//?????

int main()
{
	int caseNum;	//??????
	int originNum, nodeNum;	//?????????,?????????
	int buff;	//??????
	BinTreeNode *binBuff;	//????
	BinTreeNode binTree[MAX_NUM];
	cin >> caseNum;
	for(int i = 0; i < caseNum; i++)
	{
		BinTreeNode leftTemp;	//?????
		BinTreeNode rightTemp;	//?????
		priority_queue<BinTreeNode> binTreeQueue;
		cin >> originNum;
		nodeNum = 0;
		for(int j = 0; j < originNum; j++)
		{
			cin >> buff;
			binBuff = new BinTreeNode(buff);
			binTreeQueue.push(*binBuff);
			delete binBuff;
		}
		for(int j = 0; j < originNum - 1; j++)
		{
			leftTemp = binTreeQueue.top();
			binTreeQueue.pop();
			rightTemp = binTreeQueue.top();
			binTreeQueue.pop();
			binTree[nodeNum++] = leftTemp;
			binTree[nodeNum++] = rightTemp;	//??????????????????
			binBuff = new BinTreeNode(leftTemp.GetData() + rightTemp.GetData(),
										&(binTree[nodeNum - 2]), &(binTree[nodeNum - 1]));
			binTreeQueue.push(*binBuff);
			if(j == originNum - 2)
				binTree[nodeNum++] = binTreeQueue.top();
			delete binBuff;
		}
		qsort(binTree, nodeNum, sizeof(BinTreeNode), BinTreeNodeCompare);
		BinTreeNode *root = &binTree[nodeNum - 1];
		cout << WeighCalculate(root, 0) << endl;
	}
	return 0;
}

BinTreeNode::BinTreeNode()
{
	data = -1;
	leftChild = rightChild = NULL;
}

BinTreeNode::BinTreeNode(int val)
{
	data = val;
	leftChild = rightChild = NULL;
}

BinTreeNode::BinTreeNode(int val, BinTreeNode *left, BinTreeNode *right)
{
	data = val;
	leftChild = left;
	rightChild = right;
}

BinTreeNode *BinTreeNode::GetLeftChild()
{
	return leftChild;
}

BinTreeNode *BinTreeNode::GetRightChild()
{
	return rightChild;
}

BinTreeNode *BinTreeNode::SetLeftChild(BinTreeNode *val)
{
	leftChild = val;
	return leftChild;
}

BinTreeNode *BinTreeNode::SetRightChild(BinTreeNode *val)
{
	rightChild = val;
	return rightChild;
}

int BinTreeNode::GetData()
{
	return data;
}

int BinTreeNode::SetData(int val)
{
	data = val;
	return data;
}

bool BinTreeNode::operator<(BinTreeNode x)
{
	return data > x.GetData();	//???????,?????????????
}

bool BinTreeNode::operator==(BinTreeNode x)
{
	if(data != x.GetData())
		return false;
	else if(leftChild != x.GetLeftChild())
		return false;
	else if(rightChild != x.GetRightChild())
		return false;
	return true;
}

int BinTreeNodeCompare(const void *x, const void *y)
{
	return ((BinTreeNode *)x) -> GetData() - ((BinTreeNode *)y) -> GetData();
}

int WeighCalculate(BinTreeNode *root, int level)
{
	if(root == NULL)
		return 0;
	if(root -> GetLeftChild() == NULL && root -> GetRightChild() == NULL)	//????,???
		return root -> GetData() * level;
	return WeighCalculate(root -> GetLeftChild(), level + 1) +
			WeighCalculate(root -> GetRightChild(), level + 1);	//??????????
}

bool operator<(BinTreeNode x, BinTreeNode y)
{
	return x.GetData() > y.GetData();
}

