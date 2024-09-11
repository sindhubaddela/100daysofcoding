class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxsofar=INT_MIN;
        int maxx=0;
        for(int i=0;i<n;i++)
        {
            maxx=maxx+nums[i];
            if(maxx>maxsofar)
            {
                maxsofar=maxx;
            }
            if(maxx<0)
            {
                maxx=0;
            }
        }
        return maxsofar;
        
    }
};