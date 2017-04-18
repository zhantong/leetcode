class Solution {
public:
    vector <string> fizzBuzz(int n) {
        vector <string> result;
        for (int i = 1; i <= n; i++) {
            string formatted = to_string(i);
            if (i % 3 == 0 && i % 5 == 0) {
                formatted = "FizzBuzz";
            } else if (i % 3 == 0) {
                formatted = "Fizz";
            } else if (i % 5 == 0) {
                formatted = "Buzz";
            }
            result.push_back(formatted);
        }
        return result;
    }
};