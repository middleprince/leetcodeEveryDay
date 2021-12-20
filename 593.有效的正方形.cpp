/*
 * @lc app=leetcode.cn id=593 lang=cpp
 *
 * [593] 有效的正方形
 */

// @lc code=start
class Solution {
public:
    double dis(vector<int>& a, vector<int>& b){
        return (a[0]-b[0])*(a[0]-b[0]) + (a[1]-b[1])*(a[1]-b[1]);
        
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<double> dises{};
        dises.push_back(dis(p1, p2));
        dises.push_back(dis(p1, p3));
        dises.push_back(dis(p1, p4));
        dises.push_back(dis(p2, p3));
        dises.push_back(dis(p2, p4));
        dises.push_back(dis(p3, p4));

        sort(dises.begin(), dises.end());
        if(!dises[0]) return false;
        if(dises[0] == dises[1] && dises[1]==dises[2] &&
            dises[2] == dises[3] && dises[4]==dises[5])
            return true;
        return false;
    }
};
// @lc code=end

