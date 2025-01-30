#include<stdio.h>

char satir[33][16];//algoritmayý dolu  satýrlara gelince kontrol ettiði için son satýrlar boþsa algoritmayý kontrol etmesi için gözükmeyen bir 33.satýr ekledim
                

void y(void){printf("\n");}
int main(void){
    int i;
    int k=0;
    int eklesil;
    int dongu=0;
    int j;
    int u = 0;
    int alg;
    int uygunotokontroldizisi[32];
    int uygunotoindisi[32];
    int varmi=0;
    int elbaslangic;
    int uygunsayac=0;
    int a=0;
    int otokontrol=0;
    int otokontroldizisi[32];
    int minoto;
    int maxoto;
    int sonindis;
    int otoindisler[32];
    int elkontrol=0;
    int kontrol=-1;
    int MB;
    int t=0;
    for(i=0;i<32;i++){
        
        for(j=0;j<16;j++){satir[i][j]='-';}
        
    }
    for(j=0;j<16;j++){satir[32][j]='X';}
    while(kontrol!=4){
        dongu=0;
        t=0;
        for(i=0;i<32;i++){uygunotokontroldizisi[i]=0;}
        uygunsayac=0;
        for(i=0;i<32;i++){otokontroldizisi[i]=0;}
        for(i=0;i<32;i++){otoindisler[i]=0;}
        for(i=0;i<32;i++){uygunotoindisi[i]=0;}
        sonindis=0;
        a=0;
        u=0;
        otokontrol=0;
        elkontrol=0;
        varmi=0;
        
        
      
        printf("Mod Belirle(1:  Goruntule) / (2:  Elle) / (3:  Oto) / (4:  Cik):");
        scanf("%d",&kontrol);
        
        if(kontrol==4){return 0;}

        if(kontrol==1){
            
            for(i=0;i<32;i++){
                
                if(i>=10){ printf("%d:  ",i);}
                else{printf(" %d:  ",i);}
                
                for(j=0;j<16;j++){
                    
                    printf("%c",satir[i][j]);
                    
                }
                y();
            }
            
            
        }

        if(kontrol==2){
            
            printf("ekle(1) / sil(0):");
            scanf("%d",&eklesil);
            if(eklesil==1){
                
                printf("kac mb:");
                
                scanf("%d",&MB);
                
                printf("baslangic:");
                
                scanf("%d",&elbaslangic);

                for(i=elbaslangic;i<elbaslangic+MB;i++){
                    
                    if(satir[i][0]=='X'){elkontrol++;}
                    
                }
                
                if(elkontrol==0){
                    
                    for(i=elbaslangic;i<elbaslangic+MB;i++){
                    
                        for(j=0;j<16;j++){   satir[i][j]='X';}
                    
                   }
                }
                else {printf("yer alinamadi");
                    y();
                    continue;
                }
                
            }
            if(eklesil==0){
                printf("kac mb:");
                
                scanf("%d",&MB);
                
                printf("baslangic:");
                
                scanf("%d",&elbaslangic);
                
                for(i=elbaslangic;i<elbaslangic+MB;i++){
                    for(j=0;j<16;j++){satir[i][j]='-';}
                }
            }
        }
        
        if(kontrol==3){
            
            printf("kac MB:");
            scanf("%d",&MB);
            y();
            printf("Algoritma numarasi(1: First  , 2: Best  , 3:Worst):");
            scanf("%d",&alg);
            
            
            if(alg==1){
                for(i=0;i<32;i++){
                    
                    
                    if(satir[i][0]=='-'){         otokontrol++;}
                    else{otokontrol=0;}
                    
                    if(otokontrol==MB){
                        for(k=i-MB+1;k<=i;k++){          for(j=0;j<16;j++){satir[k][j]='X';}  }
   
                        break;
                        
                        
                        
        }
                    
                }
                
                if(otokontrol==0){printf("Yer alinamadi!");continue;}
                
                
            }
            
            if(alg==2){
                
             
                for(i=0;i<33;i++){
                    
                    
                    
                    if(satir[i][0]=='-'){
                        uygunsayac++;
                        dongu=1;
                        t++;
                        
                    }
                    
                    if(satir[i][0]=='X'&&dongu!=0){
                        otokontroldizisi[a]=uygunsayac;
                        otoindisler[a]=i-uygunsayac; a++;
                        dongu=0;
                        uygunsayac=0;
                    }
                    
                            }
                
                if(t!=32){
                    
                    for(i=0;i<a;i++){
                        
                        if(otokontroldizisi[i]>=MB){varmi=1;}
                        
                        }
                    
                    for(i=0;i<a;i++){
                        
                        if(otokontroldizisi[i]>=MB){uygunotokontroldizisi[u]=otokontroldizisi[i];uygunotoindisi[u]=otoindisler[i];u++;}
                        
                    }
                    minoto=uygunotokontroldizisi[0];
                    sonindis=uygunotoindisi[0];
                    for(i=1;i<u;i++){if(uygunotokontroldizisi[i]<minoto){minoto=uygunotokontroldizisi[i];sonindis=uygunotoindisi[i];
                        
                    }}
                    
                    if(varmi==1){
                        for(i=sonindis;i<sonindis+MB;i++){for(j=0;j<16;j++){satir[i][j]='X';}
                            
                    }
                        
                    }
                }
                if(t==32){varmi=1;for(i=0;i<MB;i++){for(j=0;j<16;j++){satir[i][j]='X';}}}
                
                if(varmi==0){printf("Yer alinamadi");continue;}
            }
            
            if(alg==3){
                
                
                   for(i=0;i<33;i++){
                       
                
                       if(satir[i][0]=='-'){
                           uygunsayac++;
                           dongu=1;
                           t++;
                       }
                       
                       if(satir[i][0]=='X'&&dongu!=0){
                           otokontroldizisi[a]=uygunsayac;
                           otoindisler[a]=i-uygunsayac; a++;
                           dongu=0;
                           uygunsayac=0;
                       }
                       
                   }
                   
                   
                   
                if(t!=32){    for(i=0;i<a;i++){
                    
                    if(otokontroldizisi[i]>=MB){varmi=1;}
                    
                }
                    
                    for(i=0;i<a;i++){
                        
                        if(otokontroldizisi[i]>=MB){uygunotokontroldizisi[u]=otokontroldizisi[i];uygunotoindisi[u]=otoindisler[i];u++;}
                        
                    }
                    maxoto=uygunotokontroldizisi[0];
                    sonindis=uygunotoindisi[0];
                    for(i=1;i<u;i++){if(uygunotokontroldizisi[i]>maxoto){maxoto=uygunotokontroldizisi[i];sonindis=uygunotoindisi[i];
                        
                    }}
                    
                    if(varmi==1){
                        for(i=sonindis;i<sonindis+MB;i++){for(j=0;j<16;j++){satir[i][j]='X';}
                            
                        }
                        
                    }
                }
                if(t==32){varmi=1;for(i=0;i<MB;i++){for(j=0;j<16;j++){satir[i][j]='X';}}}
                   if(varmi==0){printf("Yer alinamadi");continue;}
                
                
            }
            
   
            
            
        }
        

        y();
        
    }
    y();
    
return 0;
}
