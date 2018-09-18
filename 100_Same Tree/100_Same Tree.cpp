#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (p && q) {
            return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        } else {
            return !p && !q;
        }
    }
};

int main() {
    Solution solution;
    auto *p = new TreeNode(10), *q = new TreeNode(10);
    p->left = new TreeNode(3);
    q->right = new TreeNode(3);
    cout << solution.isSameTree(p, q) << endl;

    system("pause");
    return 0;
}