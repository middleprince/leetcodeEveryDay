/*
 * @lc app=leetcode.cn id=352 lang=cpp
 *
 * [352] 将数据流变为多个不相交区间
 */

// @lc code=start
#include<vector>
#include<iostream>
using namespace std;

class SummaryRanges1 {
public:
    SummaryRanges1() {
        inters.emplace_back(vector<int>{INT_MIN, INT_MIN});
        inters.emplace_back(vector<int>{INT_MAX, INT_MAX});
    }
    
    void addNum(int val) {
        int n=inters.size();
        int l=0, r=n-1;
        while(l<r){
            int m=l+((r-l)>>1);
            if(inters[m][0] <= val) l=m+1;
            else r=m;
        }
        int pre=l, nxt=l+1;
        auto beg=inters.begin();
        if(inters[pre][0]<=val && inters[pre][1]>=val ||
            inters[nxt][0]<=val && inters[nxt][1]>=val) ;
        else if(inters[pre][1]+1==val && val+1==inters[nxt][0]){
            inters[pre][1]=inters[nxt][1];
            inters.erase(beg+nxt);
        }
        else if(inters[pre][1]+1==val) inters[pre][1]=val;
        else if(inters[nxt][0]-1==val) inters[nxt][0]=val;
        else {
            inters.insert(beg+nxt, {val, val}); 
        }

    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> res{};
        
        int n=inters.size();
        
        for(int i=1; i<n-1; ++i){
            res.emplace_back(inters[i]);
        }
        return res;

    }

private:
    vector<vector<int>> inters;

};

class SummaryRanges {
public:
    SummaryRanges() {
        inters.insert(pair<int, int>{INT_MIN, INT_MIN});
        inters.insert(pair<int, int>{INT_MAX, INT_MAX});
    }
    
    void addNum(int val) {
        pair<int, int> cur{val, val};
        auto pre=inters.lower_bound(cur);
        auto nxt=inters.upper_bound(cur);

        auto beg=inters.begin();
        if(pre->first <= val && pre->second >=val ||
            nxt->first <=val && nxt->second >=val) ;
        else if(pre->second+1==val && val+1==nxt->first){
            pre->second=nxt->first;
            inters.erase(nxt);
        }
        else if(pre->second+1==val) pre->second=val;
        else if(nxt->first-1==val) nxt->first=val;
        else {
            inters.insert({val, val}); 
        }

    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> res{};
        
        int n=inters.size();
        
        for(int i=1; i<n-1; ++i){
            res.emplace_back(inters[i]);
        }
        return res;

    }

private:
    bool cmp(pair<int, int>& lhs, pair<int, int>& rhs){return lhs.first<rhs.first;}
    set<pair<int, int>, decltype(cmp)> inters(cmp);

};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
// @lc code=end

