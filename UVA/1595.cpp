#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
    int i,j,k,T,n,x,y;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        vector<int> s[20004];
        int minv=20001,maxv=-10001;     //注意minv和maxv的初始值取值
        for(i=0;i<n;i++){
            scanf("%d%d",&x,&y);
            s[y+10000].push_back(x);
            maxv=max(maxv,y+10000);
            minv=min(minv,y+10000);
        }
   //     printf("min=%d,max=%d\n",minv,maxv);
        k=s[minv][0]+s[minv][s[minv].size()-1];
        int b,t,ok=1;
        for(i=minv;i<=maxv;i++){
            b=0;t=s[i].size()-1;
            while(b<=t){
                if(s[i][b]+s[i][t]!=k){
                    ok=0;break;
                }
                b++;t--;
            }
            if(ok==0)
                break;
        }
        if(ok)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
