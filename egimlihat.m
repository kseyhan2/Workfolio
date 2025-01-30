

v=linspace(0,6*pi,100);
zl=100;
z0=50;
gama=zeros(1,100);
for k=1:100
gama(k)=(1/2)*log(zl/z0)*(sin(v(k)/2)/(v(k)/2))^2;

end
plot(v/pi,gama);
hold on;
title('yansima katsayisi grafigi');

A=1.13*pi;


gama0=1/2*log(zl/z0);

gamak=zeros(1,100);

for k=1:100
    

    
    gamak(k)  = gama0*cos(sqrt(v(k)^2-A^2 ))/cosh(A);



end
plot(v/pi,gamak);
legend('Ustel','klopfenstein');
xlabel('PI');