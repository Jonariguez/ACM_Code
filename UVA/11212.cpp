/****************
*PID:uva11212
*Auth:Jonariguez
*****************
IDA*
������������hΪ��̲���ȷ�����ָ�������ôÿ�μ���
h������3
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=9;
int n,a[maxn],maxd;
bool yes;

bool is_sort(){
    int i;
    for(i=0;i<n-1;i++)
        if(a[i]>=a[i+1]) return false;
    return true;
}

int h(){
    int i,cnt=0;
    for(i=0;i<n-1;i++)
        if(a[i]+1!=a[i+1]) cnt++;   //ͳ�ƺ�̲��Եĸ���
    if(a[n-1]!=n) cnt++;
    return cnt;
}

void dfs(int d){
    if(d*3+h()>3*maxd) return ;     //��������
    if(yes) return ;
    if(is_sort()){
            yes=true;return ;
    }

    int b[maxn],olda[maxn];
    memcpy(olda,a,sizeof(a));
    int i,j,k,p;
    //��a[i..j]��ȡ��������b[]�У�Ȼ��a[]ʣ��(��ʣ��x��)��Ԫ�ر���
    //��˳�򲻱䣬Ȼ��a[i..j]��Ϊһ������嵽x+1�������γ��µ�����
    for(i=0;i<n;i++)
        for(j=i;j<n;j++){
            int cnt=0;
            for(k=0;k<n;k++)
                if(k<i || k>j) b[cnt++]=a[k];

            for(k=0;k<=cnt;k++){
                int cnt2=0,v;
                for(v=0;v<k;v++) a[cnt2++]=b[v];
                for(v=i;v<=j;v++) a[cnt2++]=olda[v];
                for(v=k;v<cnt;v++) a[cnt2++]=b[v];
                dfs(d+1);
                memcpy(a,olda,sizeof(olda));
            }
        }
}

int solve(){
    if(is_sort()) return 0;
    int max_ans=5;          //��ʵ֤��һ�����ֻ��Ҫ5�μ���
    yes=false;
    for(maxd=1;maxd<max_ans;maxd++){
        dfs(0);
        if(yes) return maxd;
    }
    return max_ans;
}

int main()
{
    int i,kcase=1;
    while(scanf("%d",&n),n){
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        printf("Case %d: %d\n",kcase++,solve());
    }
    return 0;
}
