#include <stdio.h>
int main(){

/*
   This program checks whether the sequence of '1's in a binary input 
   follows a periodic pattern. The user inputs a sequence of '0' and '1', 
   ending with Enter. The program verifies if the number of '0's between 
   consecutive '1's remains constant, indicating periodicity.
   
   Example Input:  101010
   Output: "periyodiktir" (periodic)
*/

    int sifirsayac=0;
    int birsayac=0;
    char x='5';
    int periyodik=0;
    int m=0;
    //girilen iki tane bir arasýndaki 0 lar eþit olmalý
    while(x!='\n'){
        scanf("%c",&x);
      
        
  
        if(x=='1'){birsayac=1;}
        
        if(birsayac==1)   {
            
            
            if(x=='0'){sifirsayac++;}
            
            
            
            if (x=='1'){
                
                if(sifirsayac==m){periyodik=1;}
                else{periyodik=0;}


                    m=sifirsayac;
                
              
                sifirsayac=0;
                
            }
            
            
        }
        
        
        
    }




           
    if (periyodik==1){printf("periyodiktir\n");}
    else{printf("periyodik degildir\n");}
                
    
    return 0;
}


