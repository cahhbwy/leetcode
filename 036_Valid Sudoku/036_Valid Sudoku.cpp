#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		char flag_H[9], flag_V[9], flag_B[9];
		int i, j;
		int h, v, b;
		for (i = 0; i < 9; ++i) {
			memset(flag_H, 0, 9);
			memset(flag_V, 0, 9);
			memset(flag_B, 0, 9);
			for (j = 0; j < 9; ++j) {
				h = board[i][j] - '1';
				v = board[j][i] - '1';
				b = board[i / 3 * 3 + j / 3][i % 3 * 3 + j % 3] - '1';
				if (h >= 0) {
					if (flag_H[h]) {
						return false;
					} else {
						flag_H[h] = 0x01;
					}
				}
				if (v >= 0) {
					if (flag_V[v]) {
						return false;
					} else {
						flag_V[v] = 0x01;
					}
				}
				if (b >= 0) {
					if (flag_B[b]) {
						return false;
					} else {
						flag_B[b] = 0x01;
					}
				}
			}
		}
		return true;
	}
};
int main(int argc, char** argv) {
	Solution solution;
	vector<vector<char>> board = {
		{ '.','.','4','.','.','.','6','3','.' },
		{ '.','.','.','.','.','.','.','.','.' },
		{ '5','.','.','.','.','.','.','9','.' },
		{ '.','.','.','5','6','.','.','.','.' },
		{ '4','.','3','.','.','.','.','.','1' },
		{ '.','.','.','7','.','.','.','.','.' },
		{ '.','.','.','5','.','.','.','.','.' },
		{ '.','.','.','.','.','.','.','.','.' },
		{ '.','.','.','.','.','.','.','.','.' }
	};
	cout << solution.isValidSudoku(board) << endl;
	system("pause");
	return 0;
}
