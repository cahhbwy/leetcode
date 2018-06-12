#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
	string countAndSay(int n) {
		string s0 = "1";
		string s1;
		for (int i = 1; i < n; ++i) {
			s1.clear();
			const char *c = s0.c_str();
			int count = 1;
			char buf[2];
			while (*c != '\0') {
				if (*c == *(c + 1)) {
					++count;
				} else {
					sprintf(buf, "%d", count);
					s1.push_back(buf[0]);
					s1.push_back(*c);
					count = 1;
				}
				++c;
			}
			s0 = s1;
		}
		return s0;
	}
};
int main() {
	Solution solution;
	cout << solution.countAndSay(10) << endl;

	system("pause");
	return 0;
}