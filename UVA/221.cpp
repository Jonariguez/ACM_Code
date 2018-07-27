/****************
*ID:uva221
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=100+5;

struct Building{
    int id;
    double x,y,w,d,h;
    bool operator < (const Building &r) const {
        return x<r.x || (x==r.x && y<r.y);
    }
}b[maxn];

int n;
double x[maxn*2];       //用于离散化

bool cover(int i,double mx){
    return b[i].x<=mx && b[i].x+b[i].w>=mx;
}

bool visible(int i,double mx){
    if(!cover(i,mx)) return false;
    for(int k=0;k<n;k++){
        if(b[k].y<b[i].y && b[k].h>=b[i].h && cover(k,mx))   //在mx处有一个建筑k在i前面，且比i高，则看不见
            return false;
    }
    return true;
}

int main()
{
    int i,j,k,kcase=0;
    while(scanf("%d",&n),n){
        for(i=0;i<n;i++){
            scanf("%lf%lf%lf%lf%lf",&b[i].x,&b[i].y,&b[i].w,&b[i].d,&b[i].h);
            b[i].id=i+1;
            x[i*2]=b[i].x;x[i*2+1]=b[i].x+b[i].w;       //注意i*2,和i*2+1的用法，方便,不用tot++
        }
        sort(b,b+n);
        sort(x,x+n*2);
        int m=unique(x,x+n*2)-x;

        if(kcase++) printf("\n");
        //最左边的肯定能看得到
        printf("For map #%d, the visible buildings are numbered as follows:\n%d",kcase,b[0].id);
        for(i=1;i<n;i++){
            bool vis=false;
            for(j=0;j<m-1;j++)
                if(visible(i,(x[j]+x[j+1])/2)){
                    vis=true;break;
                }
            if(vis) printf(" %d",b[i].id);
        }
        printf("\n");
    }
    return 0;
}
