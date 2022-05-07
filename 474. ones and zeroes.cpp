class Solution {
public:

    pair<int, int> count(string s)
    {
        pair <int, int> data;
        for(char x: s)
        {
            if(x == '0') data.first = data.first+1;
            else if(x == '1')   data.second = data.second +1;
        }
        return data;
    }

    int solve(vector<string>& strs, int m, int n, int i, vector<vector<vector<int>>> &dp)
    {
        if( (m ==0 and n==0) or i == strs.size())   return 0;
        if(dp[m][n][i] != -1)   return dp[m][n][i];


        int not_take = solve(strs,m,n,i+1,dp);

        int take = 0;

        pair<int, int> calc = count(strs[i]);

        if(m>= calc.first and n>= calc.second)  take = 1+ solve(strs, m - calc.first, n- calc.second, i+1, dp);

        dp[m][n][i] = max(take,not_take);

        return dp[m][n][i];
    }


    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>> dp;
        dp.resize(101, vector<vector<int>>(101, vector<int>(600, -1)));

        return solve(strs, m,n,0, dp);


    }
};
