#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<cmath>
using namespace std;
const int maxn = 510, maxm = 510;
char map[maxn][maxm];
int w[maxn][maxm];
int vis[maxn][maxm];
int n,m;
bool find(int mid, int x, int y)
{
    if(x<0 || x>=n || y<0 || y>=m)
        return false;
    if(vis[x][y]==1) return false;
    else vis[x][y] =1;
    if(map[x][y] == 'J') return true;
    if(map[x][y] == '+') return false;
    if(w[x][y]==1) return false;
    return find(mid,x+1,y) || find(mid, x-1,y) || find(mid,x,y+1) || find(mid,x,y-1);
}
int main() {
    scanf("%d%d",&n,&m);
    pair<int,int> s,d;
    vector<pair<int,int>> t;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%c", &map[i][j]);
            if(map[i][j]=='\n'){
                j--;
                continue;
            }
            if(map[i][j] == 'V')
            {
                s.first = i;
                s.second = j;
            }
            if(map[i][j] == 'J')
            {
                d.first = i;
                d.second = j;
            }
            if(map[i][j] == '+')
            {
                t.push_back(make_pair(i,j));
            }
        }
    }

    int l =0,r = n+m-2,mid;
    while(l<r)
    {
        mid = (l+r+1)/2;
        memset(vis,0,sizeof(vis));
        memset(w,0,sizeof(w));
        for(int i=0;i<t.size();i++)
        {
            int x = t[i].first;
            int y = t[i].second;
            for(int k=0;k<=mid-1;k++)
            {
                int p = mid -1-k;
                int nx1 = x+k, ny1 = y+p;
                int nx2 = x+k, ny2 = y-p;
                int nx3 = x-k, ny3 = y+p;
                int nx4 = x-k, ny4 = y-p;
                if(nx1>=0 && nx1<n && ny1<m && ny1>=0)
                    w[nx1][ny1] = 1;
                if(nx2>=0 && nx2<n && ny2<m && ny2>=0)
                    w[nx2][ny2] = 1;
                if(nx3>=0 && nx3<n && ny3<m && ny3>=0)
                    w[nx3][ny3] = 1;
                if(nx4>=0 && nx4<n && ny4<m && ny4>=0)
                    w[nx4][ny4] = 1;
            }

        }
        if(find(mid,s.first,s.second))
                l = mid;
        else r = mid-1;
    }
    printf("%d",l);
}