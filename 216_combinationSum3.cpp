class Solution {
public:
    void solve(vector<int>&nums,vector<int>&output,vector<vector<int>>&ans,int m,int target,int k,int index)
    {
        if(k==0)
        {
            if(target==0)
            {
                ans.push_back(output);
            }
            return;
        }
        if(index>m)
        {
            return;
        }
        for(int i=index;i<=m;i++)
        {
            if(nums[i]>target)
            {
                break;
            }
            int ele = nums[i];
            output.push_back(ele);
            solve(nums,output,ans,m,target-nums[i],k-1,i+1);
            output.pop_back();

        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>nums;
        for(int i =0;i<9;i++)
        {
            nums.push_back(i+1);
        }
        int m = nums.size();
        vector<vector<int>>ans;
        vector<int>output;
        solve(nums,output,ans,m,n,k,0);
        return ans;
        
    }
};