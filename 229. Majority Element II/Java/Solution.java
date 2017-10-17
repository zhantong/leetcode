public class Solution {
    public List<Integer> majorityElement(int[] nums) {
        if (nums.length < 2) {
            List<Integer> temp = new ArrayList<>();
            for (int num : nums) {
                temp.add(num);
            }
            return temp;
        }
        int a = nums[0];
        int b = nums[0];
        int countA = 0;
        int countB = 0;
        for (int num : nums) {
            if (num == a) {
                countA++;
            } else if (num == b) {
                countB++;
            } else if (countA == 0) {
                a = num;
                countA = 1;
            } else if (countB == 0) {
                b = num;
                countB = 1;
            } else {
                countA--;
                countB--;
            }
        }
        if (a == b) {
            List<Integer> temp = new ArrayList<>();
            temp.add(a);
            return temp;
        }
        List<Integer> result = new ArrayList<>();
        countA = 0;
        countB = 0;
        for (int num : nums) {
            if (a == num) {
                countA++;
            }
            if (b == num) {
                countB++;
            }
        }
        if (countA > nums.length / 3) {
            result.add(a);
        }
        if (countB > nums.length / 3) {
            result.add(b);
        }
        return result;
    }
}