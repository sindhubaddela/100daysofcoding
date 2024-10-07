class Solution {
public:

    void solve(vector<int>& candidates,vector<vector<int>>&ans,vector<int>&output,int n,int index,int target)
    {
        
        if(target==0)
        {
            ans.push_back(output);
            return;
        }
        if(index>=n)
        {
            return;
        }
        for(int i = index;i<n;i++)
        {
            if (i > index && candidates[i] == candidates[i - 1]) {
                continue;
            }

            // If the candidate is greater than the remaining target, stop further exploration
            if (candidates[i] > target) {
                break;
            }
            int ele = candidates[i];
            output.push_back(ele);
            solve(candidates,ans,output,n,i+1,target-candidates[i]);
            output.pop_back();

        }
            





    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        sort(candidates.begin(),candidates.end());
        int index=0;
        vector<vector<int>>ans;
        vector<int>output;
        solve(candidates,ans,output,n,index,target);
        return ans;
        
    }
};