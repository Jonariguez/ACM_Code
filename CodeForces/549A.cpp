#include <stdio.h>
#include <string.h>
#include <map>
#include <algorithm>
using namespace std;

const int maxn=55;
char a[maxn][maxn];

int main()
{
    int i,j,n,m,res;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            scanf(" %c",&a[i][j]);
    if(n<2 || m<2){
        printf("0\n");return 0;
    }
    res=0;
    for(i=1;i<n;i++){
        for(j=1;j<m;j++){
            map<char,int> mp;
            mp[a[i][j]]++;
            mp[a[i][j+1]]++;
            mp[a[i+1][j]]++;
            mp[a[i+1][j+1]]++;
            if(mp['f'] && mp['a'] && mp['c'] && mp['e'])
                res++;
        }
    }
    printf("%d\n",res);
    return 0;
}
