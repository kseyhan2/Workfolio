clear all;
freq=10*10^9;
zl=131-114j;
z0=100;
znorm=zl/z0;
ynorm=z0/zl;



teta=linspace(0,2*pi,400);
reel=1;
r=1;

xekseni=linspace(-4,4,400);
empedanslar=reel+1i*xekseni;
v=empedanslar(1)-ynorm;
for k=1:length(empedanslar)

Min=empedanslar(1)-ynorm;
if empedanslar(k)-ynorm<Min
    
    Min=empedanslar(k)-ynorm;
end

end
gama=(empedanslar-1)./(1+empedanslar);
figure;

smithchart(gama);
hold on;
center=1;


xc = 1+real(znorm-1)*cos(teta);
yc = -(1+imag(znorm-1)*sin(teta));
Center = xc + 1j*yc;

smithchart(Center);
smithchart(-gama);
smithchart(-Center);

figure
smithchart([1+1i*0.5;1+1i*0])


C1 = -gama;
C2 = -Center;
E = abs(C1-C2);
[Min,idx] = min(E);

smithchart(C1(idx),'x')
smithchart(C2(idx),'o')
C2(:,idx);

suspetans=2;
for u=1:length(teta)
if  yc(u)+gama(u)<0.1
    suseptans=yc(u);
    
end

end


