public class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int i = 0;
        int j = numbers.length - 1;
        while (i < j) {
            int twoSum = numbers[i] + numbers[j];
            if (twoSum == target) {
                break;
            }
            if (twoSum > target) {
                j--;
            } else {
                i++;
            }
        }
        return new int[] {i + 1, j + 1};
    }
}