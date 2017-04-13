class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) {
            return "0";
        }
        string result;
        if ((numerator > 0) != (denominator > 0)) {
            result = "-";
        }
        long num = abs((long) numerator);
        long den = abs((long) denominator);
        result += to_string(num / den);
        num %= den;
        if (num == 0) {
            return result;
        }
        result += ".";
        unordered_map<long, int> memory;
        memory[num] = result.length();
        while (num != 0) {
            num *= 10;
            result += to_string(num / den);
            num %= den;
            if (memory.find(num) != memory.end()) {
                int startIndex = memory[num];
                result.insert(startIndex, "(");
                result += ")";
                break;
            }
            memory[num] = result.length();
        }
        return result;
    }
};