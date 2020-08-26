#pragma once
#include <vector>
#include <queue>
#include <stack>
using namespace std;
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};


class Solution {
public:
	/**
	*
	* @param root TreeNode类
	* @return int整型
	*/
	int run(TreeNode* root) {
		// write code here
		if (root == nullptr)
			return 0;
		if (root->left == nullptr)
			return run(root->right) + 1;
		if (root->right == nullptr)
			return run(root->left) + 1;
		int leftDepth = run(root->left);
		int rightDepth = run(root->right);
		return leftDepth>rightDepth ? rightDepth + 1 : leftDepth + 1;
	}
};

class Solution2 {
public:
	/**
	*
	* @param p TreeNode类
	* @param q TreeNode类
	* @return bool布尔型
	*/
	bool isSameTree(TreeNode* p, TreeNode* q) {
		// write code here
		if (p == nullptr && q == nullptr)
			return true;
		if ((p != nullptr && q == nullptr) || (p == nullptr&&q != nullptr))
			return false;
		if (p->val != q->val)
			return false;
		else
			return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
	}
};

class Solution3 {
public:
	/**
	*
	* @param root TreeNode类
	* @return int整型vector
	*/
	vector<int> preVec;
	vector<int> preVec2;
	//迭代
	void order3(TreeNode* root) {
		if (root == nullptr)
			return;
		stack<TreeNode*> stk;
		stk.push(root);
		while (!stk.empty()) {
			TreeNode* node = stk.top();
			inorderVec2.push_back(node->val);
			stk.pop();
			if (node->right != nullptr) {
				stk.push(node->right);
				node->right == nullptr;
			}
			if (node->left != nullptr) {
				stk.push(node->left);
				node->left = nullptr;
			}
		}
	}
	//递归
	void preNode(TreeNode* root) {
		if (root == nullptr)
			return;
		preVec.push_back(root->val);
		preNode(root->left);
		preNode(root->right);
	}
	vector<int> preorderTraversal(TreeNode* root) {
		// write code here
		preNode(root);
		return preVec;
	}
	vector<int> preorderTraversal2(TreeNode* root) {
		// write code here
		order3(root);
		return preVec;
	}

	//中序
	vector<int> inorderVec;
	vector<int> inorderVec2;
	void order2(TreeNode* root) {
		if (root == nullptr)
			return;
		stack<TreeNode*> stk;
		stk.push(root);
		while (!stk.empty()) {
			TreeNode* node = stk.top();
			if (node->left == nullptr) {
				inorderVec2.push_back(node->val);
				stk.pop();
				if (node->right != nullptr) {
					stk.push(node->right);
					node->right == nullptr;
				}
			}
			if (node->left != nullptr) {
				stk.push(node->left);
				node->left = nullptr;
			}
		}
	}
	vector<int> inorderTraversal2(TreeNode* root) {
		// write code here
		order2(root);
		return inorderVec2;
	}
	void inorderNode(TreeNode* root) {
		if (root == nullptr)
			return;
		inorderNode(root->left);
		inorderVec.push_back(root->val);
		inorderNode(root->right);
	}
	vector<int> inorderTraversal(TreeNode* root) {
		// write code here
		inorderNode(root);
		return inorderVec;
	}
	//后序
	vector<int> epilVec;
	vector<int> epilVec2;
	//迭代
	void order(TreeNode* root) {
		if (root == nullptr)
			return;
		stack<TreeNode*> stk;
		stk.push(root);
		while (!stk.empty()) {
			TreeNode* node = stk.top();
			if (node->left == nullptr && node->right == nullptr) {
				epilVec2.push_back(node->val);
				stk.pop();
			}
			if (node->right != nullptr) {
				stk.push(node->right);
				node->right = nullptr;
			}
			if (node->left != nullptr) {
				stk.push(node->left);
				node->left = nullptr;
			}
		}
	}
	//递归
	void epilNode(TreeNode* root) {
		if (root == nullptr)
			return;
		epilNode(root->left);
		epilNode(root->right);
		epilVec.push_back(root->val);
	}
	vector<int> epilTraversal(TreeNode* root) {
		// write code here
		epilNode(root);
		return epilVec;
	}
	vector<int> epilTraversal2(TreeNode* root) {
		// write code here
		order(root);
		return epilVec2;
	}

