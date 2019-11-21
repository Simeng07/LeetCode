class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 也是对的喔！下面用的是堆
        // unordered_map<int, int> numToCount;
        // map<int, unordered_set<int>, greater<int> > countToNum;
        // for (auto num : nums) {
        //     numToCount[num]++;
        // }
        // for (auto ntc : numToCount) {
        //     countToNum[ntc.second].insert(ntc.first);
        // }
        // vector<int> result;
        // for (auto s : countToNum) {
        //     for (auto i : s.second) {
        //         result.push_back(i);
        //         if (--k == 0) {
        //             return result;
        //         }
        //     }
        // }
        // return result;
        
        unordered_map<int,int> cnt;
        vector<int> res;
        for(auto &x:nums) cnt[x]++;
        vector<pair<int,int>> hist;
        for(auto &x:cnt){
            hist.push_back(make_pair(x.second,x.first));
        }
        make_heap(hist.begin(),hist.end());
        for(int i=0;i<k;i++){
            res.push_back(hist[0].second);
            pop_heap(hist.begin(),hist.end());
            hist.pop_back();
        }
        return res;
    }
};