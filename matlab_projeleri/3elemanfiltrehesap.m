clear all;

z0=50;

g0 = 1;

g4 = 1;

g1 = 1.0316;

g3 = g1;

g2 = 1.1474;

epsilon_r= 3.55;

h = 0.508;

fc=10^9;

ohmc = 1;

w50= 1.1;

ind_imp = 100;

ind_wdt = 0.25;

cap_imp = 30;

cap_wdt= 1.5;

lamda=3*10^8/fc;

if cap_wdt/h <=1

eps_c = (epsilon_r+1)/2 + (epsilon_r-1)/2*(1+12*h/cap_wdt)^-0.5;


else
    
    
    eps_c = (epsilon_r+1)/2 + (epsilon_r-1)/2*(1+12*h/cap_wdt)^-0.5+0.04*(1-cap_wdt/h)^2;
 
    
end

if ind_wdt/h <= 1
    
    
    
    eps_l = (epsilon_r+1)/2 + (epsilon_r-1)/2*(1+12*h/ind_wdt)^-0.5;
    

    
else
    
    
    eps_l = (epsilon_r+1)/2 + (epsilon_r-1)/2*(1+12*h/ind_wdt)^-0.5+0.04*(1-ind_wdt/h)^2;
    
     
end

L_1=(z0/g0)*ohmc/(2*pi*fc)*g1;

L_3=(z0/g0)*ohmc/(2*pi*fc)*g1;

c2 = (g0/z0)*ohmc/(2*pi*fc)*g2;

lamda_l = lamda*(eps_l)^-0.5;

lamda_c = lamda*(eps_c)^-0.5;

lL = lamda_l/(2*pi)*asin(2*pi*fc*L_1/ind_imp);

lC = lamda_c/(2*pi)*asin(2*pi*fc*c2*cap_imp);