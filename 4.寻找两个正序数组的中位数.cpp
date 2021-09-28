/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
class Solution {
public:

    double kthMax(vector<int>& nums1, vector<int>& nums2, int k){
        int m=nums1.size(), n=nums2.size();
        int i=0, j=0, i_prim=0, j_prim=0;
        while(1){
            if(i==m) return nums2[j+k-1];
            if(j==n) return nums1[i+k-1];
            if(k==1) return min(nums1[i], nums2[j]);

            i_prim=min(k/2+i-1, m-1);
            j_prim=min(k/2+j-1, n-1);
            if(nums1[i_prim] <= nums2[j_prim]){
                k -= i_prim-i+1;
                i = i_prim+1;
            }
            else{
                k -= j_prim-j+1;
                j = j_prim+1;
            }
        }
    } 
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(), n=nums2.size();
        int mid=(m+n)/2, odd=(m+n)%2;
        if(odd)
            return kthMax(nums1, nums2, mid+1);
        else
            return (kthMax(nums1, nums2, mid+1) + kthMax(nums1, nums2, mid)) / 2.0;

    }
};
// @lc code=end

