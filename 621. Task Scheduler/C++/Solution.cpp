class Solution {
public:
    int leastInterval(vector<char> &tasks, int n) {
        int letters[26] = {0};
        for (char letter : tasks) {
            letters[letter - 'A']++;
        }
        sort(begin(letters), end(letters));
        int i = 25;
        while (letters[i] == letters[25]) {
            i--;
        }
        return max((int)tasks.size(), (letters[25] - 1) * (n + 1) + 25 - i);
    }
};