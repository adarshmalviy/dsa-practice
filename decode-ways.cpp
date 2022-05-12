class Solution {
public:
    
    int recur(string &s, vector<int> &dp,int n)
    {
        if(n==0||n==1)  return 1;
        if(dp[n]!= -1)  return dp[n];
        
        int oneway=0;
        if(s[n-1]!= '0')
        {
            oneway = recur(s,dp,n-1);
        }
        int twoway=0;
        if(n>=2 && s[n-2] !='0')
        {
            int num = ((s[n-2] - '0') *10) + (s[n-1] - '0');
            
            if(num<=26 && num>0)    twoway = recur(s,dp,n-2);
        }
        
        return dp[n]  = oneway+twoway;
        
    }
    int numDecodings(string s) {
        
        if (s[0] == '0')   return 0;
        int sl = s.size();
        vector<int> dp(101,-1);
        
        return recur(s,dp,sl);
        
    }
};