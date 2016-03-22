#include <iostream>
#include <queue>

using namespace std;

struct BinaryTreeNode {
	int value;
	BinaryTreeNode * pLeft;
	BinaryTreeNode * pRight;
};

typedef enum TraverseType { preOrder, inOrder, postOrder } TraverseType;

class HappyTreeFriend {
private:
	BinaryTreeNode * root;
	
	// calculate Function
	void preOrderTraverse(BinaryTreeNode * pTree);
	void inOrderTraverse(BinaryTreeNode * pTree);
	void postOrderTraverse(BinaryTreeNode * pTree);
	void levelTraverse(BinaryTreeNode * pTree);
	int calculateNodeNum(BinaryTreeNode * pTree);
	int calculateDepth(BinaryTreeNode * pTree);
	int calculateNodeNumInNthLevel(int n, BinaryTreeNode * pTree);
	int calculateLeafNodeNum(BinaryTreeNode * pTree);

	bool calculateIsBalanced(BinaryTreeNode * pTree, int &height);

	BinaryTreeNode * calculateMirror(BinaryTreeNode * pTree);
public:
	HappyTreeFriend();
	~HappyTreeFriend();
	void initWithArray(int * nums);

	// const BinaryTreeNode * getBinaryTreeNode() {
	// 	return root;
	// }


	int getNodeNum();
	int getDepth();
	int getNodeNumInNthLevel(int n);
	int getLeafNodeNum();

	void doOrderTraverse(TraverseType type);
	void doLevelTraverse();

	bool isBalanced(int &height);

	BinaryTreeNode * getMirror();

	// bool operator==(const BinaryTreeNode &tree) const;
};


/*===========================================
=            Initial Binary Tree            =
===========================================*/

HappyTreeFriend::HappyTreeFriend() {
}
HappyTreeFriend::HappyTreeFriend(int *nums) {

}


HappyTreeFriend::~HappyTreeFriend() {

}


/*=====  End of Initial Binary Tree  ======*/



/*==============================================
=            Binary Tree Properties            =
==============================================*/

int HappyTreeFriend::getNodeNum() {
	return calculateNodeNum(root);
}

int HappyTreeFriend::getDepth() {
	return calculateDepth(root);
}

int HappyTreeFriend::getNodeNumInNthLevel(int n) {
	return calculateNodeNumInNthLevel(n, root);
}

int HappyTreeFriend::getLeafNodeNum() {
	return calculateLeafNodeNum(root);
}

int HappyTreeFriend::calculateNodeNum(BinaryTreeNode * pTree) {
	if (pTree == NULL) { return 0; }

	return calculateNodeNum(pTree->pLeft) + calculateNodeNum(pTree->pRight) + 1;
}

int HappyTreeFriend::calculateDepth(BinaryTreeNode * pTree) {
	if (pTree == NULL) { return 0; }

	int depthLeft = calculateDepth(pTree->pLeft);
	int depthRight = calculateDepth(pTree->pRight);

	return depthLeft > depthRight ? (depthLeft + 1) : (depthRight + 1);
}

int HappyTreeFriend::calculateNodeNumInNthLevel(int n, BinaryTreeNode * pTree) {
	if (pTree == NULL || n < 1) { return 0; }
	if (1 == n) { return 1; }
	int numLeft = calculateNodeNumInNthLevel(n-1, pTree->pLeft);
	int numRight = calculateNodeNumInNthLevel(n-1, pTree->pRight);
	return numLeft + numRight;
}

int HappyTreeFriend::calculateLeafNodeNum(BinaryTreeNode * pTree) {
	if (pTree == NULL) { return 0; }
	if (pTree->pLeft == NULL && pTree->pRight == NULL) { return 1; }
	int numLeft = calculateLeafNodeNum(pTree->pLeft);
	int numRight = calculateLeafNodeNum(pTree->pRight);
	return numLeft + numRight;
}

/*=====  End of Binary Tree Properties  ======*/


/*======================================
=            Order Traverse            =
======================================*/

void HappyTreeFriend::doOrderTraverse(TraverseType type) {
	switch (type) {
		case preOrder:
			preOrderTraverse(root);
			break;
		case inOrder:
			inOrderTraverse(root);
			break;
		case postOrder:
			postOrderTraverse(root);
			break;
		default: break;
	}
}

void HappyTreeFriend::preOrderTraverse(BinaryTreeNode * pTree) {
	if (pTree == NULL) { return; }

	// do something
	preOrderTraverse(pTree->pLeft);
	preOrderTraverse(pTree->pRight);
}

void HappyTreeFriend::inOrderTraverse(BinaryTreeNode * pTree) {
	if (pTree == NULL) { return; }

	postOrderTraverse(pTree->pRight);
	// do something
	postOrderTraverse(pTree->pLeft);
}

