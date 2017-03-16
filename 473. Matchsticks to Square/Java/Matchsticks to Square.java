public class Solution {
    public boolean makesquare(int[] nums) {
        class Utils {
            boolean square(int[] nums, int[] edges, int start) {
                if (start == nums.length) {
                    return edges[0] == 0 && edges[1] == 0 && edges[2] == 0 && edges[3] == 0;
                }
                int current = nums[start];
                for (int i = 0; i < edges.length; i++) {
                    if (edges[i] >= current) {
                        edges[i] -= current;
                        if (square(nums, edges, start + 1)) {
                            return true;
                        }
                        edges[i] += current;
                    }
                }
                return false;
            }
        }
        if (nums.length < 4) {
            return false;
        }
        int sumNums = 0;
        for (int num : nums) {
            sumNums += num;
        }
        if (sumNums % 4 != 0) {
            return false;
        }
        int[] edges = new int[4];
        Arrays.fill(edges, sumNums / 4);
        Arrays.sort(nums);
        for (int left = 0, right = nums.length - 1; left < right; left++, right--) {
            int temp = nums[left];
            nums[left] = nums[right];
            nums[right] = temp;
        }
        Utils utils = new Utils();
        return utils.square(nums, edges, 0);
    }
}