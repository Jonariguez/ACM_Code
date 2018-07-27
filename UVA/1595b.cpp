#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

int Min(int x,int y){
    if(x<y) return x;
    return y;
}

int Max(int x,int y){
    if(x>y) return x;
    return y;
}

int main()
{
    int i,j,k,T,n,x,y;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        set<int> s[20004];
        int minv=30001,maxv=-20001;     //注意minv和maxv的初始值取值
        for(i=0;i<n;i++){
            scanf("%d%d",&x,&y);
            s[y+10000].insert(x);
            maxv=Max(maxv,y+10000);
            minv=Min(minv,y+10000);
        }
        set<int>::iterator it1,it2;
        it1=s[minv].begin();it2=s[minv].end();
        it2--;
        k=*it1+*it2;
        int b,t,ok=1;
        for(i=minv;i<=maxv;i++){
            it1=s[i].begin();it2=s[i].end();it2--;
            while(it1!=s[i].end()){
                if(*it1+*it2!=k){
                    ok=0;break;
                }
                it1++;it2--;
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
