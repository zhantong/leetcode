/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    int eraseOverlapIntervals(vector<Interval> &intervals) {
        int count = 0;
        long currentEnd = LONG_MIN;
        sort(intervals.begin(), intervals.end(), [](const Interval & before, const Interval & after) {
            return before.end < after.end;
        });
        for (auto &interval : intervals) {
            if (interval.start >= currentEnd) {
                currentEnd = interval.end;
                count++;
            }
        }
        return intervals.size() - count;
    }
};