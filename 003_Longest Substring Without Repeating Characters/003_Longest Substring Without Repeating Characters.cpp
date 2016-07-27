#include <iostream>
using namespace std;
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		char count[256];
		memset(count, 0, 256);
		int maxlen = 0, length = 0;
		const char *head = s.c_str();
		for (const char* c = head; *c; ++c) {
			if (count[*c] == 0) {
				++count[*c];
				++length;
			} else {
				while (*head != *c) {
					count[*head] = 0;
					++head;
				}
				count[*head] = 1;
				maxlen = maxlen >= length ? maxlen : length;
				length = c - head;
				++head;
			}
		}
		maxlen = maxlen >= length ? maxlen : length;
		return maxlen;
	}
};
int main(int argc, char** argv) {
	Solution solution;
	string s("abcabcbb");
	cout << solution.lengthOfLongestSubstring(s) << endl;
	return 0;
}