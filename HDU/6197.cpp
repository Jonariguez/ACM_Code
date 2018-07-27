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
#include <malloc.h>
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

int upper_bd(int arr[], int s, int e, int key)
{
    int mid;
    if (arr[e] <= key)
        return e + 1;
    while (s < e)
    {
        mid = s + (e - s) / 2;
        if (arr[mid] <= key)
            s = mid + 1;
        else
            e = mid;
    }
    return s;
}

int LIS(int d[], int n)
{
    int i = 0, len = 1, *End = (int *)alloca(sizeof(int) * (n + 1));
    End[1] = d[0]; //初始化：长度为1的LIS末尾为d[0]
    for (i = 1; i < n; i++)
    {
        int pos = upper_bd(End, 1, len, d[i]); //找到插入位置
        End[pos] = d[i];
        if (len < pos) //按需要更新LIS长度
            len = pos;
    }
    return len;
}

int a[maxn],b[maxn];

int main()
{
    int i,j,n,T;
    scanf("%d",&T);
    while(T--){
        int k;
        scanf("%d%d",&n,&k);
        int t=n;
        for(i=0;i<n;i++){
            scanf("%d",&a[i]);
            b[--t]=a[i];
        }
        int res1=n-LIS(a,n);
        int res2=n-LIS(b,n);
        if(min(res1,res2)<=k)
            puts("A is a magic array.");
        else puts("A is not a magic array.");
    }
    return 0;
}

