#include <iostream>
#include <math.h>
using namespace std;

long Fact(int n){
	if(n == 0) {
		return 1;
	}
	else return n*Fact(n-1);
}
int main(){
	int n;
	cout<<"Nhap n: "; cin>>n;
	if(n<0){
		cout<<"Giai thua khong dung cho so am, moi nhap lai!";
	}else{
		cout<<n<<"! = "<<Fact(n);
	}
	return 0;
}
