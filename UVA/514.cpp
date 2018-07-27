#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int maxn=1000+10;
int s[maxn];

int main()
{
    int i,j,n;
    while(scanf("%d",&n),n){
        while(scanf("%d",&s[0]),s[0]){
            for(i=1;i<n;i++)
                scanf("%d",&s[i]);
            int l=0,f=1;
            for(i=1;i<n && f;i++){
                if(s[i]<s[l] && s[i]>s[i-1]){
                    f=0;break;
                }
                if(s[i]>s[l])
                    l=i;
            }
            if(f)
                printf("Yes\n");
            else
                printf("No\n");
        }
        printf("\n");
    }
    return 0;
}
