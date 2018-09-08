class Solution {
public:
    int findNthDigit(int n) {
        if (n < 10) {
            return n;
        }
        int numOfDigit = 1;
        long numOfCount = 1;
        long count = numOfCount * 9;
        while (n > count) {
            numOfDigit++;
            numOfCount *= 10;
            count += numOfDigit * numOfCount * 9;
        }
        count -= numOfDigit * numOfCount * 9;
        numOfCount /= 10;
        int remain = n - count;
        
        int a = remain / numOfDigit;
        int b = remain % numOfDigit;
        if (b != 0) {
            a++;
        }
        if (b == 0) {
            b = numOfDigit;
        }
        int currentNum = numOfCount * 10 + a - 1;
        cout << "numOfDigit: " << numOfDigit << " numOfCount: " << numOfCount << " count: " << count << "                       remain: " << remain << " a: " << a << " b: " <<  b << " currentNum: " << currentNum;

        for (int i = 0; i < (numOfDigit - b); i++) {
            currentNum /= 10;
        }
        cout << " currentNum: " << currentNum << endl;
        cout << endl;
        return currentNum % 10;
    }
};