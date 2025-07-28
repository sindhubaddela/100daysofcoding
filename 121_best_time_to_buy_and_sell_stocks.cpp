#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n  =  prices.size();
        int mini = INT_MAX;
        int profit =0;

        for(int i=0;i<n;i++)
        {
            mini = min(mini , prices[i]);
            profit = max( profit , prices[i]-mini);
        }
        return profit;
        
    }
};

int main(){
    Solution sol;
    vector<int>prices = {7,5,3,6,4};
    cout<<"max profit is:"<<sol.maxProfit(prices)<<endl;
    return 0;
}
