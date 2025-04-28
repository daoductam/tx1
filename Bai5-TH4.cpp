#include<bits/stdc++.h>

using namespace std;

int a[100], n=6, k, i;

struct Congviec{
	string macv;
	double tgbd;
	double tgth;
};

Congviec x[6] = {
		{"NV05",2, 30},
		{"NV03",2, 34},
		{"NV08",2, 38},
		{"NV07",2, 23},
		{"NV01",2, 12},
		{"NV04",2, 35},
};

string L[6] = {"Huyen", "Ha", "Thuy", "Linh", "Hue", "Phuong"};


void th(){
	cout<<"----------------------------------------------------------------------------\n";
	cout<<"STT";
	cout<<setw(10)<<"MA SV";
	cout<<setw(20)<<"TGBD";
	cout<<setw(20)<<"TGTH"<<endl;
	cout<<"----------------------------------------------------------------------------\n";
}


//hien thi list bang de quy theo thu tu nguoc lai
void A1(Congviec x[], int n){
	if(n==0){
		return;
	}
	
	cout<<6-(n-1);
	cout<<setw(10)<<x[n-1].macv;
	cout<<setw(20)<<x[n-1].tgbd;
	cout<<setw(20)<<x[n-1].tgth<<endl;
	
	
	A1(x, n-1);
	
}

//dem so congviec co tgth <= 30phut bang pp chia de tri
void A2(Congviec x[], int l, int r, int &countt){
	if(l==r){
		if(x[l].tgth <= 30){
			countt++;
		}
	}
	else{
		int m = (l+r) / 2;
		A2(x,l,m,countt);
		A2(x,m+1,r,countt);
	}
}

//hien thi cac phuong an giao n congviec LIST C cho n nhanvien trong LIST L
//pp sinh
void view_config(Congviec x[]){
	for(int i=1; i<=n; i++){
		int z = a[i];
		cout<<"Cong viec "<<z<<" - "<<L[z-1]<<setw(20);
	}
	cout<<"\n";
}

void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}

void next_config(){
	//tim a[k] thuoc day giam dan vua du lon hon a[i]
	k=n;
	while(a[k] < a[i]){
		k--;
	}
	
	swap(a[k], a[i]); //dao vi tri
	
	int j=n; i++; // dao nguoc doan cuoi => sx tang dan
	while(i<j){
		swap(a[i], a[j]);
		j--;
		i++;
	}
}

void listing_configs(Congviec x[]){
	int count2 = 0;
	for(int i=1; i<=n; i++){
		a[i] = i;
	}
	
	do{
		view_config(x);
		count2++;
		i=n-1; // duyet tu cuoi ve dau, tim doan cuoi giam dan dai nhat
		while(i>0 && a[i] > a[i+1]){
			i--;
		}
		if(i>0){
			next_config();
		}
	}
	while(i>0);
	cout<<"\nTong so cach xep hoan vi cua pp sinh la: "<<count2<<endl;
}




int main(){
	th();
	A1(x, n);
	
	int countt = 0;
	A2(x,0,n-1,countt);
	cout<<"\nSo congviec co tgth <= 30phut la: "<<countt<<"\n";
	
	
	cout<<"\n";
	listing_configs(x);
}
