/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 */

// @lc code=start

// sulotion1: put 1 to n into indx-1 by swap;
class Solution1 {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        for(int i=0; i<n; ++i){
            while(nums[i] != i+1){
                if(nums[i]<=0 || nums[i]>n ||
                    nums[i]==nums[nums[i]-1]) break;
                swap(nums[i], nums[nums[i]-1]);
            }
        }

        for(int i=0; i<n; ++i)
            if(nums[i] != i+1)
                return i+1;
        return n+1;
    }
};

// mark the value which in the valid position;
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        for(int i=0; i<n; ++i){
            if(nums[i]<=0)
                nums[i]=n+1;
        }
        for(int i=0; i<n; ++i){
            int val=abs(nums[i]);
            if(val<=n){
                nums[val-1]= -abs(nums[val-1]);
            }
        }

        for(int i=0; i<n; ++i)
            if(nums[i]>0)
                return i+1;
        return n+1;
    }
};

// @lc code=end

