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
typedef set<int> Set;   //���弯������Set
map<Set,int> IDcache;   //Setӳ���ID����Ϊ��Ŀ��stack��Ҫ������int�ģ��������ID
vector<Set> Setcache;   //����IDȡ���ϣ�Setcache[ID]=Set��ĳID��Ӧ�ļ���ΪSet

//���Ҹ�������x��ID��ֱ��mapӳ�䣩���Ҳ������·���һ��ID
int ID(Set x){
    if(IDcache.count(x)) return IDcache[x];
    Setcache.push_back(x);
    return IDcache[x]=Setcache.size()-1;    //Set��ID˵���˾��Ǹ�Set��Setcache�е��±�
}

int main()
{
    int i,j,k,T,n,x;
    string op;
    cin>>T;
    while(T--){
        cin>>n;
        stack<int> s;       //��Ŀ�еėC
        IDcache.clear();    //ע��Ҫclear
        Setcache.clear();
        while(n--){
            cin>>op;        //�������úú󣬾���Ĳ����ͺܼ򵥣�ֱ����һ��stack�C�Ϳ�����
            if(op[0]=='P') s.push(ID(Set()));
            else if(op[0]=='D')
                s.push(s.top());
            else {
                Set x1=Setcache[s.top()];s.pop();
                Set x2=Setcache[s.top()];s.pop();
                Set x;
                if(op[0]=='U')
                    set_union(ALL(x1),ALL(x2),INS(x));      //set_union���󲢼� STL
                else if(op[0]=='I')
                    set_intersection(ALL(x1),ALL(x2),INS(x));   //set_intersection ���� STL
                else if(op[0]='A'){
                    x=x2;x.insert(ID(x1));      //��ӣ�ֻ�轫һ������insert����һ�����Ͼͺ�
                }
                s.push(ID(x));
            }
            cout<<Setcache[s.top()].size()<<endl;   //ע���ǗC�����ϵ�Ԫ�ظ����������������C��size()
        }
        cout<<"***"<<endl;
    }
    return 0;
}









