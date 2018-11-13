#include <iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int maxk =1000+10;
int cnt[maxk];
int main()
{
    int k,n;
    memset(cnt,0,sizeof(cnt));
    scanf("%d%d",&k,&n);
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        cnt[x]++;
    }
    int mcc[n+1];
    memset(mcc,0,sizeof(mcc));
    for(int i=1;i<=k;i++)
    {
        mcc[cnt[i]]++;
    }
    int mccnt=0,nzcnt=0;
    vector<int> nzf;
    for(int i=0;i<=n;i++)
        if(mcc[i]!=0)
        {
            nzf.push_back(i);
            nzcnt+=1;
        }
    if(nzcnt>3)
    {
        printf("*");
        return 0;
    }
    if(nzcnt==2)
    {
        if(abs(nzf[0]-nzf[1])>1 || (mcc[nzf[0]]>1&&mcc[nzf[1]]>1))
        {
            printf("*");
            return 0;
        }
        else{
            if(mcc[nzf[0]]!=1)
            {
                int tmp;
                tmp =nzf[0];
                nzf[0] = nzf[1];
                nzf[1] = tmp;
            }
            for(int i=1;i<=k;i++)
            {
                if(cnt[i] == nzf[0])
                {
                    if(cnt[i]<nzf[1])
                    {
                        printf("+%d",i);
                    }
                    else{
                        printf("-%d",i);
                    }
                }
            }
        }
    }

    if(nzcnt==3)
    {
        if(abs(nzf[0]-nzf[1])>1 ||abs(nzf[2]-nzf[1])>1 || (mcc[nzf[0]]>1||mcc[nzf[2]]>1))
        {
            printf("*");
            return 0;
        }
        else{
            for(int i=1;i<=k;i++)
            {
                if(cnt[i] == nzf[2])
                {
                    if(cnt[i]<nzf[1])
                    {
                        printf("+%d",i);
                    }
                    else{
                        printf("-%d",i);
                    }
                }
            }
            printf(" ");
            for(int i=1;i<=k;i++)
            {
                if(cnt[i] == nzf[0])
                {
                    if(cnt[i]<nzf[1])
                    {
                        printf("+%d",i);
                    }
                    else{
                        printf("-%d",i);
                    }
                }
            }
        }
    }
//    for(int i=0;i<=n;i++)
//    {
//        printf("%d ",mcc[i]);
//        if(mcc[i]>mccnt)
//            mccnt = mcc[i];
//    }
//
//    int plus=-1,minus=-1;
//    bool succ=true;
//    for(int i=1;i<=k;i++)
//    {
//        if(cnt[i]-mccnt==-1){
//            if(plus==-1)
//            {
//                plus =i;
//            }
//            else
//            {
//                succ =false;
//                break;
//            }
//        }
//        if(cnt[i] -mccnt == 1)
//        {
//            if(minus==-1 )
//            {
//                minus =i;
//            }
//            else{
//                succ =false;
//                break;
//            }
//        }
//        if(cnt[i] -mccnt >=2 || cnt[i]-mccnt <=-2)
//        {
//            succ =false;
//            break;
//        }
//    }
//    if(succ)
//    {
//        if(plus !=-1)
//            printf("+%d",plus);
//        if(plus!=-1 && minus!=-1)printf(" ");
//        if(minus!=-1)printf("-%d",minus);
//    }
//    else
//        printf("*");


};



