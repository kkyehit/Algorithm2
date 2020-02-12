#include <iostream>
#include <stdio.h>

using namespace std;

int a, b;
int main(void){
	string res;
	scanf("%d/%d", &a, &b);
	//printf("%d/%d\n",a,b);
	
	while(a != 1 || b != 1){
		double t = (double)a / b;
		if(t < 1){
			res += "L";
			b -= a;
		}else{
			res += "R";
			a -= b;
		}
		swap(a, b);
	//printf("%d/%d\n",a,b);
	}
	cout<<res<<endl;
}