/*
 * @lc app=leetcode.cn id=563 lang=cpp
 *
 * [563] 二叉树的坡度
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
class Solution {
public:
    int findTilt(TreeNode* root) {
        _dfs(root);
        return res;
    }
private:
    int res = 0;
    int _dfs(TreeNode* root){
        if(!root) return 0;
        int l_v=_dfs(root->left);
        int r_v=_dfs(root->right);
        res += abs(l_v - r_v);
        root->val+=l_v+r_v;
        return root->val;
        
    }
};
// @lc code=end

