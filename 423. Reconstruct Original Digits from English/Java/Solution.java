public class Solution {
    public String originalDigits(String s) {
        int[] letters = new int['z' + 1];
        for (char letter : s.toCharArray()) {
            letters[letter]++;
        }
        int[] nums = new int[10];
        nums[0] = letters['z'];
        nums[2] = letters['w'];
        nums[4] = letters['u'];
        nums[6] = letters['x'];
        nums[8] = letters['g'];
        nums[1] = letters['o'] - nums[0] - nums[2] - nums[4];
        nums[3] = letters['h'] - nums[8];
        nums[5] = letters['f'] - nums[4];
        nums[7] = letters['v'] - nums[5];
        nums[9] = letters['i'] - nums[5] - nums[6] - nums[8];
        StringBuilder builder = new StringBuilder();
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < nums[i]; j++) {
                builder.append((char)('0' + i));
            }
        }
        return builder.toString();
    }
}