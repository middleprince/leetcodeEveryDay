/*
 * @lc app=leetcode.cn id=29 lang=cpp
 *
 * [29] 两数相除
 */

// @lc code=start
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(!dividend) return 0;
        int MIN=INT_MIN, MAX=INT_MAX;
        int limit=-2147483648;
        int a=dividend, b=divisor;

        if(a==INT_MIN & b==-1) return INT_MAX;
        bool sign=(dividend>0&&divisor>0) || (dividend<0 && divisor<0);
        a = -abs(a);
        b = -abs(b);
        int res=0;
        while(a <= b){
            int c=b, d=-1;
            while(c >=limit && d>=limit && a-c<=c){
                c+=c;
                d+=d;
            }
            a -=c;
            res +=d;
        }
        return sign ? -res : res;
        

    }
};
// @lc code=end

