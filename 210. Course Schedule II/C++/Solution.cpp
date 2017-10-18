class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>> &prerequisites) {
        class Utils {
        public:
            bool dfs(unordered_map<int, vector<int>> &graph, int i, vector<int> &order, vector<bool> &visiting,
                     vector<bool> &visited) {
                visiting[i] = true;
                visited[i] = true;
                for (int neighbor : graph[i]) {
                    if (visiting[neighbor]) {
                        return false;
                    }
                    if (!visited[neighbor]) {
                        if (!dfs(graph, neighbor, order, visiting, visited)) {
                            return false;
                        }
                    }
                }
                order.push_back(i);
                visiting[i] = false;
                return true;
            }
        };
        vector<int> order;
        vector<bool> visiting(numCourses, false);
        vector<bool> visited(numCourses, false);
        unordered_map<int, vector<int>> graph;
        for (auto &line : prerequisites) {
            graph[line.second].push_back(line.first);
        }
        Utils utils;
        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                if (!utils.dfs(graph, i, order, visiting, visited)) {
                    return vector<int>();
                }
            }
        }
        reverse(order.rbegin(), order.rend());
        return order;
    }
};