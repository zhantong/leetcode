class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double> &values, vector<pair<string, string>> queries) {
        class Utils {
        public:
            double dfs(string start, string end, unordered_map<string, vector<string>> &graph,
                       unordered_map<string, vector<double>> &graphValue, unordered_set<string> current,
                       double currentValue) {
                if (current.find(start) != current.end() || graph.find(start) == graph.end()) {
                    return 0.0;
                }
                if (start == end) {
                    return currentValue;
                }
                current.insert(start);
                vector<string> nodes = graph[start];
                vector<double> values = graphValue[start];
                for (int i = 0; i < nodes.size(); i++) {
                    double got = dfs(nodes[i], end, graph, graphValue, current, currentValue * values[i]);
                    if (got != 0.0) {
                        current.erase(start);
                        return got;
                    }
                }
                current.erase(start);
                return 0.0;
            }
        };
        vector<double> result(queries.size());
        unordered_map<string, vector<string>> graph;
        unordered_map<string, vector<double>> graphValue;
        for (int i = 0; i < equations.size(); i++) {
            pair<string, string> equation = equations[i];
            double value = values[i];
            graph[equation.first].push_back(equation.second);
            graphValue[equation.first].push_back(value);
            graph[equation.second].push_back(equation.first);
            graphValue[equation.second].push_back(1.0 / value);
        }
        Utils utils;
        for (int i = 0; i < queries.size(); i++) {
            pair<string, string> query = queries[i];
            unordered_set<string> temp;
            result[i] = utils.dfs(query.first, query.second, graph, graphValue, temp, 1.0);
            if (result[i] == 0.0) {
                result[i] = -1.0;
            }
        }
        return result;
    }
};