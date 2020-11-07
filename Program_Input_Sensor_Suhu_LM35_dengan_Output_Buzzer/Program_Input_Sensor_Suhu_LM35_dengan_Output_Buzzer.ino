int R_LED = 8; //menetapkan R_LED pada tipe data integer & pada pin 8 di Arduino
int B_LED = 7; //menetapkan B_LED pada tipe data integer & pin 7 di Arduino
int Buzz  = 5; //menetapkan buzzer pada tipe data integer & pin 5 di Arduino
const int temp = 0; //menentukan pin pada 0

void setup() {
  Serial.begin(9600); //menetapkan boudred seral pada 9600
  pinMode(R_LED,OUTPUT); //menetapkan R_LED sebagai output
  pinMode(B_LED,OUTPUT); //menetapkan B_LED sebagai output
  pinMode(Buzz,OUTPUT);  //menetapkan buzzer sebagai output
}
void loop() {
  float Real_Voltage=analogRead(temp)*0.004882814; //membaca temp sebagai nilai Real_Voltage
  float temp_C = Real_Voltage*100.0; //nilai pada tipe data float
  float temp_F = temp_C*(9.0/5.0)+32.0; //nilai pada tipe data float
  Serial.print("Tegangan: "); //menampilkan kata Tegangan
  Serial.println(Real_Voltage); //menampilkan nilai Real_Voltage
  Serial.print("Suhu(C): "); //menampilkan kata Suhu(C)
  Serial.println(temp_C); //menampilkan nilai temp_C
  Serial.print("Suhu(F): "); //menampilkan kata Suhu(F)
  Serial.println(temp_F); //menampilkan nilai temp_F
  
if(temp_C >= 26.0)
{
  Serial.println("Warning, Sistem PANAS"); //menampilkan kata Warning, Sistem PANAS
  digitalWrite(R_LED,HIGH); //memberi tegangan positif sehingga R_LED akan menyala pada saat bernilai 1
  analogWrite(Buzz,20);       
  delay(2000); //memberi nilai jeda selama 2.0 detik
  digitalWrite(R_LED,LOW); //memberi tegangan negatif sehingga R_LED akan mati pada saat bernilai 0     
  analogWrite(Buzz,0);
  delay(2000); //memberi nilai jeda selama 2.0 detik
}
else if (temp_C <=25.0)
{
  Serial.println("Warning, Sistem DINGIN"); //menampilkan kata Warning, Sistem DINGIN
  digitalWrite(B_LED,HIGH); //memberi tegangan positif sehingga B_LED akan menyala pada saat bernilai 1
  analogWrite(Buzz,80);   
  delay(2000); //memberi nilai jeda selama 2.0 detik
  digitalWrite(B_LED,LOW); //memberi tegangan negatif sehingga B_LED akan mati pada saat bernilai 0
  analogWrite(Buzz,0);
  delay(2000); //memberi nilai jeda selama 2.0 detik
}
else
{
  Serial.println("Sistem Berfungsi BAIK"); //menampilkan kata Sistem Berfungsi BAIK
  digitalWrite(R_LED,LOW); //memberi tegangan negatif sehingga R_LED akan mati pada saat bernilai 0
  digitalWrite(B_LED,LOW); //memberi tegangan negatif sehingga B_LED akan mati pada saat bernilai 0
  delay(2000); //memberi nilai jeda selama 2.0 detik
}
}
