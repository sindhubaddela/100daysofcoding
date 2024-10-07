class Solution {
    public:
	const int MOD = 1e9 + 7; 
	
	
	int solve(int count, int index, int tempsum, int arr[], int n, int sum) {
        if (index == n) {
            if (tempsum == sum) {
                return (count + 1)%MOD;  
            }
            return count;  
        }
        count = solve(count, index + 1, tempsum, arr, n, sum);
        count = solve(count, index + 1, tempsum + arr[index], arr, n, sum);

        return count; 
    }

	int perfectSum(int arr[], int n, int sum)
	{
        int count=0;
        
        return solve(count,0,0,arr,n,sum);
	}
};