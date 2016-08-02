#include <iostream>
#define MAX_INT 0x7FFFFFFF
using namespace std;
class Solution {
public:
	int divide(int dividend, int divisor) {
		if (divisor == 0)	return MAX_INT;
		else if (divisor == 1)	return dividend;
		else if (divisor == -1)
			if (dividend == 0x80000000)
				return MAX_INT;
			else
				return -dividend;
		int result = 0, step, times = 1;
		bool symbol = true;
		if (dividend == 0x80000000) {
			if (divisor == 0x80000000) {
				return 1;
			} else {
				result = 1;
				if (divisor > 0) {
					dividend += divisor;
				} else {
					dividend -= divisor;
				}
			}
		} else {
			if (divisor == 0x80000000) {
				return 0;
			}
		}
		if ((dividend < 0 && divisor>0) || (dividend > 0 && divisor < 0)) {
			symbol = false;
		}
		dividend = abs(dividend);
		divisor = abs(divisor);
		step = divisor;
		while (dividend > step&&step < 0x3FFFFFFF) {
			step = step << 1;
			times = times << 1;
		}
		while (dividend > 0) {
			if (dividend < step && times > 0) {
				step = step >> 1;
				times = times >> 1;
			} else {
				dividend -= step;
				result += times;
			}
		}
		return symbol ? result : -result;
	}
};
int main(int argc, char **argv) {
	Solution solution;
	cout << solution.divide(-2147483648, -3) << endl;
	return 0;
}