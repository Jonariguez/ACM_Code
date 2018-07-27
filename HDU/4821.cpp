/*
�ַ�����ϣ
����BKDRHash����������O(1)ʱ�����ĳһ��
[l,r]�ַ��Ĺ�ϣֵ_hash[], ����Ϊ����Ҫ��
��ϣֵ���ַ����ĳ��ȶ���һ���ģ���l������
����Ԥ�������i��ͷ�ģ�����Ϊl�Ĺ�ϣֵval[i]
(������_hash[i]-_hash[i+l]*fac[l])��
Ȼ��ö�ٿ�ͷ�� ��ö�ٴ�0,1,..,l-1��ͷ���Ӵ�����
����Ϊö�ٵ�l�ͺ�ǰ��ö��0ʱ�غ��ˣ�������ǰ
m������Ϊl�Ĵ������Ƿ����m����������ͬ(��map),
���������ǳ�ȡ��˼�룬��ʱt�ĺ�����ǰm�����Ŀ�ͷ
��j�ĺ����ǵ�m+1����(����Ĵ�ָ�Գ���ΪlΪ��λ
�Ĵ�)����ô��tɾ�����ӽ�ȥj�����ж��Ƿ�m����
t��jͬʱ����һ���Ӵ��ĳ���(���ƶ�l������),���ϸ���
����
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
        for(i=0;i+l<=n;i++)             //ע��������i+l<=n������i+l-1<n,����Ҳ��
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
                mp[val[j]]++;           //����һֱ����++�ˡ�����
                j+=l;
                if(mp.size()==m) res++;
            }
        }
        printf("%d\n",res);
    }
    return 0;
}
