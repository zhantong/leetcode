class RandomizedCollection {
public:
    vector<int> nums;
    unordered_map<int, unordered_set<int>> memory;

    /** Initialize your data structure here. */
    RandomizedCollection() {

    }

    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        bool isAlreadyIn = true;
        if (memory.find(val) == memory.end()) {
            isAlreadyIn = false;
            memory[val] = unordered_set<int>();
        }
        memory[val].insert(nums.size());
        nums.push_back(val);
        return !isAlreadyIn;
    }

    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if (memory.find(val) == memory.end()) {
            return false;
        }
        int lastIndex = nums.size() - 1;
        if (memory[val].find(lastIndex) == memory[val].end()) {
            int currentIndex = *(memory[val].begin());
            int lastValue = nums[nums.size() - 1];
            memory[lastValue].erase(lastIndex);
            memory[lastValue].insert(currentIndex);
            memory[val].erase(currentIndex);
            nums[currentIndex] = lastValue;
        } else {
            memory[val].erase(lastIndex);
        }
        if (memory[val].empty()) {
            memory.erase(val);
        }
        nums.pop_back();
        return true;
    }

    /** Get a random element from the collection. */
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};
/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */