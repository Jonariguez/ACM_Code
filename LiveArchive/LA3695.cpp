/****************
*PID:la3695
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=100+10;
int y[maxn],left[maxn],on[maxn],on2[maxn];

struct Point{
    int x,y;
}s[maxn];

int cmp(const Point &a,const Point &b){
    return a.x<b.x;
}

int main()
{
    int i,j,k,n,m,kcase=1;
    while(scanf("%d",&n),n){
        for(i=1;i<=n;i++){
            scanf("%d%d",&s[i].x,&s[i].y);
            y[i-1]=s[i].y;
        }
        sort(s+1,s+n+1,cmp);
        sort(y,y+n);
        m=unique(y,y+n)-y;
        printf("Case %d: ",kcase++);
        if(m<=2){
            printf("%d\n",n);continue;
        }
        int yes=0,res=0;
        for(i=0;i<m-1;i++){
            for(j=i+1;j<m;j++){
                int up=y[i],down=y[j],cur=0,cnt=0,last=-1e9-2,cntx=0;
                memset(left,0,sizeof(left));
                memset(on,0,sizeof(on));
                memset(on2,0,sizeof(on2));
                left[0]=on[0]=0;on2[0]=0;
                for(k=1;k<=n;k++){
                    if(k==1 || s[k].x!=s[k-1].x) cntx++;
                    if(s[k].y<up || s[k].y>down) continue;
                  /*  if(k==1 || s[k].x!=s[k-1].x){
                        cur++;
                        on[cur]=on2[cur]=0;
                        left[cur]+=left[cur-1]+(on2[cur-1]-on[cur-1]);
                    }
                    if(s[k].y<down && s[k].y>up)
                        on[cur]++;
                    if(s[k].y<=down && s[k].y>=up)
                        on2[cur]++;*/
                    if(s[k].y==up || s[k].y==down){     // on border
                        if(last==s[k].x){
                            cnt++;on2[cur]++;
                        }else {
                            cur++;
                            on2[cur]=0;
                            left[cur]=left[cur-1]+cnt;cnt=1;
                            on2[cur]++;
                            last=s[k].x;
                        }
                    }else {             // in range
                        if(last==s[k].x){
                            on[cur]++;on2[cur]++;
                        }else {
                            cur++;
                            left[cur]=left[cur-1]+cnt;cnt=0;
                            on[cur]=on2[cur]=1;
                            last=s[k].x;
                        }
                    }
                }
                if(cntx<=2){
                    res=n;yes=1;break;
                }
                int S=0;
                for(k=1;k<=cur;k++){
                    res=max(res,left[k]+on2[k]+S);
                    S=max(S,on[k]-left[k]);
                }
            }
            if(yes) break;
        }
        printf("%d\n",res);
    }
    return 0;
}
