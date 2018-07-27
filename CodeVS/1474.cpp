/****************
*PID:cdvs1474
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int i,j,n,m;
    scanf("%d%d",&n,&m);
    stack<int> s;
    while(n){
        s.push(n%m);
        n/=m;
    }
    while(!s.empty()){
        int x=s.top();
        if(x>=10)
            printf("%c",'A'+(x-10));
        else printf("%d",x);
        s.pop();
    }
    printf("\n");
    return 0;
}
