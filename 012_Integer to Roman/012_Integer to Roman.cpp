//I(1)£¬V(5)£¬X(10)£¬L(50)£¬C(100)£¬D(500)£¬M(1000)
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
	string intToRoman(int num) {
		string s = "";
		switch (num / 1000) {
			case 3:s = s.append("MMM"); break;
			case 2:s = s.append("MM"); break;
			case 1:s = s.append("M"); break;
			case 0:break;
			default:break;
		}
		switch (num / 100 % 10) {
			case 9:s = s.append("CM"); break;
			case 8:s = s.append("DCCC"); break;
			case 7:s = s.append("DCC"); break;
			case 6:s = s.append("DC"); break;
			case 5:s = s.append("D"); break;
			case 4:s = s.append("CD"); break;
			case 3:s = s.append("CCC"); break;
			case 2:s = s.append("CC"); break;
			case 1:s = s.append("C"); break;
			case 0:break;
			default:break;
		}
		switch (num / 10 % 10) {
			case 9:s = s.append("XC"); break;
			case 8:s = s.append("LXXX"); break;
			case 7:s = s.append("LXX"); break;
			case 6:s = s.append("LX"); break;
			case 5:s = s.append("L"); break;
			case 4:s = s.append("XL"); break;
			case 3:s = s.append("XXX"); break;
			case 2:s = s.append("XX"); break;
			case 1:s = s.append("X"); break;
			case 0:break;
			default:break;
		}
		switch (num % 10) {
			case 9:s = s.append("IX"); break;
			case 8:s = s.append("VIII"); break;
			case 7:s = s.append("VII"); break;
			case 6:s = s.append("VI"); break;
			case 5:s = s.append("V"); break;
			case 4:s = s.append("IV"); break;
			case 3:s = s.append("III"); break;
			case 2:s = s.append("II"); break;
			case 1:s = s.append("I"); break;
			case 0:break;
			default:break;
		}
		return s;
	}
};
int main(int argc, char** argv) {
	Solution solution;
	cout << solution.intToRoman(1053) << endl;
	return 0;
}