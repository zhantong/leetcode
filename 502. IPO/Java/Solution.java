public class Solution {
    public int findMaximizedCapital(int k, int W, int[] Profits, int[] Capital) {
        PriorityQueue<int[]> pqCapical = new PriorityQueue<>(new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                return o1[0] - o2[0];
            }
        });
        PriorityQueue<Integer> pqProfit = new PriorityQueue<>();
        for (int i = 0; i < Profits.length; i++) {
            pqCapical.add(new int[] {Capital[i], Profits[i]});
        }
        for (int i = 0; i < k; i++) {
            while (!pqCapical.isEmpty() && pqCapical.peek()[0] <= W) {
                int[] item = pqCapical.poll();
                pqProfit.add(-item[1]);
            }
            if (pqProfit.isEmpty()) {
                break;
            }
            W += -pqProfit.poll();
        }
        return W;
    }
}