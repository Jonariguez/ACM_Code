#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>

using namespace std;

const int maxn=100000+10;

int n,val[maxn];
vector<int> s;

int binarySearch(int x){
    int left=0,right=s.size()-1;
    int mid;
    while(left<=right){
        mid=(left+right)/2;
        if(s[mid]<=x)
            left=mid+1;
        else
            right=mid-1;
    }
    return left;
}

int main(){
    int t,i,kcase=1;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        s.clear();
        for(int i=0;i<n;i++)
            {scanf("%d",&val[i]);
            val[i]-=i;}             //涨姿势了，这里-=i就可以处理两个数之间的间距问题了，哈哈
        int tmp;
        for(int i=0;i<n;i++){
            tmp=binarySearch(val[i]);
            if(tmp>=(int)s.size())
                s.push_back(val[i]);
            else
                s[tmp]=val[i];
        }
        int ans=s.size();
        printf("Case #%d:\n%d\n",kcase++,n-ans);
    }
    return 0;
}
