#include<iostream>
#include<bits/stdc++.h>
#define in(x) scanf("%d",&x)
#define pii pair<int,int>
#define m_p make_pair
#define all(v) (v.begin(),v.end())
using namespace std;
map<pair<pii,pii>,bool>mp;
int main()
{
    ios::sync_with_stdio(0);
    cout<<"enter height and width\n";
    int H,W;
    cin>>H>>W;
    cout<<"enter number of bad node\n";
    int n;
    cin>>n;
    cout<<"enter the bad paths in a group of four\n";
    int p,q,r,s;
    for(int i=0;i<n;i++)
    {
        cin>>p>>q>>r>>s;
        if(p+q==r+s+1)
            mp[m_p(m_p(p,q),m_p(r,s))]=1;
        else
            mp[m_p(m_p(r,s),m_p(p,q))]=1;
    }
    int DP[H+1][W+1];
    for(int i=0;i<=H;i++) for(int j=0;j<=W;j++) DP[i][j]=0;
    DP[0][0]=1;
    for(int i=0;i<=H;i++)
    {
        for(int j=0;j<=W;j++)
        {
            pair<pii,pii> ver=m_p(m_p(i,j),m_p(i,j-1));
            if(j>=1&&!mp[ver])
                DP[i][j]+=DP[i][j-1];
            pair<pii,pii> hor=m_p(m_p(i,j),m_p(i-1,j));
            if(i>=1&&!mp[hor])
                DP[i][j]+=DP[i-1][j];
        }
    }
    cout<<"answer\n";
    cout<<DP[H][W]<<endl;

    return 0;
}

