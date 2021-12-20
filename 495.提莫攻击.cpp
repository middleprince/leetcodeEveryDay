/*
 * @lc app=leetcode.cn id=495 lang=cpp
 *
 * [495] 提莫攻击
 */

//timeSeries = [1,2], duration = 2
//输出：3

// @lc code=start
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int res=0;
        if(!duration) return 0;
        int e_idx=-1;
        for(const auto& cur:timeSeries){
            int n_idx=cur+duration-1;
            if(e_idx<cur)
                res+=duration;
            else 
                res+=n_idx-e_idx;
            e_idx=n_idx;
        }
        return res;

    }
};
// @lc code=end

