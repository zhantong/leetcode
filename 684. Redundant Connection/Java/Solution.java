class Solution {
    public int[] findRedundantConnection(int[][] edges) {
        class UnionFind {
            int count;
            int[] parent;
            int[] rank;

            public UnionFind(int n) {
                count = n;
                parent = new int[n];
                for (int i = 0; i < parent.length; i++) {
                    parent[i] = i;
                }
                rank = new int[n];
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
        UnionFind unionFind = new UnionFind(edges.length + 1);
        for (int[] edge : edges) {
            if (unionFind.find(edge[0]) == unionFind.find(edge[1])) {
                return edge;
            }
            unionFind.union(edge[0], edge[1]);
        }
        return null;
    }
}