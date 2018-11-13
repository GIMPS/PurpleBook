#include <iostream>
#include<cstdio>
#include<vector>
const int maxn = 100+10;
int a[maxn][maxn],visit[maxn][maxn],energy[maxn][maxn];
using namespace std;
int T,n,m,e,sr,sc,tr,tc;
int deltar[4]={-1,1,0,0};
int deltac[4]={0,0,1,-1};

int G[maxn*maxn][maxn*maxn];
void dfs(int r, int c)
{
    visit[r][c]=1;
    if(r==tr && c==tc)
        return;
    if(energy[r][c] < 0 || a[r][c] == -100000)
        return;
    for(int i=0;i<4;i++)
    {
        int newr = r+deltar[i];
        int newc = c+deltac[i];
        if(newr<=n && newr >=1 && newc<=m && newc >= 1)
        {
            if(visit[newr][newc] && energy[newr][newc]>= energy[r][c]+a[newr][newc])
                continue;
            energy[newr][newc] = energy[r][c]+a[newr][newc];
            dfs(newr,newc);
        }
    }
}

int main() {
    int Kase =0;
    cin >> T;
    while(T--)
    {
        Kase++;
        cin >> n >> m >> e >> sr >> sc >> tr >> tc;
        memset(visit,0,sizeof(visit));
        memset(energy,0,sizeof(energy));
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
            {
                cin >> a[i][j];
                G[(i-1)*n+m][(i-1)*n+m+1] = a[i][j];
                G[(i-1)*n+m][(i-1)*n+m-1] = a[i][j];
                G[(i-1)*n+m-1][(i-1)*n+m] = a[i][j];
                G[(i-1)*n+m-1][(i-1)*n+m] = a[i][j];
            }
        energy[sr][sc] = e;
        energy[tr][tc] = -100000;
        dfs(sr,sc);
        if(energy[tr][tc] == -100000)
        {
            cout << "Case #" << Kase << ": "<<-1<<endl;
        }
        else
            cout << "Case #" << Kase << ": " << energy[tr][tc]<<endl;


    }
}