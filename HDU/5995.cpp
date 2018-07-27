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
const int _K=50268147,_B=6082187,_P=100000007;
int _X;
inline int get_rand(int _l,int _r){
	_X=((long long)_K*_X+_B)%_P;
	return _X%(_r-_l+1)+_l;
}
int n,m,k,seed;
int x[1000006],y[1000006];
int row[1000006],col[1000006];
void Init(){
	scanf("%d%d%d%d",&n,&m,&k,&seed);
	_X=seed;
	memset(row,0,sizeof(row));
	memset(col,0,sizeof(col));
	int res1=n,res2=m;
	for (int i=1;i<=k;++i){
		x[i]=get_rand(1,n);
		y[i]=get_rand(1,m);
		if(!row[x[i]]) res1--;
		if(!col[y[i]]) res2--;
		row[x[i]]=1;
		col[y[i]]=1;
	}
    printf("%d %d\n",res1,res2);
}

int main()
{
    int i,j,T;
    scanf("%d",&T);
    while(T--){
        Init();
    }
    return 0;
}


