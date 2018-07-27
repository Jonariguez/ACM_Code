#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int maxn=30000+10;
int sum[maxn],par[maxn],under[maxn];

void Init(){
    for(int i=0;i<maxn;i++){
        par[i]=i;
        under[i]=0;
        sum[i]=1;
    }
}

//ע�����under[x]�����Ǵ�x���µ�par[x]һ���ж��ٸ���������ټ���
//par[x]����ĸ�����under[x]�͸�����ȷ�ˡ��Ҳ���par[x]�����ж��٣�
//����·��ѹ����ʹ��ִ����仰��ʱ����under[par[x]]��֤����ȷֵ����
//���������y�����ǲ��ݹ�õ��ģ���������·��ѹ��֮�����յĸ�������
//yֻ������par[x]=y��������·�����ĵ�ȫ��ѹ�������ո�(��������·��ѹ��)
//��͸���underû�а�ëǮ��ϵ
int Find(int x){
    if(x==par[x]) return x;
    int y=Find(par[x]);     //����һ��Ҫ�ȵݹ飬��Ϊ����under�Ǵ��ҵ����ո�Ȼ���Ÿ��µģ�
    under[x]+=under[par[x]];                //��ΪҪ�Ȱѿ������ĸ��¶ԣ���ô֮��ĸ��µĲ�����ȷֵ��
   // sum[y]+=sum[x];
    return par[x]=y;
}

//��·��ѹ����ɺ󣬾Ϳ��԰�u��v�ֱ𿴳�һ�����壬
//�����u����v���棬��Ȼv���ȫ��ש�鶼Ҫ�㵽under[x]��
void Union(int u,int v){
    if((u=Find(u))==(v=Find(v)))
        return ;
    under[u]+=sum[v];
    par[u]=v;sum[v]+=sum[u];
}

int main()
{
    int i,j,p;
    char s[5];
    Init();
    scanf("%d",&p);
    while(p--){
        scanf("%s",s);
        if(s[0]=='M'){
            int a,b;
            scanf("%d%d",&a,&b);
            Union(a,b);
        }else {
            int x;
            scanf("%d",&x);
            Find(x);        //Ҫ��ѹ��һ�£�Ȼ���ٲ�ѯ
            printf("%d\n",under[x]);
        }
    }
    return 0;
}
