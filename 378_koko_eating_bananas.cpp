class Solution {
public:
    long long solve(vector<int>& piles,int mid,int n)
    {
        long long totalsum = 0;
        for(int i=0;i<n;i++)
        {
            totalsum+= ceil((double)piles[i]/(double)mid);
        }
        return totalsum;

    }
    int minEatingSpeed(vector<int>& piles, int h) {

        int n = piles.size();
        long long start=1;
        long long end = *max_element(piles.begin(), piles.end());
        int ans = -1;
        while(start <= end)
        {
            long long mid = start + (end-start)/2;
            long long temp = solve(piles,mid,n);
            if(temp<=h)
            {
                ans = mid;
                end=mid-1;
            }
            else
            {
                start = mid+1;
            }
        }
        return ans;    
    }
};