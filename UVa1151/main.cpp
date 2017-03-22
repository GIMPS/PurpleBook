// UVa1151 Buy or Build
// Rujia Liu
#include<cstdio>
#include<cmath>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn = 1000 + 10;
const int maxq = 8;
int n;
int x[maxn], y[maxn], cost[maxq];
vector<int> subn[maxq];

int pa[maxn];
int findset(int x) { return pa[x] != x ? pa[x] = findset(pa[x]) : x; }

struct Edge {
    int u, v, d;
    Edge(int u, int v, int d):u(u),v(v),d(d) {}
    bool operator < (const Edge& rhs) const {
        return d < rhs.d;
    }
};

// initialize pa and sort e before calling this method
// cnt is the current number of components
int MST(int cnt, const vector<Edge>& e, vector<Edge>& used) {
    if(cnt == 1) return 0;
    int m = e.size();
    int ans = 0;
    used.clear();
    for(int i = 0; i < m; i++) {
        int u = findset(e[i].u), v = findset(e[i].v);
        int d = e[i].d;
        if(u != v) {
            pa[u] = v;
            ans += d;
            used.push_back(e[i]);
            if(--cnt == 1) break;
        }
    }
    return ans;
}

int main() {
    int T, q;
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &n, &q);
        for(int i = 0; i < q; i++) {
            int cnt;
            scanf("%d%d", &cnt, &cost[i]);
            subn[i].clear();
            while(cnt--) {
                int u;
                scanf("%d", &u);
                subn[i].push_back(u-1);
            }
        }
        for(int i = 0; i < n; i++) scanf("%d%d", &x[i], &y[i]);

        vector<Edge> e, need;
        for(int i = 0; i < n; i++)
            for(int j = i+1; j < n; j++) {
                int c = (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]);
                e.push_back(Edge(i, j, c));
            }

        for(int i = 0; i < n; i++) pa[i] = i;
        sort(e.begin(), e.end());

        int ans = MST(n, e, need);
        for(int mask = 0; mask < (1<<q); mask++) {
            // union cities in the same sub-network
            for(int i = 0; i < n; i++) pa[i] = i;
            int cnt = n, c = 0;
            for(int i = 0; i < q; i++) if(mask & (1<<i)) {
                    c += cost[i];
                    for(int j = 1; j < subn[i].size(); j++) {
                        int u = findset(subn[i][j]), v = findset(subn[i][0]);
                        if(u != v) { pa[u] = v; cnt--; }
                    }
                }
            vector<Edge> dummy;
            ans = min(ans, c + MST(cnt, need, dummy));
        }
        printf("%d\n", ans);
        if(T) printf("\n");
    }
    return 0;
}
/*
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <cstring>

#define ll long long
using namespace std;
#define maxn 1001

ll w[maxn],p[maxn],r[maxn*maxn],x[maxn],y[maxn],u[maxn],v[maxn],net[10][maxn],netcost[10];
ll mst[maxn*maxn],mstu[maxn*maxn],mstv[maxn*maxn],mstw[maxn*maxn],mstr[maxn*maxn];
int cmp(const int i, const int j){return w[i]<w[j];}
int mstcmp(const int i, const int j){return mstw[i]<mstw[j];}
ll find (ll x){return p[x]==x?x:p[x]=find(p[x]);}


int main()
{
    int n;
    cin >> n;
    for(int kase=1;kase<=n;kase++)
    {
        int m,k,cost=0;
        cin >> m >> k;
        for(int i=1;i<=k;i++)
        {
            int num;
            cin >> num;
            cin >> netcost[i];
            net[i][0] = num;
            for (int j = 1; j <= num; j++)
            {
                cin >> net[i][j];
            }
        }
        for(int i=1;i<=m;i++)
        {
            cin >> x[i];
            cin >> y[i];
        }

        for (int i=1;i<=m;i++)
        {
            for(int j=1;j<=m;j++)
            {
                int idx=(i-1)*m+j;
                u[idx]=i;
                v[idx]=j;
                w[idx]=sqrt(pow((x[i]-x[j]),2)+pow((y[i]-y[j]),2));
            }
        }
        for (int i=1;i<=m*m;i++)
            r[i]=i;
        for(int i=1;i<=m;i++)
            p[i]=i;
        sort(r+1,r+m*m,cmp);
        int cnt=0;
        for(int i=1;i<=m;i++)
        {
            ll e=r[i];
            ll a,b;
            a=find(u[e]);
            b=find(v[e]);
            if(a!=b)
            {
                cost+=w[e];
                cnt++;
                p[a]=b;
                mstw[cnt]=w[e];
                mstu[cnt]=u[e];
                mstv[cnt]=v[e];
            }
        }
        for(int i=0;i<(1<<m);i++)
        {
            int len=cnt,sum=0;
            for(int j=0;j<m;j++)
                if(i&(1<<j))
                {

                    for(int q=1;q<net[j][0];q++)
                    {
                        mstu[len+q]=net[j+1][q];
                        mstv[len+q]=net[j+1][q+1];
                        mstw[len+q]=0;
                    }
                    len+=net[j+1][0];
                    sum+=netcost[j+1];
                }
            for(int j=1;j<=m;j++)
            {
                p[j]=j;
            }
            for(int j=1;j<=m+len-1;j++)
            {
                mstr[j]=j;
            }
            sort(mstr+1,mstr+m+len,mstcmp);
            for(int i=1;i<=m+len;i++)
            {
                ll e=mstr[i];
                ll a=find(mstu[e]);
                ll b=find(mstv[e]);
                if(a!=b)
                {
                    sum+=mstw[e];
                    p[a]=b;
                }
            }
            if(sum<cost)
                cost=sum;
        }
        cout << cost << endl;
    }
}

*/