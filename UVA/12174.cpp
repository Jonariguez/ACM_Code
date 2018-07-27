/*
滑窗的思想
预处理出从每个数开始后面s个数是否是1-s的一个全排列
如果是，在这个数的下标ok设置为ture，否则为false，
然后枚举[0,s-1]位置，检查是否合格，检查的方法是：
如果i，i+s,i+2*s,i+3*s,...如果对于这些下标对于的ok
全是true，那么在i处开始是一个可能，答案+1。
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
typedef long long ll;

const int maxn=100000+10;
//注意数组的大小
int a[maxn*3],cnt[maxn];
bool ok[maxn*2];

int main()
{
    int i,j,s,res,n,k,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&s,&n);
        memset(ok,false,sizeof(ok));
        memset(cnt,0,sizeof(cnt));
        fill(a,a+n+2*s+1,-1);
        int sum=0;
        for(i=0;i<n;i++)
            scanf("%d",&a[i+s]);
        for(i=0;i<n+s+1;i++){
            if(sum==s) ok[i]=1;
            if(i<s && sum==i) ok[i]=1;      //处理前面的
            if(i>n && sum==n-i+s) ok[i]=1;  //处理后面的

            if(a[i]!=-1 && cnt[a[i]]--==1) sum--;
            if(a[i+s]!=-1 && cnt[a[i+s]]++==0) sum++;
        }
        int res=0;
        for(i=0;i<s;i++){
            int yes=1;
            for(j=i;j<n+s+1;j+=s)
                if(!ok[j]){ yes=0;break;}
            if(yes) res++;
        }
        if(res==n+1)        //,,,这是个特例
            res=s;
        printf("%d\n",res);
    }
    return 0;
}

/*
还有需要注意的，看例子：
s=4,  序列a: 3 4 [1 2 3 4] [3 2 1 4] 3 2  (下标起于0)
很明显中间的是符合窗口的，即ok[2]=ok[6]=true,但是还要
处理前面的3 4，很明显3 4是没有重复数字的，假如我们在
前面添加虚拟空间，那么就应该是a[-2]=x,a[-1]=y,a[0]=3,a[1]=4.
因为3 4无重复，所以我们就取x，y分别为1,2，这样3 4也
一样符合了(其实就是开头不够s个的只要没有重复数字的
都能像这样凑出一个窗口),即ok[-2]=true。
因为数组下标无负数，所以我们要在输入序列前面预留出
s个空间，并初始化为-1，表示无数字。(if(i<s && ..))
后面的3 2也类似处理。(if(i>n && ..))
再如下：
下标:-3 -2 -1 0 1 2  3 4 5 6  7 8 9 10 11 12
序列: x  x  x 3 4 4 [1 2 3 4][3 2 1 4] 3  2
ok[-3]=ok[-2]=true,因为a[1],a[2]都是4，那么ok[-1]=false
同样ok[0],ok[1]都是false.
*/
