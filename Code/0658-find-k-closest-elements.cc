class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> result;
        if (arr.size() == 0 || k == 0) {
            return result;
        }
        sort(arr.begin(), arr.end());
        // 二分
        int begin = 0;
        int end = arr.size() - 1;
        int middle = end / 2;
        
        while (begin < middle) { // 找出小于等于x的元素的index
            if (arr[middle] > x) {
                end = middle;
            } else {
                begin = middle;
            }
            middle = begin + (end - begin) / 2;
        }
        
        while (k--) {
            if (begin >= 0 && end < arr.size()) {
                if (x - arr[begin] <= arr[end] - x) {
                    result.push_back(arr[begin]);
                    begin--;
                } else {
                    result.push_back(arr[end]);
                    end++;
                }
            } else {
                if (begin >= 0) {
                    result.push_back(arr[begin]);
                    begin--;
                } else if (end < arr.size()) {
                    result.push_back(arr[end]);
                    end++;
                }
            }
        }
        
        sort(result.begin(), result.end());
        
        return result;
    }
};