#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int maxn=100+10;
char s[maxn];

int main()
{
    int i,j,k,n;
    scanf("%s",s);
    n=strlen(s);
    int f=0;
    for(i=0;i<n;i++){
        if(s[i]=='0'){
            printf("YES\n0\n");return 0;
        }else if(s[i]=='8'){
            printf("YES\n8\n");return 0;
        }
    }
    for(i=0;i<n-1;i++)
        for(j=i+1;j<n;j++)
            if(((s[i]-'0')*10+(s[j]-'0'))%8==0){
                printf("YES\n%d%d",s[i]-'0',s[j]-'0');return 0;
            }
    for(i=0;i<n-2;i++)
        for(j=i+1;j<n-1;j++)
            for(k=j+1;k<n;k++)
                if(((s[i]-'0')*100+(s[j]-'0')*10+(s[k]-'0'))%8==0){
                    printf("YES\n%d%d%d\n",s[i]-'0',s[j]-'0',s[k]-'0');
                    return 0;
                }
    printf("NO\n");
    return 0;
}
