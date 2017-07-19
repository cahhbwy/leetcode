#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		int wordSize = (words.empty() ? 0 : words.front().length());
		char *underline = new char[wordSize + 1];
		memset(underline, '_', wordSize);
		underline[wordSize] = 0;
		for (string word : words) {
			int pos = 0;
			while (true) {
				pos = s.find(word, pos);
				if (pos >= 0) {
					s.replace(pos, wordSize, underline);
					pos += wordSize;
				} else {
					break;
				}
			}
		}
		cout << s.c_str() << endl;
		delete(underline);
		int totalSize = wordSize*words.size();
		underline = new char[totalSize + 1];
		memset(underline, '_', totalSize);
		underline[totalSize] = 0;
		int pos = 0;
		vector<int> result;
		while (true) {
			pos = s.find(underline, pos);
			if (pos >= 0) {
				result.push_back(pos);
				pos += totalSize;
			} else {
				return result;
			}
		}
	}
};
template <typename TElem>
ostream& operator<<(ostream& os, const vector<TElem>& vec) {
	typedef vector<TElem>::const_iterator iter_t;
	const iter_t iter_begin = vec.begin();
	const iter_t iter_end = vec.end();
	os << "[";
	for (iter_t iter = iter_begin; iter != iter_end; ++iter) {
		cout << ((iter != iter_begin) ? "," : "") << *iter;
	}
	os << "]";
	return os;
}
int main(int argc, char **argv) {
	Solution solution;
	string s = "barfoofoobarthefoobarman";
	vector<string> words = { "bar", "foo", "the" };
	cout << solution.findSubstring(s, words) << endl;
	return 0;
}