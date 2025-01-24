#include <iostream>
using namespace std;

int i,j;
int ** olustur(int *, int *);
void temizle(int *, int *, int **);
void kontrol(int *, int *, int **);

int main(int argc, char** argv) {
	int *satir= new int;
	int *sutun= new int;
	int **dizi=olustur(satir,sutun);
	kontrol(satir,sutun,dizi);
		
	

		
	temizle(satir,sutun,dizi);

	return 0;
	
}


void kontrol(int *satir, int *sutun, int **dizi){
	int satirbirsayac=0;
	int satirsifirsayac=0;
	int yanyana=0;
	int sutunbirsayac=0;
	int sutunsifirsayac=0;
	

	for(i=0;i<*satir;i++){
		satirbirsayac=0;
		satirsifirsayac=0;
		yanyana=0;
		

		for(j=0;j<*sutun;j++){
			
			if(j+1<*sutun){
				
				if(*(*(dizi+i)+j)==*(*(dizi+i)+j+1))
				{
					yanyana++;
				}
				
			}
			

			if(*(*(dizi+i)+j)==1){
			
				satirbirsayac++;
			
			}
			
			else{
				
				satirsifirsayac++;
				
			}
			
			
		
			
		
			
			
		}
		
			if(satirsifirsayac!=satirbirsayac){
				cout<<"kosul1 saglanmadi -> satir: "<<i<<endl;
				
			}
			
				if(yanyana>2){
				
				cout<<"kosul2 saglanmadi -> satir: "<<i<<endl;
				
			}
			
			
	}
	
	
	
	
		for(j=0;j<*sutun;j++){
		sutunbirsayac=0;
		sutunsifirsayac=0;
	yanyana=0;
		for(i=0;i<*satir;i++){
			
			
			
			
				if(i+1<*satir){
				
				if(*(*(dizi+i)+j)==*(*(dizi+i+1)+j))
				{
					yanyana++;
				}
				
			}
			
				

			if(*(*(dizi+i)+j)==1){
			
				sutunbirsayac++;
			
			}
			
			else{
				
				sutunsifirsayac++;
				
			}
			
			
			
		}
		
			if(sutunsifirsayac!=sutunbirsayac){
				cout<<"kosul1 saglanmadi -> sutun: "<<j<<endl;
				
			}
			if(yanyana>2){
				
				cout<<"kosul2 saglanmadi -> sutun: "<<j<<endl;
				
			}
			
		
			
	}
	
	
	
	
}
int ** olustur(int *satir, int *sutun){
	
	
	cout<<"satir sayisini giriniz:";
	cin>>*satir;
	cout<<"sutun sayisini giriniz";
	cin>>*sutun;

	int **dizi= new int*[*satir];
	
	for(i=0;i<*satir;i++){
		*(dizi+i)=new int[*sutun];

	}
	
	for(i=0;i<*satir;i++){
		
		for(j=0;j<*sutun;j++){
			
			cin>>*(*(dizi+i)+j);
			
		}
		
		
	}
	

	return dizi;
	
	
}

void temizle(int *satir, int *sutun, int **dizi){

	for(i=0;i<*satir;i++){
		
		delete[] *(dizi+i);
		
	}
	
	delete [] dizi;
	
		delete satir;
	delete sutun;
}
