#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	struct Node
	{
		unsigned int i;
		char c;
		Node(int index, char ch) {
			i = index; c = ch;
		}
	};
	int longestValidParentheses(string s) {
		vector<Node> nodes;
		int result = 0;
		for (unsigned int i = 0; i < s.length(); ++i) {
			nodes.push_back(Node(i, s[i]));
		}
		unsigned int a = 0, b = 1;
		while (b < nodes.size()) {
			if (nodes[a].c == '('&&nodes[b].c == ')') {
				nodes.erase(nodes.begin() + b);
				nodes.erase(nodes.begin() + a);
				a = a - 1 >= 0 ? a - 1 : 0;
				b = a + 1;
			}
			else {
				++a;
				++b;
			}
		}
		for (int i = 0, j = 1; j < nodes.size(); ++i, ++j) {
			result = result > (nodes[j].i - nodes[i].i - 1) ? result : (nodes[j].i - nodes[i].i - 1);
		}
		if (nodes.size() < 2) {
			return s.length() - nodes.size();
		}
		return result;
	}
};
int main(int argc, char **argv) {
	Solution solution;
	cout << solution.longestValidParentheses("()(())") << endl;
	system("pause");
	return 0;
}