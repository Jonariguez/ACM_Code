#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int main()
{
    int i,j,k,n,w;
    scanf("%d%d%d",&k,&n,&w);
    printf("%d\n",max(k*w*(w+1)/2-n,0));
    return 0;
}
