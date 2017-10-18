class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges) {
        class UnionFind {
            int count;
            vector<int> parent;
            vector<int> rank;
        public:
            UnionFind(int n) {
                count = n;
                parent = vector<int>(n);
                for (int i = 0; i < parent.size(); i++) {
                    parent[i] = i;
                }
                rank = vector<int>(n);
            }

            int find(int num) {
                if (num != parent[num]) {
                    parent[num] = find(parent[num]);
                }
                return parent[num];
            }

            void _union(int a, int b) {
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
        UnionFind unionFind(edges.size() + 1);
        for (auto &edge : edges) {
            if (unionFind.find(edge[0]) == unionFind.find(edge[1])) {
                return edge;
            }
            unionFind._union(edge[0], edge[1]);
        }
        return vector<int>();
    }
};