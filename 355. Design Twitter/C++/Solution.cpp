class Twitter {
public:
    unordered_map<int, vector<pair<int, int>>> tweets;
    unordered_map<int, unordered_set<int>> follows;
    int time = 0;

    /** Initialize your data structure here. */
    class Order {
    public:
        bool operator()(const pair<int, int> &a, const pair<int, int> &b) {
            return b.first > a.first;
        }
    };

    Twitter() {

    }

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        if (tweets.find(userId) == tweets.end()) {
            tweets[userId] = vector<pair<int, int>>();
            follows[userId] = unordered_set<int>();
            follows[userId].insert(userId);
        }
        tweets[userId].insert(tweets[userId].begin(), pair<int, int>(time, tweetId));
        time++;
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> result;
        if (tweets.find(userId) == tweets.end()) {
            return result;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, Order> heap;
        for (auto &id : follows[userId]) {
            if (tweets.find(id) != tweets.end()) {
                for (auto &tweet : tweets[id]) {
                    heap.push(tweet);
                }
            }
        }
        while (!heap.empty() && result.size() < 10) {
            result.push_back(heap.top().second);
            heap.pop();
        }
        return result;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if (followeeId == followerId) {
            return;
        }
        if (follows.find(followerId) == follows.end()) {
            tweets[followerId] = vector<pair<int, int>>();
            follows[followerId] = unordered_set<int>();
            follows[followerId].insert(followerId);
        }
        follows[followerId].insert(followeeId);
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if (follows.find(followerId) == follows.end() ||
            follows[followerId].find(followeeId) == follows[followerId].end() || followerId == followeeId) {
            return;
        }
        follows[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */