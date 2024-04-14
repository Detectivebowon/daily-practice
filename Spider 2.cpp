#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
int n,m,q,ans[N],pa[N],compo=1;
pair<int,int> ask[N];
tuple<int,int,int> input[10004];
priority_queue<int> pq;
priority_queue<pair<int,int>> pqask;
int root(int x)
{
    if(pa[x]==x) return x;
    else return pa[x]=root(pa[x]);
}
int main()
{
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++)
        pa[i]=i;
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        input[i]={w,u,v};
    }
    sort(input+1,input+1+m);
    for(int i=1;i<=m;i++)
    {
        auto [w,u,v]=input[i];
        if(root(u)!=root(v))
        {
            // cout<<w<<"\n";
            pq.emplace(w);
            compo++;
            pa[root(u)]=root(v);
        }
    }
    for(int i=1;i<=q;i++)
    {
        int temp;
        cin>>temp;
        pqask.emplace(temp,i);
    }
    int cnt=n-compo;
    while(!pqask.empty())
    {
        while(pq.top()>pqask.top().first&&!pq.empty())
        {
            cnt+=1;
            pq.pop();
        }
        ans[pqask.top().second]=cnt;
        pqask.pop();
    }
    for(int i=1;i<=q;i++)
        cout<<ans[i]<<"\n";
}