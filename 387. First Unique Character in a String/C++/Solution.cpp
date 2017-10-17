class Solution {
public:
    int firstUniqChar(string s) {
        map<char, int> countMap;
        for (char item:s) {
            if (countMap.find(item) == countMap.end()) {
                countMap[item] = 0;
            }
            countMap[item]++;
        }
        int index = 0;
        for (char item:s) {
            if (countMap[item] == 1) {
                return index;
            }
            index++;
        }
        return -1;
    }
};