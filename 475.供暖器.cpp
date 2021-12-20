/*
 * @lc app=leetcode.cn id=475 lang=cpp
 *
 * [475] 供暖器
 */

// @lc code=start
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int l=0, r=(int)1e9;
        while(l<r){
            int mid=(l+r)>>1;
            if(valid(houses, heaters, mid)) r=mid;
            else l=mid+1;
        }
        return  r;
    }

    bool valid(vector<int>& houses, vector<int>& heaters, int len){
        int m = houses.size(), n = heaters.size();
        for(int i=0, j=0; i<m; ++i){
            while(j<n && houses[i] > heaters[j]+len) ++j;
            if(j<n && heaters[j]-len <=houses[i] && heaters[j]+len >= houses[i]) continue;
            return false;
        }
        return true;
    }
};
// @lc code=end

