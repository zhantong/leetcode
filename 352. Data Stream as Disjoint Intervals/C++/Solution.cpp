/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class SummaryRanges {
public:
    vector<Interval> intervals;

    /** Initialize your data structure here. */
    SummaryRanges() {

    }

    void addNum(int val) {
        if (intervals.empty()) {
            intervals.push_back(Interval(val, val));
        } else {
            int low = 0;
            int high = intervals.size() - 1;
            while (low < high) {
                int mid = (low + high) / 2;
                if (intervals[mid].start <= val && intervals[mid].end >= val) {
                    return;
                }
                if (intervals[mid].start > val) {
                    high = mid;
                } else {
                    low = mid + 1;
                }
            }
            if (intervals[low].start <= val && val <= intervals[low].end) {
                return;
            } else if (val < intervals[low].start) {
                if (low == 0) {
                    if (intervals[low].start == val + 1) {
                        intervals[low].start = val;
                    } else {
                        intervals.insert(intervals.begin(), Interval(val, val));
                    }
                } else {
                    if (intervals[low - 1].end + 1 == intervals[low].start - 1) {
                        intervals[low - 1].end = intervals[low].end;
                        intervals.erase(intervals.begin() + low);
                    } else {
                        if (intervals[low - 1].end + 1 == val) {
                            intervals[low - 1].end = val;
                        } else {
                            if (intervals[low].start == val + 1) {
                                intervals[low].start = val;
                            } else {
                                intervals.insert(intervals.begin() + low, Interval(val, val));
                            }
                        }
                    }
                }
            } else {
                if (intervals[low].end + 1 == val) {
                    intervals[low].end = val;
                } else {
                    intervals.push_back(Interval(val, val));
                }
            }
        }
    }

    vector<Interval> getIntervals() {
        return intervals;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 */