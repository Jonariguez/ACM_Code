/****************
*PID:518b div2
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

const int maxn=200000+10;
char s[maxn],t[maxn];
int A1[30],a1[30],A2[30],a2[30];

int main()
{
    int i,j,k,n,m;
    while(scanf("%s%s",s,t)!=EOF){
        n=strlen(s);
        m=strlen(t);
        memset(a1,0,sizeof(a1));
        memset(A1,0,sizeof(A1));
        memset(a2,0,sizeof(a2));
        memset(A2,0,sizeof(A2));
        for(i=0;i<m;i++)
            if(t[i]>='a' && t[i]<='z')
                a2[t[i]-'a']++;
            else A2[t[i]-'A']++;
        for(i=0;i<m;i++)
            if(s[i]>='a' && s[i]<='z')
                a1[s[i]-'a']++;
            else A1[s[i]-'A']++;
        int sum1=0,sum2=0;
        for(i=0;i<26;i++){
            sum1+=min(a1[i],a2[i]);
            sum1+=min(A1[i],A2[i]);
            int need1=max(0,a1[i]-a2[i]),need2=max(0,A1[i]-A2[i]);
            sum2+=min(need1,max(0,A2[i]-A1[i]));
            sum2+=min(need2,max(0,a2[i]-a1[i]));
        }
        printf("%d %d\n",sum1,sum2);
    }
    return 0;
}
