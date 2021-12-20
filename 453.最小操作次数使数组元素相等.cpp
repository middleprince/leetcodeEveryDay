/*
 * @lc app=leetcode.cn id=453 lang=cpp
 *
 * [453] 最小操作次数使数组元素相等
 */

// @lc code=start
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int res=0, tmp=INT_MAX;
        for(const auto&i:nums)
            tmp=min(tmp,i);
        for(const auto&i:nums)
            res += i-tmp;
        return res;
    }
};
// @lc code=end

