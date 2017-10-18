class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>> &edges) {
        vector<unordered_set<int>> graph(n);
        for (const auto &edge : edges) {
            graph[edge.first].insert(edge.second);
            graph[edge.second].insert(edge.first);
        }
        unordered_set<int> remain;
        for (int i = 0; i < n; i++) {
            remain.insert(i);
        }
        unordered_set<int> toDelete;
        for (int i = 0; i < n; i++) {
            if (graph[i].size() == 1) {
                toDelete.insert(i);
            }
        }
        while (remain.size() > 2) {
            unordered_set<int> temp;
            for (int item : toDelete) {
                remain.erase(item);
                for (int neighbor : graph[item]) {
                    graph[neighbor].erase(item);
                    if (graph[neighbor].size() == 1 && remain.find(neighbor) != remain.end()) {
                        temp.insert(neighbor);
                    }
                }
            }
            toDelete = temp;
        }
        return vector<int>(remain.begin(), remain.end());
    }
};