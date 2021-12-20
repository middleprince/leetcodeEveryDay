/*
 * @lc app=leetcode.cn id=223 lang=cpp
 *
 * [223] 矩形面积
 */

// @lc code=start
class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int res=0;
        int x_rt=min(ax2, bx2);
        int y_rt=min(ay2, by2);

        int x_lb=max(ax1, bx1);
        int y_lb=max(ay1, by1);

        int area1=(ax2-ax1)*(ay2-ay1);
        int area2=(bx2-bx1)*(by2-by1);

        int inter_area=max(0, x_rt-x_lb) * max(0, y_rt-y_lb);
        return area1+area2-inter_area;

        

    }
};
// @lc code=end

