#include <iostream>
#include<cstdlib>
#include<ctime>
double sqrt(double a);

using namespace std;
const int deneysayisi=10000;
bool inside(int x, int y,  int r);
bool inside(int x, int y, int z , int r);



int main(int argc, char** argv) {
	
	
srand(time(NULL));

	double olasilikkure;
	double olasilikcember;
	const int yaricap=500;
int i;

 	
	int toplamkure=0;
	int toplamcember=0;
	int a = yaricap;
	int b= -yaricap;
	

	
	

	for(i=0; i < deneysayisi; i++){
		
	
		int noktax = rand()%(2*yaricap+1)-yaricap;
	
	int noktay = rand()%(2*yaricap+1)-yaricap;
	
	int noktaz = rand()%(2*yaricap+1)-yaricap;

if(i==2){
	cout<<noktax<<"  "<< noktay<< " "<< noktaz<<endl;
}
	

	if(inside(noktax,noktay,noktaz,yaricap)==1){
		toplamkure++;
		
	}
		if( inside(noktax,noktay,yaricap)==1){
			
			toplamcember++;
		}
	}
	olasilikkure=(double)toplamkure/deneysayisi;
	cout<<"uygulama 2 yani kure icin hesaplanan pi sayisi = "<<6*olasilikkure<<"	kureye dusen nokta sayisi = "<< toplamkure<<"   deney sayisi = "<< deneysayisi<<endl;
	
	olasilikcember=(double)toplamcember/deneysayisi;
	cout<<"uygulama 1 yani cember icin hesaplanan pi sayisi = "<<4*olasilikcember<<" 	cembere dusen nokta sayisi = "<< toplamcember<<"   deney sayisi = "<< deneysayisi<<endl;
	
	
	
	
	
	
	return 0;
}



bool inside(int x, int y, int z , int r){

	if(x*x+y*y+z*z<r*r){
		return 1;
	}
	else return 0;
}


bool inside(int x, int y , int r){

	if(x*x+y*y<r*r){
		return 1;
	}
	else return 0;
}



