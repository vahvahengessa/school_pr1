#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
struct count_money
{
    ll a;
    ll b;
   // ll reqno;
};
 
struct seat_q
{
    ll a;
    bool b;
};
 
map<//,//>mp;
 
count_money request[1009];
seat_q seat[1009];
 
ll binarySearch(ll n,ll key)
{
    ll l=0,h=n;
    ll mid,ans=-1;
    while(h-l>=0)
    {
        mid=(h+l)/2;
        if(seat[mid].a>=key && seat[mid].b==0)
        {
            ans=mid;
            h=mid-1;
        }
        else
            l=mid+1;
    }
    return ans;
}
 
bool comp(count_money x,count_money y)
{
    if(x.b>y.b)
        return 1;
    else if(x.b==y.b && x.a<y.b)
        return 1;
    return 0;
}
 
 
 
ll getMax(ll att,ll n,ll m)
{
    if(att==n)
        return 0;
    ll profit1,profit2;
    ll t=binarySearch(m,request[att].a);
    if(t!=-1)
    {
        seat[t].b=1;
        profit1=request[att].b+getMax(att+1,n,m);
        seat[t].b=0;
    }
    else
        profit1=0;
    profit2=getMax(att+1,n,m);
    return max(profit1,profit2);
}
 
int main()
{
    freopen("input.txt","r",stdin);
    ll reqcount,seatcount;
    scanf("%lld",&reqcount);
    ll a,b;
    for(auto i=0; i<reqcount; i++)
    {
        scanf("%lld %lld",&request[i].a,&request[i].b);
        //request[i].reqno=i+1;
    }
    scanf("%lld",&seatcount);
    for(auto i=0; i<seatcount; i++)
    {
        scanf("%lld",&seat[i].a);
        seat[i].b=0;
    }
    cout<<getMax(0,reqcount,seatcount)<<endl;
}
