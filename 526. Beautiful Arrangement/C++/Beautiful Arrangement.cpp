class Solution {
public:
    int countArrangement(int N) {
        class Utils {
        public:
            int result = 0;

            void arrangement(int index, vector<bool> used) {
                if (index == used.size()) {
                    result++;
                    return;
                }
                for (int i = 1; i < used.size(); i++) {
                    if (!used[i] && (i % index == 0 || index % i == 0)) {
                        used[i] = true;
                        arrangement(index + 1, used);
                        used[i] = false;
                    }
                }
            }
        };
        Utils utils;
        vector<bool> temp(N + 1, false);
        utils.arrangement(1, temp);
        return utils.result;
    }
};