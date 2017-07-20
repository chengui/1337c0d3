#include <iostream>
#include <vector>

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

class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        int i = 0;
        vector<Interval> res;
        for (; i < intervals.size(); i++) {
            if (intervals[i].start > newInterval.end)
                break;
            if (intervals[i].end < newInterval.start) {
                res.push_back(intervals[i]);
            } else {
                newInterval.start = min(newInterval.start, intervals[i].start);
                newInterval.end = max(newInterval.end, intervals[i].end);
            }
        }
        res.push_back(newInterval);
        for (; i < intervals.size(); i++)
            res.push_back(intervals[i]);
        return res;
    }
};

int main() {
    vector<Interval> intervals;
    intervals.push_back(Interval(1, 3));
    intervals.push_back(Interval(6, 9));
    Solution solu = Solution();
    vector<Interval> res = solu.insert(intervals, Interval(2, 5));
    for (vector<Interval>::iterator it = res.begin(); it != res.end(); it++) {
        cout << "[" << it->start << ", " << it->end << "], ";
    }
    cout << endl;
}
