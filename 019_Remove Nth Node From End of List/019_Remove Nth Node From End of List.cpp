#include <iostream>
#include <stack>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode* removeNthFromEnd_r(ListNode* head, int &n) {	//µÝ¹é
		if (!head)	return NULL;
		head->next = removeNthFromEnd_r(head->next, n);
		--n;
		if (n == 0) {
			ListNode *p = head->next;
			head->next = NULL;
			delete head;
			return p;
		}
		return head;
	}
	ListNode* removeNthFromEnd_s(ListNode* head, int n) {		//Õ»
		ListNode *pre = new ListNode(0);
		pre->next = head;
		stack<ListNode*> s;
		ListNode *p = pre;
		while (p) {
			s.push(p);
			p = p->next;
		}
		while (n-- > 0) {
			s.pop();
		}
		p = s.top();
		ListNode *q = p->next;
		p->next = q->next;
		delete q;
		return pre->next;
	}
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		int size = 0;
		ListNode *p = head;
		while (p) {
			p = p->next;
			++size;
		}
		n = size - n;
		ListNode *pre = new ListNode(0);
		pre->next = head;
		p = pre;
		while (n-- > 0) {
			p = p->next;
		}
		ListNode *q = p->next;
		p->next = q->next;
		delete q;
		return pre->next;
	}
	ListNode* generate(int size) {
		ListNode *head = new ListNode(rand() % 10);
		ListNode *p = head;
		while (--size > 0) {
			p->next = new ListNode(rand() % 10);
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
	ListNode *l = solution.generate(5);
	solution.output(l);
	int n = 5;
	l = solution.removeNthFromEnd(l, n);
	solution.output(l);
	return 0;
}