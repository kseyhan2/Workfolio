clc;
load_imp =131 -1i*114;
car_imp = 100;
norm_imp = load_imp / car_imp;
control = 0;
freq = 10 * 10^9;
Rl = real( load_imp );
Xl = imag( load_imp );
lamda = 3*10^8 / freq;
 
t = ( Xl + sqrt( Rl *(( car_imp - Rl )^2 + Xl^2 )/ car_imp )/( Rl - car_imp) );
m = atan(t);
 
d = (1/(2*pi))*(pi+atan(t));


if t >= 0

    d = lamda*(1/(2*pi))*atan(t);

end

G = (Rl*(1+t^2))/(Rl^2+(Xl+t*car_imp)^2);
B = (Rl^2*t-(car_imp-Xl*t)*(Xl+car_imp*t))/(car_imp*(Rl^2+(Xl+t*car_imp)^2));
l1 = -1*lamda*1/(2*pi)*atan(B*car_imp);

disp( ['gereken uzunluk',num2str(l1)] );

frekans=1*10^9:0.2*10^9:3*10^9;
gama=zeros(1,11);

zstub=zeros(1,11);
lamdag=3*10^8./frekans;
for k=1:11:1
    
zl=1i*car_imp*tan(2*pi./lamdag*l1);
zstub(k)=(zl.*load_imp)/(zl+load_imp);
gama(k)=abs((zstub(k)-car_imp)/(zstub(k)+car_imp));
end
figure;
plot(frekans,gama);
