class Solution {
public:

    void solve(vector<int>& candidates, int target,int n,vector<vector<int>>&ans,vector<int>&output,int index)
    {
        if(index==n)
        {
            if(target==0)
            {
                ans.push_back(output);
            }
            return;
        }
        if(candidates[index]<=target)
        {
            int ele = candidates[index];
            output.push_back(ele);
            solve(candidates,target-candidates[index],n,ans,output,index);
            output.pop_back();
        }
        solve(candidates,target,n,ans,output,index+1);



    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        int n = candidates.size();
        int index=0;
        vector<vector<int>>ans;
        vector<int>output;
        solve(candidates,target,n,ans,output, index);
        return ans;

        
    }
};