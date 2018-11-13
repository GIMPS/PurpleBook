#include <iostream>
#include <cstdio>
using namespace std;
int u[M], v[M], w[M], r[M], n, m, fa[N], rank[N];

bool cmp(const int i, const int j) { return w[i] < w[j]; }
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
void unite(int x, int y) {
    if(rank[x] < rank[y]) fa[x] = y;
    else { fa[y] = x; if(rank[x] == rank[y]) rank[x]++; }
}
int Kruskal() {
    int ans = 0;
    // 初始化并查集和r数组
    for(int i = 0; i < m; i++) { r[i] = i; fa[u[i]] = u[i]; fa[v[i]] = v[i]; rank[u[i]] = rank[v[i]] = 0; }
    sort(r, r + m, cmp);
    for(int i = 0; i < m; i++) {
        int e = r[i];
        int x = find(u[e]), y = find(v[e]);
        if(x != y) { ans += w[e]; unite(x, y); }
    }
    return ans;
}

int main() {

}