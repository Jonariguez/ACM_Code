/****************
*PID:486a div1
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

int main()
{
    int i,j,n;
    while(scanf("%d",&n)!=EOF){
        if(n<4){
            puts("NO");continue;
        }
        puts("YES");
        LL t=n%4;
        if(t==0){
            puts("1 * 2 = 2");
            puts("2 * 3 = 6");
            puts("6 * 4 = 24");
           // n-=4;
            for(i=5;i<=n;i+=4){
                printf("%d - %d = 1\n",i+1,i);
                puts("24 + 1 = 25");
                printf("%d - %d = -1\n",i+2,i+3);
                puts("25 + -1 = 24");
            }
        }else if(t==1){
            puts("3 * 5 = 15");
            puts("2 * 4 = 8");
            puts("15 + 8 = 23");
            puts("23 + 1 = 24");
          //  n-=5;
            for(i=6;i<=n;i+=4){
                printf("%d - %d = 1\n",i+1,i);
                puts("24 + 1 = 25");
                printf("%d - %d = -1\n",i+2,i+3);
                puts("25 + -1 = 24");
            }
        }else if(t==2){
            puts("4 * 6 = 24");
            puts("2 * 3 = 6");
            puts("6 - 1 = 5");
            puts("5 - 5 = 0");
            puts("24 + 0 = 24");
         //  n-=6;
            for(i=7;i<=n;i+=4){
                printf("%d - %d = 1\n",i+1,i);
                puts("24 + 1 = 25");
                printf("%d - %d = -1\n",i+2,i+3);
                puts("25 + -1 = 24");
            }
        }else if(t==3){
            puts("5 * 7 = 35");
            puts("3 * 6 = 18");
            puts("35 - 18 = 17");
            puts("1 + 2 = 3");
            puts("3 + 4 = 7");
            puts("17 + 7 = 24");
         //   n-=7;
            for(i=8;i<=n;i+=4){
                printf("%d - %d = 1\n",i+1,i);
                puts("24 + 1 = 25");
                printf("%d - %d = -1\n",i+2,i+3);
                puts("25 + -1 = 24");
            }
        }
    }
    return 0;
}
