/****************
*PID:559B div1
*Auth:Jonariguez
*****************
·ÖÖÎ
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=200000+10;
char str1[maxn],str2[maxn];

bool Judge(char *s1,char *s2,int L){
    int i;
    for(i=0;i<L;i++)
        if(s1[i]!=s2[i]) break;
    if(i>=L) return true;
    if(L&1) return false;
    int m=L/2;
    return (Judge(s1,s2,m) && Judge(s1+m,s2+m,m) || Judge(s1,s2+m,m) && Judge(s1+m,s2,m));
}


int main()
{
    int i,j,len1,len2;
    scanf("%s%s",str1+1,str2+1);
    len1=strlen(str1+1);
    len2=strlen(str2+1);
    if(strcmp(str1+1,str2+1)==0)
        printf("YES\n");
    else if(len1%2==1 || len2%2==1 || len1!=len2)
        printf("NO\n");
    else if(Judge(str1+1,str2+1,len1))
        printf("YES\n");
    else printf("NO\n");
    return 0;
}
