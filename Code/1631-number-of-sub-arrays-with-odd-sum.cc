class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int oddCount = 0, evenCount = 0; // end with current item
        int sum = 0;
        for (int i = 0; i < arr.size(); i++) {
            int lastOdd = oddCount, lastEven = evenCount;
            if (arr[i] & 1) {
                oddCount = lastEven + 1;
                evenCount = lastOdd;
            } else {
                evenCount = lastEven + 1;
            }
            sum = (sum + oddCount) % 1000000007;
        }
        return sum;
    }
};