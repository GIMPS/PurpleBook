#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <map>
using namespace std;

int N,Q,tot=0;
int L[412345],R[412345],K[112345];
long long x[412345],y[412345],z[112345];
int bucket[1000000005];

int main() {
    int T,i,j,k,Tnum=1,maxR=0;
    int a1,b1,c1,m1;
    int a2,b2,c2,m2;
    int a3,b3,c3,m3;
    cin>>T;
    while(T--)
    {

        tot=0;
        cin>>N>>Q;
        cin>>x[1]>>x[2]>>a1>>b1>>c1>>m1;
        cin>>y[1]>>y[2]>>a2>>b2>>c2>>m2;
        cin>>z[1]>>z[2]>>a3>>b3>>c3>>m3;

        L[1] = min(x[1],y[1])+1;
        L[2] = min(x[2],y[2])+1;

        R[1] = max(x[1],y[1])+1;
        R[2] = max(x[2],y[2])+1;
        maxR = max(R[1],R[2]);

        K[1] = z[1]+1;
        K[2] = z[2]+1;

        for(i=3;i<=N;i++)
        {
            x[i] = (a1 * x[i-1] + b1*x[i-2]+c1) % m1;
            y[i] = (a2 * y[i-1] + b2*y[i-2]+c2) % m2;


            L[i] = min(x[i],y[i]) + 1;
            R[i] = max(x[i],y[i]) + 1;
            maxR = max(maxR,R[i]);

            tot += (R[i] - L[i] +1);
        }

        for(i=3;i<=Q;i++)
        {
            z[i] = (a3 * z[i-1] + b3*z[i-2]+c3) % m3;
            K[i] = z[i] + 1;
        }

        if(K[1] > tot)
        {
            printf("Case #%d: %d\n",Tnum++,0);
            continue;
        }

        for(i=1;i<=N;i++)
        {
            for(j=L[i];j<=R[i];j++)
            {
                bucket[j]++;
            }
        }

        for(i=maxR;i>=1;i--)
        {
            if(bucket[i]) K[1] -= bucket[i];
            bucket[i] = 0;
            if(K[1]<=0)
            {
                printf("Case #%d: %d\n",Tnum++,i);
                break;
            }
        }
        continue;
        
    }
    return 0;
}

/*
1
400000 1
3 1 4 1 5 100000009
2 7 1 8 2 100000009
4 8 15 16 23 42 100000009
 */