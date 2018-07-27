#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

char str[20]="anniversary";
char s[110];

int main()
{
    int i,j,cnt,n,T;
    scanf("%d",&T);
    while(T--){
        scanf("%s",s);
        n=strlen(s);
        int ok=0,mark=-2,cur=0;
        cnt=0;
        for(i=0;i<n;i++){
            if(s[i]==str[cur]){
                if(i!=mark+1)
                    cnt++;
                mark=i;
                if(++cur==11){
                    ok=1;break;
                }
            }
        }
        if(ok && cnt<=3)    //是小于等于3，而不是==3，因为小于3个时也可能拆开看做3个
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}
