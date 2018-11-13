#include <iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main() {
    int map[4][4];
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
        {
            scanf("%d",&map[i][j]);
        }
    int m;
    scanf("%d",&m);
    int res[4][4];
    memset(res,0,sizeof(res));


    if(m==0)
    {
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                if(map[i][j]==0) continue;
                else
                {
                    for(int k=j+1;k<4;k++)
                        if(map[i][k]==0) continue;
                        else
                        {
                            if(map[i][j]==map[i][k])
                            {
                                map[i][j]*=2;
                                map[i][k]=0;
                                break;
                            }
                            else break;
                        }
                }
            }
        }

        for(int i=0;i<4;i++)
        {
            int j=0,k=0;
            while(j<4)
            {
                if(map[i][j]==0)
                {
                    j++;
                    continue;
                }
                else{
                    res[i][k]=map[i][j];
                    k++;
                    j++;
                }
            }
        }

    }



    if(m==1)
    {
        for(int j=0;j<4;j++)
        {
            for(int i=0;i<4;i++)
            {
                if(map[i][j]==0) continue;
                else
                {
                    for(int k=i+1;k<4;k++)
                        if(map[k][j]==0) continue;
                        else
                        {
                            if(map[i][j]==map[k][j])
                            {
                                map[i][j]*=2;
                                map[k][j]=0;
                                break;
                            }
                            else break;
                        }
                }
            }
        }

        for(int j=0;j<4;j++)
        {
            int i=0,k=0;
            while(i<4)
            {
                if(map[i][j]==0)
                {
                    i++;
                    continue;
                }
                else{
                    res[k][j]=map[i][j];
                    k++;
                    i++;
                }
            }
        }

    }




    if(m==2)
    {
        for(int i=0;i<4;i++)
        {
            for(int j=3;j>=0;j--)
            {
                if(map[i][j]==0) continue;
                else
                {
                    for(int k=j-1;k>=0;k--)
                        if(map[i][k]==0) continue;
                        else
                        {
                            if(map[i][j]==map[i][k])
                            {
                                map[i][j]*=2;
                                map[i][k]=0;
                                break;
                            }
                            else break;
                        }
                }
            }
        }

        for(int i=0;i<4;i++)
        {
            int j=3,k=3;
            while(j>=0)
            {
                if(map[i][j]==0)
                {
                    j--;
                    continue;
                }
                else{
                    res[i][k]=map[i][j];
                    k--;
                    j--;
                }
            }
        }

    }




    if(m==3)
    {
        for(int j=0;j<4;j++)
        {
            for(int i=3;i>=0;i--)
            {
                if(map[i][j]==0) continue;
                else
                {
                    for(int k=i-1;k>=0;k--)
                        if(map[k][j]==0) continue;
                        else
                        {
                            if(map[i][j]==map[k][j])
                            {
                                map[i][j]*=2;
                                map[k][j]=0;
                                break;
                            }
                            else break;
                        }
                }
            }
        }

        for(int j=0;j<4;j++)
        {
            int i=3,k=3;
            while(i>=0)
            {
                if(map[i][j]==0)
                {
                    i--;
                    continue;
                }
                else{
                    res[k][j]=map[i][j];
                    k--;
                    i--;
                }
            }
        }

    }







    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            printf("%d",res[i][j]);
            if(j!=3) printf(" ");
        }
        if(i!=3) printf("\n");

    }


}