/*
 * @lc app=leetcode.cn id=437 lang=cpp
 *
 * [437] 路径总和 III
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// naive dfs traverse time:O(n^2)
class Solution1 {
public:
    int _dfs(TreeNode* root, int targetSum){
        int res=0;
        if(!root) return 0;
        if(root->val == targetSum)
            ++res;
        res += _dfs(root->left, targetSum - root->val);
        res += _dfs(root->right, targetSum - root->val);
        return res;
    }

    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;
        int res=0;
        
        res += _dfs(root, targetSum);
        res += pathSum(root->left, targetSum);
        res += pathSum(root->right, targetSum);
        return res;

    }
};

// soluton2, prefix sum time:O(n)
// map:{sum, count};
// map[sum-target_sum] exit, presum[j] - presum[i] == trget_sum -> the path = map[sum-target_sum];
class Solution{
public:
    void _dfs(TreeNode* root, unordered_map<int, int>& mp, int target_sum, int& res, int sum){
        if (!root) return ;
        sum += root->val;
        if(mp.count(sum-target_sum))
            res += mp[sum-target_sum];
        mp[sum]++;
        _dfs(root->left, mp, target_sum, res, sum);
        _dfs(root->right, mp, target_sum, res, sum);
        // restore for backtrack , the path will be fork 
        mp[sum]--;
    }

    int pathSum(TreeNode* root, int targetSum){
        if(!root) return 0;
        unordered_map<int, int> mp;
        mp[0]=1;
        int res=0;
        int sum=0;
        _dfs(root, mp, targetSum, res, sum);
        return res;
    }


};
// @lc code=end

