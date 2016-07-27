#include <iostream>
#include <ctime>
using namespace std;
//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode *result = new ListNode(0);
		ListNode *p1 = l1, *p2 = l2, *pr = result;
		int carry = 0;
		while (p1&&p2) {
			pr->next = new ListNode(p1->val + p2->val + carry);
			pr = pr->next;
			if (pr->val >= 10) {
				pr->val -= 10;
				carry = 1;
			} else {
				carry = 0;
			}
			p1 = p1->next;
			p2 = p2->next;
		}
		if (!p1&&p2) {
			pr->next = p2;
			if (carry) {
				p2->val += 1;
			}
			while (p2->val >= 10) {
				p2->val -= 10;
				if (!p2->next)
					p2->next = new ListNode(0);
				p2 = p2->next;
				p2->val += 1;
			}
		} else if (p1&&!p2) {
			pr->next = p1;
			if (carry) {
				p1->val += 1;
			}
			while (p1->val >= 10) {
				p1->val -= 10;
				if (!p1->next)
					p1->next = new ListNode(0);
				p1 = p1->next;
				p1->val += 1;
			}
		} else {
			if (carry) {
				pr->next = new ListNode(1);
			}
		}
		return result->next;
	}
};
ListNode* generate(int digits) {
	ListNode *l = new ListNode(rand() % 10), *p = l;
	while (--digits > 0) {
		p->next = new ListNode(rand() % 10);
		p = p->next;
	}
	return l;
}
void outputList(ListNode* l) {
	cout << l->val;
	ListNode *p = l;
	while (p->next) {
		cout << "->" << p->next->val;
		p = p->next;
	}
	cout << endl;
}
int main(int argc, char** argv) {
	srand((unsigned int)time(NULL));
	ListNode *l1 = generate(8);
	ListNode *l2 = generate(4);
	outputList(l1);
	outputList(l2);
	Solution solution;
	ListNode *result = solution.addTwoNumbers(l1, l2);
	outputList(result);
	return 0;
}