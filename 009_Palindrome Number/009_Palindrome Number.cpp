#include <iostream>
using namespace std;
class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0)	return false;
		char str[12], *c = str;
		while (x > 0) {
			*c = (x % 10) | 0x30;
			x /= 10;
			++c;
		}
		char *c1 = str, *c2 = c - 1;
		while (c1 < c2) {
			if (*c1 != *c2)
				return false;
			++c1;
			--c2;
		}
		return true;
	}
};
int main(int argc, char** argv) {
	Solution solution;
	cout << solution.isPalindrome(121) << endl;
	return 0;
}