#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <string>


#define long long ll;

#define Maxn 5000
int v[Maxn],u[Maxn],w[Maxn],s[Maxn],p[Maxn];
using namespace std;
int cmp(const int i, const int j){return w[i]<w[j];}
int find (int x) {return p[x]==x?x:p[x]=find (p[x]);}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    while(n!=0 || m!=0)
    {
        int ans,ret=10001;
        for(int i=1;i<=m;i++)
            s[i]=i;
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d%d",&u[i],&v[i],&w[i]);
        }
        sort(s+1,s+m+1,cmp);
        int l,r;
        ans=-1;
        for(l=1;l<=m;l++) {
            for(int i=1;i<=n;i++)
                p[i]=i;
            bool finish;

            for (r = l; r <= m; r++) {
                int e = s[r];
                int x = find(u[e]);
                int y = find(v[e]);
                if (x != y) {
                    p[x] = y;
                }
                finish = true;
                for (int i = 2; i <= n; i++) {
                    if (find(1) != find(i)) {

                        finish = false;
                        break;
                    }
                }
                if (finish) {
                    ans = w[s[r]] - w[s[l]];
                    break;
                }
            }
            if(ret>ans)
                ret=ans;
        }
        if(ret==10001)
            ret=-1;
        cout  << ret << endl;
        scanf("%d%d",&n,&m);
    }
    return 0;

} 
