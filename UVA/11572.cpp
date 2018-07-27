/*
滑动窗口或者尺取(只是名字不一样而已)
*/
#include <stdio.h>
#include <string.h>
#include <map>
#include <algorithm>
using namespace std;

const int maxn=1000000+5;
int a[maxn];

map<int,int> mp;

int main()
{
    int i,j,T,res,n,s,t;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        mp.clear();
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        s=t=res=0;
        for(;;){
            while(t<n && mp[a[t]]==0)
                mp[a[t++]]++;
            res=max(res,t-s);
            if(t>=n) break;
            mp[a[s++]]--;
        }
        printf("%d\n",res);
    }
    return 0;
}
