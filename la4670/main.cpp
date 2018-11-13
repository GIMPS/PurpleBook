#include<iostream>
#include<algorithm>
#include<cassert>
#include<string>
#include<sstream>
#include<set>
#include<bitset>
#include<vector>
#include<stack>
#include<map>
#include<queue>
#include<deque>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<ctime>
#include<cctype>
#include<functional>
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;

#define me(s)  memset(s,0,sizeof(s))
#define rep(i,n) for(int i=0;i<(n);i++)
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
//typedef pair <int, int> P;


const int sigma_size=26;
const int maxnode=11000;
const int maxs=150+10;

map<string,int>ms;

struct AhoCorasickAutomata
{
    int ch[maxnode][sigma_size];
    int val[maxnode];
    int f[maxnode];
    int cnt[maxnode];
    int last[maxnode];
    int sz;
    void init()
    {
        sz=1;
        me(ch[0]);me(cnt);
        ms.clear();
    }

    int idx(char c){return c-'a';}

    void insert(char*s,int v)
    {
        int u=0,n=strlen(s);
        for(int i=0;i<n;i++)
        {
            int c=idx(s[i]);
            if(!ch[u][c])
            {
                me(ch[sz]);
                val[sz]=0;
                ch[u][c]=sz++;
            }
            u=ch[u][c];
        }
        val[u]=v;
        ms[string(s)]=v;
    }
    void print(int j)
    {
        if(j)
        {
            cnt[val[j]]++;
            print(last[j]);
        }
    }
    void find(char*T)
    {
        int n=strlen(T);
        int j=0;
        for(int i=0;i<n;i++)
        {
            int c=idx(T[i]);
            while(j&&!ch[j][c])j=f[j];
            j=ch[j][c];
            if(val[j])print(j);
            else if(last[j])print(last[j]);
        }
    }
    void getFail()
    {
        queue<int>q;
        f[0]=0;
        for(int c=0;c<sigma_size;c++)
        {
            int u=ch[0][c];
            if(u){f[u]=0;q.push(u);last[u]=0;}
        }
        while(!q.empty())
        {
            int r=q.front();q.pop();
            for(int c=0;c<sigma_size;c++)
            {
                int u=ch[r][c];
                if(!u)continue;
                q.push(u);
                int v=f[r];
                while(v&&!ch[v][c])v=f[v];
                f[u]=ch[v][c];
                last[u]=val[f[u]]?f[u]:last[f[u]];
            }
        }
    }
};

AhoCorasickAutomata ac;
char text[1000001],P[151][80];
int n,T;

int main()
{
    while(~scanf("%d",&n)&&n)
    {
        ac.init();
        for(int i=1;i<=n;i++)
        {
            scanf("%s",P[i]);
            ac.insert(P[i],i);
        }
        ac.getFail();
        scanf("%s",text);
        ac.find(text);
        int best=-1;
        for(int i=1;i<=n;i++)
            if(ac.cnt[i]>best)best=ac.cnt[i]; //寻找最大的次数
        printf("%d\n",best);
        for(int i=1;i<=n;i++)
            if(ac.cnt[i]==best)//输出出现次数等于best的字符串
                printf("%s\n",P[i]);

    }
}

