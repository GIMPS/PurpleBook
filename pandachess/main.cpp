#include <iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn = 1e5+10;
vector<int> G[maxn];
map<long long, int>  name;
int c[maxn];
int topo[maxn], t, n;
bool dfs(int u) {
	c[u] = -1;
	for (int i=0;i<G[u].size();i++){
		int v = G[u][i];
		if (c[v] < 0)return false;
		else if (!c[v]&& !dfs(v))return true;
	}
	c[u] = 1; topo[--t] = u;
	return true;
}
bool toposort() {
	t = n;
	memset(c, 0, sizeof(c));
	for (int u = 0; u < n; u++)if (!c[u])
		if (!dfs(u)) return false;
	return true;
}


int main() {
    int m,d;
    scanf("%d%d%d",&n,&m,&d);
    int cnt=0;
    for(int i=0;i<m;i++)
	{
		long long u,v;
		scanf("%lld%lld",&u,&v);
		if(name.find(u) == name.end())
			name[u]=cnt++;
		if(name.find(v) == name.end())
			name[v]=cnt++;
		if (find(G[name[u]].begin(), G[name[u]].end(),name[v])==G[name[u]].end()){
			G[name[u]].push_back(name[v]);
		}
	}
//	for(int i=0;i<n;i++)
//		sort(G[i].begin(),G[i].end());
	toposort();
//	for(int i=0;i<n;i++) printf("%d ", topo[i]);
    int inverse_topo[n];
    for(int i=0;i<n;i++)
    	inverse_topo[topo[i]] = i;
	vector<int> ord;
    for(int i=0; i<n;i++)
	{
		long long u;
		scanf("%lld",&u);
		if(name.find(u) == name.end()) continue;
		else
		{
			ord.push_back(inverse_topo[name[u]]);
		}
	}
    int lis[n];
    int maxl = 0;
	for(int i=0;i<ord.size();i++)
	{
		int pos = upper_bound(lis,lis+maxl,ord[i])-lis;
		if(pos==maxl) maxl=pos+1;
	}

	printf("%d", 2*(n-maxl) );


}