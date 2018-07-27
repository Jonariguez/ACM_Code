/****************
*PID:poj2082
*Auth:Jonariguez
*****************
—CµÄÓ¦ÓÃ
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=50000+10;
struct date{
    int h,w;
};

stack<date> s;

int main()
{
    int i,j,n,res;
    while(scanf("%d",&n) && n!=-1){
        while(!s.empty()) s.pop();
        int last=0;
        res=0;
        date u;
        for(i=1;i<=n;i++){
            scanf("%d%d",&u.w,&u.h);
            if(u.h>last)
                s.push(u);
            else {
                int now=0,cur=0;
                while(!s.empty() && s.top().h>=u.h){
                    now+=s.top().w;
                    cur=now*s.top().h;
                    res=max(res,cur);
                    s.pop();
                }
                u.w+=now;
                s.push(u);
            }
            last=s.top().h;
        }
        int now=0,cur=0;
        while(!s.empty()){
            u=s.top();s.pop();
            now+=u.w;
            cur=now*u.h;
            res=max(res,cur);
        }
        printf("%d\n",res);
    }
    return 0;
}
