// https://zxi.mytechroad.com/blog/hashtable/leetcode-355-design-twitter/
// hashtable + doubly linked list
class Twitter {
public:
    Twitter() : time(0) {
        
    }
    
    void postTweet(int userId, int tweetId) {
        auto &tweets = user_tweets[userId];
        if(tweets.size() == kMaxTweets)
            tweets.pop_front();
        tweets.emplace_back(++time, tweetId);
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<pair<int, int>> feed(begin(user_tweets[userId]),
                                    end(user_tweets[userId]));
        for(int uid : user_followers[userId])
            feed.insert(end(feed),
                        begin(user_tweets[uid]),
                        end(user_tweets[uid]));
        sort(rbegin(feed), rend(feed));
        vector<int> ans;
        for(size_t i = 0; i < min(kMaxTweets, feed.size()); i++)
            ans.emplace_back(feed[i].second);
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId == followeeId) return;
        user_followers[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId == followeeId) return;
        user_followers[followerId].erase(followeeId);
    }
    
private:
    const size_t kMaxTweets = 10;
    int time;
    unordered_map<int, deque<pair<int, int>>> user_tweets;
    unordered_map<int, set<int>> user_followers;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
