class Solution {
public:
    int shoppingOffers(vector<int> &price, vector<vector<int>> &special, vector<int> &needs) {
        class Utils {
        public:
            string toKey(vector<int> &array) {
                string builder = "";
                for (int item : array) {
                    builder += to_string(item);
                }
                return builder;
            }

            vector<int> toArray(string key) {
                vector<int> array;
                for (auto letter : key) {
                    array.push_back(letter - '0');
                }
                return array;
            }

            int trace(vector<int> &prices, vector<vector<int>> &specials, string needsKey,
                      unordered_map<string, int> &memory) {
                if (memory.count(needsKey)) {
                    return memory[needsKey];
                }
                vector<int> needsArray = toArray(needsKey);
                int result = 0;
                for (int i = 0; i < prices.size(); i++) {
                    result += prices[i] * needsArray[i];
                }
                for (vector<int> &special : specials) {
                    vector<int> newNeedsArray = needsArray;
                    bool canFit = true;
                    for (int i = 0; i < needsArray.size(); i++) {
                        if (needsArray[i] < special[i]) {
                            canFit = false;
                            break;
                        }
                        newNeedsArray[i] -= special[i];
                    }
                    if (canFit) {
                        result = min(result, special.back() + trace(prices, specials, toKey(newNeedsArray), memory));
                    }
                }
                memory[needsKey] = result;
                return result;
            }
        };
        Utils utils;
        unordered_map<string, int> memory;
        return utils.trace(price, special, utils.toKey(needs), memory);
    }
};