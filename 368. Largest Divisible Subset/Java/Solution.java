public class Solution {
    public List<Integer> largestDivisibleSubset(int[] nums) {
        if (nums.length == 0) {
            return new ArrayList<>();
        }
        Arrays.sort(nums);
        int[] lengths = new int[nums.length];
        Arrays.fill(lengths, 1);
        int[] childs = new int[nums.length];
        Arrays.fill(childs, -1);
        int maxLength = 0;
        int maxLengthIndex = 0;
        for (int i = 0; i < nums.length; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && lengths[i] <= lengths[j]) {
                    lengths[i] = lengths[j] + 1;
                    childs[i] = j;
                    if (lengths[i] > maxLength) {
                        maxLength = lengths[i];
                        maxLengthIndex = i;
                    }
                }
            }
        }
        List<Integer> result = new ArrayList<>();
        int index = maxLengthIndex;
        while (index != -1) {
            result.add(nums[index]);
            index = childs[index];
        }
        return result;
    }
}