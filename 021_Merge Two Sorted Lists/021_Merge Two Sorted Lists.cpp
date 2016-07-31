#include <iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1&&!l2) {
			return l1;
		} else if (!l1&&l2) {
			return l2;
		} else if (!l1&&!l2) {
			return NULL;
		}
		ListNode *l, *p;
		if (l1->val < l2->val) {
			l = l1;
			l1 = l1->next;
		} else {
			l = l2;
			l2 = l2->next;
		}
		p = l;
		while (l1&&l2) {
			if (l1->val < l2->val) {
				p->next = l1;
				l1 = l1->next;
			} else {
				p->next = l2;
				l2 = l2->next;
			}
			p = p->next;
		}
		if (l1&&!l2) {
			p->next = l1;
		} else {
			p->next = l2;
		}
		return l;
	}
	ListNode* generate(int size) {
		if (size <= 0) return NULL;
		ListNode *head = new ListNode(rand() % 3);
		ListNode *p = head;
		while (--size > 0) {
			p->next = new ListNode(1 + p->val + rand() % 3);
			p = p->next;
		}
		return head;
	}
	void output(ListNode *head) {
		while (head) {
			cout << head->val << "->";
			head = head->next;
		}
		cout << "\b\b  " << endl;
		return;
	}
};
int main(int argc, char **argv) {
	Solution solution;
	ListNode *l1 = solution.generate(0);
	ListNode *l2 = solution.generate(7);
	solution.output(l1);
	solution.output(l2);
	ListNode *l = solution.mergeTwoLists(l1, l2);
	solution.output(l);
	return 0;
}