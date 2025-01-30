%221201034 Kaan Seyhan Ele 432 Ödev 1

%%
% X-Y ve Y-Z Plane için radiation intensity çizilişi
%x-y için teta = pi/2 olmalıdır
%yz için phi=pi/2 ve phi=3pi/2 olmalıdır ancak phi>pi için intensity 0
%olmaktadır o yüzden sadece pi/2 için yapılacaktır
%x-y plane için 

phi = linspace( 0 , pi , 33 );

theta = linspace( 0 , pi , 33 );

Uxy = sin(phi) .* sin(phi) .* sin(phi);

polarplot( phi , Uxy );

title( "Radiation İntensity at x-y Plane" );

Uyz   =  sin( theta );

figure();

polarplot( theta , Uyz );

title("Radiation İntensity at y-z Plane");
%% 



%Nümerik olarak yönlülük hesaplanması


%prad için tanım aralığında radiation intensitynin çift katlı integraline
%ihtiyaç vardır

[theta1,phi1]=meshgrid(theta,phi);

U=sin(theta1).*sin(phi1).*sin(phi1).*sin(phi1);

prad=trapz(phi, trapz(theta, U .* sin(theta1), 2));
numeric_directivity=4*pi*U./prad;
%%
% analitik ile kiyaslama
analytical_directivity=6*sin(theta1).*sin(phi1).*sin(phi1).*sin(phi1);
%analitik hesap için çift katlı integral çözülmüştür ve matlaba integralin
%sonucu yukarıdaki gibi aktarılmıştır


% Fark hesaplama

difference = abs(numeric_directivity - analytical_directivity);


% Maksimum hata

hata = max(difference(:));

z=max(max(analytical_directivity));

oran=(hata/z)*100;

fprintf('Hata: %.6f\n', oran);



