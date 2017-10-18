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
    public List<Interval> merge(List<Interval> intervals) {
        if (intervals.isEmpty()) {
            return new ArrayList<>();
        }
        intervals.sort(new Comparator<Interval>() {
            @Override
            public int compare(Interval o1, Interval o2) {
                return o1.start - o2.start;
            }
        });
        int start = intervals.get(0).start;
        int end = intervals.get(0).end;
        List<Interval> result = new ArrayList<>();
        for (Interval interval : intervals) {
            if (interval.start > end) {
                result.add(new Interval(start, end));
                start = interval.start;
            }
            end = Math.max(end, interval.end);
        }
        result.add(new Interval(start, end));
        return result;
    }
}