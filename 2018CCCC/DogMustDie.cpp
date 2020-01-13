#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=1e3+10;
int gender[maxn]; //1为女孩 
vector<vector<int> > v;
 
int read(string s){
	int len=s.length(),num=0;
	int flag=1;
	if(s[0]=='-') flag=0;
	else num=s[0]-'0';
	for(int i=1;i<len;i++){
		num=num*10+s[i]-'0';
	}
	gender[num]=flag;
	return num;
}
 
int main(){
	int n,m,k;
	string t;
	scanf("%d%d",&n,&m);
	v.resize(n);
	vector<double> pa(n,0.0);
	vector<double> pb(n,0.0);
	for(int i=0;i<m;i++){
		scanf("%d",&k);
		v[i].resize(k);
		for(int j=0;j<k;j++){
			cin>>t;
			int num=read(t);
			v[i][j]=num;
		}
	}
	
	string a,b;
	cin>>a>>b;
	int a1=read(a),b1=read(b);
	double mxa=0,mxb=0;
	for(int i=0;i<m;i++){
		bool fa=find(v[i].begin(),v[i].end(),a1)!=v[i].end();
		bool fb=find(v[i].begin(),v[i].end(),b1)!=v[i].end();
		if(fa||fb){
			for(int j=0;j<v[i].size();j++){
				if(fa){
					if(gender[v[i][j]]+gender[a1]==1){
						pa[v[i][j]]+=1.0/v[i].size();
						mxa=max(mxa,pa[v[i][j]]);
					}
				}
				if(fb){
					if(gender[v[i][j]]+gender[b1]==1){
						pb[v[i][j]]+=1.0/v[i].size();
						mxb=max(mxb,pb[v[i][j]]);
					}
				}
				
			}
		}
	}
	
	if(pa[b1]==mxa&&pb[a1]==mxb){
		printf("%s%d %s%d\n",gender[a1]?"":"-",a1,gender[b1]?"":"-",b1);
	}else{
		for(int i=0;i<n;i++){
			if(pa[i]==mxa){
				printf("%s%d %s%d\n",gender[a1]?"":"-",a1,gender[a1]?"-":"",i);
			}
		}
		
		for(int i=0;i<n;i++){
			if(pb[i]==mxb){
				printf("%s%d %s%d\n",gender[b1]?"":"-",b1,gender[b1]?"-":"",i);
			}
		}
	}
	
	return 0;
}