/****************
*PID:uva1608
*Auth:Jonariguez
*****************
如何快速判断在某个区间[l,r]中的某个元素x是否唯一。
设L[x]为在x左边且和x相等的数出现的位置(即下标),
R[x]的含义相同。
则如果L[x]<l && R[x]>r，就能说明x在区间[l,r]中是唯一的。O(1)时间

这个题会用到这个技巧，解题思路：
在整个序列中找到一个只出现一次的元素，如果不存在则直接得结论“boring”；
如果找到了，设为a[p],那么只需检查a[1..p-1]和a[p+1..n]是否满足即可。
这只需递归就好了。
还有就是在查找唯一元素的时候，必须从两边往中间找，这样最坏的情况是该
元素在中间的情况，则满足经典地退式：T(n)=2*T(n/2)+O(n)-> T(n)=O(n*logn)
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

const int maxn=200000+10;
int a[maxn],L[maxn],R[maxn],n;
map<int,int> mp;

//检查序列a[l..r]是否满足
bool solve(int l,int r){
    if(l>=r) return true;
    if(l+1==r){             //对于两个数的情况，只要两者不相等就满足，相等就不满足
        if(a[l]!=a[r]) return true;
        else return false;
    }
    int i,k=0;
    for(i=l;i<=r;i++){          //从两边往中间找唯一元素
        if(L[i]<l && R[i]>r){           //还可以for(d=0;L+d<=R-d;d++)，然后检查L+d和R-d
            k=i;break;
        }
        if(2*i>=l+r)        //(优化)走到中间就该停了，如果没有的这句话，那么在没有唯一元素的情况会走一遍的(l->r)
            break;              //如果没有这个优化的话，2.98s卡着过
        if(L[r-i+l]<l && R[r-i+l]>r){
            k=r-i+l;break;
        }
    }
    if(k==0) return false;      //没找到
    if(solve(l,k-1) && solve(k+1,r))    //两边同时满足则整个序列就满足
        return true;
    return false;
}

int main()
{
    int i,j,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        mp.clear();
        memset(L,0,sizeof(L));
        fill(R,R+n+1,n+1);
        for(i=1;i<=n;i++){          //构造L,R数组
            scanf("%d",&a[i]);
            int x=mp.count(a[i]);
            int &t=mp[a[i]];
            if(x){
             //   int t=mp[a[i]];
                L[i]=t;
                R[t]=i;
            }
            t=i;
        }
        if(solve(1,n))
            printf("non-boring\n");
        else
            printf("boring\n");
    }
    return 0;
}
