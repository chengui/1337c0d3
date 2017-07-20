#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 *Definition for an interval.
 */
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    static bool cmp(const Interval &a, const Interval &b) {
        //if (a.start == b.start)
        //    return a.end <= b.end;
        return a.start < b.start;
    }

    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> res;
        if (intervals.size() == 0)
            return res;
        Interval tmp;
        sort(intervals.begin(), intervals.end(), cmp);
        tmp.start = intervals[0].start, tmp.end = intervals[0].end;
        for (int i = 0; i < intervals.size(); i++) {
            if (tmp.end >= intervals[i].start) {
                tmp.start = min(tmp.start, intervals[i].start);
                tmp.end = max(tmp.end, intervals[i].end);
            } else {
                res.push_back(tmp);
                tmp.start = intervals[i].start;
                tmp.end = intervals[i].end;
            }
        }
        res.push_back(tmp);
        return res;
    }
};

int main() {
    vector<Interval> intervals;
    intervals.push_back(Interval(1, 3));
    intervals.push_back(Interval(2, 6));
    intervals.push_back(Interval(8, 10));
    intervals.push_back(Interval(15, 18));
    Solution solu = Solution();
    vector<Interval> res = solu.merge(intervals);
    for (vector<Interval>::iterator it = res.begin(); it != res.end(); it++) {
        cout << "[" << it->start << ", " << it->end << "], ";
    }
    cout << endl;
}