	//层级遍历
	queue<TreeNode*> queue;
	vector<int> hierarchyInt;
	void hierarchyNode(TreeNode* root) {
		if (root == nullptr)
			return;
		queue.push(root);
		while (!queue.empty()) {
			TreeNode* node = queue.front();
			queue.pop();
			hierarchyInt.push_back(node->val);
			if (node->left != nullptr)
				queue.push(node->left);
			if (node->right != nullptr)
				queue.push(node->right);
		}
	}
	vector<int> hierarchyTraversal(TreeNode* root) {
		hierarchyNode(root);
		return hierarchyInt;
	}
};

struct TreeLinkNode {
	int val;
	TreeLinkNode *left;
	TreeLinkNode *right;
	TreeLinkNode *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

/**
* Definition for binary tree with next pointer.
* struct TreeLinkNode {
*  int val;
*  TreeLinkNode *left, *right, *next;
*  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
* };
*/
/**
*完美二叉树
*next指向右边的同级
*层级遍历
*/
class Solution4 {
public:
	//层级遍历
	void connect(TreeLinkNode *root) {
		if (root == nullptr)
			return;
		while (root->left) {
			TreeLinkNode *node = root;
			while (node) {
				node->left->next = node->right;
				if (node->right) {
					node->right->next = node->next ? node->next->left : nullptr;
				}
				node = node->next;
			}
			root = root->left;
		}
	}
	//递归
	void connect2(TreeLinkNode *root) {
		if (root == nullptr)
			return;
		if (root->left)
			root->left->next = root->right;
		if (root->right)
			root->right->next = root->next ? root->next->left : nullptr;
		connect(root->left);
		connect(root->right);
	}
};

/**
*平衡二叉树
*/
class Solution5 {
public:
	/**
	*
	* @param root TreeNode类
	* @return bool布尔型
	*/
	int depth(TreeNode* root,bool & balance) {
		if (root == nullptr)
			return 0;
		int leftDepth = depth(root->left,balance);
		int rightDepth = depth(root->right,balance);
		if (abs(leftDepth - rightDepth) > 1)
			balance = false;
		return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
	}

	bool isBalanced(TreeNode* root) {
		// write code here
		bool balance = true;
		int dep = depth(root, balance);
		return balance;
	}
};

class Solution6 {
public:
	/**
	*
	* @param root TreeNode类
	* @return int整型vector<vector<>>
	*/
	vector<vector<int> > vecData;
	void GetData(queue<TreeNode*> queueNode) {
		queue<TreeNode*> queueNode2;
		vector<int> vecTmp;
		while (!queueNode.empty()) {
			TreeNode* node = queueNode.front();
			queueNode.pop();
			vecTmp.push_back(node->val);
			if (node->left)
				queueNode2.push(node->left);
			if (node->right)
				queueNode2.push(node->right);
		}
		vecData.push_back(vecTmp);
		if (!queueNode2.empty()) {
			GetData(queueNode2);
		}
	}

	vector<vector<int> > levelOrder(TreeNode* root) {
		// write code here
		if(root==nullptr)
			return vecData;
		queue<TreeNode*> queueNode;
		queueNode.push(root);
		GetData(queueNode);
		return vecData;
	}

	vector<vector<int> > levelOrder2(TreeNode* root) {
		// write code here
		if (root == nullptr)
			return vecData;
		queue<TreeNode*> queueNode;
		queueNode.push(root);
		int n_pop = queueNode.size();
		while (!queueNode.empty()) {
			vector<int> vecTmp;
			while (n_pop>0) {
				TreeNode* node = queueNode.front();
				queueNode.pop();
				vecTmp.push_back(node->val);
				if (node->left)
					queueNode.push(node->left);
				if (node->right)
					queueNode.push(node->right);
				--n_pop;
			}
			n_pop = queueNode.size();
			vecData.push_back(vecTmp);
		}
		return vecData;
	}
};

//给定N值，能组成多少个不同的二叉树
class Solution7 {
public:
	/**
	*
	* @param n int整型
	* @return int整型
	*/
	int numTrees(int n) {
		// write code here
		if (n <= 2)
			return n;
		int * bst = new int[n + 1];
		bst[0] = 1;
		bst[1] = 1;
		//b[2]=b[0]*b[1]+b[1]*b[0]=2;
		//b[3]=b[0]*b[2]+b[1]*b[1]+b[2]*b[0]=5;
		//b[4]=b[0]*b[3]+b[1]*b[2]+b[2]*b[1]+b[3]*b[0]=14
		for (int i = 2; i <= n; i++) {
			for (int j = 1; j <= i; j++) {
				bst[i] += bst[j - 1] * bst[i - j];
			}
		}
		return bst[n];
	}
};