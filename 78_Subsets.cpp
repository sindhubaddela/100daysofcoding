class Solution {
public:

    void solve(vector<vector<int>>&ans,vector<int>&output,int index,int n,vector<int>&nums)
    {
        if(index==n)
        {
            ans.push_back(output);
            return;
        }
        solve(ans,output,index+1,n,nums);

        int ele = nums[index];
        output.push_back(ele);

        solve(ans,output,index+1,n,nums);

        output.pop_back();

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>output;
        int index =0;
        int n = nums.size();
        solve(ans,output,index,n,nums);
        return ans;
        
    }
};