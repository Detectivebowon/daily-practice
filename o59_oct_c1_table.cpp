#include<bits/stdc++.h>
using namespace std;
int r,c,m,va[307][5007],dp[307],cnt[307];
bool check[307][5007];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>r>>c>>m;
    while(m--)
    {
        int op;
        cin>>op;
        if(op==1)
        {
            int x,y,tmp;
            cin>>x>>y>>tmp;
            va[x][y]=tmp;
            dp[x]=INT_MAX;
            for(int i=1;i<=c;i++)
                dp[x]=min(dp[x],va[x][i]);
        }
        else if(op==2)
        {
            int x,tmp;
            cin>>x>>tmp;
            dp[x]=tmp;
            for(int i=1;i<=c;i++)
            {
                va[x][i]=tmp;
            }
        }
        else if(op==3)
        {
            int x,y;
            cin>>x>>y;
            cout<<va[x][y]<<"\n";
        }
        else if(op==4)
        {
            int ans=INT_MAX;
            for(int i=1;i<=r;i++)
            {
                ans=min(ans,dp[i]);
            }
            cout<<ans<<"\n";
        }
    }
}