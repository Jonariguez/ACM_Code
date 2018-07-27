/****************
*PID:uva1608
*Auth:Jonariguez
*****************
��ο����ж���ĳ������[l,r]�е�ĳ��Ԫ��x�Ƿ�Ψһ��
��L[x]Ϊ��x����Һ�x��ȵ������ֵ�λ��(���±�),
R[x]�ĺ�����ͬ��
�����L[x]<l && R[x]>r������˵��x������[l,r]����Ψһ�ġ�O(1)ʱ��

�������õ�������ɣ�����˼·��
�������������ҵ�һ��ֻ����һ�ε�Ԫ�أ������������ֱ�ӵý��ۡ�boring����
����ҵ��ˣ���Ϊa[p],��ôֻ����a[1..p-1]��a[p+1..n]�Ƿ����㼴�ɡ�
��ֻ��ݹ�ͺ��ˡ�
���о����ڲ���ΨһԪ�ص�ʱ�򣬱�����������м��ң������������Ǹ�
Ԫ�����м������������㾭�����ʽ��T(n)=2*T(n/2)+O(n)-> T(n)=O(n*logn)
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

//�������a[l..r]�Ƿ�����
bool solve(int l,int r){
    if(l>=r) return true;
    if(l+1==r){             //�����������������ֻҪ���߲���Ⱦ����㣬��ȾͲ�����
        if(a[l]!=a[r]) return true;
        else return false;
    }
    int i,k=0;
    for(i=l;i<=r;i++){          //���������м���ΨһԪ��
        if(L[i]<l && R[i]>r){           //������for(d=0;L+d<=R-d;d++)��Ȼ����L+d��R-d
            k=i;break;
        }
        if(2*i>=l+r)        //(�Ż�)�ߵ��м�͸�ͣ�ˣ����û�е���仰����ô��û��ΨһԪ�ص��������һ���(l->r)
            break;              //���û������Ż��Ļ���2.98s���Ź�
        if(L[r-i+l]<l && R[r-i+l]>r){
            k=r-i+l;break;
        }
    }
    if(k==0) return false;      //û�ҵ�
    if(solve(l,k-1) && solve(k+1,r))    //����ͬʱ�������������о�����
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
        for(i=1;i<=n;i++){          //����L,R����
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
