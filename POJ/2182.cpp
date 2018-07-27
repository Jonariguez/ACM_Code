/*
BIT+二分(提醒了一下用二分，独立完成)
*/
#include <stdio.h>
#include <string.h>
#include <set>
using namespace std;

const int maxn=8000+10;

int bit[maxn],p[maxn],n;

void add(int i,int v){
    while(i<=n){
        bit[i]+=v;
        i+=i&(-i);
    }
}

int sum(int i){
    int res=0;
    while(i>0){
        res+=bit[i];
        i-=i&(-i);
    }
    return res;
}

bool C(int x,int small){
    return (sum(x-1)+small+1)>=x;
}


int ans[maxn];
set<int> s;         //用来得到最后剩的那个数。另外一种方法是用1-n的和(n*(n-1)/2)减去已经确定了的数的和sum就是剩的数

int main()
{
    int i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        s.insert(i);
    for(i=1;i<n;i++)
        scanf("%d",&p[i]);
    for(i=n-1;i>0;i--){
        int l=1,r=n,t=p[i];
        while(r-l>0){           //利用二分查找一个值，使得在它后面已经插入的值中比自己小的个数+在自己前面又比自己小的
            int m=(l+r)/2+1;    //数的个数+1=本身，那么这个数就是要在这个位置插入的数
            if(C(m,t))          //因为这个数每次都唯一，所以用二分定值，而不是求上界或下界，注意一下。
                l=m;
            else r=m-1;
        }
        s.erase(l);         //插入这个数之后，这个数就删掉
        ans[i]=l;
        add(l,1);
    }
    set<int>::iterator it;
    it=s.begin();           //最后剩的一个数肯定是前面没有数了，也就是它就是第一个数
    ans[0]=*it;
    for(i=0;i<n;i++)
        printf("%d\n",ans[i]);
    return 0;
}

