// BigO.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "static_info.h"
#include "sort.h"
#include "string_al.h"
#include "bitree.h"
#include "array-o.h"
#include "linkedlist.h"
#include "yh.h"
#include "vir-class.h"
#include "sharedptr-cus.h"
#include <vector>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	srand(time(NULL));
	int n = 10;
	ListNode* linkNode = new ListNode(11);
	ListNode* headTmp= linkNode;
	printf("link:%d  ", linkNode->val);
	while (--n > 0) {
		ListNode* lnk = new ListNode(rand()%n);
		printf("link:%d  ", lnk->val);
		linkNode->next = lnk;
		linkNode = lnk;
	}
	linkNode->next = nullptr;

	LinkedSolution2 ls;
	ListNode* result2 = ls.deleteDuplicates(headTmp);
	printf("\n\n");
	while (result2 != nullptr) {
		printf("link:%d  ", result2->val);
		result2 = result2->next;
	}
	SolutionReverse sr;
	ListNode* result = sr.reverseLink(headTmp);
	printf("\n\n");
	while (result!=nullptr) {
		printf("link:%d  ", result->val);
		result = result->next;
	}

	printf("\n\n");
	system("pause");


	
	return 1;
}


