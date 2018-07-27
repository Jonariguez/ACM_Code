/****************
*PID:B
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int i,j,n,s,f;
    while(scanf("%d%d%d",&n,&s,&f)!=EOF){
        if(s==f){
            puts("-1");continue;
        }
        int res=0;
        if(s>f){
            int t=s;s=f;f=t;
        }
        if(s!=1){
            res++;
            s++;
            if(s==f){
                if(f==n)
                    puts("1");
                else puts("-1");
                continue;
            }else {
                if(f!=n){
                    res+=(f-1-s)/3;
                    int c=(f-1-s)%3;
                    res++;
                    res+=c;
                    printf("%d\n",res);continue;
                }else {
                    res+=(f-s)/3+(f-s)%3;
                    printf("%d\n",res);continue;
                }
            }

        }
        if(f!=n){
            res+=(f-1-s)/3;
            int c=(f-1-s)%3;
            res++;
            res+=c;
            printf("%d\n",res);
            continue;
        }
        res=(f-s)/3+(f-s)%3;
        printf("%d\n",res);
    }
    return 0;
}
