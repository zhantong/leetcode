class Solution {
public:
    int compareVersion(string version1, string version2) {
        class Utils {
        public:
            vector<string> split(const string &s, char delim) {
                vector<string> elems;
                stringstream ss;
                ss.str(s);
                string item;
                while (getline(ss, item, delim)) {
                    elems.push_back(item);
                }
                return elems;
            }
        };
        Utils utils;
        vector<string> tokens1 = utils.split(version1, '.');
        vector<string> tokens2 = utils.split(version2, '.');
        int length1 = tokens1.size();
        int length2 = tokens2.size();
        for (int i = 0; i < max(length1, length2); i++) {
            int inInt1 = i < length1 ? stoi(tokens1[i]) : 0;
            int inInt2 = i < length2 ? stoi(tokens2[i]) : 0;
            if (inInt1 > inInt2) {
                return 1;
            } else if (inInt1 < inInt2) {
                return -1;
            }
        }
        return 0;
    }
};