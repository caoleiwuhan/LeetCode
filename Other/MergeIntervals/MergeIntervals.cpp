//============================================================================
// Given a collection of intervals, merge all overlapping intervals.
//
// For example,
// Given [1,3],[2,6],[8,10],[15,18],
// return [1,6],[8,10],[15,18].
//
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * Definition for an interval.
 */
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

struct StartIncreasing {
    bool operator() (const Interval &a, const Interval &b) {
        return a.start < b.start;
    }
} start_increasing;

class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        if (intervals.size() < 2) return intervals;
        sort(intervals.begin(), intervals.end(), start_increasing);
        vector<Interval> result;
        Interval curInterval;
        vector<Interval>::iterator it = intervals.begin();
        while (it != intervals.end()) {
            if (it == intervals.begin()) {
                curInterval = *it;
            }
            else if ((*it).start <= curInterval.end && curInterval.start <= (*it).end) {
                curInterval.start = (curInterval.start > (*it).start) ? (*it).start : curInterval.start;
                curInterval.end = ((curInterval.end < (*it).end) ? (*it).end : curInterval.end);
            }
            else if ((*it).start > curInterval.end) {
                result.push_back(curInterval);
                curInterval = *it;
            }
            it++;
        }
        result.push_back(curInterval);
        return result;
    }
};

int main() {
    return 0;
}
