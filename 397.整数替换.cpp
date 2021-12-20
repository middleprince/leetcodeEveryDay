/*
 * @lc app=leetcode.cn id=397 lang=cpp
 *
 * [397] 整数替换
 */

// @lc code=start

// dfs with mems 
// time: logn; space: logn
class Solution1{
public:
    int integerReplacement(int n) {
        return _dfs(n);
    }

private:
    unordered_map<int, int> um;
    int _dfs(int n){
        if(n==1) return 0; 
        if(um.count(n)) return um[n];
        int ans= n%2==0 ? _dfs(n/2) : min(_dfs(n-1), _dfs(n+1));
        um[n]=++ans;
        return ans;
    }
};

// bit greedy
// time: o(logn), space: O(1);
class Solution{
public:
    int integerReplacement(int n) {
        int res=0;
        while(n != 1){
            if(n%2==0){
                n >>=1;
            }else{
                n += (n!=3) && (n>>1)&1==1 ? 1:-1;

            }
            ++res;
        }
        return res;
    }

};

// @lc code=end

