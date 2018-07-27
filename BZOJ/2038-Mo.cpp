/****************
*PID:bzoj2038
*Auth:Jonariguez
*****************
莫队算法，分块
对于L,R的询问,设其中颜色为x,y,z..的袜子的个数为a,b,c。
那么答案即为(a*(a-1)/2+b*(b-1)/2+c*(c-1)/2....)/((R-L+1)*(R-L)/2)
化简得 (a^2+b^2+c^2+...x^2-(a+b+c+d+.....))/((R-L+1)*(R-L))
即：(a^2+b^2+c^2+...x^2-(R-L+1))/((R-L+1)*(R-L))
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=50000+5;
int num[maxn],c[maxn],n,m,unit;

struct command{
    int L,R,id;
}s[maxn];

int cmp(const command &x,const command &y){
    if(x.L/unit==y.L/unit)
        return x.R<y.R;
    return x.L/unit<y.L/unit;
}

LL gcd(LL a,LL b){
    return b==0?a:gcd(b,a%b);
}

struct Ans{
    LL a,b;
    Ans(LL a=0,LL b=0):a(a),b(b){}
    void done(){
        LL g=gcd(a,b);
        a/=g;b/=g;
    }
}res[maxn];

void solve(){
    int L=1,R=0,i;  //[L,R]目前已知的区间解。
    LL now=0;
    for(i=0;i<m;i++){
        while(R<s[i].R){        //增加
            R++;
            now-=(LL)num[c[R]]*num[c[R]];
            num[c[R]]++;
            now+=(LL)num[c[R]]*num[c[R]];
        }
        while(R>s[i].R){            //缩小
            now-=(LL)num[c[R]]*num[c[R]];
            num[c[R]]--;
            now+=(LL)num[c[R]]*num[c[R]];
            R--;
        }
        while(L<s[i].L){
            now-=(LL)num[c[L]]*num[c[L]];
            num[c[L]]--;
            now+=(LL)num[c[L]]*num[c[L]];
            L++;
        }
        while(L>s[i].L){
            L--;
            now-=(LL)num[c[L]]*num[c[L]];
            num[c[L]]++;
            now+=(LL)num[c[L]]*num[c[L]];
        }
        Ans ans(now-(R-L+1),(LL)(R-L+1)*(R-L));
        ans.done();     //化简
        res[s[i].id]=ans;
    }
}

int main()
{
    int i,j;
    while(scanf("%d%d",&n,&m)!=EOF){
        memset(num,0,sizeof(num));
        for(i=1;i<=n;i++) scanf("%d",&c[i]);
        for(i=0;i<m;i++){
            scanf("%d%d",&s[i].L,&s[i].R);
            s[i].id=i;
        }
        unit=(int)sqrt(n);
        sort(s,s+m,cmp);
        solve();
        for(i=0;i<m;i++)
            printf("%lld/%lld\n",res[i].a,res[i].b);
    }
    return 0;
}
