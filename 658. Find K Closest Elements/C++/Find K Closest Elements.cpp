class Solution {
public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x) {
        class Utils {
        public:
            int binarySearch(vector<int> &array, int x) {
                int low = 0;
                int high = array.size() - 1;
                while (low <= high) {
                    int mid = (low + high) / 2;
                    if (array[mid] == x) {
                        return mid;
                    } else if (array[mid] < x) {
                        low = mid + 1;
                    } else {
                        high = mid - 1;
                    }
                }
                return low;
            }
        };
        Utils utils;
        int j = utils.binarySearch(arr, x);
        int i = j - 1;
        while (k > 0) {
            if (i < 0 || (j < arr.size() && arr[j] - x < x - arr[i])) {
                j++;
            } else {
                i--;
            }
            k--;
        }
        return vector<int>(arr.begin() + i + 1, arr.begin() + j);
    }
};