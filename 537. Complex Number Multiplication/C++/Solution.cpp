class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        int plusIndex = a.find("+");
        int aReal = stoi(a.substr(0, plusIndex));
        int aImage = stoi(a.substr(plusIndex + 1, a.length() - plusIndex - 2));
        plusIndex = b.find("+");
        int bReal = stoi(b.substr(0, plusIndex));
        int bImage = stoi(b.substr(plusIndex + 1, b.length() - plusIndex - 2));
        int real = aReal * bReal - aImage * bImage;
        int image = bReal * aImage + aReal * bImage;
        return to_string(real) + "+" + to_string(image) + "i";
    }
};