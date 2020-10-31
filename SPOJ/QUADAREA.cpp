#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int T;
	cin>>T;
	double a,b,c,d;
	while(T--){
		cin>>a>>b>>c>>d;
		double s = (a+b+c+d)/2;
		double ans = sqrt((s-a)*(s-b)*(s-c)*(s-d));
		cout<<setprecision(2)<<fixed<<ans<<endl;
	}
	return 0;
}

