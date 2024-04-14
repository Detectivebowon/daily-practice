#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
int n,m,pa[N],cnt=0;
int root(int x)
{
    if(pa[x]==x) return x;
    else return pa[x]=root(pa[x]);
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        pa[i]=i;
    while(m--)
    {
        int u,v;
        cin>>u>>v;
        if(root(u)!=root(v))
        {
            n--;
            pa[root(u)]=root(v);
        }
    }
    cout<<n-1;

}