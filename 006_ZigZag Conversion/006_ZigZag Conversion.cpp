#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
	string convert(string s, int numRows) {
		if (numRows == 1) {
			return s;
		}
		int length = s.length();
		char *resultTemp = new char[length + 1];
		resultTemp[length] = 0;
		bool step;
		int step1 = (numRows - 1) * 2, step2 = 0;
		char *p = resultTemp;
		int i = 0;
		while (i < length) {
			*p = s[i];
			++p;
			i += step1;
		}
		step1 -= 2;
		step2 += 2;
		for (int l = 1; l < numRows - 1; ++l) {
			i = l;
			step = true;
			while (i < length) {
				*p = s[i];
				++p;
				if (step) {
					i += step1;
				} else {
					i += step2;
				}
				step = !step;
			}
			step1 -= 2;
			step2 += 2;
		}
		i = numRows - 1;
		while (i < length) {
			*p = s[i];
			++p;
			i += step2;
		}
		return string(resultTemp);
	}
};
int main(int argc, char** argv) {
	Solution solution;
	cout << solution.convert("ABcd", 2) << endl;
	return 0;
}