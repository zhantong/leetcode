class Solution {
public:
    string numberToWords(int num) {
        class Utils {
        public:
            string convert(int num) {
                vector<string> LESS_THAN_20{"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine",
                                            "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen",
                                            "Seventeen", "Eighteen", "Nineteen"};
                vector<string> TENS{"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty",
                                    "Ninety"};
                if (num == 0) {
                    return "";
                }
                if (num < 20) {
                    return LESS_THAN_20[num] + " ";
                }
                if (num < 100) {
                    return TENS[num / 10] + " " + convert(num % 10);
                }
                return LESS_THAN_20[num / 100] + " Hundred " + convert(num % 100);
            }
        };
        vector<string> THOUSANDS{"", "Thousand", "Million", "Billion"};
        if (num == 0) {
            return "Zero";
        }
        int i = 0;
        string result = "";
        Utils utils;
        while (num != 0) {
            int slice = num % 1000;
            if (slice != 0) {
                result = utils.convert(slice) + THOUSANDS[i] + " " + result;
            }
            num /= 1000;
            i++;
        }
        while (result.back() == ' ') {
            result.pop_back();
        }
        return result;
    }
};