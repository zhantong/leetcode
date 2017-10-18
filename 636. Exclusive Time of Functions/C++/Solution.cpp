class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string> &logs) {
        stack<int> sta;
        vector<int> result(n, 0);
        int current = 0;
        for (string &log : logs) {
            stringstream ss(log);
            string idStr;
            string status;
            string timeStr;
            getline(ss, idStr, ':');
            getline(ss, status, ':');
            getline(ss, timeStr, ':');
            int time = stoi(timeStr);
            if (status == "start") {
                if (!sta.empty()) {
                    result[sta.top()] += time - current;
                }
                current = time;
                sta.push(stoi(idStr));
            } else {
                result[sta.top()] += time - current + 1;
                current = time + 1;
                sta.pop();
            }
        }
        return result;
    }
};