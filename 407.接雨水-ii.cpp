/*
 * @lc app=leetcode.cn id=407 lang=cpp
 *
 * [407] 接雨水 II
 */

// @lc code=start

// 
class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m=heightMap.size(), n=heightMap[0].size();
        if(m<2 || n<2) return 0;
        int res=0;

        vector<vector<bool>> vis(m, vector<bool> (n, false));        
        auto cmp=[](vector<int>&a, vector<int>&b) {return a[2]>b[2];};
        priority_queue<vector<int>,  vector<vector<int>>, decltype(cmp)> pq(cmp);

        for(int i=0; i<n; ++i){
            vis[0][i] = vis[m-1][i]=1;
            pq.push(vector<int>{0, i, heightMap[0][i]});
            pq.push(vector<int>{m-1, i, heightMap[m-1][i]});
        }
        for(int i=0; i<m; ++i){
            vis[i][0] = vis[i][n-1]=1;
            pq.push(vector<int>{i, 0, heightMap[i][0]});
            pq.push(vector<int>{i, n-1, heightMap[i][n-1]});
        }

        int dx[4]={0, 1, 0, -1};
        int dy[4]={1, 0, -1, 0};

        while(!pq.empty()){
            auto cur=pq.top(); pq.pop();
            int x=cur[0], y=cur[1], val=cur[2];
            for(int i=0; i<4; ++i){
                int x_=x+dx[i], y_=y+dy[i];
                if(x_<0 || x_>=m || y_<0 || y_>=n || vis[x_][y_]) continue;
                int nxt_h=heightMap[x_][y_];
                vis[x_][y_]=1;
                if(nxt_h < val ) res += val-nxt_h;
                pq.push(vector<int>{x_, y_, max(nxt_h, val)});
            }
        }
        return res;
    }
};
// @lc code=end

