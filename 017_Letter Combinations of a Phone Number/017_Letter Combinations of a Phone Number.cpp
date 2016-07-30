#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
	vector<string> letterCombinations(string digits) {
		if (digits.empty())	return vector<string>();
		string letter[10] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
		int number = digits[0] - '0';
		vector<string> result;
		if (digits.length() == 1) {
			result.resize(letter[number].length());
			for (int i = 0; i < result.size(); ++i) {
				result[i] = letter[number][i];
			}
		} else {
			vector<string> subString = letterCombinations(&digits.c_str()[1]);
			result.resize(letter[number].length()*subString.size());
			int index = 0;
			for (int i = 0; i < letter[number].length(); ++i) {
				for (string s : subString) {
					result[index++] = letter[number][i] + s;
				}
			}
		}
		return result;
	}
};
int main(int argc, char** argv) {
	Solution solution;
	vector<string> result = solution.letterCombinations("466");
	for (auto i : result) {
		cout << i << endl;
	}
	return 0;
}