class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stack;
        istringstream iss(path);
        string item;
        while (getline(iss, item, '/')) {
            if (item.empty() || item == ".") {
                continue;
            }
            if (item == "..") {
                if (!stack.empty()) {
                    stack.pop_back();
                }
            } else {
                stack.push_back(item);
            }
        }
        string result = "";
        for (string &item : stack) {
            result += "/";
            result += item;
        }
        if (result.length() == 0) {
            result += "/";
        }
        return result;
    }
};