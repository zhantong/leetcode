class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char> sta;
        vector<int> counts(128, 0);
        for (char letter : s) {
            counts[letter]++;
        }
        vector<bool> exists(128, false);
        for (auto letter : s) {
            counts[letter]--;
            if (exists[letter]) {
                continue;
            }
            while (!sta.empty() && letter < sta.top() && counts[sta.top()] > 0) {
                int temp = sta.top();
                sta.pop();
                exists[temp] = false;
            }
            sta.push(letter);
            exists[letter] = true;
        }
        string result;
        while (!sta.empty()) {
            result = sta.top() + result;
            sta.pop();
        }
        return result;
    }
};