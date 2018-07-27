/****************
*PID:496b div2
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
char s[maxn],t[maxn],x[maxn],a[maxn];
int n;

void cmp(char *s,char *a){
    if(strcmp(s,a)>=0)
        strcpy(s,a);
}

int main()
{
    int i,j,res;
    while(scanf("%d",&n)!=EOF){
        scanf("%s",s);
        strcpy(x,s);
        t[n]='\0';
        a[n]='\0';
       // printf("%s\n",x);
        for(i=0;i<n;i++){
            int d=10-(x[i]-'0');
            t[i]='0';
            for(j=0;j<n;j++){
                if(j!=i)
                    t[j]=((x[j]-'0'+d)%10)+'0';
            }
          //  printf("s=%s,t=",s);
            for(int k=i,v=0;v<n;v++){
                k%=n;a[v]=t[k];k++;
            }
          //  printf("\n");
            cmp(s,a);
        }
        printf("%s\n",s);
    }
    return 0;
}
