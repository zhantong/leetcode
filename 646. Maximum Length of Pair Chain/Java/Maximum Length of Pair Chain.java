class Solution {
    public int findLongestChain(int[][] pairs) {
        Arrays.sort(pairs, new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                return o1[1] - o2[1];
            }
        });
        int result = 1;
        int current = pairs[0][1];
        for (int[] pair : pairs) {
            if (pair[0] > current) {
                current = pair[1];
                result++;
            }
        }
        return result;
    }
}