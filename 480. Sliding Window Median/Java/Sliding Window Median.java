public class Solution {
    public double[] medianSlidingWindow(int[] nums, int k) {
        class Utils {
            PriorityQueue<Long> minHeap;
            PriorityQueue<Long> maxHeap;

            public Utils() {
                minHeap = new PriorityQueue<>();
                maxHeap = new PriorityQueue<>();
            }

            double getMedian() {
                if (maxHeap.isEmpty() && minHeap.isEmpty()) {
                    return 0;
                }
                if (maxHeap.size() == minHeap.size()) {
                    return ((double) minHeap.peek() - maxHeap.peek()) / 2.0;
                }
                return (double) minHeap.peek();
            }

            void add(int num) {
                if (num < getMedian()) {
                    maxHeap.add(-(long) num);
                } else {
                    minHeap.add((long) num);
                }
                if (maxHeap.size() > minHeap.size()) {
                    minHeap.add(-maxHeap.poll());
                } else if (minHeap.size() > maxHeap.size() + 1) {
                    maxHeap.add(-minHeap.poll());
                }
            }

            void remove(int num) {
                if (num < getMedian()) {
                    maxHeap.remove(-(long) num);
                } else {
                    minHeap.remove((long) num);
                }
                if (maxHeap.size() > minHeap.size()) {
                    minHeap.add(-maxHeap.poll());
                } else if (minHeap.size() > maxHeap.size() + 1) {
                    maxHeap.add(-minHeap.poll());
                }
            }
        }
        double[] result = new double[nums.length - k + 1];
        Utils utils = new Utils();
        for (int i = 0; i <= nums.length; i++) {
            if (i >= k) {
                result[i - k] = utils.getMedian();
                utils.remove(nums[i - k]);
            }
            if (i < nums.length) {
                utils.add(nums[i]);
            }
        }
        return result;
    }
}