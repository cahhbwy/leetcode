#include <iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	bool canReverse(ListNode *l, int k, ListNode **p) {
		while (k-- > 0) {
			if (!l) {
				return false;
			}
			p[k] = l;
			l = l->next;
		}
		return true;
	}
	ListNode* reverseKGroup(ListNode* head, int k) {
		ListNode **p = new ListNode*[k], *newHead = new ListNode(0), *pp = newHead;
		pp->next = head;
		while (canReverse(pp->next, k, p)) {
			p[k - 1]->next = p[0]->next;
			for (int i = 0; i < k - 1; ++i) {
				p[i]->next = p[i + 1];
			}
			pp->next = p[0];
			pp = p[k - 1];
		}
		head = newHead->next;
		delete newHead;
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
	l = solution.reverseKGroup(l, 3);
	solution.output(l);
	return 0;
}