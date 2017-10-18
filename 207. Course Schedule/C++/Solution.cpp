class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>> &prerequisites) {
        vector<unordered_set<int>> graph(numCourses);
        vector<int> inDegrees(numCourses);
        for (const auto &prerequisite : prerequisites) {
            int before = prerequisite.second;
            int after = prerequisite.first;
            if (graph[before].find(after) == graph[before].end()) {
                inDegrees[after]++;
                graph[before].insert(after);
            }
        }
        queue<int> queue;
        for (int i = 0; i < numCourses; i++) {
            if (inDegrees[i] == 0) {
                queue.push(i);
            }
        }
        int count = 0;
        while (!queue.empty()) {
            int current = queue.front();
            queue.pop();
            count += 1;
            for (int i : graph[current]) {
                inDegrees[i]--;
                if (inDegrees[i] == 0) {
                    queue.push(i);
                }
            }
        }
        return count == numCourses;
    }
};