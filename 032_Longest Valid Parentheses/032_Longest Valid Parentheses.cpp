#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	/*
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
		nodes.push_back(Node(0, ')'));
		for (unsigned int i = 0; i < s.length(); ++i) {
			nodes.push_back(Node(i + 1, s[i]));
		}
		nodes.push_back(Node(s.length() + 1, '('));
		unsigned int a = 0, b = 1;
		while (b < nodes.size()) {
			if (nodes[a].c == '('&&nodes[b].c == ')') {
				nodes.erase(nodes.begin() + b);
				nodes.erase(nodes.begin() + a);
				--a;
				--b;
			}
			else {
				++a;
				++b;
			}
		}
		for (int i = 0, j = 1; j < nodes.size(); ++i, ++j) {
			result = result > (nodes[j].i - nodes[i].i - 1) ? result : (nodes[j].i - nodes[i].i - 1);
		}
		return result;
	}
	*/
	int longestValidParentheses(string s) {
		int length = s.length() + 2;
		char *temp = new char[length + 1];
		temp[0] = ')';
		strncpy(temp + 1, s.c_str(), s.length());
		temp[length - 1] = '(';
		temp[length] = 0;
		int a = 0, b = 1;
		while (b < length) {
			if (temp[a] == '('&&temp[b] == ')') {
				temp[a] = temp[b] = '_';
				while (temp[--a] == '_');
				++b;
			} else {
				a = b;
				++b;
			}
		}
		int result = 0, tmp = 0;
		char *c = temp;
		while (*c) {
			if (*c == '_') {
				++tmp;
			} else {
				result = result < tmp ? tmp : result;
				tmp = 0;
			}
			++c;
		}
		return result;
	}
};
int main(int argc, char **argv) {
	Solution solution;
	cout << solution.longestValidParentheses("(()())") << endl;
	system("pause");
	return 0;
}