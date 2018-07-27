/*
看正负方向的苹果树个数，
先苹果个数多的方向走
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int maxn=105;

struct pp{
    int x,a;
}s[maxn];

int cmp(const pp &u,const pp &v){
    return u.x<v.x;
}

int main()
{
    int i,j,n,zh,fu;
    while(scanf("%d",&n)!=EOF){
        zh=fu=0;
        int sum=0;
        for(i=0;i<n;i++){
            scanf("%d%d",&s[i].x,&s[i].a);
            sum+=s[i].a;
            if(s[i].x<0) fu++;
            else zh++;
        }
        sort(s,s+n,cmp);
        int res=0;
        if(fu==zh) res=sum;
        else if(fu>zh){
            for(i=n-1;i>=n-zh*2-1;i--)
                res+=s[i].a;
        }else {
            for(i=0;i<=fu*2;i++)
                res+=s[i].a;
        }
        printf("%d\n",res);
    }
    return 0;
}
