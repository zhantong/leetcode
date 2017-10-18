class Solution {
public:
    unordered_map<string, vector<int>> memory;
    vector<int> diffWaysToCompute(string input) {
        if (memory.find(input) != memory.end()) {
            return memory[input];
        }
        vector<int> result;
        for (int i = 0; i < input.size(); i++) {
            char letter = input[i];
            if (letter == '+' || letter == '-' || letter == '*') {
                vector<int> leftVals = diffWaysToCompute(input.substr(0, i));
                vector<int> rightVals = diffWaysToCompute(input.substr(i + 1));
                for (auto left : leftVals) {
                    for (auto right : rightVals) {
                        int current = 0;
                        switch (letter) {
                        case '+':
                            current = left + right;
                            break;
                        case '-':
                            current = left - right;
                            break;
                        case '*':
                            current = left * right;
                            break;
                        }
                        result.push_back(current);
                    }
                }
            }
        }
        if (result.empty()) {
            result.push_back(stoi(input));
        }
        memory[input] = result;
        return result;
    }
};