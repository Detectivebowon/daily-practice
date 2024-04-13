#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,s,mxt,dp[107][100007],mx[100007],ans=INT_MIN;
int check[107][100007];
signed main()
{
    cin>>n>>m>>s;
    while(m--)
    {
        int t,h,b;
        cin>>t>>h>>b;
        check[h][t]=b;
        mxt=max(t,mxt);
    }
    for(int i=0;i<=n+1;i++)
        for(int j=0;j<=mxt+1;j++)
            dp[i][j]=INT_MIN;
    dp[s][0]=0;
    for(int j=1;j<=mxt;j++)
    {
        for(int i=1;i<=n;i++)
        {
            if(dp[i-1][j-1]==INT_MIN&&dp[i][j-1]==INT_MIN&&dp[i+1][j-1]==INT_MIN)
                {
                    dp[i][j]=dp[i][j-1];
                    continue;
                }
            if(check[i][j])
            {
                dp[i][j]=max({dp[i-1][j-1],dp[i][j-1],dp[i+1][j-1]})+check[i][j];
            }
            else
            {
                dp[i][j]=max({dp[i-1][j-1],dp[i][j-1],dp[i+1][j-1]});
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        ans=max(ans,dp[i][mxt]);
    }
    cout<<ans;
}


