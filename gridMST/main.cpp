#include <iostream>
#include <vector>
#include<cstdio>
#include<math.h>
#include<algorithm>
const int M=1e9, N=1e5;
using namespace std;

int u[M], v[M], w[M], r[M], n, m, fa[N], k[N];

bool cmp(const int i, const int j) { return w[i] < w[j]; }
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
void unite(int x, int y) {
    if(k[x] < k[y]) fa[x] = y;
    else { fa[y] = x; if(k[x] == k[y]) k[x]++; }
}
int Kruskal() {
    int ans = 0;
    // 初始化并查集和r数组
    for(int i = 0; i < m; i++) { r[i] = i; fa[u[i]] = u[i]; fa[v[i]] = v[i]; k[u[i]] = k[v[i]] = 0; }
    sort(r, r + m, cmp);
    for(int i = 0; i < m; i++) {
        int e = r[i];
        int x = find(u[e]), y = find(v[e]);
        if(x != y) { ans += w[e]; unite(x, y); }
    }
    return ans;
}

int main()
{
    scanf("%d",&n);
    m=n*n;
    pair<int,int> p[n];
    for(int i=0;i<n;i++)
    {
        int x,y;
        scanf("%d%d", &x,&y);
        p[i] = make_pair(x,y);
    }
    int cnt=0;
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
        {
            u[cnt]=i;
            v[cnt]=j;
            w[cnt] = abs(p[i].first-p[j].first)+abs(p[i].second-p[j].second);
            cnt++;
        }

    printf("%d", Kruskal());

}