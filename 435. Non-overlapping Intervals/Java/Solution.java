/**
 * Definition for an interval.
 * public class Interval {
 *     int start;
 *     int end;
 *     Interval() { start = 0; end = 0; }
 *     Interval(int s, int e) { start = s; end = e; }
 * }
 */
public class Solution {
    public int eraseOverlapIntervals(Interval[] intervals) {
        int count = 0;
        long currentEnd = Long.MIN_VALUE;
        Arrays.sort(intervals, new Comparator<Interval>() {
            @Override
            public int compare(Interval o1, Interval o2) {
                return o1.end - o2.end;
            }
        });
        for (Interval interval : intervals) {
            if (interval.start >= currentEnd) {
                currentEnd = interval.end;
                count += 1;
            }
        }
        return intervals.length - count;
    }
}