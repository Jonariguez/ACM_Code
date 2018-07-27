/****************
*PID:cdvs3145
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> num,from,to;

int cnt;

void hanno(char a,char b,char c,int n){
    if(n==1){
        num.push_back(1);
        from.push_back(a-'A');
        to.push_back(c-'A');
        cnt++;
        return ;
    }
    hanno(a,c,b,n-1);
    num.push_back(n);
    from.push_back(a-'A');
    to.push_back(c-'A');
    cnt++;
    hanno(b,a,c,n-1);
  //  cnt++;
}



int main()
{
    int i,j,n;
    cnt=0;
    scanf("%d",&n);
    hanno('A','B','C',n);
    printf("%d\n",cnt);
    for(i=0;i<num.size();i++)
        printf("%d from %c to %c\n",num[i],from[i]+'A',to[i]+'A');
    return 0;
}
