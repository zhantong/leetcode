public class Solution {
    public int majorityElement(int[] nums) {
        int majority = 0;
        int count = 0;
        for (int num : nums) {
            if (count == 0) {
                majority = num;
            }
            if (majority == num) {
                count++;
            } else {
                count--;
            }
        }
        return majority;
    }
}