class Solution {
public:
    int findCircleNum(vector<vector<int>> &M) {
        class UnionFind {
        public:
            int count;
            vector<int> parent;
            vector<int> rank;

            UnionFind(int n) {
                count = n;
                rank = vector<int>(n, 0);
                parent = vector<int>(n);
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

            void uni(int a, int b) {
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
        };
        int length = M.size();
        UnionFind unionFind(length);
        for (int i = 0; i < length; i++) {
            for (int j = i + 1; j < length; j++) {
                if (M[i][j] == 1) {
                    unionFind.uni(i, j);
                }
            }
        }
        return unionFind.count;
    }
};