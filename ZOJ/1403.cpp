/****************
*PID:zoj1403
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

LL target;
char s[15];

LL cal(char a,char b,char c,char d,char e){
    LL v=a-'A'+1,w=b-'A'+1,x=c-'A'+1,y=d-'A'+1,z=e-'A'+1;
    return v-w*w+x*x*x-y*y*y*y+z*z*z*z*z;
}

int main()
{
    int i,j,k,v,p;
    while(scanf("%I64d %s",&target,s+1)!=EOF){
        if(target==0 && strcmp(s+1,"END")==0) break;
        int vis[30],n=strlen(s+1),yes=0;
        if(n<5){
            printf("no solution\n");continue;
        }
      //  printf("??\n");
        memset(vis,0,sizeof(vis));
        sort(s+1,s+n+1);
        for(i=n;i>=1 && !yes;i--){
            vis[i]=1;
            for(j=n;j>=1 && !yes;j--){
                if(vis[j]==0){
                    vis[j]=1;
                    for(k=n;k>=1 && !yes;k--){
                        if(vis[k]==0){
                            vis[k]=1;
                            for(v=n;v>=1 && !yes;v--){
                                if(vis[v]==0){
                                    vis[v]=1;
                                    for(p=n;p>=1 && !yes;p--){
                                        if(vis[p]==0){
                                        //    printf("cal=%I64d\n",cal(s[i],s[j],s[k],s[v],s[p]));
                                            if(cal(s[i],s[j],s[k],s[v],s[p])==target){
                                                printf("%c%c%c%c%c\n",s[i],s[j],s[k],s[v],s[p]);yes=1;
                                                break;
                                            }
                                        }
                                    }
                                    vis[v]=0;
                                }
                            }
                            vis[k]=0;
                        }
                    }
                    vis[j]=0;
                }
            }
            vis[i]=0;
        }
        if(yes==0)
            printf("no solution\n");
    }
    return 0;
}
