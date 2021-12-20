/*
 * @lc app=leetcode.cn id=372 lang=cpp
 *
 * [372] 超级次方
 */

// @lc code=start
class Solution {
public:
    const int MOD=1337;
    int superPow(int a, vector<int>& b) {
        a %= MOD;
        return _dfs(a, b, b.size()-1);
    }
    int _dfs(int a, vector<int>& nums, int idx){
        if (idx==-1) return 1;
        return qPow(_dfs(a, nums, idx-1), 10) * qPow(a, nums[idx])%MOD;
    }
    int qPow(int a, int b){
        int res=1;
        a %=MOD;
        while(b){
            if(b&1) res = res*a % MOD;
            b >>= 1;
            a = a*a % MOD;
        }
        return res;
    }
};
// @lc code=end

