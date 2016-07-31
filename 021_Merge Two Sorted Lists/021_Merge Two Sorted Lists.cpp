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
	ListNode *l1 = solution.generate(5);
	ListNode *l2 = solution.generate(7);
	solution.output(l1);
	solution.output(l2);
	ListNode *l = solution.mergeTwoLists(l1, l2);
	solution.output(l);
	return 0;
}