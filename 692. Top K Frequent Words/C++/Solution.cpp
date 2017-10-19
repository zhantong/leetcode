class Solution {
public:
    vector<string> topKFrequent(vector<string> &words, int k) {
        unordered_map<string, int> counts;
        for (auto &word : words) {
            counts[word]++;
        }
        auto comp = [&](const pair<string, int> &a, const pair<string, int> &b) {
            return a.second > b.second || (a.second == b.second && a.first < b.first);
        };
        typedef priority_queue< pair<string, int>, vector<pair<string, int>>, decltype(comp) > my_priority_queue;
        my_priority_queue  heap(comp);
        for (auto &item : counts) {
            heap.push(pair<string, int>(item.first, item.second));
            if (heap.size() > k) {
                heap.pop();
            }
        }
        vector<string> result;
        for (int i = 0; i < k; i++) {
            if (heap.empty()) {
                break;
            }
            result.push_back(heap.top().first);
            heap.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};