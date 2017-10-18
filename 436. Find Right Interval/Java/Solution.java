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
    public int[] findRightInterval(Interval[] intervals) {
        int[] result = new int[intervals.length];
        int[] starts = new int[intervals.length];
        Map<Integer, Integer> indexs = new HashMap<>();
        for (int i = 0; i < intervals.length; i++) {
            starts[i] = intervals[i].start;
            indexs.put(intervals[i].start, i);
        }
        Arrays.sort(starts);
        for (int i = 0; i < intervals.length; i++) {
            int end = intervals[i].end;
            int low = 0;
            int high = starts.length - 1;
            while (low <= high) {
                int mid = (low + high) / 2;
                if (starts[mid] < end) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            if (low == starts.length) {
                result[i] = -1;
            } else {
                result[i] = indexs.get(starts[low]);
            }
        }
        return result;
    }
}