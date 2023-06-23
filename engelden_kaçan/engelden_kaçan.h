//Kütüphane Tanımlamaları
#include <NewPing.h>
#include <PID_v1.h>
//Pin Tanımlamaları
#define MotorRE 3
#define MotorR1 2
#define MotorR2 4
#define MotorLE 5
#define MotorL1 6
#define MotorL2 9

const int trigger_pin1 = 7;
const int echo_pin1 = 8;

const int trigger_pin2 = A0;
const int echo_pin2 = A1;
// Motorun hızını tutan değişken. 0 ile 255 arasında değer alabilir.
int hiz = 0; 
double setpoint = 0;      // Hedef değer
double input = 0;         // Giriş değeri (örneğin sensörden okunan değer)
double output = 0;        // Çıkış değeri (örneğin motor sinyali)
double Kp = 1;            // Orantısal katsayı
double Ki = 0;            // Integral katsayı
double Kd = 0;

PID myPID(&input, &output, &setpoint, Kp, Ki, Kd, DIRECT); //PID kontrol için gerekli ayarlamalar


NewPing sonar1(trigger_pin1,echo_pin1 ); //Mesafe sensörü için pin tanımlamaları
NewPing sonar2(trigger_pin2,echo_pin2 );

int sure;
int mesafe1;
int mesafe2;
void pin_mode(void)
{
  pinMode(MotorR1, OUTPUT);
  pinMode(MotorR2, OUTPUT);
  pinMode(MotorRE, OUTPUT);
  pinMode(MotorL1, OUTPUT);
  pinMode(MotorL2, OUTPUT);
  pinMode(MotorLE, OUTPUT);
  pinMode(trigger_pin1, OUTPUT);
  pinMode(echo_pin1, INPUT);
}



void ileri(void){  

  digitalWrite(MotorR1, HIGH); 
  digitalWrite(MotorR2, LOW); 
  analogWrite(MotorRE, 50); 


  digitalWrite(MotorL1, HIGH); 
  digitalWrite(MotorL2, LOW);
  analogWrite(MotorLE, 57); 
}
void geri(void)
{ 
  digitalWrite(MotorR1, LOW); 
  digitalWrite(MotorR2, HIGH); 
  analogWrite(MotorRE, 50); 

  digitalWrite(MotorL1, LOW); 
  digitalWrite(MotorL2, HIGH); 
  analogWrite(MotorLE, 50); 
  
}


void sag(void){ 

  digitalWrite(MotorR1, HIGH); 
  digitalWrite(MotorR2, LOW); 
  analogWrite(MotorRE, 0);

  digitalWrite(MotorL1, HIGH); 
  digitalWrite(MotorL2, LOW); 
  analogWrite(MotorLE, 50); 
  
  
}

void sol(void){ 

  digitalWrite(MotorL1, HIGH); 
  digitalWrite(MotorL2, LOW); 
  analogWrite(MotorLE, 0); 

  digitalWrite(MotorR1, HIGH); 
  digitalWrite(MotorR2, LOW); 
  analogWrite(MotorRE, 50); 
  
  
}

void mesafe(void)
{
    mesafe1 = sonar1.ping_cm();
    mesafe2 = sonar2.ping_cm();
    Serial.print("mesafe1= "); 
    Serial.println(mesafe1);

    Serial.print("mesafe2= "); 
    Serial.println(mesafe2);
}

void mesafe_sartlari_1(void)
{


     if(mesafe1!=0)
 {
 
    
     if(mesafe1<15)
     {
    geri();  
    delay(1000);
    sol();  
    delay(1000);
      
    
      Serial.println("geri ve sol ");
    
  
     }
     else 
     {  // değil ise,
   ileri(); // ileri git
   Serial.println("ileri");
    
   }
  }
}

void mesafe_sartlari_2(void)
{
    
  if(mesafe2!=0)
 {
 
    
     if(mesafe2<15)
     {
    geri();  
    delay(1000);
    sag();  
    delay(1000);
      
    
      Serial.println("geri ve sag ");
    
  
     }
     else 
     {  // değil ise,
   ileri(); // ileri git
   Serial.println("ileri");
    
   }
  }



}