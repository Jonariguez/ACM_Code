/****************
*PID:496c div2
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <math.h>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=100+10;
int n,m;
char str[maxn][maxn];

int main()
{
    int i,j,res;
    while(scanf("%d%d",&n,&m)!=EOF){
        for(i=0;i<n;i++)
            scanf("%s",str[i]);
        string s[110];
        int col;
        for(col=0;col<m;col++){
            for(i=1;i<n;i++)
                if(s[i-1]+str[i-1][col]>s[i]+str[i][col]) break;
            if(i>=n){
                for(i=0;i<n;i++)
                    s[i]+=str[i][col];
            }
        }
        printf("%d\n",m-s[0].length());
    }
    return 0;
}
