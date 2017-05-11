public class Solution {
    public int kthSmallest(int[][] matrix, int k) {
        class Item {
            int value;
            int i;
            int j;

            public Item(int value, int i, int j) {
                this.value = value;
                this.i = i;
                this.j = j;
            }
        }
        int m = matrix.length;
        int n = matrix[0].length;
        PriorityQueue<Item> minHeap = new PriorityQueue<>(new Comparator<Item>() {
            @Override
            public int compare(Item o1, Item o2) {
                return o1.value - o2.value;
            }
        });
        for (int j = 0; j < n; j++) {
            minHeap.add(new Item(matrix[0][j], 0, j));
        }
        while (!minHeap.isEmpty()) {
            Item item = minHeap.poll();
            if (item.i < m - 1) {
                minHeap.add(new Item(matrix[item.i + 1][item.j], item.i + 1, item.j));
            }
            k--;
            if (k == 0) {
                return item.value;
            }
        }
        return 0;
    }
}