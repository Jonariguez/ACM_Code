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
typedef vector<int> vec;
typedef vector<vec> mat;
const int N = 1100;
const int A = 30;
Ll quick_pow(Ll a,Ll b,Ll MOD){a%=MOD;Ll res=1;while(b){if(b&1)res=(res*a)%MOD;b/=2;a=(a*a)%MOD;}return res;}

const int maxn=200000+10;
const int MOD=1e9+7;


map<char, int> mp;

struct ACAutomata {

    int next[N][A], fail[N],End[N];
    int root, L;

    int idx(char ch)
    {
        return mp[ch];
    }
    int newNode()
    {
        for (int i = 0; i < A; ++i) next[L][i] = -1;
        End[L] = 0;
        return L++;
    }
    void init()
    {
        L = 0;
        root = newNode();
    }
    void insert(char buf[])
    {
        int len = strlen(buf);
        int now = root;
        for (int i = 0; i < len; ++i) {
            int ch = idx(buf[i]);
            if (next[now][ch] == -1) next[now][ch] = newNode();
            now = next[now][ch];
        }
        End[now]++;
    }
    void build()
    {
        queue<int> Q;
        fail[root] = root;
        for (int i = 0; i < A; ++i) {
            if (next[root][i] == -1) {
                next[root][i] = root;
            } else {
                fail[ next[root][i] ] = root;
                Q.push( next[root][i] );
            }
        }
        while (Q.size()) {
            int now = Q.front();
            Q.pop();
            if (End[ fail[now] ]) End[now]++; //!!
            for (int i = 0; i < A; ++i) {
                if (next[now][i] == -1) {
                    next[now][i] = next[ fail[now] ][i];
                } else {
                    fail[ next[now][i] ] = next[ fail[now] ][i];
                    Q.push(next[now][i]);
                }
            }
        }
    }
    mat query(int n)
    {
        mat F(L, vec(L));
        for (int i = 0; i < L; ++i) {
            for (unsigned j = 0; j < mp.size(); ++j) {
                int nt = next[i][j];
                if (!End[nt]) F[i][nt]++;
            }
        }
        return F;
    }

} ac;

char word[1005];
LL dp[2][1100];

int main()
{
    int i,n, m, p;
    for(i=0;i<26;i++)
        mp[i+'a']=i;
    while (scanf("%d%d", &n, &m)!=EOF) {
        m=n;
        n=26;
        ac.init();
        scanf("%s",word);
        ac.insert(word);
        ac.build();
        mat F=ac.query(m);
        int now = 0;
        dp[now][0]=1;
        for (int i=1;i<ac.L;++i) dp[now][i] = 0;
        for (int i=1;i<=m;++i){
            now ^= 1;
            for (int j=0;j<ac.L;++j) dp[now][j] = 0;
            for (int j=0;j<ac.L;++j)
                for (int k = 0; k < ac.L; ++k)
                    if (F[j][k]){
                        dp[now][k]=dp[now][k]+dp[now^1][j]*F[j][k];
                        dp[now][k]%=MOD;
                    }
        }
        LL res = 0;
        for (int i = 0; i < ac.L; ++i){
            res=res+dp[now][i];
            res%=MOD;
        }
        printf("%lld\n",res);
    }
    return 0;
}

