#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    int n;
    cout<<"enter the number of elements\n";
    cin>>n;
    int a[n];
    cout<<"enter the array\n";
    for(int i=0;i<n;i++)
        cin>>a[i];
    int DP[n][2];
    DP[0][0]=1;
    DP[0][1]=1;
    for(int i=0;i<n;i++)
    {
        DP[i][0]=1;
        for(int j=i-1;j>=0;j--)
        {
            if(a[j]>a[i])
                DP[i][0]=max(DP[i][0],DP[j][1]+1);
        }
        DP[i][1]=1;
        for(int j=i-1;j>=0;j--)
        {
            if(a[j]<a[i])
                DP[i][1]=max(DP[i][1],DP[j][0]+1);
        }
    }
    int MAXIMUM=1;
    cout<<"length of the maximum subsequence is ";
    for(int i=0;i<n;i++)
        MAXIMUM=max(MAXIMUM,max(DP[i][0],DP[i][1]));
    cout<<MAXIMUM<<endl;
    return 0;
}

