/*
 * @lc app=leetcode.cn id=410 lang=cpp
 *
 * [410] 分割数组的最大值
 */

// @lc code=start
using ll=long long;
// dp time:O(n^2m)
class Solution1 {
public:
    int splitArray(vector<int>& nums, int m) {
        int n=nums.size();
        vector<vector<ll>> dp(n+1, vector<ll>(m+1, LONG_MAX));
        vector<ll> pre_sum(n+1, 0);

        for(int i=1; i<=n; ++i){
            pre_sum[i]=pre_sum[i-1] + nums[i-1];
            dp[i][1]=pre_sum[i]; 
        }
        dp[0][0]=0;

        for(int i=1; i<=n; ++i){
            for(int k=1; k<=min(i, m); ++k){
                for(int j=0; j<i; ++j){
                    dp[i][k]=min(dp[i][k], max(dp[j][k-1], pre_sum[i]-pre_sum[j]));
                }
            }
        }
        return dp[n][m];
    }
};

// greedy and binary search
// time: O(n*log(\sum(nums)))
class Solution {
public:
    // count number of splits which the upper bound of sum of each sub-array is max_value;
    int split(vector<int>& nums, ll max_value){
        int cnt=1;
        ll tmp=0;

        for(auto i:nums){
            if(tmp+i>max_value){
                ++cnt;
                tmp=0;
            } 
            tmp += i;
        }
        return cnt;
    }

    int splitArray(vector<int>& nums, int m){
        int n=nums.size(), max_item=0;
        ll sum=0; 
        for(int i=0; i<n; ++i){
            sum += nums[i];
            max_item = max(max_item, nums[i]);
        }

        // search the minMax sum of subarray by binary search 
        // when cut the array into m groups, the last max sum will be the minMax sum.
        ll l=max_item, h=sum;
        while(l<h){
            ll mid=l+(h-l)/2;
            int cnt=split(nums, mid);
            if(cnt>m) l=mid+1;
            else h=mid;
        }
        return l;
    }
};
// @lc code=end

