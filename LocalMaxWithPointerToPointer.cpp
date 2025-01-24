#include <iostream>


using namespace std;

 int i,j;

int ** olustur(int *satir, int* sutun){
	
	cout<<"satir sayisini giriniz:";
	cin>>*satir;
	cout<<endl;
	cout<<"sutun sayisini giriniz:";
	cin>>*sutun;
   
    


int **dizi= new int*[*satir];
    
  for(i=0;i<*satir;i++){
  	
  	*(dizi+i)= new int[*sutun];
  	
  	
  	
  }
  
  
    for(i=0;i<*satir;i++){
    
	
		for(j=0;j<*sutun;j++){
    		
    		cin>>*(*(dizi+i)+j);
		}
    	
    
    
	}
    
      for(i=0;i<*satir;i++){
    
	
		for(j=0;j<*sutun;j++){
    		
    		cout<<*(*(dizi+i)+j)<<" ";
		}
    	cout<<endl;
    
    
	}
    
    for(i=0;i<4;i++){
    	cout<<endl;
	}
     
    
return dizi;


}




int kontrolet(int **dizi, int *satir, int *sutun){
	bool kontrol=0;
	
	int dondurulecek;
	
	bool bikere=false;
int max;
	for(i=0;i<*satir;i++){
		for(j=0;j<*sutun;j++){
			if(j>=1&&i>=1&&j<=*sutun-1&&i<=*satir-1){
				
				
				if(*(*(dizi+i)+j)>*(*(dizi+i)+j-1)&&*(*(dizi+i)+j)>*(*(dizi+i)+j+1)&&*(*(dizi+i)+j)>*(*(dizi+i-1)+j)&&*(*(dizi+i)+j)>*(*(dizi+i+1)+j)&&bikere==false){
					
					kontrol=1;
					dondurulecek=*(*(dizi+i)+j);
					max=dondurulecek;
				}
				
				if(*(*(dizi+i)+j)>*(*(dizi+i)+j-1)&&*(*(dizi+i)+j)>*(*(dizi+i)+j+1)&&*(*(dizi+i)+j)>*(*(dizi+i-1)+j)&&*(*(dizi+i)+j)>*(*(dizi+i+1)+j)&&bikere!=0&&*(*(dizi+i)+j)>max){
					
				
				
					dondurulecek=*(*(dizi+i)+j);
				
				}
				
				
				
				
			}
			
			
			
			
			
			
		}
		
		
		
	}
	
	
	if(kontrol==0){
	
	return kontrol;
	
	}
	
	
	else
	{
		
		return dondurulecek;
	}
	
	
}





int main(int argc, char** argv) {
	
	int *satir= new int;
	
	int *sutun= new int;
	
	int **dizi=olustur(satir, sutun);
	
	
	int bastir= kontrolet(dizi,satir,sutun);
	
	if(bastir==0){
		cout<<"boyle bir maksimum bulunamadi.";
		
	}
	
	else{
		cout<<"yerel maksimum = "<<bastir<<endl;
	}
	
	delete satir;
	
	delete sutun;
	
	return 0;
}
