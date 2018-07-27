#include <stdio.h>
#include <string.h>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=5000+10;

struct Point{
    int x,h;
    bool bLeft;
    bool operator < (const Point &r) const {
        if(x==r.x) return h>r.h;
        return x<r.x;
    }
}s[maxn*2];

int cmp(const Point &a,const Point &b){
    if(a.x==b.x) return a.h>b.h;
    return a.x<b.x;
}

int main()
{
    int i,j,L,R,H,tot=0;
    priority_queue<int> pq;
    while(scanf("%d%d%d",&L,&H,&R)!=EOF){
        s[tot].x=L;s[tot].bLeft=true;s[tot].h=H;
        tot++;
        s[tot].x=R;s[tot].bLeft=false;s[tot].h=H;
        tot++;
        if(tot==16) break;
    }
    sort(s,s+tot);
    int curH=0,cnt=0;
    pq.remove(2);





    printf("0\n");
    return 0;
}
