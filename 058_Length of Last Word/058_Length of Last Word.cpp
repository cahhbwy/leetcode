#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int result = 0, len = 0;
        for (const char *c = s.c_str(); *c; ++c) {
            if ((*c >= 'a' && *c <= 'z') || (*c >= 'A' && *c <= 'Z')) {
                ++len;
            } else {
                if (len > 0) {
                    result = len;
                }
                len = 0;
            }
        }
        if (len > 0) {
            result = len;
        }
        return result;
    }
};

int main(int argc, char **argv) {
    Solution solution;
    cout << solution.lengthOfLastWord("") << endl;
    cout << solution.lengthOfLastWord(" ") << endl;
    cout << solution.lengthOfLastWord(" Hello") << endl;
    cout << solution.lengthOfLastWord("Hello world") << endl;
    cout << solution.lengthOfLastWord("Helloworld") << endl;
    cout << solution.lengthOfLastWord("Today is a nice day") << endl;
    cout << solution.lengthOfLastWord("b   a    ") << endl;
    return 0;
}