#include <iostream>
#include <string>
#include <math.h>
using namespace std;

string transform(int x,int y,string s){
	string res="";
	int sum=0;
	for(int i=0;i<s.length();i++){
		if(s[i]=='-') continue;
		if(s[i]>='0' && s[i]<='9')
			sum=sum*x+s[i]-'0';
		else
			sum=sum*x+s[i]-'A'+10;
	}
	while(sum){
		char temp=sum%y;
		sum/=y;
		if(temp<=9)
			temp+='0';
		else
			temp=temp-10+'A';
		res=temp+res;
	}
	if(res.length()==0)
		return res='0';
	if(s[0]=='-') res='-'+res;
	return res;
}

int main()
{
	int n,r;
	string s,res;
	while(cin>>s>>r){
		res=transform(10,r,s);
		cout<<res<<endl;
	}
	return 0;
}
