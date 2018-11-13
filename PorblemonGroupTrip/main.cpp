#include <iostream>
#include<cstdio>
#include<queue>
using namespace std;
const int maxn =100 +10;

struct People{
    int idx,s1, s2, s3;
    bool operator < (const People &t) const
    {
        return idx > t.idx;
    }
}p[maxn];
priority_queue<People> q1,q2,q3,qq1,qq2,qq3;
int main()
{
    int T,Kase=0;
    scanf("%d",&T);
    while(T--)
    {
        Kase++;
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            int s1,s2,s3;
            scanf("%d%d%d",&s1,&s2,&s3);
            p[i].idx=i;
            p[i].s1=s1;
            p[i].s2=s2;
            p[i].s3=s3;
        }
        int max1 = p[0].s1,max2=p[0].s2,max3=p[0].s3;
        for(int i=0;i<n;i++)
        {
            if(p[i].s1>max1) max1 = p[i].s1;
            if(p[i].s2>max1) max2 = p[i].s2;
            if(p[i].s3>max1) max3 = p[i].s3;

        }
        int sum=0;
        for(int i=0;i<n;i++)
        {
            if(p[i].s1!=0)
                q1.push(p[i]);
            else if(p[i].s2!=0)
                q2.push(p[i]);
            else if(p[i].s3!=0)
                q3.push(p[i]);
        }
        if(!q1.empty())
        {
            qq1.push(q1.top());
            q1.pop();
        }
        if(!q2.empty())
        {
            qq2.push(q2.top());
            q2.pop();
        }
        if(!q3.empty())
        {
            qq3.push(q3.top());
            q3.pop();
        }
        while(1)
        {
            if(!q1.empty()&&qq1.empty())
            {
                qq1.push(q1.top());
                q1.pop();
            }
            if(!qq1.empty()) {
                while (qq1.top().s1 == 0) {
                    if(qq1.top().s2!=0)
                    {
                        q2.push(qq1.top());
                    }
                    else if(qq1.top().s3!=0)
                    {
                        q3.push(qq1.top());
                    }
                    qq1.pop();
                    if(!q1.empty())
                    {
                        qq1.push(q1.top());
                        q1.pop();
                    }
                    if (q1.empty()) break;
                }
            }
            if(!qq1.empty())
            {
                People t = qq1.top();
                qq1.pop();
                t.s1--;
                qq1.push(t);
            }
            if(!q2.empty()&&qq2.empty())
            {
                qq2.push(q2.top());
                q2.pop();
            }
            if(!qq2.empty()) {
                while (qq2.top().s2 == 0) {
                    if(qq2.top().s3!=0)
                    {
                        q3.push(qq2.top());
                    }
                    qq2.pop();
                    if(!q2.empty())
                    {
                        qq2.push(q2.top());
                        q2.pop();
                    }
                    if (q2.empty()) break;
                }
            }
            if(!qq2.empty())
            {
                People t = qq2.top();
                qq2.pop();
                t.s2--;
                qq2.push(t);
            }
            if(!q3.empty()&&qq3.empty())
            {
                qq3.push(q3.top());
                q3.pop();
            }
            if(!qq3.empty()){
                while(qq3.top().s3==0)
                {
                    qq3.pop();
                    if(!q3.empty())
                    {
                        qq3.push(q3.top());
                        q3.pop();
                    }
                    if(q3.empty()) break;
                }

            }

            if(!qq3.empty())
            {
                People t = qq3.top();
                qq3.pop();
                t.s3--;
                qq3.push(t);
            }

            if(q1.empty()&&q2.empty()&&q3.empty()&&qq1.empty()&&qq2.empty()&&qq3.empty())
            {
                break;
            }
            sum++;
//            if(sum%5==0)printf("%d %d %d \n",q1.empty()?-1:q1.top().idx+1,q2.empty()?-1:q2.top().idx+1,q3.empty()?-1:q3.top().idx+1);
        }
        printf("Case #%d: %d\n",Kase,sum);
        while(!q1.empty()) q1.pop();
        while(!q2.empty()) q2.pop();
        while(!q3.empty()) q3.pop();
        while(!q1.empty()) qq1.pop();
        while(!q2.empty()) qq2.pop();
        while(!q3.empty()) qq3.pop();
    }

}