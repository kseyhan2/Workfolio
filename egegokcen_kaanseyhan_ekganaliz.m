% ekg sinyalinin 0.05 ve 150 hz arasında frekans bileşenleri içeren bir
% sinyal olduğuna dikkat edilmelidir



%Ele 202 2024-2025 Güz Dönemi Projesi


%İsim 1: Kaan Seyhan    Numara 1: 221201034
%İsim 2: Ege Gökçen     Numara 2: 221201022
filename='hazirsinyal.txt';
veri=readmatrix(filename);
time=veri(:, 1);
voltage=veri(:, 2);

voltage=10^3*voltage;


ekg=voltage;
ekg=transpose(ekg);
time=transpose(time);
fs1=2001; % Grafik hassasiyet için saniyede 500 örnek tercih edilmiştir değeri değiştirilebilir
t1=linspace(0,2,fs1);





fs=2001; % Grafik hassasiyet için saniyede 500 örnek tercih edilmiştir değeri değiştirilebilir
t=time; 


figure();
plot(t,ekg);
title('Gürültüsüz EKG Sinyali Zaman Alanı Grafiği');
xlabel('Zaman (saniye)');
ylabel('Genlik (mV)');

% Oluşturulan Gürültüsüz EKG Sinyalinin Frekans Spekturumu İncelenmelidir
% Bunun İçin Fourier Dönüşümü Kullanıp Grafik Çizdirmek Uygundur

% Frekans Alan grafiği için zaman vektörü olduğu gibi bir frekans vektörü
% tanımlanmalıdır
orneklemefrekans=1000;
fouriergurultusuzsinyal=fft(ekg);
n=length(ekg);
frekans = (0:n-1)*(orneklemefrekans/n);% örnekleme frekansıyla artış

max_frekans=200;
indeksler =frekans <=max_frekans;

figure();
plot(frekans(indeksler),abs(fouriergurultusuzsinyal(indeksler)));
title('Gürültüsüz EKG Sinyalinin Frekans Spektrum Grafiği');
xlabel('frekans (hertz)');
ylabel('genlik');


%oluşturulan Gürültüsüz EKG Sinyalini gerçeğe yaklaştırmak için gürültü
%eklenmesi gerekmektedir.

fdusuk=0.02;
fsebeke=50;
fyuksek=170;


% gürültüler için randi fonksiyonu ile farklı 
% değerlerde 0 ile 10 arasında tamsayı üretiyoruz
d=randi([0,10])/45; 
s=randi([0,10])/18;
y=randi([0,10])/35;


dusukgurultu = d*cos(2*pi*fdusuk*t);

sebekegurultu=s*cos(2*pi*fsebeke*t);

yuksekgurultu= y*cos(2*pi*fyuksek*t);

gurultuluekg=ekg+dusukgurultu+yuksekgurultu+sebekegurultu;

%gürültüler istenilen frekansa göre oluşturup orjinal ekg sinyaline
%eklenmiştir
%gürültüler, düşük genlikli ve görece yüksek frekanslı sinüzoidler olarak
%tanımlanabilir bu yüzden gürültü genlikleri seçilirken orijinal ekg
%sinyaline göre daha düşük değerlerde seçilmiştir
figure();

plot(t,gurultuluekg);

title('Gürültülü EKG Sinyali Zaman Alanı Grafiği ');
xlabel('zaman (saniye)');
ylabel(' Genlik (mV)');
figure();


fouriergurultulusinyal= fft(gurultuluekg);
plot(frekans(indeksler),abs(fouriergurultulusinyal(indeksler)));

title('Gürültülü EKG Sinyalinin Frekans Spektrumu');

xlabel('Frekans (hz)');

ylabel('Genlik')
% oluşturulan frekans vektörüyle gürültülü sinyalin frekans spektrumu
% çizdirilmiştir frekans spektrumunda yeni bileşenlerin ortaya çıktığına
% dikkat edilmelidir!
spiceaktarilcak= [t' gurultuluekg']; % ' (üssü) işareti csv dosyasına uygun sütun forma geçirmek 
% için kullanılan transpoze işlemini gerçekleştirir


csvwrite('gurultuluekg.csv',spiceaktarilcak);%analiz lt spice üzerinden yapılacak ancak
% ek analiz olarak pspice analizi istenirse diye csv dosyası olarak da
% kaydedildi

gurultuluekgmilivolt=gurultuluekg;
%değerler grafik çizdirimi için önceden milivolt tanımlıydı ancak spicea
%geçirirken değerlerin milivolt olarak gözükmesi için katsayıyı 1000 e
%bölmek gerekir
spiceaktarilacakpwl= sprintf('%.6f %.6f\n', [t; gurultuluekgmilivolt]);

