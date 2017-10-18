class Solution {
    public String nextClosestTime(String time) {
        char[] times = time.toCharArray();
        int[] nums = new int[] {times[0] - '0', times[1] - '0', times[3] - '0', times[4] - '0'};
        int[] greater = new int[10];
        Arrays.fill(greater, -1);
        int minNum = Integer.MAX_VALUE;
        for (int num : nums) {
            minNum = Math.min(minNum, num);
            if (num > 0) {
                greater[num - 1] = num;
            }
        }
        int current = -1;
        for (int i = greater.length - 1; i >= 0; i--) {
            if (greater[i] != -1) {
                current = greater[i];
            }
            greater[i] = current;
        }
        char minTime = (char)('0' + minNum);
        if (greater[nums[3]] != -1) {
            times[4] = (char)('0' + greater[nums[3]]);
        } else {
            times[4] = minTime;
            if (greater[nums[2]] != -1 && greater[nums[2]] < 6) {
                times[3] = (char)('0' + greater[nums[2]]);
            } else {
                times[3] = minTime;
                if (greater[nums[1]] != -1 && (nums[0] < 2 || greater[nums[1]] < 4)) {
                    times[1] = (char)('0' + greater[nums[1]]);
                } else {
                    times[1] = minTime;
                    if (greater[nums[0]] != -1 && greater[nums[0]] < 2) {
                        times[0] = (char)('0' + greater[nums[0]]);
                    } else {
                        times[0] = minTime;
                    }
                }
            }
        }
        return String.valueOf(times);
    }
}