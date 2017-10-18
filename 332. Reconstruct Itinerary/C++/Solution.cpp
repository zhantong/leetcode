class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        class Utils {
        public:
            bool dfs(unordered_map<string, vector<string>> &travels, vector<string> &result, string start, int length) {
                result.push_back(start);
                if (travels.find(start) == travels.end() || travels[start].empty()) {
                    if (result.size() == length) {
                        return true;
                    }
                    result.pop_back();
                    return false;
                }
                for (int i = 0; i < travels[start].size(); i++) {
                    string newStart = travels[start][i];
                    travels[start].erase(travels[start].begin() + i);
                    if (dfs(travels, result, newStart, length)) {
                        return true;
                    }
                    travels[start].insert(travels[start].begin() + i, newStart);
                }
                result.pop_back();
                return false;
            }
        };
        unordered_map<string, vector<string>> travels;
        for (auto &ticket : tickets) {
            travels[ticket.first].push_back(ticket.second);
        }
        for (auto &item : travels) {
            sort(item.second.begin(), item.second.end());
        }
        string start = "JFK";
        vector<string> result;
        Utils utils;
        utils.dfs(travels, result, start, tickets.size() + 1);
        return result;
    }
};