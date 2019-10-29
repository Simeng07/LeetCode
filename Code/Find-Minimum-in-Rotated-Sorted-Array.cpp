class Solution {
public:
    int findMin(vector<int> &num) {
        int first = 0;
        int last = num.size()-1;
        if (num[first] <= num[last]) return num[0];
        
        while (first < last - 1 && num[last] < num[first]) {
            int middle = (last+first)/2;
            if (num[middle] > num[last]) {
                first = middle;
            } else {
                last = middle;
            }
        }
        if (num[first]<num[last]) {
            return num[first];
        } else {
            return num[last];
        }
    }
};