#include <cstdio>
#include <iostream>
#include <sstream>
#include <string.h>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

const int maxp=1000000+10;
int a[maxp];

int Min(int x,int y){
    if(x<y) return x;
    return y;
}

int main()
{
    int i,j,s,t,num,sum,p,res;
    scanf("%d",&p);
    set<int> sa;
    for(i=0;i<p;i++){
        scanf("%d",&a[i]);
        sa.insert(a[i]);
    }
    num=sa.size();
    map<int,int> cnt;
    s=t=sum=0;res=p;
    for(;;){
        while(t<p && sum<num){
            if(cnt[a[t]]==0)
                sum++;
            cnt[a[t++]]++;
        }
        if(sum<num) break;
        res=Min(res,t-s);
        if(--cnt[a[s++]]==0)
            sum--;
    }
    printf("%d\n",res);
    return 0;
}
