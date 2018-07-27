/****************
*PID:hdu4497
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

LL G,L;
vector<int> g,l,cntg,cntl;

int main()
{
    int i,j,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&G,&L);
        if(L%G){
            puts("0");continue;
        }
        g.clear();l.clear();
        cntg.clear();cntl.clear();
        int cnt;
        for(i=2;(LL)i*i<=G;i++){
            if(G%i==0){
                cnt=0;
                while(G%i==0){
                    G/=i;cnt++;
                }
                g.push_back(i);cntg.push_back(cnt);
            }
        }
        if(G!=1){
            g.push_back(G);cntg.push_back(1);
        }
        for(i=2;(LL)i*i<=L;i++){
            if(L%i==0){
                cnt=0;
                while(L%i==0){
                    L/=i;cnt++;
                }
                l.push_back(i);cntl.push_back(cnt);
            }
        }
        if(L!=1){
            l.push_back(L);cntl.push_back(1);
        }
       // printf("cntl=%d\n",cntl.size());
        LL res=1LL;
        int nowl=0,nowg=0,n;
        while(nowl<l.size() && nowg<g.size()){
            if(g[nowg]==l[nowl]){
                n=cntl[nowl]-cntg[nowg]+1;
                if(n>1)
                    res*=((n-2)*6+6);
                nowg++;nowl++;
            }else if(l[nowl]<g[nowg]){
                n=cntl[nowl]+1;
                if(n>1)
                    res*=((n-2)*6+6);
                nowl++;
            }
        }
        while(nowl<l.size()){
            n=cntl[nowl]+1;
            if(n>1)
                res*=((n-2)*6+6);
            nowl++;
        }
        printf("%lld\n",res);
    }
    return 0;
}
