#pragma once

#include <string>
#include <vector>
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

//链表时候有环
//快慢指针是否会相遇
class LinkedSolution {
public:
	bool hasCycle(ListNode *head) {
		if (!head) return false;
		ListNode* fast = head;
		ListNode* slow = head;
		while (fast && fast->next) {
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast) {
				return true;
			}
		}
		return false;
	}
};

//删除重复节点
class LinkedSolution2 {
public:
	/**
	*
	* @param head ListNode类
	* @return ListNode类
	*/
	ListNode* deleteDuplicates(ListNode* head) {
		// write code here
		if (head == nullptr)
			return nullptr;
		ListNode* tmp = head;
		while (tmp->next) {
			if (tmp->val == tmp->next->val) {
				ListNode* del = tmp->next;
				tmp->next = tmp->next->next;
				delete del;
				del = nullptr;
			}
			else {
				tmp = tmp->next;
			}
		}
		return head;
	}
};


class MergeSolution {
public:
	/**
	*
	* @param l1 ListNode类
	* @param l2 ListNode类
	* @return ListNode类
	*/
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		// write code here
		ListNode* head = nullptr;
		ListNode* tmp = nullptr;
		ListNode* p = l1;
		ListNode* q = l2;
		if (p == nullptr && q == nullptr)
			return nullptr;
		if (p == nullptr)
			return q;
		if (q == nullptr)
			return p;
		//l1 : 1,3,4,5,6,7,8,9
		//l2 : 2,3,4,5,6,7,8,9
		while (p || q) {
			if (!p) {
				head->next = q; break;
			}
			if (!q) {
				head->next = p; break;
			}
			if (p->val < q->val) {
				if (head == nullptr) {
					head = p;
					tmp = head;
				}
				else {
					head->next = p;
					head = head->next;
				}
				p = p->next;
			}
			else {
				if (head == nullptr) {
					head = q;
					tmp = head;
				}
				else {
					head->next = q;
					head = head->next;
				}
				q = q->next;
			}
		}
		return tmp;
	}
};
