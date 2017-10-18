class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string> &words) {
        vector<vector<int>> result;
        unordered_map<string, int> wordsSet;
        for (int i = 0; i < words.size(); i++) {
            wordsSet[words[i]] = i;
        }
        for (int i = 0; i < words.size(); i++) {
            string word = words[i];
            for (int j = 0; j <= word.length(); j++) {
                string left = word.substr(0, j);
                string right = word.substr(j);
                string leftReverse(left);
                reverse(leftReverse.rbegin(), leftReverse.rend());
                string rightReverse(right);
                reverse(rightReverse.rbegin(), rightReverse.rend());
                if (left == leftReverse && wordsSet.find(rightReverse) != wordsSet.end() &&
                    wordsSet[rightReverse] != i) {
                    result.push_back(vector<int> {wordsSet[rightReverse], i});
                }
                if (!right.empty() && right == rightReverse && wordsSet.find(leftReverse) != wordsSet.end() &&
                    wordsSet[leftReverse] != i) {
                    result.push_back(vector<int> {i, wordsSet[leftReverse]});
                }
            }
        }
        return result;
    }
};