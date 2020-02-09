class TweetCounts {
    unordered_map<string, set<int>> m;
public:
    TweetCounts() {
        m.clear();
    }
    
    void recordTweet(string tweetName, int time) {
        m[tweetName].insert(time);
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        vector<int> result;
        if (endTime == startTime) {
            return {0};
        }
        int gap;
        if (freq == "minute") {
            gap = 60;
        } else if (freq == "hour") {
            gap = 3600;
        } else {
            gap = 86400;
        }
        set<int> &s = m[tweetName];
        auto it = s.lower_bound(startTime);
        for (int i = 0; startTime + i * gap <= endTime; i++) {
            int start = startTime + i * gap;
            int end = min(start + gap, endTime + 1);
            
            if (it == s.end()) {
                for (int ii = i; startTime + ii * gap <= endTime; ii++) {
                    result.push_back(0);
                }
                return result;
            }
            
            int tmp = 0;
            while (it != s.end()) {
                if (*it < end) {
                    tmp++;
                    ++it;
                } else {
                    break;
                }
            }
            result.push_back(tmp);
        }
        return result;
    }
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */