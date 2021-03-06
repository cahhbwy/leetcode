#include <iostream>
#include <vector>
#include <stack>
#include <set>
using namespace std;
class Solution {
public:
	void solveSudoku(vector<vector<char>>& board) {
		initial(board);
		while (!finished(board)) {
			if (back) {
				if (!backtracking(board)) {
					cout << "No Answer!" << endl;
					return;
				}
			} else if (!solveSudoku_OneStep(board)) {
				if (!explore(board)) {
					if (!backtracking(board)) {
						cout << "No Answer!" << endl;
						return;
					}
				}
			}
		}
	}
	void output(vector<vector<char> > board) {
		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {
				cout << " " << board[i][j];
			}
			cout << endl;
		}
		cout << endl;
	}
private:
	struct Record {
		int i, j;
		char v;
	};
	stack<Record> record;
	vector<vector<set<int> > > available;
	vector<vector<bool> > mask;
	bool back;
	bool equal(vector<vector<char> > board) {
		vector<vector<char>> tmp = {
			{ '1','2','3','4','7','5','6','8','9' },
			{ '4','5','6','8','9','.','1','2','3' },
			{ '7','8','9','1','2','3','4','5','.' },
			{ '2','3','1','6','5','9','7','4','8' },
			{ '6','7','4','2','3','8','9','1','5' },
			{ '8','9','5','7','1','4','2','3','6' },
			{ '5','6','2','9','8','1','3','7','4' },
			{ '9','4','7','5','.','2','8','6','1' },
			{ '3','1','8','.','4','.','5','9','2' }
		};
		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {
				if (board[i][j] != tmp[i][j]) {
					return false;
				}
			}
		}
		return true;
	}
	void initial(vector<vector<char> >& board) {
		back = false;
		available.resize(9);
		mask.resize(9);
		for (int i = 0; i < 9; ++i) {
			available[i].resize(9);
			mask[i].resize(9);
			for (int j = 0; j < 9; ++j) {
				mask[i][j] = (board[i][j] == '.');
				if (mask[i][j]) {
					available[i][j] = set<int>({ 1,2,3,4,5,6,7,8,9 });
				}
			}
		}
		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {
				if (board[i][j] != '.') {
					set_value(board, i, j, board[i][j] - '0');
				}
			}
		}
	}
	bool solveSudoku_OneStep(vector<vector<char> > &board) {
		bool status = false;
		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {
				if (board[i][j] == '.' && available[i][j].size() == 1) {
					int t = *available[i][j].begin();
					set_value(board, i, j, t);
					record.push({ i,j,char('0' + t) });
					status = true;
				}
			}
		}
		return status;
	}
	bool finished(vector<vector<char> > board) {
		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {
				if (board[i][j] == '.') {
					return false;
				}
			}
		}
		return true;
	}
	bool explore(vector<vector<char> > &board) {
		Record r = { -1,-1, '.' };
		int short_available = 10;
		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {
				if (board[i][j] == '.' && !available[i][j].empty()) {
					if (available[i][j].size() < short_available) {
						short_available = available[i][j].size();
						r.i = i;
						r.j = j;
					}
				}
			}
		}
		if (short_available > 9) {
			return false;
		}
		int min_t = 10;
		for (int t : available[r.i][r.j]) {
			if (t < min_t) {
				min_t = t;
			}
		}
		set_value(board, r.i, r.j, min_t);
		record.push({ r.i,r.j,char(min_t + '0') });
		return true;
	}
	bool backtracking(vector<vector<char> > &board) {
		while (!record.empty()) {
			Record r = record.top();
			record.pop();
			del_value(board, r.i, r.j);
			if (available[r.i][r.j].size() > 1) {
				int cur_t = r.v - '0';
				int next_t = 10;
				for (int t : available[r.i][r.j]) {
					if (t > cur_t && t < next_t) {
						next_t = t;
					}
				}
				if (next_t <= 9) {
					set_value(board, r.i, r.j, next_t);
					record.push({ r.i,r.j,char(next_t + '0') });
					back = false;
					return true;
				}
			}
		}
		return false;
	}
	void set_value(vector<vector<char> > &board, int i, int j, int t) {
		board[i][j] = '0' + t;
		for (int y = 0; y < 9; ++y) {
			available[i][y].erase(t);
			if (board[i][y] == '.' && available[i][y].empty()) {
				back = true;
			}
		}
		for (int x = 0; x < 9; ++x) {
			available[x][j].erase(t);
			if (board[x][j] == '.' && available[x][j].empty()) {
				back = true;
			}
		}
		for (int x = i / 3 * 3; x < i / 3 * 3 + 3; ++x) {
			for (int y = j / 3 * 3; y < j / 3 * 3 + 3; ++y) {
				available[x][y].erase(t);
				if (board[x][y] == '.' && available[x][y].empty()) {
					back = true;
				}
			}
		}
	}
	void del_value(vector<vector<char> > &board, int i, int j) {
		char v = board[i][j];
		int t = v - '0';
		board[i][j] = '.';
		for (int y = 0; y < 9; ++y) {
			if (mask[i][y]) {
				available[i][y].insert(t);
			}
		}
		for (int x = 0; x < 9; ++x) {
			if (mask[x][j]) {
				available[x][j].insert(t);
			}
		}
		for (int x = i / 3 * 3; x < i / 3 * 3 + 3; ++x) {
			for (int y = j / 3 * 3; y < j / 3 * 3 + 3; ++y) {
				if (mask[x][y]) {
					available[x][y].insert(t);
				}
			}
		}
		for (int a = 0; a < 9; ++a) {
			for (int b = 0; b < 9; ++b) {
				if (board[a][b] == v) {
					set_value(board, a, b, t);
				}
			}
		}
	}
};
int main(int argc, char** argv) {
	Solution solution;
	vector<vector<char>> board = {
		{ '.','.','.','.','.','.','.','.','.' },
		{ '.','.','.','.','.','.','.','.','.' },
		{ '.','.','.','.','.','.','.','.','.' },
		{ '.','.','.','.','.','.','.','.','.' },
		{ '.','.','.','.','.','.','.','.','.' },
		{ '.','.','.','.','.','.','.','.','.' },
		{ '.','.','.','.','.','.','.','.','.' },
		{ '.','.','.','.','.','.','.','.','.' },
		{ '.','.','.','.','.','.','.','.','.' }
	};
	//vector<vector<char>> board = {
	//	{ '5','3','.','.','7','.','.','.','.' },
	//	{ '6','.','.','1','9','5','.','.','.' },
	//	{ '.','9','8','.','.','.','.','6','.' },
	//	{ '8','.','.','.','6','.','.','.','3' },
	//	{ '4','.','.','8','.','3','.','.','1' },
	//	{ '7','.','.','.','2','.','.','.','6' },
	//	{ '.','6','.','.','.','.','2','8','.' },
	//	{ '.','.','.','4','1','9','.','.','5' },
	//	{ '.','.','.','.','8','.','.','7','9' }
	//};
	solution.solveSudoku(board);
	solution.output(board);
	system("pause");
	return 0;
}