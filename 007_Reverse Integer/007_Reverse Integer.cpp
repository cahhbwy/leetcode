#include <iostream>
using namespace std;
class Solution {
public:
	int reverse(int x) {
		bool symbol = true;
		if (x < 0) {
			symbol = false;
			x = -x;
		}
		int result = 0, next;
		while (x > 0) {
			next = result * 10;
			if (next / 10 != result) {
				return 0;
			}
			result = next + x % 10;
			x /= 10;
		}
		return symbol ? result : -result;
	}
};
int main(int argc, char** argv) {
	Solution solution;
	cout << solution.reverse(-2147483648) << endl;
	return 0;
}