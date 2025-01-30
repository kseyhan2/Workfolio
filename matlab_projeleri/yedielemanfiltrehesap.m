%% filter

z0=50;

g0 = 1;

g1 =1.1812;

g2 = 1.4228;

g3 =  2.0967;

g4 = 1.5734;

g5=2.0967;

g6=1.4228;

g7=1.1812;

g8=1;

epsilon_r= 3.55;

h = 0.508;

fc=7*10^9;

ohmc = 1;

w50= 1.3;

ind_imp = 107.8;


ind_wdt = 0.2;

cap_imp = 22.10;

cap_wdt= 3.5;

lamda=3*10^8/fc;

lg=lamda/sqrt(epsilon_r);



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

L_3=(z0/g0)*ohmc/(2*pi*fc)*g3;

L_5=(z0/g0)*ohmc/(2*pi*fc)*g5;

L_7=(z0/g0)*ohmc/(2*pi*fc)*g7;

c2=(g0/z0)*ohmc/(2*pi*fc)*g2;

c4=(g0/z0)*ohmc/(2*pi*fc)*g4;

c6=(g0/z0)*ohmc/(2*pi*fc)*g6;

lamda_l = lamda*(eps_l)^-0.5;

lamda_c = lamda*(eps_c)^-0.5;

lL_1 = 1000*lamda_l/(2*pi)*asin(2*pi*fc*L_1/ind_imp);

lL_2= 1000*lamda_l/(2*pi)*asin(2*pi*fc*L_5/ind_imp);

lC_1 = 1000*lamda_c/(2*pi)*asin(2*pi*fc*c2*cap_imp);

lC_2 = 1000*lamda_c/(2*pi)*asin(2*pi*fc*c4*cap_imp);