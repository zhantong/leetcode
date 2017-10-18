class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string> &paths) {
        unordered_map<string, vector<string>> memory;
        for (auto &path : paths) {
            stringstream ss(path);
            string base;
            string file;
            getline(ss, base, ' ');
            while (getline(ss, file, ' ')) {
                int leftParentIndex = file.find('(');
                memory[file.substr(leftParentIndex + 1)].push_back(base + '/' + file.substr(0, leftParentIndex));
            }
        }
        vector<vector<string>> result;
        for (auto pair : memory) {
            if (pair.second.size() > 1) {
                result.push_back(pair.second);
            }
        }
        return result;
    }
};