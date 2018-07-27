/*
字符串哈希
采用BKDRHash，这样可以O(1)时间求出某一段
[l,r]字符的哈希值_hash[], 又因为本题要求
哈希值的字符串的长度都是一定的，是l，所以
可以预处理出以i开头的，长度为l的哈希值val[i]
(即等于_hash[i]-_hash[i+l]*fac[l])。
然后枚举开头。 即枚举从0,1,..,l-1开头的子串即可
（因为枚举到l就和前面枚举0时重合了），处理前
m个长度为l的串，看是否符合m个串都不相同(用map),
接下来就是尺取的思想，此时t的含义是前m个串的开头
，j的含义是第m+1个串(这里的串指以长度为l为单位
的串)，那么把t删掉，加进去j，再判断是否够m个，
t和j同时后移一个子串的长度(即移动l个长度),不断更新
即可
*/
#include <stdio.h>
#include <string.h>
#include <map>
#include <algorithm>
using namespace std;
#define base 31
typedef unsigned long long ull;

const int maxn=100000+10;
char str[maxn];

ull fac[maxn],_hash[maxn],val[maxn];
map<ull,int> mp;

int main()
{
    int i,j,m,l,n;
    fac[0]=1;
    for(i=1;i<=100000;i++)
        fac[i]=fac[i-1]*base;
    while(scanf("%d%d",&m,&l)!=EOF){
        scanf("%s",str);
        n=strlen(str);
        _hash[n]=0;
        for(i=n-1;i>=0;i--)
            _hash[i]=_hash[i+1]*base+(str[i]-'a'+1);
        int res=0;
        for(i=0;i+l<=n;i++)             //注意这里是i+l<=n，不是i+l-1<n,下面也是
            val[i]=(_hash[i]-_hash[i+l]*fac[l]);
        for(i=0;i<l && i+m*l<=n;i++){
            mp.clear();
            for(j=i;j<i+m*l;j+=l)
                mp[val[j]]++;
            if(mp.size()==m) res++;
            int t=i;
            while(j+l<=n){
                if(--mp[val[t]]==0)
                    mp.erase(val[t]);
                t+=l;
                mp[val[j]]++;           //这里一直忘加++了。。。
                j+=l;
                if(mp.size()==m) res++;
            }
        }
        printf("%d\n",res);
    }
    return 0;
}
