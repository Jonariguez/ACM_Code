/****************
*PID:519d div2
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <map>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=100000+10;
int v[30];
LL sum[maxn];
char str[maxn];
map<LL,int> mp[30];

int main()
{
    int i,j,k,n,m;
    for(i=0;i<26;i++)
        scanf("%d",&v[i]);
    scanf("%s",str+1);
    n=strlen(str+1);
    sum[0]=0;
    for(i=1;i<=n;i++)
        sum[i]=sum[i-1]+v[str[i]-'a'];
    LL res=0;
    for(i=1;i<=n;i++){
        int x=str[i]-'a';
        res+=mp[x][sum[i-1]];
        mp[x][sum[i]]++;
    }
    printf("%I64d\n",res);
    return 0;
}

