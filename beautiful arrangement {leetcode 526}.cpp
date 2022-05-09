class Solution {
public:

    void permute(int n, vector<int> &mp, int &c, int i)

    {
          if (i == mp.size())
          {
                c++;
              return;
          }
          else
          {
              for (int j = i; j < mp.size(); j++)
              {
                swap(mp[i], mp[j]);
                if(mp[i]%(i+1)==0 || (i+1)%mp[i]==0)   permute(n,mp,c, i+1);
                swap(mp[i], mp[j]);
              }
          }
    }

    int countArrangement(int n) {
        if(n==1 || n==0)    return n;
        vector<int> mp (n,0);
        for(int i =0;i<n;i++)
        {
            mp[i]=i+1;
        }
        int c =0;
        permute(n, mp, c, 0);
        return c;
    }
};
