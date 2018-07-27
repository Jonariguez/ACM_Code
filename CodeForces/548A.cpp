#include <stdio.h>
#include <string.h>
#include <math.h>

const int maxn=1000+10;
char s[maxn];
int k;

bool check(char *s){
    for(int i=0;i<k/2;i++)
        if(s[i]!=s[k-i-1])
            return false;
    return true;
}

int main()
{
    int i,j,n;
    scanf("%s",s);
    scanf("%d",&k);
    n=strlen(s);
    bool yes=true;
    if(n%k!=0)
        yes=false;
    else {
        k=n/k;
        for(i=0;i<n;i+=k)
            if(!check(s+i))
                yes=false;
    }
    if(yes)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
