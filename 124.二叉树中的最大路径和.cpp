/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
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

// solution1: dfs sum the max_sub_sum

class Solution {
public:

    int _dfs(TreeNode* root, int& res){
        if(!root) return 0;
        int l=_dfs(root->left, res);
        int r=_dfs(root->right, res);
        int lmr=max(0, l) + max(0, r) + root->val;
        int singel_branch=root->val + max(0, max(l, r));
        res=max(res, max(lmr, singel_branch));
        return singel_branch;

    }
    int maxPathSum(TreeNode* root) {
        int res=INT_MIN;
         _dfs(root, res);
        return res;
    }
};
// @lc code=end

