#include <iostream>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	bool isSameTree(TreeNode* p, TreeNode* q) {
		if (p && q) {
			return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
		} else if (!p && !q) {
			return true;
		} else {
			return false;
		}
	}
};
int main() {
	Solution solution;
	TreeNode *p = &TreeNode(10), *q = &TreeNode(10);
	p->left = &TreeNode(3);
	q->right = &TreeNode(3);
	cout << solution.isSameTree(p, q) << endl;

	system("pause");
	return 0;
}