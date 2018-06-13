#include <iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode * swapPairs(ListNode* head) {
		ListNode *pp, *p, *q;
		if (!head || !head->next) {
			return head;
		}
		q = head->next;
		head->next = q->next;
		q->next = head;
		head = q;
		pp = head->next;
		p = pp->next;
		while (p&&p->next) {
			q = p->next;
			p->next = q->next;
			q->next = p;
			pp->next = q;
			pp = p;
			p = pp->next;
		}
		return head;
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
	ListNode *l = solution.generate(10);
	solution.output(l);
	l = solution.swapPairs(l);
	solution.output(l);
	return 0;
}