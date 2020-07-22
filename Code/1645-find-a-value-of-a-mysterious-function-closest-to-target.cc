class Solution {
    
public:
    int closestToTarget(vector<int>& arr, int target) {
        vector<int> v(arr.size());
        int result = 1000000000 - target;
        int lastEnd = arr.size();
        for (int i = 0; i < arr.size(); i++) {
            int length = arr.size() - i;
            int end = andOperation(arr, v, i, length, target, lastEnd);
            lastEnd = end;
            // add greater<int>() for decreasing vector
            auto it = lower_bound(v.begin() + i, v.begin() + end + 1, target, greater<int>());
            if (it == v.begin())  {
                result = min(result, abs(target - *it));
            } else {
                if (it != v.end()) {
                    result = min(result, abs(target - *it));
                }
                --it;
                result = min(result, abs(target - *it));
            }
            if (result == 0) {
                return result;
            }
        }
        
        return result;
    }
    
    int andOperation(vector<int>& arr, vector<int> &v, int begin, int length, int target, int lastEnd) {
        v[begin] = arr[begin];
        for (int i = 1; i < length; i++) {
            if (begin != 0 && (v[begin + i - 1] & arr[begin + i]) == v[begin + i]) {
                // if a[i]&a[i+1]==a[i+1], then we don't need to calculate the sequence for begin=i+1
                // since we have gotten it when begin = i
                return lastEnd;
            }
            v[begin + i] = (v[begin + i - 1] & arr[begin + i]);
            if (v[begin + i] <= target) {
                return i;
            }
        }
        return length - 1;
    }
};