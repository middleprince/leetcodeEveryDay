#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution1 {
public:
    void plusN(vector<int>& nums, int l, int r, int n) {
        while(l <= r)
            nums[l++]=n;
    }
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> res(n, 0);
        //auto com=[](vector<int>& a, vector<int>& b){return a[0] < b[0] && a[1] < b[1];};
        //sort(bookings.begin(), bookings.end(), com);

        int m=bookings.size();
        for(int i=0; i<m; ++i){
            plusN(res, bookings[i][0]-1, bookings[i][1]-1, bookings[i][2]);

        }
        return res;

    }
};

class Solution {
public:

    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> res(n, 0);

        for (const auto& nums : bookings) {
            res[nums[0]-1] += nums[2];
            if(nums[1] < n)
                res[nums[1]] -= nums[2];

        }
        for(int i=1; i<n; ++i)
            res[i] += res[i-1];
        return res;

    }
};
