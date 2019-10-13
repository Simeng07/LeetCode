class Solution {
public:
    int divide(int dividend, int divisor) {
        // another way:
        // /** a/b = e^(ln(a))/e^(ln(b)) = e^(ln(a)-ln(b)) **/
        //     if(dividend==0)  return 0;
        //     if(divisor==0)  return INT_MAX;

        //     double t1=log(fabs(dividend));
        //     double t2=log(fabs(divisor));
        //     long long result=double(exp(t1-t2));
        //     if((dividend<0) ^ (divisor<0))  result=-result;
        //     if(result>INT_MAX)  result=INT_MAX;
        //     return result;
        
        if (divisor == 0 || (dividend == INT_MIN && divisor == -1)) return INT_MAX;
        // 这个判断符号棒！
        int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
        long long result = 0;
        // labs，long格式的绝对值，为了过程中不溢出
        long long dvd = labs(dividend);
        long long dvs = labs(divisor);
        while (dvd >= dvs) {
            long long tmp = dvs, multiple = 1;
            while (dvd >= (tmp << 1)) {
                tmp <<= 1;
                multiple <<= 1;
            }
            dvd -= tmp;
            result += multiple;
        }
        return (int)(sign * result);
    }
};