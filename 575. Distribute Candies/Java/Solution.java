class Solution {
    public int distributeCandies(int[] candies) {
        Set<Integer> nums = new HashSet<>();
        for (int candy : candies) {
            nums.add(candy);
        }
        int numNums = nums.size();
        int numTarget = candies.length / 2;
        return numNums >= numTarget ? numTarget : numNums;
    }
}