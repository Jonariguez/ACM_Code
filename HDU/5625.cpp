/****************
*PID:hdu5625
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=100+10;
int A[maxn],B[maxn],C[maxn];

int main()
{
    int i,j,T,a,b,c;
    scanf("%d",&T);
    while(T--){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        memset(A,0,sizeof(A));
        memset(B,0,sizeof(A));
        memset(C,0,sizeof(A));
        char s[2];
        for(i=1;i<=x;i++){
            scanf("%s%d",s,&a);
            A[s[0]-'A']=a;
        }
        for(i=1;i<=y;i++){
            scanf("%s%d",s,&a);
            B[s[0]-'A']=a;
        }
        int yes=1;
        for(i=1;i<=z;i++){
            scanf("%s%d",s,&a);
            C[s[0]-'A']=a;
            if(A[s[0]-'A']==0 && B[s[0]-'A']==0)
                yes=0;
        }
        if(yes==0){
            puts("NO");continue;
        }
        for(a=1;a<=100;a++){
            for(b=1;b<=100;b++){
                for(i=0;i<26;i++)
                    if(a*A[i]+b*B[i]!=C[i]) break;
                if(i<26) continue;
                else {
                    yes=0;printf("%d %d\n",a,b);break;
                }
            }
            if(yes==0) break;
        }
        if(yes)
            puts("NO");
    }
    return 0;
}

