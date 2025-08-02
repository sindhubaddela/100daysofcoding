
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int charrep(string &s ,int &k)
    {
        int n = s.size();
        int start=0;
        int end=0;
        int maxlen=0;
        int maxfreq=0;
        vector<int>freq(26,0);

        while(end<n)
        {
            freq[s[end]-'A']++;
            maxfreq = max(maxfreq, freq[s[end]-'A']);

            while(end-start+1 -maxfreq > k)
            {
                freq[s[start]-'A']--;
                start++;
                maxfreq=0;
                for(int i=0;i<26;i++)
                {
                    maxfreq=max(maxfreq , freq[i]);
                }
            } 
            maxlen = max(maxlen , end-start+1);
            end++;
        }
        return maxlen;
    }


};
int main()
{
    string s = "ABAB";
    int k=2;
    Solution sol;
    cout<<sol.charrep(s,k)<<endl;
    return 0;
}