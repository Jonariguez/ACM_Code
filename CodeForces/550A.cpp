#include <stdio.h>
#include <string.h>
#include <map>
#include <algorithm>
using namespace std;

const int maxn=100000+10;

char s[maxn],str[maxn];

int main()
{
    int i,j,n,flag1=0,flag2=0;
    scanf("%s",str);
    n=strlen(str);
    strcpy(s,str);
    for(i=0;i<n-1;i++){
        if(s[i]=='A' && s[i+1]=='B'){
            s[i]=s[i+1]='@';flag1=1;break;
        }
    }
    for(i=0;i<n-1;i++){
        if(s[i]=='B' && s[i+1]=='A'){
            s[i]=s[i+1]='@';flag2=1;break;
        }
    }
    if(flag1 && flag2){
        printf("YES\n");return 0;
    }
    strcpy(s,str);
    flag1=flag2=0;
    for(i=0;i<n-1;i++){
        if(s[i]=='B' && s[i+1]=='A'){
            s[i]=s[i+1]='@';flag1=1;break;
        }
    }
    for(i=0;i<n-1;i++){
        if(s[i]=='A' && s[i+1]=='B'){
            s[i]=s[i+1]='@';flag2=1;break;
        }
    }
    if(flag1 && flag2){
        printf("YES\n");return 0;
    }
    printf("NO\n");
    return 0;
}
