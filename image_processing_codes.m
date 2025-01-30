
% NOTE TO USERS:
% This script uses functions such as imread, imwrite, audioread, and audiowrite
% to load and save files. Please ensure that:
% 1. The required image and audio files are placed in the appropriate locations.
% 2. You update the file paths in the script (e.g., 'path/to/your/file.jpg')
%    to match the actual location of these files on your system.
%
% Example:
% Replace 'path/to/your/image.jpg' with the actual path to your image file:
% imageData = imread('path/to/your/image.jpg');
%
% To avoid errors, ensure the file paths are correct before running the script.
















%1.Soru:
%%


aslan=imread('');% The argument of the imread function should contain the path to a JPEG file named "aslan".









%imread,resmi matlaba aktarmak için kullanılmıştır bütün sorulardaki kodların farklı bir bilgisayarda 
%çalışması için imread fonksiyonunun paremetresi dosyanın bulunduğu konuma
%göre değiştirilmelidir. resim aslan değişkeninde 3 boyutlu bir matris
%olarak tutulmuştur

en=size(aslan,1);
boy=size(aslan,2);
renk=size(aslan,3);


% resmin en boy ve renk değerlerinin tutulduğu matristen değerler size komutu ile
% alınmıştır ve değişkenlere atanmıştır


disp(['Enine piksel sayisi=',num2str(en)]);
disp(['Boyuna piksel sayisi=',num2str(boy)]);
%enine ve boyuna piksel değerleri disp komutu ile ekrana yazdırılmıştır

rgbdeger=aslan(371,371,:);
disp(['istenilen konumdaki rgb degeri= ',num2str(rgbdeger),' seklindedir']);
%üç boyutlu aslan matrisinin 371,371,: gösterimi ile 3.boyuttaki tüm
%değerleri rgbdeger değişkenine atanmıştır ve ekrana yazdırılmıştır

imshow(aslan);
%resmi figür olarak göstermek için kullanılan imshow komutu ile resim
%gösterilmiştir














%2.Soru:
%%
aslan=imread('');% The argument of the imread function should contain the path to a JPEG file named "aslan".
%bu komutla ilgili açıklama 1.soruda yapılmıştır


siyahbeyazaslan=rgb2gray(aslan);
imshow(siyahbeyazaslan);
%rgb2gray komutu ile resim 3 boyutlu renkli halden 2 boyutlu siyah beyaz
%hale çevrilmiştir ve imshow komutu ile figür olarak gösterilmiştir

pikseldeger=siyahbeyazaslan(371,371);
disp(['istenilen konumdaki piksel degeri= ',num2str(pikseldeger),' seklindedir']);
%371,371 konumundaki piksel degeri pikseldeger matrisine atanmıştır ve disp
%komutu ile ekrana yazdırılmıştır
resminhistogrami=imhist(siyahbeyazaslan);
figure;
plot(resminhistogrami);
xlabel('piksel renk degerleri');
ylabel('Piksel sayisi');
%imhist komutu ile resmin histogramı oluşturulmuştur ve plot ile
%çizilmiştir bu kodun çalışması için çalıştırıldığı bilgisayarda image
%processing toolbox olması gerekmektedir

buyukindis = siyahbeyazaslan(:,:)>131;
b=zeros(1024,1024);
b(buyukindis)=1;
buyukpiksel=sum(b,"all");
toplampiksel=1024*1024;

olasilik= buyukpiksel./toplampiksel;
disp(['bu resimden rastgele secilen bir pikselin değerinin 131 den büyük olma olasılığı= ',num2str(olasilik),' dir']);
% resmin matrisindeki değeri 131'den büyük olan indisler buyukindis
% değişkenine kaydedilmiştir sonra zeros ile 0'lardan oluşan resimle aynı
% boyutlu bir matris açılıp değeri 131 den büyük olan indisleri 0 dan 1 e
% çevrilmiştir. Bu matrisin tüm elemanları sum komutu ile toplanmıştır ve
% 131'den büyük kaç tane indis bulunduğu tespit edilmiştir. Bulunan bu
% değerin toplam piksel sayısına oranı(1024*1024) bize istenen olasılığı vericektir



boyananresim=zeros(1024,1024,3);

for a=1:1024


for b=1:1024

    

    
 if siyahbeyazaslan(a,b)<=92
