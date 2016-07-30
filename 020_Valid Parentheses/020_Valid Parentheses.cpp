#include <iostream>
#include <stack>
using namespace std;
class Solution {
public:
	bool isValid(string s) {
		stack<char> sta;
		const char *c = s.c_str();
		char top;
		while (*c) {
			if (sta.empty()) {
				sta.push(*c);
			} else {
				top = sta.top();
				switch (*c) {
					case ')':top == '(' ? sta.pop() : sta.push(*c); break;
					case ']':top == '[' ? sta.pop() : sta.push(*c); break;
					case '}':top == '{' ? sta.pop() : sta.push(*c); break;
					default:sta.push(*c); break;
				}
			}
			++c;
		}
		return sta.empty();
	}
};
int main(int argc, char **argv) {
	Solution solution;
	cout << solution.isValid("((") << endl;
	return 0;
}