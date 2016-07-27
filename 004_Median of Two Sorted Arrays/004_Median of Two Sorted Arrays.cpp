#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int size1 = nums1.size(), size2 = nums2.size(),
			p1 = 0, p2 = 0, q1 = size1 - 1, q2 = size2 - 1,
			m10, m11, m20, m21, minStep;
		m10 = (p1 + q1) / 2;
		m11 = m10 + 1;
		m20 = (p2 + q2) / 2;
		m21 = m20 + 1;
		if (size1 == 0 && size2 > 0) {
			return size2 & 0x01 ? nums2[m20] : (nums2[m20] + nums2[m21]) / 2.0;
		} else if (size1 > 0 && size2 == 0) {
			return size1 & 0x01 ? nums1[m10] : (nums1[m10] + nums1[m11]) / 2.0;
		} else if (size1 == 0 && size2 == 0) {
			return 0;
		}
		while (size1 > 1 && size2 > 1) {
			minStep = size1 < size2 ? size1 / 2 - 1 : size2 / 2 - 1;
			minStep = minStep < 1 ? 1 : minStep;
			if ((size1 & 0x01) && (size2 & 0x01)) {
				if (nums1[m10] < nums2[m20]) {
					p1 += minStep;
					q2 -= minStep;
				} else if (nums1[m10] > nums2[m20]) {
					p2 += minStep;
					q1 -= minStep;
				} else {
					return nums1[m10];
				}
			} else if ((size1 & 0x01) && !(size2 & 0x01)) {
				if (nums1[m10] <= nums2[m20]) {
					p1 += minStep;
					q2 -= minStep;
				} else if (nums1[m10] >= nums2[m21]) {
					p2 += minStep;
					q1 -= minStep;
				} else {
					return nums1[m10];
				}
			} else if (!(size1 & 0x01) && (size2 & 0x01)) {
				if (nums2[m20] <= nums1[m10]) {
					p2 += minStep;
					q1 -= minStep;
				} else if (nums2[m20] >= nums1[m11]) {
					p1 += minStep;
					q2 -= minStep;
				} else {
					return nums2[m20];
				}
			} else {
				if (nums1[m10] < nums2[m20] && nums1[m11] <= nums2[m21]) {
					p1 += minStep;
					q2 -= minStep;
				} else if (nums1[m11] > nums2[m21] && nums1[m10] >= nums2[m20]) {
					p2 += minStep;
					q1 -= minStep;
				} else if (nums1[m10] <= nums2[m20] && nums1[m11] >= nums2[m21]) {
					p1 += minStep;
					q1 -= minStep;
				} else {
					p2 += minStep;
					q2 -= minStep;
				}
			}
			m10 = (p1 + q1) / 2;
			m11 = m10 + 1;
			m20 = (p2 + q2) / 2;
			m21 = m20 + 1;
			size1 = q1 - p1 + 1;
			size2 = q2 - p2 + 1;
		}
		if (size1 == 0 && size2 > 0) {
			if (size2 & 0x01) {
				return nums2[m20];
			} else {
				return (nums2[m20] + nums2[m21]) / 2.0;
			}
		}
		if (size1 > 0 && size2 == 0) {
			if (size1 & 0x01) {
				return nums1[m10];
			} else {
				return (nums1[m10] + nums1[m11]) / 2.0;
			}
		}
		if (size1 == 1 && size2 > 0) {
			if (size2 & 0x01) {
				if (m20 > 0 && nums1[m10] < nums2[m20 - 1]) {
					return (nums2[m20 - 1] + nums2[m20]) / 2.0;
				} else if (m21<nums2.size() && nums1[m10]>nums2[m21]) {
					return (nums2[m20] + nums2[m21]) / 2.0;
				} else {
					return (nums1[m10] + nums2[m20]) / 2.0;
				}
			} else {
				if (nums1[m10] < nums2[m20]) {
					return nums2[m20];
				} else if (nums1[m10]>nums2[m21]) {
					return nums2[m21];
				} else {
					return nums1[m10];
				}
			}
		}
		if (size1 > 0 && size2 == 1) {
			if (size1 & 0x01) {
				if (m10 > 0 && nums2[m20] < nums1[m10 - 1]) {
					return (nums1[m10 - 1] + nums1[m10]) / 2.0;
				} else if (m11<nums1.size() && nums2[m20]>nums1[m11]) {
					return (nums1[m10] + nums1[m11]) / 2.0;
				} else {
					return (nums2[m20] + nums1[m10]) / 2.0;
				}
			} else {
				if (nums2[m20] < nums1[m10]) {
					return nums1[m10];
				} else if (nums2[m20]>nums1[m11]) {
					return nums1[m11];
				} else {
					return nums2[m20];
				}
			}
		}
		return 0;
	}
};
int main(int argc, char** argv) {
	Solution solution;
	vector<int> nums1 = { 1, 4 };
	vector<int> nums2 = { 2, 3, 5, 6, 7, 8 };
	cout << solution.findMedianSortedArrays(nums1, nums2) << endl;
	return 0;
}