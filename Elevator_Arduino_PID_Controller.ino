// Buton ve motor pinleri
const int buttonPins[8] = {2, 3, 4, 5, 6, 7, 8, 9}; // 8 butonun

int lastButtonStates[8] = {LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW};
// Önceki buton durumları
const int pwmpos = 10;
const int pwmneg = 11;
const int trigPin = 12;
const int echoPin = 13;
// Durum ve kontrol değişkenleri
int kontrolcu = 0;
int selectedAlgorithm = 0;

int selectedKat = 0;
int currentKat = 0;
bool algorithmSelected = false;
bool katSelected = false;
bool isMoving = false;
bool salinim = false;
int kontrolcuSinyali=0;
float integral=0.0;
float Kd = 1000.0;
float turev=0;
int sonMesafe=0;
int fs=20;
// Kat mesafeleri (cm cinsinden)
const int katMesafeleri[3] = {15, 30, 50};
void setup() {
 for (int i = 0; i < 8; i++) {
 pinMode(buttonPins[i], INPUT);
 }
 pinMode(pwmpos, OUTPUT);
 pinMode(pwmneg, OUTPUT);
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 digitalWrite(pwmpos, LOW);
 digitalWrite(pwmneg, LOW);
 Serial.begin(9600);
}
void loop() {

 // Kullanıcıdan algoritma ve kat seçimi al
 if (!algorithmSelected || !katSelected) {
 checkButtons();
 }
 // Seçim yapıldıktan sonra asansör kontrolü
 if (algorithmSelected && katSelected) {
 moveElevator();
 }
}
// Butonları kontrol eden fonksiyon
void checkButtons() {
 for (int i = 0; i < 8; i++) {
 int buttonState = digitalRead(buttonPins[i]);
 if (buttonState == HIGH && lastButtonStates[i] == LOW) {
 delay(50); // Debounce

 if (i < 5 && !algorithmSelected) {
 selectedAlgorithm = i + 1;
 printAlgorithmName(selectedAlgorithm);
 algorithmSelected = true;
 }
 else if (i >= 5 && !katSelected) {
 selectedKat = i - 4;
 Serial.print("Kat ");
 Serial.print(selectedKat);
 Serial.println(" seçildi!");
 katSelected = true;
 }
 }
 lastButtonStates[i] = buttonState;
 }

}
// Algoritma isimlerini yazdıran fonksiyon
void printAlgorithmName(int algorithm) {
 switch (algorithm) {
 case 1:
 Serial.println("Aç Kapa algoritması seçildi!");
 kontrolcu = 1;
 break;
 case 2:
 Serial.println("P algoritması seçildi!");
 kontrolcu = 2;
 break;
 case 3:
 kontrolcu=3;
 Serial.println("PI Kontrol algoritması seçildi!");
 break;
 case 4:
 kontrolcu=4;
 Serial.println("PD Kontrol algoritması seçildi!");
 break;
 case 5:
 kontrolcu=5;
 Serial.println("PID Kontrol algoritması seçildi!");
 break;
 }
}
// Mesafe ölçen fonksiyon
long measureDistance() {
 digitalWrite(trigPin, LOW);
 delayMicroseconds(2);
 digitalWrite(trigPin, HIGH);

 delayMicroseconds(10);
 digitalWrite(trigPin, LOW);
 long duration = pulseIn(echoPin, HIGH);
 long distance = duration * 0.034 / 2; // Mesafeyi santimetre cinsinden hesapla ses hızı ile analiz
 return distance;
}
// Asansörü hedef kata taşıyan fonksiyon
void moveElevator() {
 isMoving = true;
 long distance = measureDistance();
 while (true) {
 // Aç-Kapa kontrol algoritması

 if (kontrolcu == 1) {
 integral=0;
 int santimkat = katMesafeleri[selectedKat - 1] - distance;
 Serial.print(distance); // Mesafe
 Serial.print("\t"); // Tab karakteri, iki veriyi ayırmak için
 Serial.println(katMesafeleri[selectedKat - 1]);
 delay(4);

 if (santimkat > 0.1) {
 digitalWrite(pwmpos, HIGH);
 digitalWrite(pwmneg, LOW);
 if (abs(santimkat) < 2) {
 currentKat = selectedKat;
 algorithmSelected = false;
 katSelected = false;

 }
 } else if (santimkat < 0.1) {
 digitalWrite(pwmpos, LOW);
 digitalWrite(pwmneg, HIGH);
 if (abs(santimkat) < 2) {
 currentKat = selectedKat;
 algorithmSelected = false;
 katSelected = false;
 }
 }

 }
 if (kontrolcu == 2) { // P Kontrol
 int santimkat = katMesafeleri[selectedKat - 1] - distance;
 integral =0;
 int Kp=14;
 Serial.print(distance); // Mesafe
 Serial.print("\t"); // Tab karakteri, iki veriyi ayırmak için
 Serial.println(katMesafeleri[selectedKat - 1]);

 kontrolcuSinyali = Kp*abs(santimkat);

 Serial.println(distance);
 //Serial.print("Kontrolcu Sinyali : ");
 //Serial.println(kontrolcuSinyali);
 if (santimkat > 0) {
 analogWrite(pwmpos,constrain(kontrolcuSinyali,190,255));
 digitalWrite(pwmneg, LOW);
 if (abs(santimkat) < 2) {
 currentKat = selectedKat;
 algorithmSelected = false;

 katSelected = false;

 }
 } else if (santimkat < 0) {
 digitalWrite(pwmpos, LOW);
 analogWrite(pwmneg,constrain(kontrolcuSinyali,50,255));
 if (abs(santimkat) < 2) {

 currentKat = selectedKat;
 algorithmSelected = false;
 katSelected = false;
 if(abs(santimkat) <= 0.1){
 digitalWrite(pwmpos, LOW);
 digitalWrite(pwmneg, LOW);
 currentKat = selectedKat;
 algorithmSelected = false;
 }
 }
 }

 }
if (kontrolcu == 3) { // PI Kontrol
 int santimkat = katMesafeleri[selectedKat - 1] - distance;

 Serial.print(distance); // Mesafe
 Serial.print("\t");
 Serial.println(katMesafeleri[selectedKat - 1]);
 int Kp=1;
 float Ki =0.1;



 //Serial.println(santimkat);

 if (santimkat > 0.05) {

 integral +=abs(santimkat);
 kontrolcuSinyali = Ki*abs(integral)+Kp*abs(santimkat);
 analogWrite(pwmpos,constrain(kontrolcuSinyali,190,255));
 digitalWrite(pwmneg, LOW);
 if (abs(santimkat) < 2) {
 integral=0;
 currentKat = selectedKat;
 algorithmSelected = false;
 katSelected = false;
 }
 } else if (santimkat < 0.05) {

 integral +=abs(santimkat);
 kontrolcuSinyali = Ki*abs(integral)+Kp*abs(santimkat);
 digitalWrite(pwmpos, LOW);
 analogWrite(pwmneg,constrain(kontrolcuSinyali,50,255));
 if (abs(santimkat) < 2) {
 integral=0;
 currentKat = selectedKat;
 algorithmSelected = false;
 katSelected = false;
 }
 }


 }
if (kontrolcu == 4) { // PD Kontrol
 int santimkat = katMesafeleri[selectedKat - 1] - distance;
 int Kp=6;
 int Kd=15;
 Serial.print(distance); // Mesafe
 Serial.print("\t"); // Tab karakteri, iki veriyi ayırmak için
 Serial.println(katMesafeleri[selectedKat - 1]);
 turev = (sonMesafe)/fs;
 kontrolcuSinyali = Kp*abs(santimkat)+Kd*(turev);

 if (santimkat > 0) {

 sonMesafe=(santimkat);
 kontrolcuSinyali = Kd*(turev)+Kp*abs(santimkat);
 analogWrite(pwmpos,constrain(kontrolcuSinyali,190,255));
 digitalWrite(pwmneg, LOW);
 if (abs(santimkat) < 2) {

 currentKat = selectedKat;
 algorithmSelected = false;
 katSelected = false;
 }
 } else if (santimkat < 0) {


 sonMesafe=abs(santimkat);
 kontrolcuSinyali = Kd*(turev)+Kp*abs(santimkat);
 digitalWrite(pwmpos, LOW);
 analogWrite(pwmneg,constrain(kontrolcuSinyali,50,255));
 if (abs(santimkat) < 2) {

 currentKat = selectedKat;
 algorithmSelected = false;
 katSelected = false;
 }
 }

 }
if (kontrolcu == 5) { // PID Kontrol
 int santimkat = katMesafeleri[selectedKat - 1] - distance;
 int Kp=6;
 Serial.print(distance); // Mesafe
 Serial.print("\t"); // Tab karakteri, iki veriyi ayırmak için
 Serial.println(katMesafeleri[selectedKat - 1]);
 int Kd=40;
 int Ki = 0.08;
 integral +=abs(santimkat);
 turev =(sonMesafe)/fs;
 kontrolcuSinyali =
Kp*abs(santimkat)+Kd*(turev)+Ki*abs(integral);

 if (santimkat > 0) {

 sonMesafe=(santimkat);

 kontrolcuSinyali =
Kd*(turev)+Kp*abs(santimkat)+Ki*abs(integral);
 analogWrite(pwmpos,constrain(kontrolcuSinyali,190,255));
 digitalWrite(pwmneg, LOW);
 if (abs(santimkat) < 2) {
 integral=0;
 currentKat = selectedKat;
 algorithmSelected = false;
 katSelected = false;
 }
 } else if (santimkat < 0) {

 sonMesafe=(santimkat);

 kontrolcuSinyali =
Ki*abs(integral)+Kp*abs(santimkat)+Kd*(turev);
 digitalWrite(pwmpos, LOW);
 analogWrite(pwmneg,constrain(kontrolcuSinyali,50,255));
 if (abs(santimkat) < 2) {
 integral=0;
 currentKat = selectedKat;
 algorithmSelected = false;
 katSelected = false;
 }
 }

 }
 distance = measureDistance();
 delay(275);
 checkButtons();
 }

 isMoving = false;
}
