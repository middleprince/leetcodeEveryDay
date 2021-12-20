/*
 * @lc app=leetcode.cn id=375 lang=cpp
 *
 * [375] 猜数字大小 II
 */

// @lc code=start
class Solution {
public:

    int getMoneyAmount(int n) {
        vector<vector<int>> mems(n+1, vector<int>(n+1, 0));
        return _dfs(1, n, mems);
    }

    int _dfs(int l, int r, vector<vector<int>> &mems){
        if(r<=l) {return 0;}
        if(mems[l][r]!=0) return mems[l][r];
        int res=INT_MAX;
        for(int i=l; i<=r; ++i){
            res=min(res, max(_dfs(l, i-1, mems), _dfs(i+1, r, mems)) + i);
        }
        mems[l][r]=res;
        return res;
    }
};
// @lc code=end

