class Solution {
public:
    bool isPerfectSquare(int num) {
        long low = 0;
        long high = num;
        while (low <= high) {
            long mid = (low + high) / 2;
            long sqar = mid * mid;
            if (sqar == num) {
                return true;
            }
            if (sqar < num) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return false;
    }
};