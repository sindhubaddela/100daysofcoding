class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count1=0;
        int count2=0;
        int count0=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
            {
                count0++;
            }
            else if(nums[i]==1)
            {
                count1++;
            }
            else
            {
                count2++;
            }
        }
        int start=0;
        while(count0>0)
        {
            nums[start]=0;
            start++;
            count0--;
        }
        while(count1>0)
        {
            nums[start]=1;
            start++;
            count1--;
        }
        while(count2>0)
        {
            nums[start]=2;
            start++;
            count2--;
        }
    }
};