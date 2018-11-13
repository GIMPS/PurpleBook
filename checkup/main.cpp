#include <iostream>
#include<cstdio>
using namespace std;
const int maxn =1e5+10;
int h[maxn];
int main() {
    int n,t;
    while(scanf("%d%d",&n,&t)==2){

        h[0]=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&h[i]);
        }
        int cur=2,start = -1,sum=0;
        for(int i=1;i<=n;i++)
        {
            if((cur-2)*h[i]+sum>start)
            {
                cur = (t-sum)/h[i]+1;
                start = (cur-1)*h[i]+sum;
            }
            else{
//            printf("%d %d %d\n",start,h[i],t);
                if(start+h[i]>t)
                {
                    start = start-h[i];
                    cur--;
                }
                else
                {
                    start = start+h[i];
                }
            }
            printf("%d\n",cur);
            sum+=h[i];
    }

    }
}