public class Solution {
    public int[] nextGreaterElement(int[] findNums, int[] nums) {
        if (findNums.length == 0) {
            return new int[] {};
        }
        int numMax = -1;
        for (int num : nums) {
            if (num > numMax) {
                numMax = num;
            }
        }
        int[] map = new int[numMax + 1];
        for (int i = 0; i < nums.length; i++) {
            map[nums[i]] = i;
        }
        int[] result = new int[findNums.length];
        for (int i = 0; i < findNums.length; i++) {
            int currentNum = findNums[i];
            if (currentNum > numMax) {
                result[i] = -1;
            } else {
                int currentIndex = map[currentNum] + 1;
                while (currentIndex < nums.length) {
                    if (nums[currentIndex] > currentNum) {
                        result[i] = nums[currentIndex];
                        break;
                    }
                    currentIndex++;
                }
                if (currentIndex == nums.length) {
                    result[i] = -1;
                }
            }
        }
        return result;
    }
}