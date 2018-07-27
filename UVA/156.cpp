#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

map<string,int> cnt;
vector<string> b;

string st(string str){
    string ans=str;     //注意这里要把str赋值给ans，然后对ans操作
    for(int i=0;i<str.length();i++)
        ans[i]=tolower(ans[i]);
    sort(ans.begin(),ans.end());
    return ans;
}

int main()
{
    int i;
    string s;
    while(cin>>s){
        if(s[0]=='#') break;
        b.push_back(s);
        string t;
        t=st(s);
        if(cnt.count(t)==0)
            cnt[t]=0;
        cnt[t]++;
    }
    vector<string> res;     //这里要再创建一个vector，然后需要再排序输出
    for(i=0;i<b.size();i++){
        s=b[i];
        string t=st(s);
        if(cnt[t]==1)
            res.push_back(s);
    }
    sort(res.begin(),res.end());
    for(i=0;i<res.size();i++)
        cout<<res[i]<<endl;
    return 0;
}
