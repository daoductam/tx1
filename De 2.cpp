#include<bits/stdc++.h>

using namespace std;

struct Maygiat{
	string hsx;
	long double kl;
	double giaban;
};

int a[100], n=7, k=n-1,i;

Maygiat d[7] = {
	{"Electrolux", 12, 600000},
	{"LG", 10, 900000},
	{"Samsung", 12, 800000},
	{"Sony", 9, 899000},
	{"Apple", 8, 799000},
	{"LGG", 8, 698000},
	{"Tosiba", 8, 800000},
	};
	
	
void th(){
	cout<<"Danh sach cac MAY GIAT la: \n";
	cout<<"----------------------------------------------------------------------------\n";
	cout<<"STT";
	cout<<setw(20)<<"HSX";
	cout<<setw(20)<<"KHOI LUONG";
	cout<<setw(20)<<"GIA BAN"<<endl;
	cout<<"----------------------------------------------------------------------------\n";
}

//HIEN THI LIST 
//de quy
void A1(Maygiat d[], int n){
	if(n==0){
		return;
	}
	A1(d, n-1);
	
	cout<<n;
	cout<<setw(20)<<d[n-1].hsx;
	cout<<setw(20)<<d[n-1].kl;
	cout<<setw(20)<<d[n-1].giaban<<endl;	
}

//chia de tri
void A11(Maygiat d[], int l, int r, int &stt){
	if(l==r){
	stt++;	
	cout<<stt;
	cout<<setw(20)<<d[l].hsx;
	cout<<setw(20)<<d[l].kl;
	cout<<setw(20)<<d[l].giaban<<endl;
	}
	else{
		int m = (l+r)/2;
		A11(d,l,m,i);
		A11(d,m+1,r,i);
	}
}


//TINH VA TRA VE TONG GIA BAN CUA CAC MAYGIAT CO KL >= 9
void A2(Maygiat d[], int l, int r, double &sum){
	if(l==r){
		if(d[l].kl > 9){
			sum+=d[l].giaban ;
		}
	}
	else{
		int m = (l+r)/2;
		A2(d,l,m,sum);
		A2(d,m+1,r,sum);
	}
}


double A22(Maygiat d[], int n, double &sum){
	if(n==0){
		return sum;
	}
		
	if(d[n-1].kl > 9){
		sum+=d[n-1].giaban ;
	}	
	
	A22(d, n-1,sum);

}


//SINH CAC LUA CHON (N-1) MAYGIAT TRONG LIST d
void view_config(Maygiat d[]){                                                        
	for(int i=1; i<=k; i++){
		int z = a[i];
//		cout<<d[z-1].hsx<<"-"<<d[z-1].giaban<<setw(10);
		cout<<"May giat"<<z<<setw(20);

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

void A3(Maygiat d[]){
	int count =0;
	for(int i=1; i<=k; i++){
		a[i]=i;
	}
	do{
		view_config(d);
		count++;
		i=k;
		while(i>0 && a[i]==n-k+i){
			i--;
		}
		if(i>0){
			next_config();
		}
	}
	while(i>0);
	cout<<"Tong so phuong an lua chon (n-1) may giat la: "<<count<<"\n";
}




int main(){
	
	th();
//	A1(d, n);
	int stt = 0;
	A11(d,0,n-1,stt);
	
	
	double sum=0;	
//	A2(d,0,n-1,sum);
	cout<<"\nTong gia ban cua cac MAY GIAT co trong luong > 9 la: "<<A22(d,n,sum)<<"\n";
	
	
	
	
	cout<<"\nCac phuong an lua chon (n-1) may giat la: \n";
	A3(d);
	
	
	
}

