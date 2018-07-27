#include <stdio.h>

int s[1010];

int main()
{
    int i,j,T,n;
    while(scanf("%d",&n),n){
        while(scanf("%d",&s[0])){
            if(s[0]==0) break;
            for(i=1;i<n;i++)
                scanf("%d",&s[i]);
            int f=1;
            for(int j=0;j<n-1&&f;j++){
                int l=n;
                for(int p=j;p<n;p++)
                {
                    if(s[p]<s[j]&&s[p]>l)
                    {
                        f=0;
                        break;
                    }
                    else if(s[p]<s[j])
                        l=s[p];
                }
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
