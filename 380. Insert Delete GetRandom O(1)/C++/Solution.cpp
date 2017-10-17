class RandomizedSet {
public:
    unordered_map<int, int> valDict;
    vector<int> vals;

    /** Initialize your data structure here. */
    RandomizedSet() {

    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (valDict.find(val) != valDict.end()) {
            return false;
        }
        valDict[val] = vals.size();
        vals.push_back(val);
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (valDict.find(val) == valDict.end()) {
            return false;
        }
        int index = valDict[val];
        vals[index] = vals.back();
        valDict[vals[index]] = index;
        valDict.erase(val);
        vals.pop_back();
        return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
        return vals[rand() % vals.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */