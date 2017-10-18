class Solution {
    public double[] medianSlidingWindow(int[] nums, int k) {
        PriorityQueue<int[]> minHeap = new PriorityQueue<>(new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                if (o1[0] == o2[0]) {
                    return Integer.compare(o1[1], o2[1]);
                }
                return Integer.compare(o1[0], o2[0]);
            }
        });
        PriorityQueue<int[]> maxHeap = new PriorityQueue<>(new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                if (o1[0] == o2[0]) {
                    return Integer.compare(o1[1], o2[1]);
                }
                return Integer.compare(o2[0], o1[0]);
            }
        });
        List<Double> result = new ArrayList<>();
        for (int i = 0; i < k; i++) {
            maxHeap.add(new int[] {nums[i], i});
        }
        for (int i = 0; i < (k - k / 2); i++) {
            minHeap.add(new int[] {maxHeap.peek()[0], maxHeap.peek()[1]});
            maxHeap.poll();
        }
        for (int i = k; i < nums.length; i++) {
            int num = nums[i];
            result.add(k % 2 == 0 ? ((long) minHeap.peek()[0] + maxHeap.peek()[0]) / 2.0 : minHeap.peek()[0] / 1.0);
            if (num >= minHeap.peek()[0]) {
                minHeap.add(new int[] {num, i});
                if (nums[i - k] <= minHeap.peek()[0]) {
                    maxHeap.add(new int[] {minHeap.peek()[0], minHeap.peek()[1]});
                    minHeap.poll();
                }
            } else {
                maxHeap.add(new int[] {num, i});
                if (nums[i - k] >= minHeap.peek()[0]) {
                    minHeap.add(new int[] {maxHeap.peek()[0], maxHeap.peek()[1]});
                    maxHeap.poll();
                }
            }
            while (!maxHeap.isEmpty() && maxHeap.peek()[1] <= i - k) {
                maxHeap.poll();
            }
            while (!minHeap.isEmpty() && minHeap.peek()[1] <= i - k) {
                minHeap.poll();
            }
        }
        result.add(k % 2 == 0 ? ((long) minHeap.peek()[0] + maxHeap.peek()[0]) / 2.0 : minHeap.peek()[0] / 1.0);
        double[] res = new double[result.size()];
        for (int i = 0; i < res.length; i++) {
            res[i] = result.get(i);
        }
        return res;
    }
}