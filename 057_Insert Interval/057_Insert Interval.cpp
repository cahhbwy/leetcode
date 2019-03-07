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
    for (int i = 0; i < intervals.size(); ++i) {
        if (i < intervals.size() - 1) {
            out << intervals[i] << ", ";
        } else {
            out << intervals[i];
        }
    }
    out << "}";
    return out;
}

bool cmp_start(int num, Interval interval) {
    return interval.start > num;
}

bool cmp_end(Interval interval, int num) {
    return interval.end < num;
}

class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> result;
        long low, high;
        low = lower_bound(intervals.begin(), intervals.end(), newInterval.start, cmp_end) - intervals.begin();
        high = upper_bound(intervals.begin(), intervals.end(), newInterval.end, cmp_start) - intervals.begin();
        for (long i = 0; i < low; ++i) {
            result.push_back(intervals[i]);
        }
        if (low < high) {
            result.emplace_back(
                    min(newInterval.start, intervals[low].start),
                    max(newInterval.end, intervals[high - 1].end)
            );
        } else {
            result.push_back(newInterval);
        }
        for (long i = high; i < intervals.size(); ++i) {
            result.push_back(intervals[i]);
        }
        return result;
    }
};

int main(int argc, char **argv) {
    Solution solution;
    vector<Interval> intervals, result;
    Interval newInterval;
    intervals = {{1, 3},
                 {6, 9}};
    newInterval = {2, 5};
    result = solution.insert(intervals, newInterval);
    cout << result << endl;
    intervals = {{1,  2},
                 {3,  5},
                 {6,  7},
                 {8,  10},
                 {12, 16}};
    newInterval = {4, 8};
    result = solution.insert(intervals, newInterval);
    cout << result << endl;
    intervals = {{1, 5}};
    newInterval = {6, 8};
    result = solution.insert(intervals, newInterval);
    cout << result << endl;
    intervals = {{1, 5}};
    newInterval = {0, 0};
    result = solution.insert(intervals, newInterval);
    cout << result << endl;

    vector<int> a = {1, 1, 1, 3, 3, 3, 5, 5, 5, 7, 7, 7};
    cout << (lower_bound(a.begin(), a.end(), 4) - a.begin()) << endl;
    cout << (upper_bound(a.begin(), a.end(), 4) - a.begin()) << endl;
    return 0;
}