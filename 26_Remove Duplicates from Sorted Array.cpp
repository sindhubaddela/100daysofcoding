class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=1;
        int j=1;
        int n = nums.size();
        if(n==1)
        {
            return 1;
        }
        while(j<n)
        {
            if(nums[j]==nums[j-1])
            {
                j++;
            }
            else{
                nums[i]=nums[j];
                j++;
                i++;
            }
        }
        return i;
    }
};