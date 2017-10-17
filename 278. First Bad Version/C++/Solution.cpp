// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long low = 0;
        int high = n;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (isBadVersion(mid)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        if (high == n) {
            return high;
        }
        return high + 1;
    }
};