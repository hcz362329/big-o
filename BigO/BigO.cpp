// BigO.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "static_info.h"
#include "sort.h"
#include "string_al.h"
#include "bitree.h"
#include "climb.h"
#include "linkedlist.h"
int main() {
	srand(0);
	
	TreeNode* node1 = new TreeNode;
	node1->val = 1;

	TreeNode* node2 = new TreeNode;
	node2->val = 2;

	TreeNode* node3 = new TreeNode;
	node3->val = 3;

	TreeNode* node4 = new TreeNode;
	node4->val = 4;

	TreeNode* node5 = new TreeNode;
	node5->val = 5;

	

	TreeNode* node6 = new TreeNode;
	node6->val = 6;

	TreeNode* node7 = new TreeNode;
	node7->val = 7;

	

	TreeNode* node8 = new TreeNode;
	node8->val = 8;

	TreeNode* node9 = new TreeNode;
	node9->val = 9;

	TreeNode* node10 = new TreeNode;
	node10->val = 10;

	node1->left = node2;
	node1->right = node3;
	node2->left = node4;
	node2->right = node5;
	node3->left = node6;
	node3->right = node7;
	node4->left = node8;
	node4->right = nullptr;
	node5->left = nullptr;
	node5->right = nullptr;
	node6->left = nullptr;
	node6->right = nullptr;
	node7->left = nullptr;
	node7->right = nullptr;
	node8->left = nullptr;
	node8->right = node9;
	node9->right = nullptr;
	node9->left = node10;
	node10->right = nullptr;
	node10->left = nullptr;

	/*Solution3 s3;
	vector<int> vec1 = s3.preorderTraversal(node1);
	vector<int> vec2 = s3.inorderTraversal(node1);
	vector<int> vec3 = s3.epilTraversal(node1);
	vector<int> vec4 = s3.hierarchyTraversal(node1);

	for (int i = 0; i < vec1.size(); ++i) {
		printf("	%d	", vec1[i]);
	}
	printf("\n\n");
	for (int i = 0; i < vec2.size(); ++i) {
		printf("	%d	", vec2[i]);
	}
	printf("\n\n");
	for (int i = 0; i < vec3.size(); ++i) {
		printf("	%d	", vec3[i]);
	}
	printf("\n\n");
	for (int i = 0; i < vec4.size(); ++i) {
		printf("	%d	", vec4[i]);
	}

	Solution5 s5;
	bool b = s5.isBalanced(node1);
	printf("\n\n");

	Solution6 s6;
	vector<vector<int> > vecData = s6.levelOrder(node1);
	for (int i = 0; i < vecData.size(); ++i) {
		printf("\n");
		for (int j = 0; j < vecData[i].size(); ++j) {
			printf("	%d	", vecData[i][j]);
		}
	}
	printf("\n\n");
	vector<vector<int> > vecData2 = s6.levelOrder2(node1);
	for (int i = 0; i < vecData2.size(); ++i) {
		printf("\n");
		for (int j = 0; j < vecData2[i].size(); ++j) {
			printf("	%d	", vecData2[i][j]);
		}
	}*/

	ListNode* linknode1 = new ListNode(1);
	ListNode* linknode2 = new ListNode(2);
	ListNode* linknode3 = new ListNode(3);
	ListNode* linknode4 = new ListNode(4);
	ListNode* linknode5 = new ListNode(5);

	ListNode* linknode6 = new ListNode(6);
	ListNode* linknode7 = new ListNode(7);
	ListNode* linknode8 = new ListNode(8);
	ListNode* linknode9 = new ListNode(9);
	ListNode* linknode10 = new ListNode(10);

	linknode1->next = linknode2;
	linknode2->next = linknode3;
	linknode3->next = linknode4;
	linknode4->next = linknode5;

	linknode6->next = linknode7;
	linknode7->next = linknode8;
	linknode8->next = linknode9;
	linknode9->next = linknode10;
	printf("\n\n");
	/*while (linknode1) {
		printf("	%d	", linknode1->val);
		linknode1 = linknode1->next;
	}

	printf("\n\n");
	while (linknode6) {
		printf("	%d	", linknode6->val);
		linknode6 = linknode6->next;
	}*/

	MoveSolution moveS;
	int m = 10;
	int n = 10;
	int **k = moveS.uniquePaths(m,n);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			printf("	%d	", k[i][j]);
		}
		printf("\n\n");
	}
	printf("	%d	", k);
	printf("\n\n");
	system("pause");


	
	return 1;
}


