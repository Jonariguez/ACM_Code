/****************
*PID:474a div2
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

const int maxn=100000+10;
char a[maxn]="qwertyuiopasdfghjkl;zxcvbnm,./";
char s[maxn];

int main()
{
    int i,j,n,m,T;
    char ss[4];
    scanf("%s",ss);
    scanf("%s",s);
    n=strlen(s);
    if(ss[0]=='R'){
        for(i=0;i<n;i++){
            for(j=0;j<30;j++){
                if(s[i]==a[j]) printf("%c",a[j-1]);
            }
        }
        puts("");
    }else {
        for(i=0;i<n;i++){
            for(j=0;j<30;j++){
                if(s[i]==a[j]) printf("%c",a[j+1]);
            }
        }
        puts("");
    }
    return 0;
}


