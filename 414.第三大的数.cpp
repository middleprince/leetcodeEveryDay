/*
 * @lc app=leetcode.cn id=414 lang=cpp
 *
 * [414] 第三大的数
 */

// @lc code=start
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long a=LONG_MIN, b=LONG_MIN, c=LONG_MIN;
        for(const auto&x:nums){
            if(x>a) {c=b; b=a; a=x;}
            else if(x<a && x>b) {c=b; b=x;}
            else if(x<b && x>c) {c=x;}
        }
        return c!=LONG_MIN ? int(c) : int(a);
    }
};
// @lc code=end

