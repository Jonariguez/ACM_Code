#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <algorithm>
using namespace std;
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
typedef set<int> Set;   //定义集合类型Set
map<Set,int> IDcache;   //Set映射成ID，因为题目的stack是要存整型int的，即这里的ID
vector<Set> Setcache;   //根据ID取集合，Setcache[ID]=Set即某ID对应的集合为Set

//查找给定集合x的ID（直接map映射），找不到就新分配一个ID
int ID(Set x){
    if(IDcache.count(x)) return IDcache[x];
    Setcache.push_back(x);
    return IDcache[x]=Setcache.size()-1;    //Set的ID说白了就是该Set在Setcache中的下标
}

int main()
{
    int i,j,k,T,n,x;
    string op;
    cin>>T;
    while(T--){
        cin>>n;
        stack<int> s;       //题目中的桟
        IDcache.clear();    //注意要clear
        Setcache.clear();
        while(n--){
            cin>>op;        //上面设置好后，具体的操作就很简单，直接用一个stack桟就可以了
            if(op[0]=='P') s.push(ID(Set()));
            else if(op[0]=='D')
                s.push(s.top());
            else {
                Set x1=Setcache[s.top()];s.pop();
                Set x2=Setcache[s.top()];s.pop();
                Set x;
                if(op[0]=='U')
                    set_union(ALL(x1),ALL(x2),INS(x));      //set_union是求并集 STL
                else if(op[0]=='I')
                    set_intersection(ALL(x1),ALL(x2),INS(x));   //set_intersection 交集 STL
                else if(op[0]='A'){
                    x=x2;x.insert(ID(x1));      //求加，只需将一个集合insert到另一个集合就好
                }
                s.push(ID(x));
            }
            cout<<Setcache[s.top()].size()<<endl;   //注意是桟顶集合的元素个数，而不是整个桟的size()
        }
        cout<<"***"<<endl;
    }
    return 0;
}









