/****************
*ID:LA3664|uva1612
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
#define eps 1e-9

const int maxn=26384+10;

struct player{
    int rank,id;
 //   double score[3];
 //   double sum;
    int score[3];
    int sum;
}s[maxn];

int cmp(const player &x,const player &y){
    if(x.rank==y.rank)
        return x.id<y.id;
    return x.rank<y.rank;
}

vector<int> u;

void solve(int id){
    int temp=-30000000;
    int i,j,flag=0;
    for(i=0;i<(1<<3);i++){
        int t=0;
        for(j=0;j<3;j++)
            if((i>>j)&1)
                t+=s[id].score[j];
        u.push_back(t);
    }
}

int main()
{
    int i,j,k,n,kcase=1;
    while(scanf("%d",&n),n){
        float x,y,z;
        for(i=0;i<n;i++){
            scanf("%f%f%f",&x,&y,&z);
            s[i].score[0]=(int)(round((x*100.0)));
            s[i].score[1]=(int)(round((y*100.0)));
            s[i].score[2]=(int)(round((z*100.0)));
            sort(s[i].score,s[i].score+3);
            s[i].sum=s[i].score[0]+s[i].score[1]+s[i].score[2];
            s[i].id=i;
        }
        int v;
        for(i=0;i<n;i++){
            scanf("%d",&v);
            s[v-1].rank=i;
        }
        sort(s,s+n,cmp);
        int yes=1;
        int now=s[0].sum;
        for(i=1;i<n;i++){        //排名靠后的分大于前面的，或者总分相同但编号小于前面的，都要降分
            u.clear();
            solve(i);
            sort(u.begin(),u.end());
            int ok=0;
            for(j=u.size()-1;j>=0;j--){
                if(u[j]==now && s[i].id>s[i-1].id){
                    ok=1;break;
                }else if(u[j]<now){
                    now=u[j];
                    ok=1;break;
                }
            }
            if(!ok){
                yes=0;break;
            }
       /*     if(s[i].sum>=now){
                if(s[i].id<s[i-1].id)
                    solve(i,now);
            }
            else now=s[i].sum;
            if(now<0){
                yes=0;break;
            }*/
        }
        if(!yes) printf("Case %d: No solution\n", kcase++);
        else printf("Case %d: %.2f\n", kcase++, now/100.0);
    }
    return 0;
}
