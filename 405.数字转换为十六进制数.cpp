/*
 * @lc app=leetcode.cn id=405 lang=cpp
 *
 * [405] 数字转换为十六进制数
 */

// @lc code=start
class Solution {
public:
    string toHex(int num) {
        string res{};
        if(num==0) return "0";
        while(num != 0){
            int tmp = num&15;
            char c = (char)(tmp+'0'); 
            if(tmp >= 10) c=(char)(tmp-10+'a');
            res.push_back(c);
            num >>= 4;
        }
        reverse(res.begin(), res.end());
        return res;
        
    }
};
// @lc code=end

