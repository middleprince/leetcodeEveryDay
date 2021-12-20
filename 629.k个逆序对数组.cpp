/*
 * @lc app=leetcode.cn id=629 lang=cpp
 *
 * [629] K个逆序对数组
 */

// @lc code=start
class Solution {
public:
    const int mod=1e9+7;
    int kInversePairs(int n, int k) {
        vector<vector<int>> dp(n+1, vector<int>(k+1, 0));
        vector<vector<int>> sum(n+1, vector<int>(k+1, 0));
        dp[1][0]=1;
        for(int i=0; i<=k; ++i)
            sum[1][i]=1;
        for(int i=2; i<=n; ++i){
            for(int j=0; j<=k; ++j){
                // sum_{k=0}^{i-1} dp[i-1][j-(i-k-1)] 
                // 
                dp[i][j]= j<i ? sum[i-1][j] : (sum[i-1][j]-sum[i-1][j-(i-1)-1]+mod)%mod;
                sum[i][j]= j==0 ? dp[i][j] : (sum[i][j-1]+dp[i][j])%mod;
            }
        }
        return dp[n][k];
    }
};
// @lc code=end