output= 'gurultuluekgsinyali.txt';
% Kullanici, dosya yolu ve dosya adini guncellemelidir
fyazilacak=fopen(output,'w');
fprintf(fyazilacak,'%s',spiceaktarilacakpwl);
fclose(fyazilacak);

%LT Spiceda Okunmak Üzere PWL ve CSV formatında Sinyal ve Zaman verisi 
%kaydedilmiştir
%LT spiceda, başka bir bilgisayrdan bu proje okunacağından dolayı dosya
%yolu değiştirlmesi uygun olacaktır


%spiceda gerekli analizden sonra bu kısım çalıştırılmalıdır
filename='ilklowpassfiltrecikisi.txt';
veri=readmatrix(filename);
time=veri(:, 1);
voltage=veri(:, 2);

voltage=10^3*voltage;

figure;

plot(time, voltage);

xlabel('Zaman (saniye)');
ylabel('Genlik (mV)');
title('İlk Low Pass Çıkışındaki Sinyalin Zaman Alanı Grafiği');

filtrelenmisfourier=abs( fft(voltage));
figure();

plot(frekans(indeksler),filtrelenmisfourier(indeksler));

xlabel('Frekans (Hz)');
ylabel(' Genlik ');
title('İlk Low Pass Çıkışındaki Sinyalin Frekans Alanı Grafiği');


%spiceda gerekli analizden sonra bu kısım çalıştırılmalıdır
filename='ilkhighpassfiltrecikis.txt';
veri=readmatrix(filename);
time=veri(:, 1);
voltage=veri(:, 2);

voltage=10^3*voltage;

figure;

plot(time, voltage);

xlabel('Zaman (saniye)');
ylabel('Genlik (mV)');
title('İlk High Pass Filtrenin Çıkışındaki Sinyalin Zaman Alanı Grafiği');

filtrelenmisfourier=abs( fft(voltage));
figure();

plot(frekans(indeksler),filtrelenmisfourier(indeksler));

xlabel('Frekans (Hz)');
ylabel(' Genlik ');
title('İlk High Pass Filtrenin Çıkışındaki Sinyalin Frekans Alanı Grafiği');


%spiceda gerekli analizden sonra bu kısım çalıştırılmalıdır
filename='gurultuluekgsinyali.txt';
veri=readmatrix(filename);
time2=veri(:, 1);
voltage2=veri(:, 2);

filename='filtrelenmissinyal.txt';
veri=readmatrix(filename);
time=veri(:, 1);
voltage=veri(:, 2);

figure;

plot(time, voltage);

xlabel('Zaman (saniye)');
ylabel('Genlik (mV)');
title('Bantdurduran Filtrenin Çıkışındaki Sinyalin Zaman Alanı Grafiği');

filtrelenmisfourier=abs( fft(voltage));
figure();

plot(frekans(indeksler),filtrelenmisfourier(indeksler));

xlabel('Frekans (Hz)');
ylabel(' Genlik ');
title('Bantdurduran Filtrenin Çıkışındaki Sinyalin Frekans Alanı Grafiği');

%detaylı analiz için tek figürde isteğe bağlı incelenebilir
figure();

subplot(2,2,1);
plot(t1,ekg,'LineWidth',1);
title('Gurultusuz EKG Sinyalinin Zaman Alanı Grafigi');
xlabel(' Zaman (saniye)');
ylabel(' Genlik (mV)');

subplot(2,2,2);
plot(time,voltage,'LineWidth',0.01);
title('Gurultu Eklenip Filtrelenmis EKG Sinyalinin Zaman Alanı Grafiği');
xlabel(' Zaman (saniye)');
ylabel(' Genlik (mV)');
subplot(2,2,3);
plot(frekans(indeksler),abs(fouriergurultusuzsinyal(indeksler)));
title('Gurultusuz EKG Sinyalinin Frekans Spektrum Grafigi');
xlabel('Frekans (hertz)');
ylabel('Genlik');
subplot(2,2,4);
plot(frekans(indeksler),abs(filtrelenmisfourier(indeksler)));
title('Gurultu Eklenip Filtrelenmis EKG Sinyalinin Frekans Spektrum Grafigi');
xlabel('Frekans (hertz)');
ylabel('Genlik');
%kolay analiz için  subplot kullanımı uygun görüldü

figure();

plot(time,voltage);
hold on;
plot(t1,voltage2);
hold off;
title('Gürültü Filtreleme Öncesi ve Sonrası Oluşan EKG Sinyalleri');
xlabel('Zaman (s)');
ylabel('Genlik (mV)');
%filtre etkisi gözlemi için hold on kullanımı ile aynı grafikte çizdirim
%yapıldı