class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int maxcount=0;
        int count=0;
        for(int i =0 ;i<n;i++)
        {
            if(nums[i])
            {
                count++;
            }
            else 
            {
                maxcount=max(count,maxcount);
                count=0;
            }
        }
        maxcount = max(maxcount,count);
        return maxcount;

        
    }
};