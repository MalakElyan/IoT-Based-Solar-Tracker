#define BLYNK_TEMPLATE_ID "TMPLyY5b6AS_"
#define BLYNK_DEVICE_NAME "solar "
#define BLYNK_AUTH_TOKEN "aKvme0I1wGfLD59uZgOq0xkTNZ9oCa6j"
#define BLYNK_PRINT Serial
#define W5100_CS  10
#define SDCARD_CS 4
#define dutyCycle 200

#include <SPI.h>
#include <Ethernet.h>
#include <BlynkSimpleEthernet.h>
#include <DHT.h>

char auth[] = BLYNK_AUTH_TOKEN;

#define DHTPIN 2         
#define DHTTYPE DHT11   
DHT dht(DHTPIN, DHTTYPE);
BlynkTimer timer;


//Motor PINs
int IN1 = 8;
int IN2 = 9;
int IN3 = 12;
int IN4 = 11;


bool top = 0;
bool bottom = 0;
bool left = 0;
bool right = 0;
bool led = 0;

float ewldr, nsldr;


int analogInput = A3;
float vout = 0.0;
float vin = 0.0;
float current = 0.0;
float power = 0.0;
float R1 = 68000 ;  
float R2 = 10000.0;  
int analogvalue = 0;

void setup() {
  Serial.begin(9600);
  Blynk.begin(auth);
  dht.begin();
  Serial.println("start program");
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  delay(1000);


}


BLYNK_WRITE(V11) {
  top = param.asInt();
  Serial.println("V11  ");
  Serial.println(top);
  
  }

BLYNK_WRITE(V10) {
  bottom = param.asInt();
  Serial.println("V10  ");
  Serial.println(bottom);
  }

BLYNK_WRITE(V9) {
  left = param.asInt();
  Serial.println("V9  ");
  Serial.println(left);
  }

BLYNK_WRITE(V8) {
  right = param.asInt();
  Serial.println("V8  ");
  Serial.println(right);
  }
BLYNK_WRITE(V13) {
  led = param.asInt();
  Serial.println("V13  ");
  Serial.println(led);
  
}

void automaticmode(){
  
  if (ewldr >600)
 {   
  moveM1Left();
  Serial.println("m1 left");
  }
  else if (ewldr  <400)
  { 
    moveM1Right();
      Serial.println("m1 Right");
    }
  else
   { 
    stopM1();
    Serial.println("m1 stop");
    }

if (nsldr >600)
   { 
    moveM2Left();
    Serial.println("m2 left");
    }
  else if (nsldr <400)
  {  
    moveM2Right();
    Serial.println("m2 Right");
    }
  else
   { 
    stopM2();
    Serial.println("m2 stop");
    }
  
  }




void smartsolar() {

 if (left == 1)
   { 
    moveM2Left();
   Serial.println("m2 left");
    }
  else if (right == 1)
  {    
    moveM2Right();
   Serial.println("m2 Right");
  }
  
  else if (  top == 1)
 { 
  moveM1Right();
  Serial.println("m1 Right");
  }
  else if ( bottom == 1)
  { 
    moveM1Left();
    Serial.println("m1 Left");
  }
  
   else 
    {
    stopM2();
    stopM1();
    
 Serial.println("solar stop");
    }
} 

void sendSensor()
{
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  ewldr = analogRead(A0);
  nsldr = analogRead(A1);  
  Blynk.virtualWrite(V0, h);
  Blynk.virtualWrite(V1, t);
  Blynk.virtualWrite(V5, ewldr);
  Blynk.virtualWrite(V6, nsldr);


int analogvalue = analogRead(analogInput);
   vout = (analogvalue * 5 ) / 1024.0; 
   vin = vout * 7.4 ;
   
   Serial.print("Vin: ");
   Serial.println(vout);
   Blynk.virtualWrite(V3,vin);
  
  

  int adc = analogRead(A2);
  float voltage = adc*5/1024.0;
  float current = (voltage-2.5)/0.066;
  
  Serial.print("Current : ");
  Serial.println(current);
  Blynk.virtualWrite(V2,current);
  

  float powerout = (vin* current );
  Serial.print("Power: ");
  Serial.println(powerout);
  Blynk.virtualWrite(V4,powerout);


  if(t>30)
  { 
    Blynk.logEvent("2205230225std@gtc.edu.ps","test_Temperature");
  }
}


void loop() {
     Blynk.run();
sendSensor();
  if (led == 1)
   {
    automaticmode();
    }
  else if (led == 0)
  {    
     smartsolar();
  }

}

void moveM1Left()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
 // analogWrite(IN2,dutyCycle);
}
void moveM1Right()
{
  digitalWrite(IN1, HIGH);
 // analogWrite(IN1, dutyCycle);
  digitalWrite(IN2, LOW);
}
void stopM1()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
}
void moveM2Left()
{
  digitalWrite(IN3, LOW);
  analogWrite(IN4, dutyCycle);
}
void moveM2Right()
{
  analogWrite(IN3, dutyCycle);
  digitalWrite(IN4, LOW);
}
void stopM2()
{
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}


