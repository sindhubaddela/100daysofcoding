
#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
    int solve(vector<int>&nums ,int goal)
    {
        int n= nums.size();
        int start=0;
        int end=0;
        int ans=0;
        int currsum=0;

        while(end<n)
        {
            currsum= nums[end] + currsum;
            while(currsum > goal)
            {
                currsum= currsum - nums[start];
                start++;
            }
            ans = ans + end-start+1;
            end++;
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        int ans1 = solve(nums , goal);
        int ans2 = solve(nums, goal-1);
        return ans1-ans2;
    }
};
int main(){

    Solution sol;
    vector<int>nums={1,0,1,0,1};
    int goal=2;
    cout<<sol.numSubarraysWithSum(nums, goal)<<endl;
    return 0;
}