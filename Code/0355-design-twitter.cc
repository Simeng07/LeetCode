class Twitter {
    unordered_map<int, unordered_set<int>> follows;
    unordered_map<int, vector<pair<int, int>>> posts;
    int ts; // maybe, it should be unsigned long long?
public:
    /** Initialize your data structure here. */
    Twitter() {
        ts = 0;
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        if (follows[userId].find(userId) == follows[userId].end()) {
            follows[userId].insert(userId);
        }
        posts[userId].push_back(make_pair(tweetId, ts));
        ts++;
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        // check for lambda expressions
        auto comp = [](pair<int, int> a, pair<int, int> b) {return a.second > b.second;};
        auto s = set<pair<int, int>, decltype(comp)>( comp );
        for (auto person : follows[userId]) {
            // "i >= posts[person].size() - 10 && i >= 0" is wrong!
            for (int i = posts[person].size() - 1; i >= max((int)posts[person].size() - 10, 0); i--) {
                s.insert({posts[person][i]});
                if (s.size() > 10) {
                    auto endIt = s.end();
                    endIt--;
                    if (endIt->first == posts[person][i].first) {
                        s.erase(endIt);
                        break;
                    }
                    s.erase(endIt);
                }
            }
        }
        vector<int> result;
        for (auto r : s) {
            result.push_back(r.first);
        }
        return result;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        follows[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            follows[followerId].erase(followeeId);
        }
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */