/*
遇见'.'且在\/里面就加2，遇见\和/就加1
通过bool型yes来判断遇见的'.'是否在\/里面

这里结果肯定是整数，但是\和/是加0.5的，
所以这里一开始累加的时候按乘2算，最好再/2
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
typedef long long ll;

const int maxw=110;
char a[maxw][maxw];

int main()
{
    int i,j,h,w,res;
    while(scanf("%d%d",&h,&w)!=EOF){
        for(i=1;i<=h;i++)
            for(j=1;j<=w;j++)
                scanf(" %c",&a[i][j]);
        res=0;
        for(i=1;i<=h;i++){
            bool yes=false;
            for(j=1;j<=w;j++){
                if(a[i][j]=='.' && yes)
                    res+=2;
                if(a[i][j]!='.'){
                    res++;
                    yes=!yes;
                }
            }
        }
        printf("%d\n",res/2);
    }
    return 0;
}
