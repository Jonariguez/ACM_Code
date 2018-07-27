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

const int maxn=100000+10;
const int MOD=1e9+7;

int bit[maxn*2],N;

struct node{
    int v;  //值
    int lft; //lft=1:代表这个点是某个线段的左端点，=0，代表是一个竖着的线段，-1代表是某个线段的右端点,这样处理方便下面排序
    int y,y1,y2;
}s[maxn*3];

vector<int> lisan;
map<int,int> mp;

int cmp(const node &a,const node &b){
    if(a.v==b.v)        //如果出现多个点x坐标相同时，应该先加左端点，再查询，再撤销右端点
        return a.lft>b.lft;
    return a.v<b.v;
}

//下面是树状数组的代码
void add(int i,int v){
    while(i<=N){
        bit[i]+=v;
        i+=i&(-i);
    }
}

int sum(int i){
    int res=0;
    while(i>0){
        res+=bit[i];
        i-=i&(-i);
    }
    return res;
}

int main()
{
    int i,j,n,m,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        int tot=0;
        lisan.clear();
        for(i=1;i<=n;i++){
            int x1,x2,y1,y2;
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            if(x1==x2){     //说明这个线段是竖着的
                tot++;
                s[tot].v=x1;
                s[tot].lft=0;
                s[tot].y1=min(y1,y2);   //s[tot].y1代表这个竖着的线段的下端点的值，同理，y2代表上端点的值
                s[tot].y2=max(y1,y2);
            }else {         //说明这个线段是横着的，那么就要分左右端点了
                tot++;
                s[tot].v=min(x1,x2);
                s[tot].lft=1;       //这是个左端点
                s[tot].y=y1;    //s[tot].y=y2也是可以的，因为y1和y2是相等的，都一样
                tot++;
                s[tot].v=max(x1,x2);
                s[tot].lft=-1;      //这是个右端点
                s[tot].y=y1;
            }
            lisan.push_back(y1);    //把所有出现过的y都加进去，用于离散化
            lisan.push_back(y2);
        }

        //下面就是离散化
        sort(lisan.begin(),lisan.end());    //使用unique函数之前要先排序
        lisan.erase(unique(lisan.begin(),lisan.end()),lisan.end()); //把后面重复的都删掉
        mp.clear();
        for(i=0;i<lisan.size();i++)
            mp[lisan[i]]=i+1;       //把所有不同的y值离散化为[1,li.size()]范围内

        N=lisan.size();
        sort(s+1,s+tot+1,cmp);
        memset(bit,0,sizeof(bit));
        LL res=0;
        for(i=1;i<=tot;i++){
            if(s[i].lft==1){       //这是某个线段的左端点,则应该在扫描线上的那个点+1
                int temp=mp[s[i].y];    //这里就是离散化的应用，将可能用1e9那么大的s[i].y映射为范围更小的temp
                add(temp,1);
            }else if(s[i].lft==0){  //这时个竖着的线段，该查询了
                int down=mp[s[i].y1];   //离散化出上下端点
                int up=mp[s[i].y2];
                res+=sum(up)-sum(down-1);   //然后求[down,up]这个范围内有多少横着的线段就有多少交点
            }else if(s[i].lft==-1){  //这是某个线段的右端点，则应该在扫描线上的那个点-1
                int temp=mp[s[i].y];
                add(temp,-1);
            }
        }
        printf("%lld\n",res);
    }
    return 0;
}



