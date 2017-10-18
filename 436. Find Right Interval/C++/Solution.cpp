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
    vector<int> findRightInterval(vector<Interval> &intervals) {
        vector<int> result(intervals.size());
        vector<int> starts(intervals.size());
        unordered_map<int, int> indexs;
        for (int i = 0; i < intervals.size(); i++) {
            starts[i] = intervals[i].start;
            indexs[intervals[i].start] = i;
        }
        sort(starts.begin(), starts.end());
        for (int i = 0; i < intervals.size(); i++) {
            int end = intervals[i].end;
            int low = 0;
            int high = starts.size() - 1;
            while (low <= high) {
                int mid = (low + high) / 2;
                if (starts[mid] < end) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            if (low == starts.size()) {
                result[i] = -1;
            } else {
                result[i] = indexs[starts[low]];
            }
        }
        return result;

    }
};