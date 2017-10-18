public class Solution {
    public List<int[]> kSmallestPairs(int[] nums1, int[] nums2, int k) {
        class Pair implements Comparator<Pair> {
            int sum;
            int i;
            int j;

            public Pair(int sum, int i, int j) {
                this.sum = sum;
                this.i = i;
                this.j = j;
            }

            @Override
            public int compare(Pair o1, Pair o2) {
                return o1.sum - o2.sum;
            }
        }
        if (nums1.length == 0 || nums2.length == 0 || k == 0) {
            return new ArrayList<>();
        }
        List<int[]> result = new ArrayList<>();
        PriorityQueue<Pair> queue = new PriorityQueue<Pair>(new Pair(0, 0, 0));
        queue.add(new Pair(nums1[0] + nums2[0], 0, 0));
        while (!queue.isEmpty() && result.size() < k) {
            Pair pair = queue.poll();
            result.add(new int[] {nums1[pair.i], nums2[pair.j]});
            if (pair.j < nums2.length - 1) {
                queue.add(new Pair(nums1[pair.i] + nums2[pair.j + 1], pair.i, pair.j + 1));
            }
            if (pair.j == 0 && pair.i < nums1.length - 1) {
                queue.add(new Pair(nums1[pair.i + 1] + nums2[pair.j], pair.i + 1, pair.j));
            }
        }
        return result;
    }
}