/*
 * @lc app=leetcode.cn id=520 lang=cpp
 *
 * [520] 检测大写字母
 */

// @lc code=start
class Solution1 {
public:
    bool detectCapitalUse(string word) {
        bool first_up=toupper(word[0])==word[0];
        bool all_up=first_up;
        bool all_low=true;

        for(int i=1; i<word.size(); ++i){
            char c=word[i];
            bool up=toupper(c)==c;
            if(!first_up && up) return false;
            all_up &=up; 
            all_low &=!up;
        }
        return all_up ? 1 : ((first_up && all_low) || (!first_up && all_low)); 
        

    }
};

class Solution {
public:
    bool detectCapitalUse(string word) {
        int cnt=0;
        for(const auto &c:word)
            cnt += toupper(c)==c ? 1:0;
        int n=word.size();
        return cnt==0 || cnt==n || (cnt==1 && word[0]==toupper(word[0]));
        

    }
};

// @lc code=end

