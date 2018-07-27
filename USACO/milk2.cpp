/*
ID:Jonairugez7
PROG:milk2
LANG:C++
*/

/*法一：
#include <stdio.h>
#include <string.h>

const int maxn=1000000+10;
int vis[maxn];

int Max(int x,int y){
    if(x>y) return x;
    return y;
}

int main()
{
    freopen("milk2.in","r",stdin);
    freopen("milk2.out","w",stdout);
    int i,j,k,n;
    scanf("%d",&n);
    int x,y;
    memset(vis,0,sizeof(vis));
    int maxv=-1,minv=1000006;
    for(i=0;i<n;i++){
        scanf("%d%d",&x,&y);
        if(maxv<y) maxv=y;
        if(minv>x) minv=x;
        vis[x]++;vis[y]--;      //注意这里，根据题目来看这里是vis[y]--,不是vis[y+1]--
    }
    for(i=1;i<=maxv;i++)
        vis[i]+=vis[i-1];
    int ans1=-1,ans2=-1,zero=0,nzero=0;
    for(i=minv;i<=maxv;i++){        //一定要注意这里从minv开始，而不是0
        if(vis[i]==0){
            zero++;
            ans1=Max(ans1,nzero);
            nzero=0;
        }
        else {
            nzero++;
            ans2=Max(ans2,zero);
            zero=0;
        }
    }
    printf("%d %d\n",ans1,ans2);
    return 0;
}
*/

/*法二：
#include <stdio.h>
#include <string.h>

const int maxn=1000000+10;
int vis[maxn];

int Max(int x,int y){
    if(x>y) return x;
    return y;
}

int main()
{
    freopen("milk2.in","r",stdin);
    freopen("milk2.out","w",stdout);
    int i,j,k,n;
    scanf("%d",&n);
    int x,y;
    memset(vis,0,sizeof(vis));
    int maxv=-1,minv=1000006;
    for(i=0;i<n;i++){
        scanf("%d%d",&x,&y);
        if(maxv<y) maxv=y;
        if(minv>x) minv=x;
        vis[x]++;vis[y]--;      //注意这里，根据题目来看这里是vis[y]--,不是vis[y+1]--
    }
    //该方法就免去了下面的扫描
//    for(i=1;i<=maxv;i++)
//        vis[i]+=vis[i-1];
    int ans1=0,ans2=0,sum=0,mark;
    mark=minv;
    bool free=false;
    //sum之所以有下面的性质，因为在上面输入的时候，只要前面有一个vis[x]+1，后面就有一个vis[y]-1与其对应
    //也正是因此不会出现sum=0的情况，因为有-1，那么之前必有+1，即对于maxv<=i<=maxv，在i之前遇到的+1的次数不少于-1的次数
    for(i=minv;i<=maxv;i++){
        sum+=vis[i];            //如果sum==0,表示vis[i]位于0区，即没人喂牛(但vis[i]不一定不为0)
                                //如果sum!=0,表示位于非0区，此时有人喂奶(至少有一人在喂牛,同时vis[i]也不一定不为0)
        if(sum==0 && free==false){
            if(ans1<i-mark) ans1=i-mark;
            mark=i;
            free=true;      //进入无人喂牛区
        }
        if(sum!=0 && free==true){
            if(ans2<i-mark) ans2=i-mark;
            mark=i;
            free=false;     //进入有人喂牛区
        }
    }
    printf("%d %d\n",ans1,ans2);
    return 0;
}
*/

/*法三：
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int maxn=1000000+10;

struct pp
{
    int b,e;
}s[maxn];

int cmp(const pp &x,const pp &y){
    if(x.b==y.b) return x.e<y.e;
    return x.b<y.b;
}

int main()
{
    freopen("milk2.in","r",stdin);
    freopen("milk2.out","w",stdout);
    int i,k,n;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d%d",&s[i].b,&s[i].e);
    if(n==1){
        printf("%d 0\n",s[0].e-s[0].b);
        return 0;
    }
    sort(s,s+n,cmp);
    int ans1=0,ans2=0,f=s[0].b,t=s[0].e;      //ans1和ans2的初值应该为0，而不是为-1，因为方便后面的处理
    for(i=1;i<n;i++){
        if(t>=s[i].b){
            t=max(t,s[i].e);
        }
        else {
            ans1=max(ans1,t-f);     //ans1也要在这里更新，而不是上面的if里
            ans2=max(ans2,s[i].b-t);
            f=s[i].b,t=s[i].e;
        }
    }
    ans1=max(ans1,t-f);         //如果出现一个人一直从头干到尾的情况
    printf("%d %d\n",ans1,ans2);
    return 0;
}
*/

