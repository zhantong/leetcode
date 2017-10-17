public class RandomizedSet {
    Map<Integer, Integer> valDict;
    List<Integer> vals;
    Random random;

    /**
     * Initialize your data structure here.
     */
    public RandomizedSet() {
        valDict = new HashMap<>();
        vals = new ArrayList<>();
        random = new Random();
    }

    /**
     * Inserts a value to the set. Returns true if the set did not already contain the specified element.
     */
    public boolean insert(int val) {
        if (valDict.containsKey(val)) {
            return false;
        }
        valDict.put(val, vals.size());
        vals.add(val);
        return true;
    }

    /**
     * Removes a value from the set. Returns true if the set contained the specified element.
     */
    public boolean remove(int val) {
        if (!valDict.containsKey(val)) {
            return false;
        }
        int index = valDict.get(val);
        vals.set(index, vals.get(vals.size() - 1));
        valDict.put(vals.get(index), index);
        valDict.remove(val);
        vals.remove(vals.size() - 1);
        return true;
    }

    /**
     * Get a random element from the set.
     */
    public int getRandom() {
        return vals.get(random.nextInt(vals.size()));
    }
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * boolean param_1 = obj.insert(val);
 * boolean param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */