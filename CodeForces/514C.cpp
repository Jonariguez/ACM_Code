/****************
*PID:514c div2
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn=600000+5;
const LL MOD=1000000000000000007;
LL n,m,fact[maxn];
char str[maxn];
set<LL> Hash;

LL getHash(char *s){
    int i,n=strlen(s);
    LL res=0;
    for(i=0;i<n;i++){
        res=res+(s[i]-'a'+1)*fact[i]%MOD;
        res%=MOD;
    }
    return res;
}

bool check(char *s){
    int i,j,n=strlen(s);
    LL now=getHash(s),temp;
    for(i=0;i<n;i++){
        for(j=1;j<=3;j++){
            if(j==s[i]-'a'+1) continue;
            temp=(now-(s[i]-'a'+1)*fact[i]+j*fact[i])%MOD;
            if(temp<0) temp+=MOD;
            if(Hash.count(temp)) return true;
        }
    }
    return false;
}

int main()
{
    int i,j;
    fact[0]=1;
    for(i=1;i<maxn;i++)
        fact[i]=(fact[i-1]*4)%MOD;
    while(scanf("%I64d%I64d",&n,&m)!=EOF){
        Hash.clear();
        for(i=0;i<n;i++){
            scanf("%s",str);
            Hash.insert(getHash(str));
        }
        while(m--){
            scanf("%s",str);
            if(check(str)) puts("YES");
            else puts("NO");
        }
    }
    return 0;
}
