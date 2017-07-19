#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	vector<int> getRow(int rowIndex) {
		vector<int> row(rowIndex + 1);
		row[0] = 1;
		for (int i = rowIndex, j = 1; i >= 1; i--, j++) {
			row[j] = (long long)row[j - 1] * i / j;
		}
		return row;
	}
};
int main() {
	Solution solution;
	vector<int> result = solution.getRow(30);
	for (auto j : result) {
		cout << j << " ";
	}
	system("pause");
	return 0;
}