class Solution {
public:
    bool isValid(string s) {
        stack<char> stac;
        for (char item : s) {
            if (item == '(' || item == '{' || item == '[') {
                stac.push(item);
            } else if (stac.empty() && (item == ')' || item == '}' || item == ']')) {
                return false;
            } else if (item == ')') {
                if (stac.top() == '(') {
                    stac.pop();
                } else {
                    return false;
                }
            } else if (item == '}') {
                if (stac.top() == '{') {
                    stac.pop();
                } else {
                    return false;
                }
            } else if (item == ']') {
                if (stac.top() == '[') {
                    stac.pop();
                } else {
                    return false;
                }
            }
        }
        return stac.empty();
    }
};