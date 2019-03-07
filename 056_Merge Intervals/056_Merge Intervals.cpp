#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//Definition for an interval.
struct Interval {
    int start;
    int end;

    Interval() : start(0), end(0) {}

    Interval(int s, int e) : start(s), end(e) {}

};

ostream &operator<<(ostream &out, Interval &interval) {
    return out << "{" << interval.start << ", " << interval.end << "}";
}

ostream &operator<<(ostream &out, vector<Interval> &intervals) {
    out << "{";
    for (Interval interval : intervals) {
        out << interval << ", ";
    }
    out << "\b\b}";
    return out;
}


class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<int> starts, ends;
        make_heap(starts.begin(), starts.end(), greater<int>());
        make_heap(ends.begin(), ends.end(), greater<int>());
        vector<int> self;
        make_heap(self.begin(), self.end(), greater<int>());
        for (Interval interval:intervals) {
            starts.push_back(interval.start);
            push_heap(starts.begin(), starts.end(), greater<int>());
            ends.push_back(interval.end);
            push_heap(ends.begin(), ends.end(), greater<int>());
            if (interval.start == interval.end) {
                self.push_back(interval.start);
                push_heap(self.begin(), self.end(), greater<int>());
            }
        }
        sort_heap(self.begin(), self.end(), greater<int>());
        reverse(self.begin(), self.end());
        int count = 0, start = 0, end = 0;
        vector<Interval> result;
        while (!starts.empty() || !ends.empty()) {
            if (!starts.empty() && starts.front() < ends.front()) {
                if (count <= 0) {
                    start = starts.front();
                }
                ++count;
                pop_heap(starts.begin(), starts.end(), greater<int>());
                starts.pop_back();
            } else if (starts.empty() || starts.front() > ends.front()) {
                --count;
                if (count <= 0) {
                    end = ends.front();
                    if (!result.empty() && result.back().start == result.back().end && result.back().end == start) {
                        result.pop_back();
                    }
                    result.emplace_back(start, end);
                }
                pop_heap(ends.begin(), ends.end(), greater<int>());
                ends.pop_back();
            } else {
                if (count == 0 && binary_search(self.begin(), self.end(), starts.front())) {
                    if (result.empty() || result.back().end < starts.front()) {
                        result.emplace_back(starts.front(), ends.front());
                    }
                }
                pop_heap(starts.begin(), starts.end(), greater<int>());
                starts.pop_back();
                pop_heap(ends.begin(), ends.end(), greater<int>());
                ends.pop_back();
            }
        }
        return result;
    }
};

int main(int argc, char **argv) {
    Solution solution;
    vector<Interval> intervals, result;
//    intervals = {{1,  3},
//                 {2,  6},
//                 {8,  10},
//                 {15, 18}};
//    result = solution.merge(intervals);
//    cout << result << endl;
//    intervals = {{1, 4},
//                 {4, 5}};
//    result = solution.merge(intervals);
//    cout << result << endl;
    intervals = {{1, 4},
                 {0, 0}};
    result = solution.merge(intervals);
    cout << result << endl;
//    intervals = {{2, 3},
//                 {3, 4},
//                 {2, 3},
//                 {3, 4}};
//    result = solution.merge(intervals);
//    cout << result << endl;
//    intervals = {{2, 3},
//                 {5, 5},
//                 {2, 2},
//                 {3, 4},
//                 {3, 4}};
//    result = solution.merge(intervals);
//    cout << result << endl;
    return 0;
}