#include <iostream>
using namespace std;
#define max(a,b) (((a) > (b)) ? (a) : (b))
class Solution {
public:
	int strStr(string haystack, string needle) {
		int m = needle.length();
		int n = haystack.length();
		if (m == 0)	return 0;
		if (n == 0)	return -1;
		int i, j;
		//bad charater
		int bc[256];
		for (i = 0; i < 256; ++i) {
			bc[i] = m;
		}
		const char *c = needle.c_str();
		i = m;
		while (i > 0) {
			bc[*c++] = i--;
		}
		j = 0;
		while (j <= n - m) {
			i = 0;
			while (i < m&&haystack[j + i] == needle[i]) {
				++i;
			}
			if (i >= m) {
				return j;
			}
			if (j >= n - m) {
				break;
			}
			j += bc[haystack[j + m]];
		}
		return -1;
	}
};
int main(int argc, char **argv) {
	Solution solution;
	cout << solution.strStr("ABCDABCDAABCDABDBDAABCDABDBD", "ABCDABD") << endl;
	return 0;
}