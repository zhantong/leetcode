public class Solution {
    public List<int[]> getSkyline(int[][] buildings) {
        List<int[]> heights = new ArrayList<>();
        List<int[]> result = new ArrayList<>();
        for (int[] building : buildings) {
            heights.add(new int[]{building[0], -building[2]});
            heights.add(new int[]{building[1], building[2]});
        }
        Collections.sort(heights, new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                if (o1[0] != o2[0]) {
                    return o1[0] - o2[0];
                }
                return o1[1] - o2[1];
            }
        });
        PriorityQueue<Integer> priorityQueue = new PriorityQueue<>(new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                return o2 - o1;
            }
        });
        priorityQueue.offer(0);
        int prev = 0;
        for (int[] height : heights) {
            if (height[1] < 0) {
                priorityQueue.offer(-height[1]);
            } else {
                priorityQueue.remove(height[1]);
            }
            int current = priorityQueue.peek();
            if (current != prev) {
                result.add(new int[]{height[0], current});
                prev = current;
            }
        }
        return result;
    }
}