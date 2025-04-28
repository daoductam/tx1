#include<bits/stdc++.h>

using namespace std;

int a[100], n=6, k=4, i, dd[100];

struct Chuyenbay{
	string sohieu;
	long long giave;
	int soghe;
};

Chuyenbay x[6] = {
	{"VN005", 7100000, 3}, 
	{"VN002", 400000, 98}, 
	{"VN004", 500000, 6},
	{"VN003", 800000, 3},
	{"VN000", 300000, 6},
	{"VN008", 7900000, 9},
	};
	
	
void th(){
	cout<<"----------------------------------------------------------------------------\n";
	cout<<"STT";
	cout<<setw(10)<<"SO HIEU";
	cout<<setw(20)<<"GIA VE";
	cout<<setw(20)<<"SO GHE"<<endl;
	cout<<"----------------------------------------------------------------------------\n";
}


//hien thi list bang de quy
void displayList(Chuyenbay x[], int n){
	if(n==0){
		return;
	}
	displayList(x, n-1);
	
	cout<<n;
	cout<<setw(10)<<x[n-1].sohieu;
	cout<<setw(20)<<x[n-1].giave;
	cout<<setw(20)<<x[n-1].soghe<<endl;
	
}


//hien thi ra mh cac CHUYENBAY có giá vé > 700000 bang pp de quy
void A1_ktragiave(Chuyenbay x[], int l, int r, int &stt){
	if(l==r){
		if(x[l].giave > 700000){
			stt++;
			cout<<stt;
			cout<<setw(10)<<x[l].sohieu;
			cout<<setw(20)<<x[l].giave;
			cout<<setw(20)<<x[l].soghe<<endl;
			
		}
	}
	else{
		int m = (l+r) / 2;
		A1_ktragiave(x,l,m,stt);
		A1_ktragiave(x,m+1,r,stt);
	}	
}


//Tinh tong va dem GIAVE cua CHUYENBAY co SOGHE LE bang pp chia de tri
void tongsoghele(Chuyenbay x[], int l, int r, long &sum, long &countt){
	if(l==r){
		if(x[l].soghe % 2 != 0){
			sum += x[l].giave;
			countt++;
		}
	}
	else{
		int m = (l+r) / 2;
		tongsoghele(x,l,m,sum,countt);
		tongsoghele(x,m+1,r,sum,countt);
	}
}


//tim va tra ve CHUYENBAY co gia ve thap nhat bang pp chia de chi
Chuyenbay A2_min_giave(Chuyenbay x[], int l, int r){
	if(l==r) return x[l];
	int m = (l+r) / 2;
	Chuyenbay a = A2_min_giave(x, l, m);
	Chuyenbay b = A2_min_giave(x, m+1, r);
	return a.giave < b.giave ? a:b;
}


//sinh tap con 4 CHUYENBAY cua LIST B 
//bang pp quay lui
void A3_chon_4_chuyenbay(Chuyenbay x[], int k, int start){
	if(k==0){
		//in tap con
		for(int i=0; i<n; i++){
			if(a[i]){
				cout<<"Chuyen bay "<<i+1<<" "<<x[i].sohieu<<" "<<x[i].soghe<<setw(20);
			}
		}
		cout<<"\n";
	}
	for(int i=start; i<n; i++){
		a[i] = 1;
		A3_chon_4_chuyenbay(x, k-1, i+1);
		a[i] = 0;
	}
}


//bang pp sinh
void view_config(Chuyenbay x[]){
	for(int i=1; i<=k; i++){
		int z = a[i];
		cout<<"Chuyen bay "<<z<<" "<<x[z-1].sohieu<<" "<<x[z-1].soghe<<setw(20);
	}
	cout<<"\n";
}

void next_config(){
	a[i]+=1; 
	i++;
	while(i<=k){
		a[i]=a[i-1]+1;
		i++;
	}
}

void listing_configs(Chuyenbay x[]){
	for(int i=1; i<=k; i++){
		a[i]=i;
	}
	do{
		view_config(x);
		i=k;
		while(i>0 && a[i]==n-k+i){
			i--;
		}
		if(i>0){
			next_config();
		}
	}
	while(i>0);
}



