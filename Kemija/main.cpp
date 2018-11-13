#include <iostream>
#include<cstring>
using namespace std;
long long n;
int main() {
    cin>>n;
    long long a[n];
    long long x[n];
    for(long long i=0;i<n;i++)
        cin>>a[i];
    long long cur =0;
    memset(x,0,sizeof(x));

    if(n%3==0)
    {
        x[(cur+3)%n] = x[cur]+a[(cur+2)%n]-a[(cur+1)%n];
        cur = (cur+3)%n;
        while(cur!=0)
        {
            x[(cur+3)%n] = x[cur]+a[(cur+2)%n]-a[(cur+1)%n];
            cur = (cur+3)%n;
        }
        cur =1;
        x[(cur+3)%n] = x[cur]+a[(cur+2)%n]-a[(cur+1)%n];
        cur = (cur+3)%n;
        while(cur!=1)
        {
            x[(cur+3)%n] = x[cur]+a[(cur+2)%n]-a[(cur+1)%n];
            cur = (cur+3)%n;
        }
        cur =2;
        x[(cur+3)%n] = x[cur]+a[(cur+2)%n]-a[(cur+1)%n];
        cur = (cur+3)%n;
        while(cur!=2)
        {
            x[(cur+3)%n] = x[cur]+a[(cur+2)%n]-a[(cur+1)%n];
            cur = (cur+3)%n;
        }

        long long diff = (a[1] -x[0] -x[1] -x[2]);

        long long min0 = x[0];
        for(long long i=0;i<n;i+=3)
        {
            if(x[i]<min0) min0 = x[i];
        }
        for(long long i=0;i<n;i+=3)
        {
            x[i]-=min0;
        }
        long long min1 = x[1];
        for(long long i=1;i<n;i+=3)
        {
            if(x[i]<min1) min1 = x[i];
        }
        for(long long i=1;i<n;i+=3)
        {
            x[i]-=min1;
        }

        for(long long i=2;i<n;i+=3)
        {
            x[i]+=(diff+min1+min0);
        }
        for(long long i=0;i<n;i++)
        {
            cout<<x[i]<<endl;
        }
        return 0;
    }
    else{
        x[(cur+3)%n] = x[cur]+a[(cur+2)%n]-a[(cur+1)%n];
        cur = (cur+3)%n;
        while(cur!=0)
        {
            x[(cur+3)%n] = x[cur]+a[(cur+2)%n]-a[(cur+1)%n];
            cur = (cur+3)%n;
        }
        long long diff = (a[1] -x[0] -x[1] -x[2])/3;
        for(long long i=0;i<n;i++)
        {
            cout<<x[i]+diff<<endl;
        }
    }
}