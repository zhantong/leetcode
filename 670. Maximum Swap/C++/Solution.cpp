class Solution {
public:
    int maximumSwap(int num) {
        string numStr = to_string(num);
        unordered_map<char, int> lastIndex;
        for (int i = 0; i < numStr.size(); i++) {
            lastIndex[numStr[i]] = i;
        }
        for (int i = 0; i < numStr.size(); i++) {
            for (char digit = '9'; digit > numStr[i]; digit--) {
                if (lastIndex.count(digit) && lastIndex[digit] > i) {
                    char temp = numStr[i];
                    numStr[i] = numStr[lastIndex[digit]];
                    numStr[lastIndex[digit]] = temp;
                    return stoi(numStr);
                }
            }
        }
        return num;
    }
};