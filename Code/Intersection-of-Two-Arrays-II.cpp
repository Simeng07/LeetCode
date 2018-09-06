class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        if (nums1.size() == 0 || nums2.size() == 0) {
            return result;
        }
        unordered_map<int, int> m;
        for (int i = 0; i < nums1.size(); i++) {
            m[nums1[i]]++;
        }
        for (int i = 0; i < nums2.size(); i++) {
            if (m[nums2[i]] > 0) {
                result.push_back(nums2[i]);
                m[nums2[i]]--;
            }
        }
        return result;
    }
};