#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

typedef long long LL;
const int maxn=100000+10;
int a[maxn];
char str[maxn],t[maxn];

bool check(){
    int n=strlen(str+1),cnt=0;
    for(int i=1;i<=n;i++){
        if(str[i]!='0' &&str[i]!='1') return false;
        if(str[i]=='1') cnt++;
    }
    return cnt<=1;
}

int main()
{
    int i,j,n,m;
    while(scanf("%d",&n)!=EOF){
        int cnt=0,yes=1;
        memset(t,0,sizeof(t));
        for(i=1;i<=n;i++){
            scanf("%s",str+1);
            if(yes==0) continue;
            m=strlen(str+1);
            if(m==1){
                if(str[1]=='1') continue;
                else yes=0;
            }
            if(check())
                cnt+=(strlen(str+1)-1);
            else {
                yes=2;strcpy(t+1,str+1);
            }
        }
        if(yes==0)
            puts("0");
        else {
            if(yes==2)
                printf("%s",t+1);
            else printf("1");
            for(i=0;i<cnt;i++)
                printf("0");
            puts("");
        }
    }
    return 0;
}
