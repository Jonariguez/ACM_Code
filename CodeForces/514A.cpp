/****************
*PID:514a div2
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
char s[25];

int main()
{
    int i,j,n,m;
    while(scanf("%s",s+1)!=EOF){
        n=strlen(s+1);
        if(s[1]!='9'){
            if(s[1]>='5')
                s[1]=(9-(s[1]-'0')+'0');
        }
        for(i=2;i<=n;i++){
            if(s[i]>='5')
                s[i]=(9-(s[i]-'0')+'0');
        }
        LL res=0;
        for(i=1;i<=n;i++)
            if(s[i]!='0') break;
        if(i>n) printf("9\n");
        else {
            for(;i<=n;i++) printf("%c",s[i]);
            printf("\n");
        }
    }
    return 0;
}
