/*
 * @lc app=leetcode.cn id=1436 lang=cpp
 *
 * [1436] 旅行终点站
 */

// @lc code=start
class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, int> out{};
        for(auto &node:paths){
            if(out.find(node[0]) == out.end())
                out[node[0]] = 1;
            else 
                out[node[0]] += 1;
            if(out.find(node[1]) == out.end())
                out[node[1]] = 0;
        }

        string res;
        for(auto &iter:out){
            if(iter.second == 0){
                res = iter.first;
                break;
            }
        }
        return res;
    }
};
// @lc code=end

