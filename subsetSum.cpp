/*
Problem statement
You are given an array 'A' of 'N' integers. 
You have to return true if there exists a subset of elements of 'A' that sums up to 'K'. 
Otherwise, return false.
For Example
'N' = 3, 'K' = 5, 'A' = [1, 2, 3].
Subset [2, 3] has sum equal to 'K'.
So our answer is True.
*/
bool solve(vector<int>&a,int tempsum,int n, int k,int index)
{
    if(index==n)
    {
        if(tempsum==k)
        {
            return true;
        }
        return false;
    }

    bool ans1 = solve(a,tempsum,n,k,index+1);
    bool ans2 = solve(a,tempsum+a[index],n,k,index+1);
    return ans1 || ans2;
}
bool isSubsetPresent(int n, int k, vector<int> &a)
{
    int index=0;
    int tempsum=0;
    bool ans = solve(a,tempsum,n,k,index);
    return ans;
}