/****************
*PID:464a div1
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

const int maxn=1000+10;
char str[maxn];
int n,m;

char check(int p){
    char i;
    for(i=str[p]+1;i-'a'+1<=m;i++){
        if(str[p-1]!=i && str[p-2]!=i) return i;
    }
    return '.';
}

bool solve(){
    int i;
    char t;
    for(i=n;i>=1;i--){
        t=check(i);
        if(t!='.'){
            str[i]=t;break;
        }
    }
    if(i==0) return false;

    i++;
    for(;i<=n;i++){
        str[i]='a'-1;
        t=check(i);
        if(t!='.'){
            str[i]=t;
        }
    }
    return true;
}


int main()
{
    int i,j,k;
    while(scanf("%d%d",&n,&m)!=EOF){
        scanf("%s",str+1);
        if(!solve())
            puts("NO");
        else printf("%s\n",str+1);
    }
    return 0;
}

