/* The isBadVersion API is defined in the parent class VersionControl.
      boolean isBadVersion(int version); */

public class Solution extends VersionControl {
    public int firstBadVersion(int n) {
        long low = 0;
        int high = n;
        while (low <= high) {
            long mid = (low + high) / 2;
            if (isBadVersion((int) mid)) {
                high = (int)(mid - 1);
            } else {
                low = mid + 1;
            }
        }
        if (high == n) {
            return high;
        }
        return high + 1;
    }
}