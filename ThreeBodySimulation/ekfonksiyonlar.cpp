#ifndef EKFONKSIYONLAR_CPP
#define EKFONKSIYONLAR_CPP

#include "ekfonksiyonlar.h"



inline void create(Universe * u1, canvas * graphic){
	
	
	int cisimsayisi;
	int roketsayisi;
	double kutleval;
	double hizx;
	double hizy;
	double konumx;
	double konumy;
	double puskurtmehizix;
	double puskurtmehiziy;
	double puskurtmekutlesi;
	double karadelikx;
	double karadeliky;
	double etkimeyaricapi;
	
	std::cout<<"Kac tane cisim eklemek istersiniz(eklemek istemiyorsaniz 0 giriniz): ";
	std::cin>>cisimsayisi;
	std::cout<<std::endl;	
	std::cout<<"Kac tane roket eklemek istersiniz(eklemek istemiyorsaniz 0 giriniz): ";
	std::cin>>roketsayisi;
	std::cout<<std::endl;
	
	for(int i=0;i<cisimsayisi;i++){
		
		std::cout<<i+1<<"."<<"Cismin kutlesini giriniz: ";
		std::cin>>kutleval;
		y();
		std::cout<<i+1<<"."<<"Cismin baslangic konumunun x bilesenini giriniz: ";
		std::cin>>konumx;
		y();
		std::cout<<i+1<<"."<<"Cismin baslangic konumunun y bilesenini giriniz: ";
		std::cin>>konumy;
		y();	
		std::cout<<i+1<<"."<<"Cismin baslangic hizinin x bilesenini giriniz: ";
		std::cin>>hizx;
		y();
		std::cout<<i+1<<"."<<"Cismin baslangic hizinin y bilesenini giriniz: ";
		std::cin>>hizy;
		y();
		u1->insertCisim(kutleval,vector2d(konumx,konumy),vector2d(hizx,hizy));
		
	}
		
	for(int i=0;i<roketsayisi;i++){
			
		std::cout<<i+1<<"."<<"Roketin kutlesini giriniz: ";
		std::cin>>kutleval;
		y();
		std::cout<<i+1<<"."<<"Roketin baslangic konumunun x bilesenini giriniz: ";
		std::cin>>konumx;
		y();
		std::cout<<i+1<<"."<<"Roketin baslangic konumunun y bilesenini giriniz: ";
		std::cin>>konumy;
		y();
		std::cout<<i+1<<"."<<"Roketin baslangic hizinin x bilesenini giriniz: ";
		std::cin>>hizx;
		y();
		std::cout<<i+1<<"."<<"Roketin baslangic hizinin y bilesenini giriniz: ";
		std::cin>>hizy;
		y();
		std::cout<<i+1<<"."<<"Roketin puskurtme hizinin x bilesenini giriniz: ";
		std::cin>>puskurtmehizix;
		y();	
		std::cout<<i+1<<"."<<"Roketin puskurtme hizinin y bilesenini giriniz: ";
		std::cin>>puskurtmehiziy;
		y();
		std::cout<<i+1<<"."<<"Roketin puskurtme kutlesini (wp) giriniz: ";
		std::cin>>puskurtmekutlesi;
		y();	
		u1->insertRoket(kutleval,vector2d(konumx,konumy),vector2d(hizx,hizy),vector2d(puskurtmehizix,puskurtmehiziy),puskurtmekutlesi);
		
	}
		
		std::cout<<"Cisim ve roketler eklendi"<<std::endl<<"Simulasyona karadelik eklemek ister misiniz (evet:1 / hayir : 0)";
		bool salinim;
		std::cin>>salinim;
		bool kontrol;

		if(salinim == 1){
			
			std::cout<<"Onerilen karadelik parametrelerini kullanmak ister misiniz? (evet:1 / hayir : 0)	";
			std::cin>>kontrol;
			
			if(kontrol == 1 ){
				
				u1 -> createBlackHole(20000, vector2d(0,0),100);  // Kara delik merkezde
				graphic->drawPoint(0,0,"black",100);
				graphic->drawText("Kara Delik",-120,-120,"Black",14);
				       	    
			}
			
			
			
			else {
				
				std::cout<<"Karadeligin merkezinin x bilesenini giriniz:";
				std::cin>>karadelikx;
				y();
				std::cout<<"Karadeligin merkezinin y bilesenini giriniz:";
				std::cin>>karadeliky;
				y();
				std::cout<<"Karadeligin etkime alaninin yaricapini giriniz:";
				std::cin>>etkimeyaricapi;
				y();
				u1->createBlackHole(20000, vector2d(karadelikx,karadeliky),etkimeyaricapi);
				graphic->drawPoint(karadelikx,karadeliky,"black",etkimeyaricapi);
				graphic->drawText("Kara Delik",karadelikx-120,karadeliky-120,"Black",14);
				       
				
			}
				
		}
		
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	








#endif 

