#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
	vector<string> generateParenthesis(int n) {
		if (n <= 0)	return vector<string>();
		char *temp = new char[2 * n + 1];
		temp[2 * n] = 0;
		int *count = new int[n];
		int i = 0, left, right, offset;
		memset(count, 0, sizeof(int)*n);
		vector<string> result;
		while (i < n) {
			while (--i >= 0) {
				count[i] = count[i + 1];
			}
// 			for (int j = n - 1; j >= 0; --j) {
// 				cout << count[j];
// 			}
// 			cout << endl;
			left = right = offset = 0;
			for (int j = n - 1; j >= 0;) {
				if (count[j] <= right) {
					temp[offset++] = '(';
					--j;
				} else {
					temp[offset++] = ')';
					++right;
				}
			}
			while (offset < 2 * n) {
				temp[offset++] = ')';
			}
			result.push_back(temp);
			for (i = 0; i < n;) {
				if (count[i] < n - i - 1) {
					++count[i];
					break;
				} else {
					++i;
				}
			}
		}
		return result;
	}
};
int main(int argc, char **argv) {
	Solution solution;
	vector<string> result = solution.generateParenthesis(2);
	for (string s : result) {
		cout << s << endl;
	}
	return 0;
}