/*
滑动窗口或者尺取
*/
#include <stdio.h>
#include <string.h>
#include <map>
#include <algorithm>
using namespace std;

const int maxn=1000000+5;
int a[maxn],last[maxn];

map<int,int> mp;

int main()
{
    int i,j,n,T,s,t,res;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        mp.clear();
        for(i=0;i<n;i++){
            scanf("%d",&a[i]);
            if(!mp.count(a[i])) last[i]=-1;     //注意这里要用count，不能用直接用mp[a[i]]的值，原因就在0这个特殊
            else last[i]=mp[a[i]];              //下标，当然也也可以用mp[]值来判断，那循环就应从1开始
            mp[a[i]]=i;
        }
        s=t=res=0;
        while(t<n){
            while(t<n && last[t]<s)
                t++;
            res=max(res,t-s);
            s++;
        }
        printf("%d\n",res);
    }
    return 0;
}
