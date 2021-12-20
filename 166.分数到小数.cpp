/*
 * @lc app=leetcode.cn id=166 lang=cpp
 *
 * [166] 分数到小数
 */

// @lc code=start
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string res;
        long a=numerator, b=denominator;
        if(a%b == 0) return to_string(a/b);
        if(a*b < 0) res.push_back('-');
        a=abs(a); b=abs(b);
        res.append(to_string(a/b));
        res.push_back('.');
        a %=b;

        unordered_map<long, int> mp;
        while(a){
            int l=res.size();
            mp[a]=l;
            a *=10;
            res.append(to_string(a/b));
            a %=b;
            if(mp.count(a)){
                int loc=mp[a];
                return res.substr(0, loc) + "(" + res.substr(loc) + ")";
            }
        }
        return res;
        

    }
};
// @lc code=end