boyananresim(a,b,1)=0;
boyananresim(a,b,2)=0;
boyananresim(a,b,3)=0;
 end
     if siyahbeyazaslan(a,b)>92&&siyahbeyazaslan(a,b)<=171
boyananresim(a,b,1)=255;
boyananresim(a,b,2)=0;
boyananresim(a,b,3)=0;
    end

if siyahbeyazaslan(a,b)>171
boyananresim(a,b,1)=255;
boyananresim(a,b,2)=255;
boyananresim(a,b,3)=0;
 end

end 
end
figure;
imshow(boyananresim);

%resim renkli olacağı için boyanan resim matrisi 3 boyutlu açıldı sonra
%eşik değerlerine göre karşılaştırma yapılıp matrisin uygun if bloğuna girip kırmızı
%siyah ve sarı renklerine eşitlenmesi işlemi yapıldı renk değerlerine
%internetten baktım
gosterilecekresim=boyananresim(200:824,200:824,:);
figure;
imshow(gosterilecekresim);
%boyananresim yani yeni resmin istenilen değerler arasındaki bölgesi
%kırpılıp imshow ile gösterilmiştir arasında derken eşitlik olup olmadığını
%anlamadığım için sınırları 200 824 aldım 201 823 de alınabilir

%%
%3.Soru:
aslan=imread('');% The argument of the imread function should contain the path to a JPEG file named "aslan".

rpiksel=aslan(:,:,1);
gpiksel=aslan(:,:,2);
bpiksel=aslan(:,:,3);
  
 rpikseltoplam=sum(rpiksel(:));
 gpikseltoplam=sum(gpiksel(:));
  bpikseltoplam=sum(bpiksel(:));
%bu işlemlerle r g b değerlerinin tutulduğu aslan matrisinin 3.boyutundaki
%değerler ayrı ayrı toplanmıştır bu toplamı toplam piksel sayısına bölmek
%bize ortalamayı vericektir
toplampiksel=1024*1024;
rortalama=rpikseltoplam/toplampiksel;
gortalama=gpikseltoplam/toplampiksel;
bortalama=bpikseltoplam/toplampiksel;

disp([' ortalama R değeri= ',num2str(rortalama),' ortalama G değeri= ',num2str(gortalama),' ortalama B değeri=',num2str(bortalama)]);
%matris bölmesi olduğu için bölme işleminde ./ notasyonu kullanılmıştır
yeniresim=zeros(1024,1024,3);
for i=1:1024
    for j=1:1024
        for k= 1:3
            if k==1
            yeniresim(i,j,k)=aslan(i,j,k)-rortalama;
            end
            if k==2
                   yeniresim(i,j,k)=aslan(i,j,k)-gortalama;
            end
            if k==3
                   yeniresim(i,j,k)=aslan(i,j,k)-bortalama;
            end
        end 
    end 
end
figure;
imshow(yeniresim);
%r için g için ve g için ortalama değerler hesaplandı ve ayrı ayrı orjinal  1. 2 .
%ve 3. kısımdan çıkarıldı yeni resim değişkenine atandı 
tersresim=zeros(1024,1024,3);
for a=1:1024
    for b=1:1024
for k=1:3
 tersresim(a,b,k)=abs(255-aslan(a,b,k));
    
end
    
    end
end
figure ;
imshow(tersresim);
%3 lü döngü ile matrisin tüm elemanlarına erişilmiştir ve hepsinin 255 ile
%arasındaki fark alınmıştır negatif gelme durumuna karşılık abs
%kullanılmıştır
toplamresim=zeros(1024,1024,3);
for i=1:1024
    for j=1:1024
        for k=1:3

            toplamresim(i,j,k)=aslan(i,j,k)+tersresim(i,j,k);
        end 
    end 
end

figure;
imshow(toplamresim);   
%üçlü döngü ile matrislerin tüm elemanları tek tek toplanmıştır
%bu toplam sonucunda beyaz görüntü elde edilmiştir çünkü tersi ve orjinalin
%toplanmasıyla tüm piksel değerleri 255 e tamamlanmıştır ve R=255 G=255
%B=255 değeri beyazı temsil eder
%%
% 4.Soru:
aslan=imread('');% The argument of the imread function should contain the path to a JPEG file named "aslan".
resim=imfinfo('C:       FILE Location      \aslan.jpeg');
boyut=resim.FileSize/1024;
disp(['resmin boyutu=',num2str(boyut),'kilobayttir']);
%bu değer byte cinsindendir 1024 e bölerek kaç kb olduğunu tespit
%edebiliriz imfinfo komutunu file sizeı araştırarak dökümantasyondan
%öğrendim

ciftcikarilmisresim= aslan(1:2:end,1:2:end,:);

dortluresim=aslan(4:4:end,4:4:end,:);
imwrite(ciftcikarilmisresim,'C:        FILE Location     \ciftcikarilmis.jpeg');
imwrite(dortluresim,'C:     FILE Location        \dortlu.jpeg');
cift=imfinfo('C:        FILE Location       \ciftcikarilmis.jpeg');
dortlu=imfinfo('C:          FILE Location         \dortlu.jpeg');
ciftboyut=cift.FileSize/1024;
dortboyut=dortlu.FileSize/1024;
disp(['cift indisleri cikarilan resmin boyutu=',num2str(ciftboyut),('kb dordun katı indislerin alindigi resmin boyutu= '),num2str(dortboyut),(' kb ')]);
figure;
subplot(1,3,1);
imshow(dortluresim);
title('dort kati olan resim');
subplot(1,3,2);
imshow(ciftcikarilmisresim);
title('cift indisler cikarilmis resim');
subplot(1,3,3);
imshow(aslan);
title('orjinal resim');

%1 den başlayıp 2 şer 2 şer atlayarak tek sayılı indisler alındı ve 4 ten
%başlayıp 4 er 4 er atlayarak 4 ün katı olan indisler alındı imwrite komutu
%ile kaydedildi imfinfo komutu ile dosyanın bilgileri okundu FileSize ile
%boyutu alınıp 1024 e bölündü ve kilobayt cinsinden boyutu bulundu disp
%komutu ile yazdirildi ve imshow ile 3 resim yanyana açılıp incelendi
averagepooling=zeros(512,512,3);
c=1;
d=1;


for a=1:2:1023 
    for b= 1:2:1023
      averagepooling(c,d,1)=aslan(a,b,1)/4+aslan(a+1,b,1)/4+aslan(a,b+1,1)/4+aslan(a+1,b+1,1)/4;
 averagepooling(c,d,2)=aslan(a,b,2)/4+aslan(a+1,b,2)/4+aslan(a,b+1,2)/4+aslan(a+1,b+1,2)/4;
  averagepooling(c,d,3)=aslan(a,b,3)/4+aslan(a+1,b,3)/4+aslan(a,b+1,3)/4+aslan(a+1,b+1,3)/4;
     
  d=d+1;
    
    end 

    d=1;
  
    c=c+1;
end


maxpooling=zeros(512,512,3);
c=1;
d=1;
for a=1:2:1023 
    for b= 1:2:1023
      maxpooling(c,d,1)=max([aslan(a,b,1),aslan(a+1,b,1),aslan(a,b+1,1),aslan(a+1,b+1,1)]);
 maxpooling(c,d,2)=max([aslan(a,b,2),aslan(a+1,b,2),aslan(a,b+1,2),aslan(a+1,b+1,2)]);
  maxpooling(c,d,3)=max([aslan(a,b,3),aslan(a+1,b,3),aslan(a,b+1,3),aslan(a+1,b+1,3)]);
     
  d=d+1;
    
    end 

    d=1;
  
    c=c+1;
end


minpooling=zeros(512,512,3);
c=1;
d=1;
for a=1:2:1023 
    for b= 1:2:1023
      minpooling(c,d,1)=min([aslan(a,b,1),aslan(a+1,b,1),aslan(a,b+1,1),aslan(a+1,b+1,1)]);
 minpooling(c,d,2)=min([aslan(a,b,2),aslan(a+1,b,2),aslan(a,b+1,2),aslan(a+1,b+1,2)]);
  minpooling(c,d,3)=min([aslan(a,b,3),aslan(a+1,b,3),aslan(a,b+1,3),aslan(a+1,b+1,3)]);
     
  d=d+1;
    
    end 

    d=1;
  
    c=c+1;
end

figure;
subplot(2,2,1);
imshow(aslan);
title('orjinal ');
subplot(2,2,2);
imshow(averagepooling);
title('average ');
subplot(2,2,3);
imshow(maxpooling);
title('max');
subplot(2,2,4);
imshow(minpooling);
title('min');
%average min ve max pooling kodlarında örneğin 1.piksel için a,b,1 a+1,b,1
%a,b+1,1 a+1,b+1,1 ile seçilen matrisin etrafındaki 2x2 karelik tüm
%elemanlar döngüde ele alınmıştır min max ve toplayıp 4 e bölme işlemi ile
%istenilen işlemlere tabii tutulmuştur(1,2,3 dahil tüm piksel değerleri bu
%işleme girmiştir algoritma sadece averagepooling için yazılıp kopyala yapıştır ile yapılan işlemler değiştirilmiştir) c,d değişkeni ise oluşturulacak yeni matrisin
%yerleştirme indisleridir her satır yerleştirmesinde c 1 artmıştır ve her
%sütun yerleştirmesinde d 1 artmıştır ancak yeni satıra geçince sütun
%sayısını başa almak için satır döngüsünde d tekrardan 1 e eşitlenmiştir
%döngülerin 2 şer 2 şer artırılarak örneğin a+1,b,1 deki elemanı tekrar
%kullanmamak içindir mesela a 1 den 3'e atlar ve a=2 yalnızca bir kere
%kullanılmış olur
imwrite(minpooling,'C:      FILE Location         \minpooling.jpeg');
imwrite(maxpooling,'C:          FILE Location         \maxpooling.jpeg');
imwrite(averagepooling,'C:      FILE Location         \averagepooling.jpeg');
averagep=imfinfo('C:        FILE Location       \averagepooling.jpeg');
maxp=imfinfo('C:        FILE Location       \maxpooling.jpeg');
minp=imfinfo('C:        FILE Location   \minpooling.jpeg');
minboyut=minp.FileSize/1024;
maxboyut=maxp.FileSize/1024;
averageboyut=averagep.FileSize/1024;
disp(['minpooling resminin boyutu=',num2str(minboyut),('kb'),('maxpooling resminin boyutu= '),num2str(maxboyut),(' kb '),('average pooling boyutu='),num2str(averageboyut),('kb')]);

%%
%5.Soru:
sehir=imread("");% The argument of the imread function should contain the path to a JPG file named "sehir".
siyahbeyazsehir=rgb2gray(sehir);


durtu=zeros(1,2);
durtu(1,1)=0.02;
durtu(2,2)=-0.02;
konvolusyonresim=conv2(siyahbeyazsehir,durtu,'same');
figure;
subplot(1,3,1);
imshow(sehir);
title('orjinal ');
subplot(1,3,2);
imshow(siyahbeyazsehir);

title('siyah beyaz');
subplot(1,3,3);
imshow(konvolusyonresim);
title('Konvolüsyon');
%conv2 2 değişkeni konvolüsyon almaya yarayan fonksiyondur
%same parametresi kenar kaybı olmadan konvolüsyonun tam olarak alınmasını
%sağlar
%resime bakıldığı zaman uygulanan konvolüsyon işleminin koyu renkleri açığa
%açık renkleri koyuya çevirdiği rahatlıkla görülebiliyor
%%

%6.Soru:
aslan=imread("");% The argument of the imread function should contain the path to a JEPG file named "aslan".
birvaryans=imnoise(aslan,'gaussian',0.1);
dortvaryans=imnoise(aslan,'gaussian',0.4);
yedivaryans=imnoise(aslan,'gaussian',0.7);
figure;
%imnoise komutu ile gaussian filtresi istenilen varyans değerlerince
%uygulanmıştır bu fonksiyonun 3. parametresi varyans değerlerini alırken
%2.parametresi filtrenin adını alır
subplot(2,2,1);

imshow(aslan);
title('orjinal resim');
subplot(2,2,2);

imshow(birvaryans);
title('0.1 varyansli resim');
subplot(2,2,3);

imshow(dortvaryans);
title('0.4 varyansli  resim');
subplot(2,2,4);

imshow(yedivaryans);
title('0.7 varyansli  resim');
%subplot, aynı figur içinde birden fazla resim göstermeye yarar
filtrelisifirbir=imgaussfilt(birvaryans);
%imgaussfilt fonksiyonu parametre yerine yazılan resime filtre uygulamıştır
figure;
subplot(1,3,1);

imshow(aslan);
title('orjinal resim');
subplot(1,3,2);

imshow(birvaryans);
title('gurultulu resim');
subplot(1,3,3);

imshow(filtrelisifirbir);
title('filtreli resim');
%%

% 7.Soru
[gitar,orneklemeorani]=audioread("");
%dosya yolu kodun çalıştırıldığı bilgisaya göre güncellenmelidir
%sound(gitar,orneklemeorani); 
% seslerin hepsinin aynı anda çalmaması için her birinin başına % işareti
% koydum kod sırayla yüzdeler kaldırıp çalıştırılırsa sesler ayrı ayrı
% dinlenebilir ayrıca bu işlemlere girmeden tüm sesler audiowrite ile
% kaydedilmiştir o şekilde de dinlebilir

%sound komutu sesin matlabda çalınması için kullanılmıştır 2.parametreye
%örnekleme frekansı girilmiştir
disp([('ornekleme frekansi='),num2str(orneklemeorani)]);
disp([('toplam ornekleme sayisi='),num2str(length(gitar))]);
orneklemesayisi=length(gitar);
sure=(length(gitar)-1)/orneklemeorani;
%length komutu toplam örnekleme sayısını verirken orneklemeorani bir
%saniyedeki ornekleme sayısını verir bu ikisini oranlayınca geçen süreyi
%elde ederiz

disp([('sesin suresi='),num2str(sure),('saniyedir')]);
t1=0:(1/orneklemeorani):(length(gitar)-1)/orneklemeorani;
%1 çıkarılmasının sebebi matlabda indislerin 1 den başlamasıdır ancak
%zamanın 0 dan başlaması gerektiğidir zaman 0 dan başlayıp 1/orneklemeorani
%adımla lentgh-1/orneklemeorani yani süreye kadar gider
plot(t1,gitar);
title('orjinal gitar sesinin zamana bagli grafigi');
xlabel('zaman(saniye)');
ylabel('ses');

sesfourier=fft(gitar);
figure;
plot(abs(sesfourier));
%abs ile plot kullanımını https://www.youtube.com/watch?v=aUkCeNPYblY
%linkli youtube videosundan öğrendim
title('orjinal gitar sesinin frekans grafigi');
xlabel('frekans(hertz)');
ylabel('genlik');



v=length(durtu);
durtu =[1,zeros(1,orneklemeorani),1/4,zeros(1,orneklemeorani),1/16,zeros(1,orneklemeorani)];
%bu sekilde durtu fonksiyonu oluşturmayı
%https://www.youtube.com/watch?v=ASzWEwiz3rw&t=156s linkli youtube
%videosundan öğrendim durtu fonksiyonunun değerlerinin arasına örnekleme
%frekansı kadar boşluk konulunca gecikme yaptığı görülmüştür
yankiligitarsesi= conv(durtu,gitar,'full');

%sound(yankiligitarsesi,orneklemeorani);


%verilen sistemde birim dürtü girdisi için t=1 de 1 t=2 de 1/4 ve t=3 de
%1/16 değerini alan durtu yanıtı tanımlandı
%y(n)=x(n)*h(n) bağıntısından yeni çıkış sinyali hesaplanmalıdır
%durtu fonksiyonu t=0,1,2 dışında tüm t'ler için tanımsızdır onu tanımlı
%yapmak için 0 a eşitleyebiliriz

yankilisure=(length(yankiligitarsesi)-1)/orneklemeorani;
disp(['yankili sesin suresi',num2str(yankilisure),'saniye olarak bulunmustur']);
audiowrite("",yankiligitarsesi,orneklemeorani);
t2= 0:1/orneklemeorani:(length(yankiligitarsesi)-1)/orneklemeorani;
figure;
plot(t2,yankiligitarsesi);
xlabel('zaman');
ylabel('ses');
title('yankili sesin zamana bagli grafigi');
yankiforier=fft(yankiligitarsesi);
figure;
plot(abs(yankiforier));
xlabel('frekans');
ylabel('genlik');
title('yankili grafigin frekans spektrum grafigi');
cbirkhz=cos(2*pi*10^3*t2);
conmhz=cos(2*pi*10^7*t2);
modulebirkhz=zeros(1,length(yankiligitarsesi));
moduleonmhz=zeros(1,length(yankiligitarsesi));
for i=1:1:length(yankiligitarsesi)
modulebirkhz(i)=yankiligitarsesi(i)*cbirkhz(i);
moduleonmhz(i)=yankiligitarsesi(i)*conmhz(i);
end

%matris çarpımı olmadığı için döngüler kullanılmıştır
%sound(modulebirkhz,orneklemeorani);
%sound(moduleonmhz,orneklemeorani);
figure;
plot(t2,conmhz);
xlabel('zaman');
ylabel('genlik');
title('tasiyici sinyalin zaman grafigi');
figure;
plot(abs(fft(conmhz)));
xlabel('frekans(hertz)');
ylabel('genlik');
title('tasiyici sinyalin frekans grafigi');
figure;
plot(t2,moduleonmhz);
title('modulasyonlu sinyalin zaman grafigi');
xlabel('zaman');
ylabel('deger');
figure;
plot(abs(fft(moduleonmhz)));
xlabel('frekans(hertz)');
ylabel('genlik');
title('module edilmis sinyalin frekans grafigi');
modulemoduleonmhz=zeros(1,length(moduleonmhz));
for i=1:1:length(moduleonmhz)
modulemoduleonmhz(i)=moduleonmhz(i)*conmhz(i);
%eleman çarpımından dolayı döngüyle tek tek çarpılmıştır
end
figure;
plot(abs(fft(modulemoduleonmhz)));
title('tekrardan module edilmis sinyalin frekans grafigi');
xlabel('frekans');
ylabel('genlik');
figure;
plot(t2,modulemoduleonmhz);
title('tekrardan module edilmis sinyalin zaman grafigi');
xlabel('zaman');
ylabel('deger');
[b,a]=butter(6,10000/orneklemeorani/2);
%ikiye bölünme sebebi maksimum nyquist frekansıdır
z=filter(b,a,modulemoduleonmhz);
o1=abs(z);
%demodülasyon için mutlak değere alındı
figure;
plot(t2,o1);
title('lowpass gecirilmis sinyalin zaman grafigi');
xlabel('zaman');
ylabel('deger');
figure;
plot(abs(fft(o1)));
title('lowpass gecirilmis sinyalin frekans grafigi');
xlabel('frekans(hertz)');
ylabel('genlik');
%lowpass filtreyi https://www.youtube.com/watch?v=G1M3Iaf6Rq4 linkli
%youtube videosu ve dökümantasyondan öğrendim

gurultu=wgn(length(o1),1,0.002);
gurultuluses=zeros(1,length(o1));
for i=1:1:length(o1)
gurultuluses(i)=(1/400)*gurultu(i)+o1(i);
%gurultunun genliği 1/400 ile çarpılmıştır çünkü gürültü normal sesi çok
%bastırmıştır  ama 1/400 ile çarpılarak eklendiğinden dolayı hem arkadan gelen cızırtı hem de gitar
%melodisi rahatlıkla duyulmaktadır
end
%sound(o1,orneklemeorani);
%sound(gurultuluses,orneklemeorani);
figure;
plot(abs(fft(gurultuluses)));
title('gurultulu sinyalin frekans grafigi');
xlabel('frekans');
ylabel('genlik');
[b1,a1]=butter(6,25000/orneklemeorani/2);
filtrelenmisgurultu=filter(b1,a1,gurultuluses);
%sound(filtrelenmisgurultu,orneklemeorani);
figure;
plot(abs(fft(filtrelenmisgurultu)));
title('filtrelenmis goruntu spektrumu');
xlabel('frekans');
ylabel('genlik');
sound(filtrelenmisgurultu,orneklemeorani);
tersdurtu=fliplr(durtu);
%dürtünün tersiyle konvolüsyon işlemi yapılırsa önceki haline döner
bastakisinyal = deconv(filtrelenmisgurultu, durtu, 'full');

%sound(bastakisinyal,orneklemeorani);
figure;
plot(abs(fft(bastakisinyal)));
title('basa dondurulmus sinyalin frekans grafigi');
xlabel('frekans');
ylabel('genlik');
audiowrite("C:   file location  \birkhz.wav",modulebirkhz,orneklemeorani);
audiowrite("C:       file location           \onmhz.wav",moduleonmhz,orneklemeorani);
audiowrite("C:      file location           \ensoncevrilmis.wav",bastakisinyal,orneklemeorani);
audiowrite("C:      file location        \gurultuluses.wav",gurultuluses,orneklemeorani);
audiowrite("C:      file location       \filtrelenmisgurultu.wav",filtrelenmisgurultu,orneklemeorani);
audiowrite("C:      file location    \demodule.wav",o1,orneklemeorani);
