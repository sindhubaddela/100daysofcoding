class Solution {
public:

    bool possible(vector<int>& bloomDay,int mid,int m,int k,long long n)
    {
        int count=0;
        int numberofbouquet =0;
        for(long long i=0;i<n;i++)
        {
            if(bloomDay[i]<=mid)
            {
                count++;
            }
            else
            {
                numberofbouquet+=count/k;
                count=0;
            }
        }
        numberofbouquet+=count/k;
        if(numberofbouquet>=m)
        {
            return true;
        }
        return false;

    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long int n = bloomDay.size();
        long long int j = (long long)m*k;
        if(n < j)
        {
            return -1;
        }
        int start= *min_element(bloomDay.begin(),bloomDay.end());
        int end= *max_element(bloomDay.begin(),bloomDay.end());
        int ans = -1;

        while(start<=end)
        {
            
            int mid = start + (end-start)/2;
            bool temp = possible(bloomDay,mid,m,k,n);
            if(temp== true)
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