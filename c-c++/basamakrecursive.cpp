#include <iostream>

using namespace std;
int *ptr;
int toplam= 0;  

//�zyineleme kullanarak basamaklar toplam�n� hesapla

int hesapla(int n) {


// modunu al toplama ekle ve 10 a b�l
  
   
if (n==0){
	
	return 0;
	
	
}

*ptr+= n%10;






return hesapla(n/10);

}




int main() {
	ptr=&toplam;
	int a;
	cout<<"giriniz:";
	cin>>a;
	cout<<"\n";
hesapla(a);
	
cout<<("\n");
cout<<*ptr;
    return 0;
}

