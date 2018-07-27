/****************
*PID:596c div2
*Auth:Jonariguez
*****************
数形结合。
yi-xi=wi -->yi=xi+wi，这样把wi看出截距，用map<wi,v>,
其中v代表当前s(xi,yi)=wi的点"使用到"了x=v。(第一象限）
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=100000+10;
map<int,int> left;
int w[maxn],h[maxn];

struct Point{
    int xx,yy;
    Point(int _x=0,int _y=0):xx(_x),yy(_y){}
    bool operator < (const Point &r) const {
        if(xx==r.xx) return yy<r.yy;
        return xx<r.xx;
    }
}s[maxn],res[maxn];
set<Point> sot[maxn*2],point;

int cmp(const Point &a,const Point &b){
    return a.xx>b.xx;
}

bool check(int n){
    int i,j;
    point.clear();
    for(i=1;i<=n;i++){
        int v;
        scanf("%d",&v);
        v+=100000;
        if(sot[v].size()==0) return false;
        int x=(sot[v].begin())->xx;
        int y=sot[v].begin()->yy;
        sot[v].erase(sot[v].begin());
        if(x && !point.count(Point(x-1,y))) return false;
        if(y && !point.count(Point(x,y-1))) return false;
        point.insert(Point(x,y));
        res[i]=Point(x,y);
    }
    return true;
}

int main()
{
    int i,j,n;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d%d",&s[i].xx,&s[i].yy);
        sot[s[i].yy-s[i].xx+100000].insert(s[i]);
    }
    if(check(n)){
        printf("YES\n");
        Point p;
        for(i=1;i<=n;i++){
            printf("%d %d\n",res[i].xx,res[i].yy);
        }
    }else printf("NO\n");
    return 0;
}


