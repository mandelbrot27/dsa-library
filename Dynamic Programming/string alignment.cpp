#include<bits/stdc++.h>
using namespace std;

pair<string,string> aligned_strings(string x, string y)
{
    x="#"+x;
    y="#"+ y;   // converting strings to 1-based index
    
    long long dp[x.length()+1][y.length()+1];
    int penalty_gap=1,penalty_mismatch=1;

    for(int i=0;i<=x.length();i++) dp[i][0]=penalty_gap*i;
    for(int i=0;i<=y.length();i++) dp[0][i]=penalty_gap*i;

    for(int i=1;i<=x.length();i++)
    {
        for(int j=1;j<=y.length();j++)
        {
            dp[i][j]=min(dp[i][j-1]+penalty_gap, dp[i-1][j]+penalty_gap);
            if (x[i]==y[j]) dp[i][j]=min(dp[i][j],dp[i-1][j-1]);
            else dp[i][j]=min(dp[i][j],dp[i-1][j-1]+penalty_mismatch);
        }
    }

    string a="",b="";

    // reconstructing the solution;
    int i = x.length();
    int j=y.length();
    while(i>0 && j>0)
    {
        if(x[i]==y[j]) penalty_mismatch=0;
        else penalty_mismatch=1;

        if(dp[i][j]==dp[i-1][j-1]+penalty_mismatch)
        {
            a+=x[i];
            b+=y[j];
            i--;
            j--;
        } 
        else if (dp[i][j]==dp[i-1][j]+penalty_gap)
        {
            a+=x[i];
            b+=" ";
            i--;
        }
        else
        {
            a+=" ";
            b+=y[j];
            j--;
        }
    }
    while(i>0)
    {
        a+=x[i];
        b+=" ";
        i--;
    }
    while(j>0)
    {
        a+=" ";
        b+=y[j];
        j--;
    }
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    return {a,b};

}

int main()
{
    string x,y; //cin>>x>>y;
    x="AGGGCT";
    y="AGGCA";
    pair<string,string> res=aligned_strings(x,y);
    cout<<res.first<<"\n";
    cout<<res.second<<"\n";


}
