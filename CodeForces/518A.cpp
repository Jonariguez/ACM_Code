/****************
*PID:518a div2
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
char s[maxn],t[maxn],res[maxn];
int main()
{
    int i,j,k,n,m;
    while(scanf("%s%s",s,t)!=EOF){
        n=strlen(s);
        int flag=0,yes=0;
        for(i=0;i<n;i++){
            if(s[i]==t[i]){
                res[i]=s[i];continue;
            }
            if(t[i]-s[i]==1){
                for(j=i+1;j<n;j++)
                    if(s[j]!='z') break;
                if(j<n){
                    res[i]=s[i];
                    for(j=i+1;j<n;j++)
                        if(s[j]!='z') res[j]=(s[j]-'a'+1)+'a';
                        else res[j]=s[j];
                    yes=1;break;
                }else {
                    for(j=i+1;j<n;j++)
                        if(t[j]!='a') break;
                    if(j<n){
                        res[i]=t[i];
                        for(j=i+1;j<n;j++)
                            if(t[j]!='a') res[j]=(t[j]-'a'-1)+'a';
                            else res[j]=t[j];
                        yes=1;break;
                    }
                }
                if(yes==0) break;
            }else {
                res[i]=s[i]+1;
                for(j=i+1;j<n;j++) res[j]=s[j];
                yes=1;break;
            }
        }
        res[n]='\0';
        if(!yes){
            printf("No such string\n");
            continue;
        }
        printf("%s\n",res);
    }
    return 0;
}

