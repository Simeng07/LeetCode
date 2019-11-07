class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int begin = 0, end = n - 1, mid;
        while (begin <= end) {
            mid = (begin + end) / 2;
            if (citations[mid] == n - mid) return citations[mid];
            else if (citations[mid] > n - mid) end = mid - 1;
            else begin = mid + 1;
        }
        return n - (end + 1);
    }
};