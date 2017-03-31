class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> factor(n);
        factor[0] = 1;
        for (int i = 1; i < n; i++) {
            factor[i] = factor[i - 1] * i;
        }
        string result = "";
        k--;
        vector<int> numbers;
        for (int i = 1; i < 10; i++) {
            numbers.push_back(i);
        }
        for (int i = n - 1; i >= 0; i--) {
            int number = k / factor[i];
            k %= factor[i];
            result += (to_string(numbers[number]));
            numbers.erase(numbers.begin() + number);
        }
        return result;
    }
};