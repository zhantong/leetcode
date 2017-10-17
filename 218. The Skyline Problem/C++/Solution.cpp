class Solution {
public:
    template<typename T>
    class custom_priority_queue : public std::priority_queue<T, std::vector<T>> {
    public:

        bool remove(const T &value) {
            auto it = std::find(this->c.begin(), this->c.end(), value);
            if (it != this->c.end()) {
                this->c.erase(it);
                std::make_heap(this->c.begin(), this->c.end(), this->comp);
                return true;
            } else {
                return false;
            }
        }
    };

    vector<pair<int, int>> getSkyline(vector<vector<int>> &buildings) {
        vector<pair<int, int>> heights;
        vector<pair<int, int>> result;
        for (auto &building:buildings) {
            heights.push_back(pair<int, int>(building[0], -building[2]));
            heights.push_back(pair<int, int>(building[1], building[2]));
        }
        sort(heights.begin(), heights.end());
        custom_priority_queue<int> priorityQueue;
        priorityQueue.push(0);
        int prev = 0;
        for (auto &height:heights) {
            if (height.second < 0) {
                priorityQueue.push(-height.second);
            } else {
                priorityQueue.remove(height.second);
            }
            int current = priorityQueue.top();
            if (current != prev) {
                result.push_back(pair<int, int>(height.first, current));
                prev = current;
            }
        }
        return result;
    }
};