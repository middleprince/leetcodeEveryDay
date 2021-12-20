/*
 * @lc app=leetcode.cn id=517 lang=cpp
 *
 * [517] 超级洗衣机
 */

// @lc code=start

using ll=int;
class Solution {
public:
    int findMinMoves(vector<int>& machines) {
         int n=machines.size();
         ll totals=0;
         for(auto i:machines)
            totals+=i;
        if(totals%n) return -1;
        ll final_val=totals/n;

        int res=0;
        ll l_sum=0, r_sum=totals;
        for(int i=0; i<n; ++i){
            r_sum-=machines[i];
            int a=max(0, final_val*i-l_sum);
            int b=max(0, final_val*(n-i-1)-r_sum);
            res = max((a+b), res);
            l_sum+=machines[i];
        }
        return res;
    }
};
// @lc code=end

