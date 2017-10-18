/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    NestedInteger deserialize(string s) {
        if (s.empty()) {
            return NestedInteger();
        }
        if (s[0] != '[') {
            return NestedInteger(stoi(s));
        }
        int prevIndex = 0;
        int index = 0;
        stack<NestedInteger> sta;
        while (index < s.length()) {
            if (s[index] == '[') {
                sta.push(NestedInteger());
                prevIndex = index + 1;
            }
            if (s[index] == ',') {
                if (s[index - 1] != ']') {
                    int item = stoi(s.substr(prevIndex, index - prevIndex));
                    sta.top().add(NestedInteger(item));
                }
                prevIndex = index + 1;
            }
            if (s[index] == ']') {
                if (s[index - 1] != ']' && s[index - 1] != '[') {
                    int item = stoi(s.substr(prevIndex, index - prevIndex));
                    sta.top().add(NestedInteger(item));
                }
                NestedInteger temp = sta.top();
                sta.pop();
                if (sta.empty()) {
                    return temp;
                }
                sta.top().add(temp);
            }
            index++;
        }
        return NestedInteger();
    }
};