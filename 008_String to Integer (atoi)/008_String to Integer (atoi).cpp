#include <iostream>
using namespace std;
class Solution {
public:
	int myAtoi(string str) {
		const char *c = str.c_str();
		while (*c == ' ')
			++c;
		bool symbol = true;
		if (*c == '-') {
			symbol = false;
			++c;
		} else if (*c == '+') {
			++c;
		}
		int result = 0, next;
		while (*c >= '0'&&*c <= '9') {
			next = result * 10 + *c - '0';
			if (next / 10 != result) {
				return symbol ? 2147483647 : -2147483648;
			}
			result = next;
			++c;
		}
		return symbol ? result : -result;
	}
};
int main(int argc, char** argv) {
	Solution solution;
	cout << solution.myAtoi("9223372036854775809") << endl;
	return 0;
}