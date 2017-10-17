public class Twitter {
    Map<Integer, List<Tweet>> tweets;
    Map<Integer, Set<Integer>> follows;
    int time = 0;

    class Tweet {
        int time;
        int id;

        public Tweet(int time, int id) {
            this.time = time;
            this.id = id;
        }
    }

    /**
     * Initialize your data structure here.
     */
    public Twitter() {
        tweets = new HashMap<>();
        follows = new HashMap<>();
    }

    /**
     * Compose a new tweet.
     */
    public void postTweet(int userId, int tweetId) {
        if (!tweets.containsKey(userId)) {
            tweets.put(userId, new LinkedList<>());
            follows.put(userId, new HashSet<>());
            follows.get(userId).add(userId);
        }
        tweets.get(userId).add(0, new Tweet(time, tweetId));
        time++;
    }

    /**
     * Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent.
     */
    public List<Integer> getNewsFeed(int userId) {
        if (!tweets.containsKey(userId)) {
            return new ArrayList<>();
        }
        PriorityQueue<Tweet> heap = new PriorityQueue<>(new Comparator<Tweet>() {
            @Override
            public int compare(Tweet o1, Tweet o2) {
                return o2.time - o1.time;
            }
        });
        for (int id : follows.get(userId)) {
            if (tweets.containsKey(id)) {
                for (Tweet tweet : tweets.get(id)) {
                    heap.add(tweet);
                }
            }
        }
        List<Integer> result = new ArrayList<>();
        while (!heap.isEmpty() && result.size() < 10) {
            result.add(heap.poll().id);
        }
        return result;
    }

    /**
     * Follower follows a followee. If the operation is invalid, it should be a no-op.
     */
    public void follow(int followerId, int followeeId) {
        if (followeeId == followerId) {
            return;
        }
        if (!follows.containsKey(followerId)) {
            tweets.put(followerId, new LinkedList<>());
            follows.put(followerId, new HashSet<>());
            follows.get(followerId).add(followerId);
        }
        follows.get(followerId).add(followeeId);
    }

    /**
     * Follower unfollows a followee. If the operation is invalid, it should be a no-op.
     */
    public void unfollow(int followerId, int followeeId) {
        if (!follows.containsKey(followerId) || !follows.get(followerId).contains(followeeId) || followerId == followeeId) {
            return;
        }
        follows.get(followerId).remove(followeeId);
    }
}

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * List<Integer> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */