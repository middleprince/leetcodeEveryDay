/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */

// @lc code=start
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        for(int i=n-1; i>=0; --i){
            ++digits[i];
            digits[i]=digits[i]%10;
            if(digits[i]) return digits;
        }
        vector<int> res(n+1, 0);
        res[0]=1;
        copy(move_iterator(digits.begin()), move_iterator(digits.end()), res.begin()+1);
        return res;
    }
};
// @lc code=end

