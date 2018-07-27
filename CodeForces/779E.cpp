/****************
*PID:
*Auth:Jonariguez
*****************
*/
#define lson k*2,l,m
#define rson k*2+1,m+1,r
#define rep(i,s,e) for(i=(s);i<=(e);i++)
#define For(j,s,e) For(j=(s);j<(e);j++)
#define sc(x) scanf("%d",&x)
#define In(x) scanf("%I64d",&x)
#define SS(x,y) scanf("d",&x,&y)
#define pf(x) printf("%d",x)
#define pfn(x) printf("%d\n",(x))
#define Pf(x) printf("%I64d",(x))
#define Pfn(x) printf("%I64d\n",(x))
#define Pc printf(" ")
#define PY puts("YES")
#define PN puts("NO")
#define MP make_pair
#define X first
#define Y second
#define PI acos(-1.0)
#include <stdio.h>
#include <string.h>
#include <string>
#include <math.h>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
typedef int Ll;
Ll quick_pow(Ll a,Ll b,Ll MOD){a%=MOD;Ll res=1;while(b){if(b&1)res=(res*a)%MOD;b/=2;a=(a*a)%MOD;}return res;}

const int maxn=200000+10;
const int MOD=1e9+7;

char str[5003][2500];
map<string,int> mp;
int n,m,val1[5003][1003],val2[5003][1003];

void cal(int a,int b,int op,int c,int d,int id){
    int i,j;
    if(op==2){
        if((a==b && str[id][a]=='?') || (c==d && str[id][c]=='?'))
            for(i=1;i<=m;i++){
                val1[id][i]=0;
                val2[id][i]=1;
            }
        else {
            int p1=mp[string(str[id],a,b-a+1)],p2=mp[string(str[id],c,d-c+1)];
            for(i=1;i<=m;i++){
                val1[id][i]=val2[id][i]=val
        return ;
    }
    if(op==1){
        if(a==b)





void solve1(){
    int i,j;
    mp.clear();
    for(i=1;i<=n;i++){
        j=0;
        while(str[i][j]!=' ') j++;
        string ss(str[i],0,j);
        mp[ss]=i;
        j+=4;   //¿ªÍ·
        if(str[i][j]=='0' || str[i][j]=='1'){
            int c=0;
            for(;str[i][j]!='\0';j++){
                c++;
                val1[i][c]=val[i][c]=(str[i][j]-'0');
            }
            continue;
        }
        int p1,p2,p3,p4;
        p1=j;
        p2=p1;
        while(str[i][p2]!=' ') p2++;
        p2--;
        int op;
        if(str[i][p2+2]=='O') op=0;
        else if(str[i][p2+2]=='X') op=1;
        else op=3;
        j=p2+2;
        while(str[i][j]!=' ') j++;
        p3=j+1;
        p4=p3;
        while(str[i][p4]!='\0') p4++;
        p4--;
        cal(p1,p2,op,p3,p4,i);
    }
}





int main()
{
    int i,j;
    while(scanf("%d%d",&n,&m)!=EOF){
        getchar();
        for(i=1;i<=n;i++)
            gets(str[i]);
    }
    return 0;
}

