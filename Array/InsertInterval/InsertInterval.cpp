//============================================================================
// Given a set of non-overlapping intervals, insert a new interval into the
// intervals (merge if necessary).
//
// You may assume that the intervals were initially sorted according to their
// start times.
//
// Example 1:
// Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].
//
// Example 2:
// Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as
// [1,2],[3,10],[12,16].
//
// This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

/**
 * Definition for an interval.
 */
struct Interval {
    int start;
    int end;
public:
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> result;
        bool merge_finished = false;
        for (vector<Interval>::iterator it = intervals.begin(); it != intervals.end(); it++) {
            if ((*it).start <= newInterval.end && newInterval.start <= (*it).end) {
                newInterval.start = (newInterval.start > (*it).start) ? (*it).start : newInterval.start;
                newInterval.end = ((newInterval.end < (*it).end) ? (*it).end : newInterval.end);
                continue;
            }
            if (!merge_finished && (*it).start > newInterval.end) {
                result.push_back(newInterval);
                merge_finished = true;
            }
            result.push_back(*it);
        }
        if (!merge_finished) result.push_back(newInterval);
        return result;
    }
};

int main() {
    return 0;
}
