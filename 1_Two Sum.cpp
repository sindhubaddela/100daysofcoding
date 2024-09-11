class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<int,int> map;
        vector<int>ans;

        for(int i=0;i<n;i++)
        {
            int ele = target-nums[i];
            if(map.find(ele)!=map.end())
            {
                ans.push_back(map[ele]);
                ans.push_back(i);
                return ans;
            }
            map[nums[i]]=i;
            
        }
        return {} ;
    }
};
