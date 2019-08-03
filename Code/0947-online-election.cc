class TopVotedCandidate {
    // 以下方法超过51%，但明显有更好的方法：
    // 直接记录person的投票数，维护当前最大值。如果某一时刻达到了当前最大值，则更新timeSequence。不需要用自动排序的map的。
    vector<pair<int, int> > timeSequence; // 时间，人
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        unordered_map<int, int> personToCount; // 人，票数
        map<int, unordered_set<int>, greater<int> > countToPerson; // 票数，人群(需要排序)
       
        for (int i = 0; i < persons.size(); i++) {
            personToCount[persons[i]]++;
            int count = personToCount[persons[i]];
            countToPerson[count].insert(persons[i]);
            if (count > 1) {
                countToPerson[count - 1].erase(persons[i]); // 删除之前的记录
            }
            
            if (timeSequence.size() == 0) {
                timeSequence.push_back({times[i], persons[i]});
                continue;
            }
            
            if (count == countToPerson.begin()->first) { // 当前这个就是最多的
                if (timeSequence.back().second != persons[i]) { // 需要变更
                    timeSequence.push_back({times[i], persons[i]});
                }
            }
            
        }
    }
    
    int q(int t) {
        // 二分法
        int begin = 0;
        int end = timeSequence.size() - 1;
        int middle = begin + (end - begin) / 2;
        while (begin < middle) {
            if (t > timeSequence[middle].first) {
                begin = middle;
            } else {
                end = middle;
            }
            middle = begin + (end - begin) / 2;
        }
        
        if (t >= timeSequence[end].first) {
            return timeSequence[end].second;
        } else {
            return timeSequence[begin].second;
        }
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */