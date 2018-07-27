/*
注意，只要是lgor猜对一个就算猜对，
所以构造出来的就是lgor一个都没猜对
*/
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=100+10;
char s[maxn][maxn];
int d[maxn];
vector<int> v;

int main()
{
    int i,j,n,flag;
    while(scanf("%d",&n)!=EOF){
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                scanf(" %c",&s[i][j]);
        flag=0;
        for(i=1;i<=n;i++)
            scanf("%d",&d[i]);
        v.clear();
        while(true){
            flag=0;
            for(i=1;i<=n;i++)
                if(d[i]==0){
                    flag=1;
                    v.push_back(i);
                    for(j=1;j<=n;j++)
                        if(s[i][j]=='1')
                            d[j]--;
                }
            if(flag==0) break;
        }
        printf("%d\n",v.size());
        for(i=0;i<v.size();i++)
            printf("%d%c",v[i],i==v.size()-1?'\n':' ');
    }
    return 0;
}

