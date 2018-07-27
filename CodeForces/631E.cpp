/****************
*PID:631e div2
*Auth:Jonariguez
*****************
�����lλ���ϵ�������ƶ���λ��r������
a[1,2,..l+1,l+2,..,r,l,r+1,r+2,..n]��
��ô���ԭ�����У�sigma������ֵΪ��
a[l]*(r-l)-(a[l+1]+a[l+2]+..+a[r])
=a[l]*(r-l)-(sum[r]-sum[l]) //sum[i]Ϊǰ׺������
ͬ����Եõ���λ��r�ϵ�����ǰ�ƶ���λ��l����sigma������ֵΪ��
a[r]*(l-r)+(a[l]+...+a[r-1])
=a[r]*(l-r)+(sum[r-1]-sum[l-1])
=(a[r]*l-sum[l-1])+(sum[r-1]-a[r]*r)
ö��r����ʽ����Ϊ��ֵ��ֻ��Ҫ����a[r]�ҵ�(a[r]*l-sum[l-1])�����ֵ���ɡ�
��Y=l*a[r]-sum[l-1],������Y����l����б�ʣ�-sum[l-1]�����ؾࡣ
��͹��ά�������ֲ��ҡ�
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn=200000+10;
LL sum[maxn],a[maxn];

struct Convex_Hull{
    int Size;
    pair<LL,LL> Stack[maxn];
    void Init(){
        memset(Stack,0,sizeof(Stack));
        Size=0;
    }
    LL cal(int p,LL v){
        return Stack[p].first*v+Stack[p].second;
    }
    bool better(LL p1,LL p2,LL p3){
        LL old=(Stack[p1].second-Stack[p3].second)*(Stack[p1].first-Stack[p2].first);
        LL now=(Stack[p1].second-Stack[p2].second)*(Stack[p1].first-Stack[p3].first);
        return now<old;
    }
    void add(LL x,LL y){
        Stack[Size++]=make_pair(x,y);
        while(Size>2 && better(Size-3,Size-2,Size-1)){
            Stack[Size-2]=Stack[Size-1];Size--;
        }
    }
    LL ask(LL v){
        int l=-1,r=Size-1;
        while(l<r-1){
            int m=(l+r)/2;
            if(cal(m,v)<=cal(m+1,v))
                l=m;
            else r=m;
        }
        return cal(r,v);
    }
}CH;

int main()
{
    LL i,j,n;
    while(scanf("%I64d",&n)!=EOF){
        sum[0]=0;
        LL res=0,ans=0;
        for(i=1;i<=n;i++){
            scanf("%I64d",&a[i]);
            res+=a[i]*i;
            sum[i]=sum[i-1]+a[i];
        }
        CH.Init();
        for(i=2;i<=n;i++){
            CH.add(i-1,-sum[i-2]);
            ans=max(ans,CH.ask(a[i])+sum[i-1]-a[i]*i);
        }
        CH.Init();
        for(i=n-1;i>=1;i--){
            CH.add(-(i+1),-sum[i+1]);
            ans=max(ans,CH.ask(-a[i])+sum[i]-a[i]*i);
        }
        printf("%I64d\n",res+ans);
    }
    return 0;
}
