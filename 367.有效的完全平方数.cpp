/*
 * @lc app=leetcode.cn id=367 lang=cpp
 *
 * [367] 有效的完全平方数
 */

// @lc code=start
class Solution {
public:
    bool isPerfectSquare(int num) {
        long l=0, r=num;
        while(l<r){
            long mid=l+(r-l+1)>>1;
            if(mid*mid>num) r=mid; 
            else l=mid+1;
        }
        return l*l == num;

    }
};
// @lc code=end

