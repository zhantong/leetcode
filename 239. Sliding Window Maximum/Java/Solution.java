public class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        Deque<Integer> que = new ArrayDeque<>();
        List<Integer> resultList = new ArrayList<>();
        for (int i = 0; i < nums.length; i++) {
            if (!que.isEmpty() && que.peekFirst() == i - k) {
                que.pollFirst();
            }
            while (!que.isEmpty() && nums[que.peekLast()] < nums[i]) {
                que.pollLast();
            }
            que.addLast(i);
            if (i + 1 >= k) {
                resultList.add(nums[que.peekFirst()]);
            }
        }
        int[] result = new int[resultList.size()];
        for (int i = 0; i < result.length; i++) {
            result[i] = resultList.get(i);
        }
        return result;
    }
}