#include<bits/stdc++.h>
using namespace std;
 
long long pos(long long DP[], long long l,long long r,long long key);
long long lis(long long a[], long long  l);
 
int main()
{
	long long ans,t,n,i,a[20010];
    cin>>t;
    while(t--)
    {
    	cin>>n;
        for(i=0;i<n;i++){
        	cin>>a[i];
        	a[i+n]=a[i];
        }
        ans=0;
        for(i=0;i<n;i++){
        	ans=max(ans,lis(a+i,n));
        }
        cout<<ans<<endl;
    }
    return 0;
}
 
inline long long  pos(long long DP[], long long l,long long r,long long key)
{
    while(r-l>1)
    {
        long long m=l+(r-l)/2;
        if(DP[m]>=key){
        	r=m;
		}
        else{
        	l=m;
		}
    }
    return r;
}
 
long long lis(long long a[], long long  l)
{
    long long len,i;
    long long DP[10001];
    for(i=0;i<10001;++i){
    	DP[i]=0;
	}
    DP[0]=a[0];
    len=1;
    for(i=1;i<l;i++)
    {
        if(a[i]<DP[0]){
        	DP[0]=a[i];
		}
        else if(a[i]>DP[len-1]){
        	DP[len++]=a[i];
		}
        else{
        	DP[pos(DP,-1,len-1,a[i])]=a[i];
		}   
    }
    return len;
}



