#include<bits/stdc++.h>
using namespace std;


int a[100], dd[100], n = 7, k =7;

struct MayIn {
	string hangsx;
	string loai;
	double giaban;
	double phantramgiamgia;
};

MayIn d[7] = {
	{"Lenovo", "Den", 24000000,0.2},
	{"LG", "trang", 30000000,0.25},
	{"Dell", "den", 32000000,0.2},
	{"HP", "vang", 20000000, 0},
	{"Macbook", "do", 39000000,0.3},
	{"Asus", "trang", 15000000, 0.25},
	{"Sony", "vang", 50000000,0},
};
	
void th() {
	cout<<"-----------------------------------"<<endl;
	cout << "STT"<<"Ten hang"<<setw(20)<<"loai"<<setw(20)<<"gia ban"<<setw(20)<<"giam gia"<<endl;
	cout<<"-----------------------------------"<<endl;
}

//de quy
void A1(MayIn d[], int n,int stt) {
	if(n ==0) {
		return;
	}
	
	
	cout << stt<<d[n-1].hangsx
	<<setw(20)<<d[n-1].loai
	<<setw(20)<<fixed<<setprecision(0)<<d[n-1].giaban
	<<setw(20)<<fixed<<setprecision(2)<<d[n-1].phantramgiamgia<<endl;
	A1(d,n-1,stt+1);
}

bool cmpGG(MayIn a, MayIn b) {
	return a.giaban < b.giaban;
	}
void A2(MayIn d[], int l, int r, int &stt) {
	if(l==r) {
		if(d[l].phantramgiamgia>0.05) {
			stt++;
			cout << stt<<d[l].hangsx<<setw(20)<<d[l].loai<<setw(20)<<fixed<<setprecision(0)<<d[l].giaban
			<<setw(20)<<fixed<<setprecision(2)<<d[l].phantramgiamgia<<endl;
		}
	} else {
		
		int m = (l+r)/2;
		A2(d,l,m,stt);
		A2(d,m+1,r,stt);
	}
}



void A3(MayIn d[], int n) {
	int index = 0;
	double min =d[0].giaban * (1-d[0].phantramgiamgia);
	
	for(int i =1; i<n;i++) {
		double giaGg= d[i].giaban * (1-d[i].phantramgiamgia);
		if(giaGg < min ) {
			min = giaGg;
			index = i;
		}
	}
	

	 cout << "\nMay in co gia sau giam gia thap nhat: \n";
	cout<<"-----------------------------------"<<endl;
	cout << "STT"<<"Ten hang"<<setw(20)<<"loai"<<setw(20)<<"gia ban"<<setw(20)<<"giam gia"<< setw(15) << "Gia sau giam\n";
	cout<<"-----------------------------------"<<endl;
	cout << 1<<d[index].hangsx<<setw(20)<<d[index].loai<<setw(20)<<fixed<<setprecision(0)<<d[index].giaban
	<<setw(20)<<fixed<<setprecision(2)<<d[index].phantramgiamgia<< setw(20)<< fixed << setprecision(0) << d[index].giaban * (1 - d[index].phantramgiamgia) << endl;
}

//dua ra tong so cach xep n MAY TINH vao n cho bang pp quay lui


	void view_config(MayIn d[]) {
		for(int i =1; i<=n;i++) {
			int z = a[i];
			cout << "May in "<<z<<setw(20);
		}
		cout<<endl;
	}
	
	int count2 = 0;
	void A4(MayIn d[], int k) {
		for(int i =1; i<=n;i++) {
			if(dd[i]==0) {
				a[k] = i;
				if(k ==n) {
					view_config(d);
					count2++;
				} else {
					dd[i] = 1;
					A4(d, k+1);
					dd[i] = 0;
				}
			}
		}
	}
int main() {
	
	cout << "danhsach ca may tinh" <<endl;
	//in
	th();
	A1(d,n,1);
	// in ra tang dan voi muc giam > 5%
	cout<<"\nDanh sach cac MAY TINH co kich thuoc > 15.6 inches la: \n";
	th();
	int stt = 0;
	A2(d,0,n-1,stt);
	// May in co gia sau giam gia thap nhat
	A3(d,n);
	
	A4(d,1);
	cout<<"\nTong so cach xep n MAY TINH vao n cho la: "<<count2<<"\n";
	return 0;
}