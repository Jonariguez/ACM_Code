#include <stdio.h>
#include <string.h>
#include <set>
#include <algorithm>
using namespace std;

const int maxn=100000+10;

char str1[maxn],str2[maxn];

int main()
{
    int i,j,n,cnt;
    scanf("%s%s",str1,str2);
    n=strlen(str1);
    cnt=0;
    for(i=0;i<n;i++)
        if(str1[i]!=str2[i])
            cnt++;
    if(cnt&1)
        printf("impossible\n");
    else {
        cnt=0;
        for(i=0;i<n;i++){
            if(str1[i]==str2[i])
                printf("%c",str1[i]);
            else {
                if(cnt&1)
                    printf("%c",str1[i]);
                else
                    printf("%c",str2[i]);
                cnt++;
            }
        }
    }
    return 0;
}
