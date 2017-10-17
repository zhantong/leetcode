class Solution {
public:
    bool isValidSerialization(string preorder) {
        int degree = -1;
        string node;
        stringstream ss(preorder);
        while (getline(ss, node, ',')) {
            degree++;
            if (degree > 0) {
                return false;
            }
            if (node != "#") {
                degree -= 2;
            }
        }
        return degree == 0;
    }
};