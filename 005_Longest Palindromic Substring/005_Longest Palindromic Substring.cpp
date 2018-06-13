#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
	string longestPalindrome(string s) {
		string result;
		const char* start = s.c_str();
		const char* end = s.c_str() + s.length() - 1;
		for (int i = 0; i < s.length(); ++i) {
			const char* p = s.c_str() + i, *q = p;
			while (q <= end && (*p == *q)) {
				++q; ++i;
			}
			--q; --i;
			while (p >= start && q <= end && (*p == *q)) {
				--p; ++q;
			}
			++p; --q;
			if (result.length() < q - p + 1) {
				result = string(s.substr(p - start, q - p + 1));
			}
		}
		return result;
	}
};
int main(int argc, char** argv) {
	Solution solution;
	cout << solution.longestPalindrome("aaaa") << endl;
	return 0;
}