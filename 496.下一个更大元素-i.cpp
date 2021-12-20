/*
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] 下一个更大元素 I
 */

// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(), n=nums2.size();
        vector<int> res(m, -1);
        unordered_map<int, int> mp;
        stack<int> stk;
        for(int i=n-1; i>=0; --i){
            int tmp=nums2[i];
            while(!stk.empty() && tmp>=stk.top())
                stk.pop();
            mp[tmp]=stk.empty()? -1:stk.top();
            stk.push(tmp);
        }

        for(int i=0; i<m; ++i){
            res[i]=mp[nums1[i]];
        }
        return res;
    }
};
// @lc code=end

