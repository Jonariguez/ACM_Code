#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<map>
#include<stack>
#include<queue>
#include<vector>

#define M 10007
#define ll long long
#define mod 1000000007
#define eps (1e-8)
using namespace std;
int n,m,k,flag;
int vis[1007][1007];
bool bfs(int x,int y)
{

    int a=vis[x][y-1];
    int b=vis[x-1][y];
    int c=vis[x][y+1];
    int d=vis[x+1][y];
    if(x==1)
    {
        if(y==1)
        {
            if(c&&d){vis[x][y]=1;return true;}
        }
        else if(y==m)
        {
            if(a&&d){vis[x][y]=1;return true;}
        }
        else
        {
            if((a&&d)||(c&&d))
            {
                vis[x][y]=1;
                return true;
            }
        }
    }
    if(x==n)
    {
        if(y==1)
        {
            if(b&&c)
            {
                vis[x][y]=1;
                return true;
            }
        }
        else if(y==m)
        {
            if(a&&b)
            {
                vis[x][y]=1;
                return true;
            }
        }
        else
        {
            if((b&&c)||(a&&b))
            {
                vis[x][y]=1;
                return true;
            }
        }
    }
    if(y==1)
    {
        if( b&&c || c&&d)
        {
            vis[x][y]=1;
            return true;
        }
    }
    if(y==n)
    {
        if(a&&b || d&&a)
        {
            vis[x][y]=1;
            return true;
        }
    }

    if((a&&b)||(a&&d)||(b&&c)||(c&&d))
    {
        vis[x][y]=1;
        return true;
    }
    return false;
}
int main()
{
    int T,kcase=1;
    scanf("%d",&T);
    while(T--)
    {
        int res=0;
        printf("Case #%d:\n",kcase++);
        memset(vis,0,sizeof(vis));
        scanf("%d%d%d",&n,&m,&k);
        int x,y;
        for(int i=0; i<k; i++)
            scanf("%d%d",&x,&y),vis[x][y]=1;
        while(true)
        {
            flag=0;
            for(int i=1; i<=n; i++)
                for(int j=1; j<=m; j++)
                    if(!vis[i][j])
                        if(bfs(i,j))flag=1;
            if(!flag)break;
        }
        for(int i=1; i<=n; i++)
            for(int j=1; j<=m; j++)
                if(vis[i][j])res++;
        printf("%d\n",res);
    }
    return 0;
}
