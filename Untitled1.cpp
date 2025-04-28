#include<bits/stdc++.h>

using namespace std;

int a[100], n=7, k=7, i, dd[100];

struct Maytinh{
	string tenhang;
	double kichthuoc;
	double giaban;
};

Maytinh d[7] = {
	{"Lenovo", 18, 24000000},
	{"LG", 21, 30000000},
	{"Dell", 23, 32000000},
	{"HP", 9, 20000000},
	{"Macbook", 8, 39000000},
	{"Asus", 13, 15000000},
	{"Sony", 14, 10000000},
	};
	
//HIEN THI LIST BANG PP DE QUY

void th(){
	cout<<"----------------------------------------------------------------------------\n";
	cout<<"STT";
	cout<<setw(20)<<"TEN HANG";
	cout<<setw(20)<<"KICH THUOC";
	cout<<setw(20)<<"GIA BAN"<<endl;
	cout<<"----------------------------------------------------------------------------\n";
}


void A(Maytinh d[], int n){
	if(n==0){
		return;
	}
	A(d, n-1);
	
	cout<<n;
	cout<<setw(20)<<d[n-1].tenhang;
	cout<<setw(20)<<d[n-1].kichthuoc;
	cout<<setw(20)<<fixed<<setprecision(0)<<d[n-1].giaban<<endl;	
}
	
	
//in ra mt co KICHTHUOC > 15.6 inches theo pp chia de tri	
void A1(Maytinh d[], int l, int r, int &stt){
	if(l==r){
		if(d[l].kichthuoc > 15.6){
			stt++;
			cout<<stt;
			cout<<setw(20)<<d[l].tenhang;
			cout<<setw(20)<<d[l].kichthuoc;
			cout<<setw(20)<<fixed<<setprecision(0)<<d[l].giaban<<endl;
		}
	}
	else{
		int m = (l+r) / 2;
		A1(d,l,m,stt);
		A1(d,m+1,r,stt);
	}
}

//in ra tong GIA BAN cua list MAY TINH bang pp de quy
double A2(Maytinh d[], int n, int &sum){
	if(n==0){
		return sum;
	}
	
	sum+=d[n-1].giaban;
	A2(d,n-1,sum);
}


//dua ra tong so cach xep n MAY TINH vao n cho bang pp quay lui
void view_config(Maytinh d[]){
	for(int i=1; i<=n; i++){
		int z = a[i];
		cout<<"May tinh "<<z<<setw(20);
	}
	cout<<"\n";
}

int count2 = 0;
void A3(Maytinh d[], int k){
	for(int i=1; i<=n; i++){
		if(dd[i] == 0){
			a[k] = i;
			if(k == n){
//				view_config(d);
				count2++;	
			}
			else{
				dd[i] = 1;
				A3(d,k+1);
				dd[i] = 0;
			}
		}
	}
}
int main(){
	cout<<"Danh sach cac MAY TINH la: \n";
	th();
	A(d,n);
	
	
	cout<<"\nDanh sach cac MAY TINH co kich thuoc > 15.6 inches la: \n";
	th();
	int stt = 0;
	A1(d,0,n-1,stt);
	
	
	int sum = 0;
	cout<<"\nTong gia ban cua danh sach may tinh la: "<<A2(d,n,sum)<<"\n";
	
	A3(d,1);
	cout<<"\nTong so cach xep n MAY TINH vao n cho la: "<<count2<<"\n";
	
	
	return 0;
}