void HappyTreeFriend::postOrderTraverse(BinaryTreeNode * pTree) {
	if (pTree == NULL) { return; }

	inOrderTraverse(pTree->pLeft);
	inOrderTraverse(pTree->pRight);
	// do something
}

/*=====  End of Order Traverse  ======*/


/*======================================
=            Level Traverse            =
======================================*/

void HappyTreeFriend::doLevelTraverse() {
	levelTraverse(root);
}

void HappyTreeFriend::levelTraverse(BinaryTreeNode * pTree) {
	if (pTree == NULL) { return; }

	queue<BinaryTreeNode *> q;
	q.push(pTree);
	while (!q.empty()) {
		BinaryTreeNode * pNode = q.front();
		q.pop();
		// do something
		if (pNode->pLeft != NULL) {
			q.push(pNode->pLeft);
		}
		if (pNode->pRight != NULL) {
			q.push(pNode->pRight);
		}
	}
}

/*=====  End of Level Traverse  ======*/


/*============================================
=            Operator overloading            =
============================================*/

// bool HappyTreeFriend::operator==(const HappyTreeFriend &tree) const {
// 	const BinaryTreeNode * pTree = &tree.;
// 	cout << "run" << endl;
// 	if (root == NULL) {
// 		cout << "root1 is empty" << endl;
// 	}
// 	if (pTree == NULL) {
// 		cout << "root1 is empty" << endl;
// 	}

// 	if (root == NULL && pTree == NULL) {
// 		return true;
// 	} else if (root == NULL || pTree == NULL) {
// 		cout << "test" << endl;
// 		return false;
// 	}

// 	bool resultLeft = (root->pLeft == pTree->pLeft);
// 	bool resultRight = (root->pRight == pTree->pRight);
// 	cout << "resultLeft" << resultLeft << endl;
// 	cout << "resultRight" << resultRight << endl;
// 	return (resultLeft && resultRight);
// }

// inline bool HappyTreeFriend::operator==(const HappyTreeFriend &tree1, const HappyTreeFriend &tree2) {
// 	const BinaryTreeNode * pTree1 = (tree1)->getBinaryTreeNode();
// 	const BinaryTreeNode * pTree2 = (tree2)->getBinaryTreeNode();
// 	cout << "run" << endl;
// 	if (pTree1 == NULL) {
// 		cout << "root1 is empty" << endl;
// 	}
// 	if (pTree2 == NULL) {
// 		cout << "root1 is empty" << endl;
// 	}

// 	if (pTree1 == NULL && pTree2 == NULL) {
// 		return true;
// 	} else if (pTree1 == NULL || pTree2 == NULL) {
// 		cout << "test" << endl;
// 		return false;
// 	}

// 	bool resultLeft = (pTree1->pLeft == pTree2->pLeft);
// 	bool resultRight = (pTree1->pRight == pTree2->pRight);
// 	cout << "resultLeft" << resultLeft << endl;
// 	cout << "resultRight" << resultRight << endl;
// 	return (resultLeft && resultRight);
// }

/*=====  End of Operator overloading  ======*/


/*===============================================
=            is Balanced Binary Tree            =
===============================================*/

bool HappyTreeFriend::isBalanced(int &height) {
	return calculateIsBalanced(root, height);
}

bool HappyTreeFriend::calculateIsBalanced(BinaryTreeNode * pTree, int &height) {
	if (root == NULL) {
		height = 0;
		return true;
	}
	int heightLeft, heightRight;
	bool resultLeft = calculateIsBalanced(pTree->pLeft, heightLeft);
	bool resultRight = calculateIsBalanced(pTree->pRight, heightRight);

	height = max(heightLeft, heightRight) + 1;
	if (resultLeft && resultRight && abs(heightLeft - heightRight) <= 1) {
		return true;
	} else {
		return false;
	}
}

/*=====  End of is Balanced Binary Tree  ======*/


/*=============================
=            Get mirror       =
=============================*/

BinaryTreeNode * HappyTreeFriend::getMirror() {
	return calculateMirror(root);
}

BinaryTreeNode * HappyTreeFriend::calculateMirror(BinaryTreeNode * pTree) {
	if (pTree == NULL) { return NULL; }
	BinaryTreeNode * pLeftTemp = calculateMirror(pTree->pLeft);
	BinaryTreeNode * pRightTemp = calculateMirror(pTree->pRight);
	pTree->pLeft = pLeftTemp;
	pTree->pRight = pRightTemp;
	return pTree;
}

/*=====  End of Get mirror ======*/




int main() {
	// HappyTreeFriend * tree1 = new HappyTreeFriend();
	// HappyTreeFriend * tree2 = new HappyTreeFriend();

	
	return 0;
}

