/****************
*PID:hdu5517
*Auth:Jonariguez
*****************
*/
#define lson k*2,l,m
#define rson k*2+1,m+1,r
#define rep(i,s,e) for(i=(s);i<=(e);i++)
#define For(j,s,e) For(j=(s);j<(e);j++)
#define sc(x) scanf("%d",&x)
#define In(x) scanf("%I64d",&x)
#define pf(x) printf("%d",x)
#define pfn(x) printf("%d\n",(x))
#define Pf(x) printf("%I64d",(x))
#define Pfn(x) printf("%I64d\n",(x))
#define Pc printf(" ")
#define PY puts("YES")
#define PN puts("NO")
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

const int maxn=100000+10;
const int Size=1000+10;
int b[maxn],cnt_b[maxn];

struct node{
    int c,d;
    bool operator < (const node &r) const {
        if(c==r.c)
            return d>r.d;
        return c>r.c;
    }
};
vector<node> e[maxn];
//a:decreasing
struct point{
    int a,c,d;
    LL cnt;
    bool operator < (const point &r) const {
        if(a==r.a){
            if(c==r.c)
                return d>r.d;
            return c>r.c;
        }
        return a>r.a;
    }
    bool operator == (const point &r) const {
        return !(r<(*this) || (*this)<r);
    }
};

vector<point> vec;

void Init(){
    memset(b,0,sizeof(b));
    memset(cnt_b,0,sizeof(cnt_b));
    for(int i=0;i<=100000;i++)
        e[i].clear();
    vec.clear();
}

struct BIT{
    int bit[Size][Size];
    void Ini(){
        memset(bit,0,sizeof(bit));
    }
    int lowbit(int i){ return i&(-i);}
    void add(int x,int y,int v){
        int tempx=x,tempy;
        while(tempx<=1000){
            tempy=y;
            while(tempy<=1000){
                bit[tempx][tempy]+=v;
                tempy+=lowbit(tempy);
            }
            tempx+=lowbit(tempx);
        }
    }
    int sum(int x,int y){
        int res=0,tempx=x,tempy;
        while(tempx>=1){
            tempy=y;
            while(tempy>=1){
                res+=bit[tempx][tempy];
                tempy-=lowbit(tempy);
            }
            tempx-=lowbit(tempx);
        }
        return res;
    }
}Bit;

int main()
{
    int i,j,n,m,T,kcase=1;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        Init();
        int mx=0;
        for(i=1;i<=n;i++){
            int A,B;
            scanf("%d%d",&A,&B);
            if(b[B]<A){
                b[B]=A;cnt_b[B]=1;
            }else if(b[B]==A)
                cnt_b[B]++;
            mx=max(mx,B);
        }
        for(i=1;i<=m;i++){
            int C,D,E;
            scanf("%d%d%d",&C,&D,&E);
            if(b[E])
                vec.push_back((point){b[E],C,D,(LL)cnt_b[E]});
        }
        sort(vec.begin(),vec.end());
        int temp=vec.size();
        n=0;
        for(i=1;i<temp;i++){
            if(vec[i]==vec[n])
                vec[n].cnt+=vec[i].cnt;
            else vec[++n]=vec[i];
        }
     /*   for(i=1;i<=m;i++){
            int C,D,E;
            scanf("%d%d%d",&C,&D,&E);
            e[E].push_back((node){C,D});
            mx=max(mx,E);
        }
        int k,cnt;
        for(i=1;i<=mx;i++){
            if(b[i] && (int)e[i].size()){
                sort(e[i].begin(),e[i].end());
                for(j=0;j<e[i].size();){    //因为相同的c，只保留最大的d，但有可能都多个c相等，d也相等的
                    k=j;
                    while(k<e[i].size() && e[i][k].c==e[i][j].c && e[i][k].d==e[i][j].d)
                        k++;
                    cnt=k-j;
                    vec.push_back((point){b[i],e[i][j].c,e[i][j].d,(LL)cnt_b[i]*cnt});
                    while(k<e[i].size() && e[i][k].c==e[i][j].c) k++;
                    j=k;
                }
            }
        }*/
       // sort(vec.begin(),vec.end());
      //  for(i=0;i<vec.size();i++)
      //      printf("%d %d %d cnt=%d\n",vec[i].a,vec[i].c,vec[i].d,vec[i].cnt);
        LL res=0;
        if(n){
            Bit.Ini();
            for(i=0;i<=n;i++){
                //当前BIT里共有i个点
                if(Bit.sum(vec[i].c-1,1000)+Bit.sum(1000,vec[i].d-1)-Bit.sum(vec[i].c-1,vec[i].d-1)==Bit.sum(1000,1000))
                    res+=vec[i].cnt;
                Bit.add(vec[i].c,vec[i].d,1);
            }
        }
        printf("Case #%d: %I64d\n",kcase++,res);
    }
    return 0;
}


