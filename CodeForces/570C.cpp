/****************
ID:cf570C
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=300000+10;

char str[maxn];

int main()
{
    int i,j,n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        scanf("%s",str+1);
        int res=0;
        for(i=1;i<n;i++)
            if(str[i]=='.' && str[i+1]=='.')
                res++;
        while(m--){
            int p;
            char ch;
            scanf("%d %c",&p,&ch);
            if(ch=='.' && str[p]=='.' || ch!='.' && str[p]!='.'){
                printf("%d\n",res);
                continue;
            }
            if(ch=='.'){
                if(p!=n && str[p+1]=='.')
                    res++;
                if(p!=1 && str[p-1]=='.')
                    res++;
            }else {
                if(p!=n && str[p+1]=='.')
                    res--;
                if(p!=1 && str[p-1]=='.')
                    res--;
            }
            str[p]=ch;
            printf("%d\n",res);
        }
    }
    return 0;
}
