class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        int length = s.length();
        int i = length - 2;
        while (i >= 0) {
            if (s[i] < s[i + 1]) {
                break;
            }
            i--;
        }
        if (i == -1) {
            return -1;
        }
        int j = i + 1;
        char smallest = '9';
        int smallestIndex = -1;
        while (j < length) {
            if (s[j] > s[i] && s[j] <= smallest) {
                smallest = s[j];
                smallestIndex = j;
            }
            j++;
        }
        char temp = s[i];
        s[i] = s[smallestIndex];
        s[smallestIndex] = temp;
        sort(s.begin() + i + 1, s.end());
        long result = stol(s);
        if (result > INT_MAX) {
            return -1;
        }
        return (int) result;
    }
};