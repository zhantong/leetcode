class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
        queue<string> que;
        que.push(beginWord);
        unordered_set<string> set(wordList.begin(), wordList.end());
        int count = 0;
        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; i++) {
                string current = que.front();
                que.pop();
                if (current == endWord) {
                    return count + 1;
                }
                for (int j = 0; j < current.length(); j++) {
                    string temp = current;
                    for (char letter = 'a'; letter <= 'z'; letter++) {
                        temp[j] = letter;
                        if (set.find(temp) != set.end()) {
                            que.push(temp);
                            set.erase(temp);
                        }
                    }
                }
            }
            count++;
        }
        return 0;
    }
};