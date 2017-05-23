public class Solution {
    public int findCircleNum(int[][] M) {
        class UnionFind {
            int count;
            int[] parent;
            int[] rank;

            public UnionFind(int n) {
                count = n;
                rank = new int[n];
                parent = new int[n];
                for (int i = 0; i < n; i++) {
                    parent[i] = i;
                }
            }

            int find(int num) {
                if (num != parent[num]) {
                    parent[num] = find(parent[num]);
                }
                return parent[num];
            }

            void union(int a, int b) {
                int parentA = find(a);
                int parentB = find(b);
                if (parentA == parentB) {
                    return;
                }
                if (rank[parentA] > rank[parentB]) {
                    parent[parentB] = parentA;
                } else {
                    parent[parentA] = parentB;
                    if (rank[parentA] == rank[parentB]) {
                        rank[parentB]++;
                    }
                }
                count--;
            }
        }
        int length = M.length;
        UnionFind unionFind = new UnionFind(length);
        for (int i = 0; i < length; i++) {
            for (int j = i + 1; j < length; j++) {
                if (M[i][j] == 1) {
                    unionFind.union(i, j);
                }
            }
        }
        return unionFind.count;
    }
}