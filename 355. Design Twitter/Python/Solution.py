class Twitter(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.tweets = {}
        self.follows = {}
        self.time = 0

    def postTweet(self, userId, tweetId):
        """
        Compose a new tweet.
        :type userId: int
        :type tweetId: int
        :rtype: void
        """
        if userId not in self.tweets:
            self.tweets[userId] = []
            self.follows[userId] = [userId]
        self.tweets[userId].insert(0, (-self.time, tweetId))
        self.time += 1

    def getNewsFeed(self, userId):
        """
        Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent.
        :type userId: int
        :rtype: List[int]
        """
        heap = []
        if userId not in self.follows:
            return heap
        for id in self.follows[userId]:
            if id in self.tweets:
                for tweet in self.tweets[id]:
                    heapq.heappush(heap, tweet)
        result = []
        count = 10
        while heap and count:
            result.append(heapq.heappop(heap)[1])
            count -= 1
        return result

    def follow(self, followerId, followeeId):
        """
        Follower follows a followee. If the operation is invalid, it should be a no-op.
        :type followerId: int
        :type followeeId: int
        :rtype: void
        """
        if followerId == followeeId:
            return
        if followerId not in self.follows:
            self.tweets[followerId] = []
            self.follows[followerId] = [followerId]
        if followeeId in self.follows[followerId]:
            return
        self.follows[followerId].insert(0, followeeId)

    def unfollow(self, followerId, followeeId):
        """
        Follower unfollows a followee. If the operation is invalid, it should be a no-op.
        :type followerId: int
        :type followeeId: int
        :rtype: void
        """
        if followerId not in self.follows or followeeId not in self.follows[followerId] or followerId == followeeId:
            return
        self.follows[followerId].remove(followeeId)


# Your Twitter object will be instantiated and called as such:
# obj = Twitter()
# obj.postTweet(userId,tweetId)
# param_2 = obj.getNewsFeed(userId)
# obj.follow(followerId,followeeId)
# obj.unfollow(followerId,followeeId)
