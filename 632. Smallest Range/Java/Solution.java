class Solution {
    public int[] smallestRange(List<List<Integer>> nums) {
        PriorityQueue<int[]> heap = new PriorityQueue<>(new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                return o1[0] - o2[0];
            }
        });
        int end = Integer.MIN_VALUE;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums.get(i).get(0);
            end = Math.max(end, num);
            heap.add(new int[] {num, i, 0});
        }
        int start = heap.peek()[0];
        int tempEnd = end;
        while (heap.size() == nums.size()) {
            int[] current = heap.poll();
            if (current[2] + 1 < nums.get(current[1]).size()) {
                tempEnd = Math.max(tempEnd, nums.get(current[1]).get(current[2] + 1));
                heap.add(new int[] {nums.get(current[1]).get(current[2] + 1), current[1], current[2] + 1});
                if (tempEnd - heap.peek()[0] < end - start) {
                    start = heap.peek()[0];
                    end = tempEnd;
                }
            }
        }
        return new int[] {start, end};
    }
}