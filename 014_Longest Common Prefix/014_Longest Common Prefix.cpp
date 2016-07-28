#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.empty())	return "";
		sort(strs.begin(), strs.end());
		const char *c1 = strs.front().c_str(), *c2 = strs.back().c_str();
		while (*c1 == *c2&&*c1 != 0) {
			++c1;
			++c2;
		}
		return strs.front().substr(0, c1 - strs.front().c_str());
	}
};
int main(int argc, char** argv) {
	Solution solution;
	vector<string> strs = {  };
	cout << solution.longestCommonPrefix(strs) << endl;
	return 0;
}