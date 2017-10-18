/**
 * Definition for an interval.
 * public class Interval {
 *     int start;
 *     int end;
 *     Interval() { start = 0; end = 0; }
 *     Interval(int s, int e) { start = s; end = e; }
 * }
 */
public class SummaryRanges {
    List<Interval> intervals;

    /**
     * Initialize your data structure here.
     */
    public SummaryRanges() {
        intervals = new ArrayList<>();
    }

    public void addNum(int val) {
        if (intervals.isEmpty()) {
            intervals.add(new Interval(val, val));
        } else {
            int low = 0;
            int high = intervals.size() - 1;
            while (low < high) {
                int mid = (low + high) / 2;
                if (intervals.get(mid).start <= val && intervals.get(mid).end >= val) {
                    return;
                }
                if (intervals.get(mid).start > val) {
                    high = mid;
                } else {
                    low = mid + 1;
                }
            }
            Interval currentInterval = intervals.get(low);
            Interval leftNeighbor = low > 0 ? intervals.get(low - 1) : null;
            if (currentInterval.start <= val && val <= currentInterval.end) {
                return;
            } else if (val < currentInterval.start) {
                if (leftNeighbor == null) {
                    if (currentInterval.start == val + 1) {
                        currentInterval.start = val;
                    } else {
                        intervals.add(0, new Interval(val, val));
                    }
                } else {
                    if (leftNeighbor.end + 1 == currentInterval.start - 1) {
                        leftNeighbor.end = currentInterval.end;
                        intervals.remove(currentInterval);
                    } else {
                        if (leftNeighbor.end + 1 == val) {
                            leftNeighbor.end = val;
                        } else {
                            if (currentInterval.start == val + 1) {
                                currentInterval.start = val;
                            } else {
                                intervals.add(low, new Interval(val, val));
                            }
                        }
                    }
                }
            } else {
                if (currentInterval.end + 1 == val) {
                    currentInterval.end = val;
                } else {
                    intervals.add(new Interval(val, val));
                }
            }
        }
    }

    public List<Interval> getIntervals() {
        return intervals;
    }
}

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * List<Interval> param_2 = obj.getIntervals();
 */