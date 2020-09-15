class Solution {
    // bubble
public:
    bool isTransformable(string s, string t) {
        vector<vector<int>> position(10, vector<int>());
        int index[10] = {0};
        
        for (int i = 0; i < s.size(); i++) {
            position[s[i] - '0'].push_back(i);
        }
        
        for (auto &c : t) {
            int num = c - '0';
            if (index[num] >= position[num].size()) {
                // no more certain num
                return false;
            }
            
            for (int i = 0; i < num; i++) {
                if (index[i] < position[i].size() && position[i][index[i]] < position[num][index[num]]) {
                    return false;
                }
            }
            
            index[num]++;
        }
        
        return true;
    }
};