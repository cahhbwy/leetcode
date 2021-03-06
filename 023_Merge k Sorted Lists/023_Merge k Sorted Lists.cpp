#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode * mergeKLists(vector<ListNode*>& lists) {
		priority_queue<int> temp;
		for (ListNode *head : lists) {
			ListNode *p = head;
			while (p) {
				temp.push(-(p->val));
				p = p->next;
			}
		}
		ListNode *l = new ListNode(0), *p = l;
		while (!temp.empty()) {
			p->next = new ListNode(-(temp.top()));
			p = p->next;
			temp.pop();
		}
		return l->next;
		// 		ListNode *head = new ListNode(0), *p = head;
		// 		vector<ListNode*>::iterator it, min;
		// 		for (it = lists.begin(); it != lists.end();) {
		// 			if (!*it) {
		// 				it = lists.erase(it);
		// 			} else {
		// 				++it;
		// 			}
		// 		}
		// 		while (!lists.empty()) {
		// 			min = lists.begin();
		// 			for (it = lists.begin(); it != lists.end();++it) {
		// 				if ((*min)->val>(*it)->val) {
		// 					min = it;
		// 				}
		// 			}
		// 			p->next = *min;
		// 			*min = (*min)->next;
		// 			p = p->next;
		// 			if (!*min) {
		// 				lists.erase(min);
		// 			}
		// 		}
		// 		return head->next;
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
	vector<ListNode*> lists;
	// 	for (int i = 0; i < 0; ++i) {
	// 		ListNode *temp = solution.generate(rand() % 10);
	// 		lists.push_back(temp);
	// 		solution.output(temp);
	// 	}
	lists.resize(2);
	lists[0] = solution.generate(3);
	lists[1] = solution.generate(0);

	ListNode *l = solution.mergeKLists(lists);
	solution.output(l);
	return 0;
}