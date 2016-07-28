//I(1)£¬V(5)£¬X(10)£¬L(50)£¬C(100)£¬D(500)£¬M(1000)
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
	int romanToInt(string s) {
		int result = 0;
		const char *c = s.c_str();
		while (*c == 'M') {
			result += 1000;
			++c;
		}
		if (*c == 'C') {
			++c;
			if (*c == 'M') {
				++c;
				result += 900;
			} else if (*c == 'D') {
				++c;
				result += 400;
			} else {
				result += 100;
				while (*c == 'C') {
					++c;
					result += 100;
				}
			}
		}
		if (*c == 'D') {
			++c;
			result += 500;
			while (*c == 'C') {
				++c;
				result += 100;
			}
		}
		while (*c == 'C') {
			++c;
			result += 100;
		}
		if (*c == 'X') {
			++c;
			if (*c == 'C') {
				++c;
				result += 90;
			} else if (*c == 'L') {
				++c;
				result += 40;
			} else {
				result += 10;
				while (*c == 'X') {
					++c;
					result += 10;
				}
			}
		}
		if (*c == 'L') {
			++c;
			result += 50;
			while (*c == 'X') {
				++c;
				result += 10;
			}
		}
		while (*c == 'X') {
			++c;
			result += 10;
		}
		if (*c == 'I') {
			++c;
			if (*c == 'X') {
				++c;
				result += 9;
			} else if (*c == 'V') {
				++c;
				result += 4;
			} else {
				result += 1;
				while (*c == 'I') {
					++c;
					result += 1;
				}
			}
		}
		if (*c == 'V') {
			++c;
			result += 5;
			while (*c == 'I') {
				++c;
				result += 1;
			}
		}
		return result;
	}
};
int main(int argc, char** argv) {
	Solution solution;
	cout << solution.romanToInt("MCMXCVI") << endl;
	return 0;
}