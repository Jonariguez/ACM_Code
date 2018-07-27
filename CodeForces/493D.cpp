/****************
*PID:493d div2
*Auth:Jonariguez
*****************
n为奇数时先手负，因为后手可以按先手对称来走。
如果n是奇数，则white怎么走，那么black就怎么走，这样black赢
如果n是偶数，则white应该先向右走，n-1为奇数，先手black败
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int i,j,n;
    while(scanf("%d",&n)!=EOF){
        if(n&1)
            printf("black\n");
        else printf("white\n1 2\n");
    }
    return 0;
}
