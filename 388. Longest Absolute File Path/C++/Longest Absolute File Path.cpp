class Solution {
public:
    int lengthLongestPath(string input) {
        stack<int> sta;
        int maxLength = 0;
        string item;
        istringstream ss(input);
        while (getline(ss, item)) {
            int countTabs = item.find_last_of('\t') + 1;
            while (sta.size() > countTabs) {
                sta.pop();
            }
            int length = (sta.empty() ? 0 : sta.top()) + item.size() - countTabs + 1;
            if (item.find('.') != string::npos) {
                maxLength = max(maxLength, length - 1);
            }
            sta.push(length);
        }
        return maxLength;
    }
};