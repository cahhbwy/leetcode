#include <iostream>
using namespace std;
class Solution {
public:
	bool isMatch(string s, string p) {
		const char* sc = s.c_str(), *pc = p.c_str();
		while (*pc) {
			if (*(pc + 1) == '*') {
				if (*pc == '.') {
					pc += 2;
					if (*pc == 0) {
						return true;
					}
					while (*sc) {
						if (isMatch(s.substr(sc - s.c_str()), p.substr(pc - p.c_str()))) {
							return true;
						}
						++sc;
					}
				} else {
					pc += 2;
					while (*sc == *(pc - 2)) {
						if (isMatch(s.substr(sc - s.c_str()), p.substr(pc - p.c_str()))) {
							return true;
						}
						++sc;
					}
				}
			} else {
				if (*pc == '.') {
					++pc;
					++sc;
				} else if (*pc == *sc) {
					++pc;
					++sc;
				} else {
					return false;
				}
			}
		}
		return *pc == *sc;
	}
};
int main(int argc, char** argv) {
	Solution solution;
	cout << solution.isMatch("aaaccbccbcbaabcaa", "c*a*.*a*.*c*.c*.a*c") << endl;
	return 0;
}