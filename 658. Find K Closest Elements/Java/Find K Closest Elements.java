class Solution {
    public List<Integer> findClosestElements(List<Integer> arr, int k, int x) {
        class Utils {
            int binarySearch(List<Integer> array, int x) {
                int low = 0;
                int high = array.size() - 1;
                while (low <= high) {
                    int mid = (low + high) / 2;
                    if (array.get(mid) == x) {
                        return mid;
                    } else if (array.get(mid) < x) {
                        low = mid + 1;
                    } else {
                        high = mid - 1;
                    }
                }
                return low;
            }
        }
        Utils utils = new Utils();
        int j = utils.binarySearch(arr, x);
        int i = j - 1;
        while (k > 0) {
            if (i < 0 || (j < arr.size() && arr.get(j) - x < x - arr.get(i))) {
                j++;
            } else {
                i--;
            }
            k--;
        }
        return arr.subList(i + 1, j);
    }
}