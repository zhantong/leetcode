public class Solution {
    public int hIndex(int[] citations) {
        int length = citations.length;
        if (length == 0) {
            return 0;
        }
        int low = 0;
        int high = length - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (citations[mid] == length - mid) {
                return length - mid;
            }
            if (citations[mid] < length - mid) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return length - low;
    }
}