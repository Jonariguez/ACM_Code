/****************
*PID:493d div2
*Auth:Jonariguez
*****************
nΪ����ʱ���ָ�����Ϊ���ֿ��԰����ֶԳ����ߡ�
���n����������white��ô�ߣ���ôblack����ô�ߣ�����blackӮ
���n��ż������whiteӦ���������ߣ�n-1Ϊ����������black��
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
