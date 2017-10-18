class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> sta;
        for (string &token : tokens) {
            if (token == "+") {
                int a = sta.top();
                sta.pop();
                int b = sta.top();
                sta.pop();
                sta.push(b + a);
            } else if (token == "-") {
                int a = sta.top();
                sta.pop();
                int b = sta.top();
                sta.pop();
                sta.push(b - a);
            } else if (token == "*") {
                int a = sta.top();
                sta.pop();
                int b = sta.top();
                sta.pop();
                sta.push(b * a);
            } else if (token == "/") {
                int a = sta.top();
                sta.pop();
                int b = sta.top();
                sta.pop();
                sta.push(b / a);
            } else {
                sta.push(stoi(token));
            }
        }
        return sta.top();
    }
};