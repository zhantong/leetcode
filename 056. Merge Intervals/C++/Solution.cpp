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
    vector<Interval> merge(vector<Interval> &intervals) {
        if (intervals.empty()) {
            return vector<Interval>();
        }
        sort(intervals.begin(), intervals.end(), [](const Interval & a, const Interval & b) {
            return a.start < b.start;
        });
        int start = intervals[0].start;
        int end = intervals[0].end;
        vector<Interval> result;
        for (const auto &interval : intervals) {
            if (interval.start > end) {
                result.push_back(Interval(start, end));
                start = interval.start;
            }
            end = max(end, interval.end);
        }
        result.push_back(Interval(start, end));
        return result;
    }
};