//sinh hoan vi cac CHUYENBAY cua List B
//pp sinh
void view_config(Chuyenbay x[]){
	for(int i=1; i<=n; i++){
		int z = a[i];
		cout<<"Chuyen bay "<<z<<setw(20);
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

void listing_configs(Chuyenbay x[]){
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
	cout<<"Tong so cach xep hoan vi cua pp sinh la: "<<count2<<endl;
}


//pp quay lui
int count2 = 0;
void Try(Chuyenbay x[], int k){
	for(int i=1; i<=n; i++){
		if(dd[i] == 0){
			a[k] = i;
			if(k == n){
				view_config(x);
				count2++;	
			}
			else{
				dd[i] = 1;
				Try(x,k+1);
				dd[i] = 0;
			}
		}
	}
}




//sap xep gia ve tang dan
void A4_merge_giavetangdan(Chuyenbay x[], int l, int m, int r){
	int n1 = m-l+1;
	int n2 = r-(m+1) +1;
	Chuyenbay a[n1], b[n2];
	
	for(int i=0 ; i<n1; i++){
		a[i] = x[i+l];
	} 
	for(int i=0; i<n2; i++){
		b[i] = x[i+m+1];
	}
	
	int i=0, j=0;
	while(i<n1 && j<n2){
		if(a[i].giave  <= b[j].giave) x[l++] = a[i++];
		else x[l++] = b[j++];
	}
	
	while(i<n1) x[l++] = a[i++];
	while(j<n2) x[l++] = b[j++];
}

void A4_mergeSort_giavetangdan(Chuyenbay x[], int l, int r){
	if(l>=r) return;
	int m = (l+r)/2;
	A4_mergeSort_giavetangdan(x, l, m);
	A4_mergeSort_giavetangdan(x, m+1, r);
	A4_merge_giavetangdan(x, l, m, r);
}


//Tim gia ve == 400000 bang chia de tri
//muon ap dung duoc BinarySearch thi phia Sort roi
int search(Chuyenbay x[], long long t, int l, int r){
	if(l > r) return -1;
	else{
		int m = (l+r)/2;
		if(x[m].giave == t) return m;
		else if(t > x[m].giave) return search(x, t, m+1, r);
		else return search(x, t, l, m);
	}	
}





int main(){
	
	th();
	displayList(x,n);
	
	
	
	cout<<"\nCac chuyen bay co gia ve tren 700000 la: \n";
	th();
	int stt = 0;
	A1_ktragiave(x, 0, n-1, stt);
	cout<<"\n";


	
	long sum = 0, countt = 0;
	tongsoghele(x, 0, n-1, sum, countt);
	cout<<"\nSo chuyen bay co so ghe le la: "<<countt<<"\n";
	cout<<"\nTong gia ve cua cac chuyen bay co GIAVE LE la: "<<sum<<"\n";
	
	
	
	cout<<"Chuyen bay co gia ve nho nhat la: \n";
	th();
	cout<<setw(10)<<A2_min_giave(x, 0, n-1).sohieu;
	cout<<setw(20)<<A2_min_giave(x, 0, n-1).giave;
	cout<<setw(20)<<A2_min_giave(x, 0, n-1).soghe<<endl;
	cout<<"\n";

	
	
	
//	cout<<"Cac phuong an chon ra 4 chuyen bay tu danh sach b bang PP SINH la: \n";
//	listing_configs(x);
//	cout<<"Cac phuong an chon ra 4 chuyen bay tu danh sach b bang PP QUAY LUI la: \n";
//	A3_chon_4_chuyenbay(x,4,0);


	
//	cout<<"Cac hoan vi sap xep chuyen bay tu danh sach b la: \n";
//	listing_configs(x);
//	Try(x,1);
//	cout<<"Tong so cach xep cua pp quay lui la: "<<count2<<endl;

	
	
	
	
//	cout<<"Before sort price: \n";
//	displayList(x,n);
//	cout<<"After soft price: \n";
//	A4_mergeSort_giavetangdan(x, 0, n-1);
//	displayList(x,n);
//	
//	
//	
////	long long m;
////	cout<<"Nhap GIA VE cua mot CHUYENBAY: "; cin>>m;
//		if(search(x,400000,0,n-1)){
	//		cout<<"Vi tri chuyen bay DAU TIEN co gia ve = 400000 tim kiem duoc la: "<<search(x,400000,0,n-1)<<"\n";
	//		th()
	//		cout<<setw(10)<<x[search(x,400000,0,n-1)].sohieu;
	//		cout<<setw(20)<<x[search(x,400000,0,n-1)].giave;
	//		cout<<setw(20)<<x[search(x,400000,0,n-1)].soghe<<"\n";
//	}
	
	return 0;
}
