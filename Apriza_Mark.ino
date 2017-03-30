#include <Brain.h>
#include <Servo.h> 
 

Brain brain(Serial);
Servo myservo;  
//char a[400];
String a,a1;
int v = 0;
int z=0,output;
uint32_t num=0;
uint32_t num1=0;
void setup() {
    // Start the hardware serial.
    Serial.begin(9600);
    myservo.attach(9);  
     pinMode(12, OUTPUT);
     pinMode(11, OUTPUT);
}
 
void loop() {
 
    // "signal strength, attention, meditation, delta, theta, low alpha, high alpha, low beta, high beta, low gamma, high gamma"    
    if (brain.update()) {
     
        a = brain.readCSV();
        v = a.indexOf(',');
        v = a.indexOf(',',v+1);
        v = a.indexOf(',',v+1);
        v = a.indexOf(',',v+1);
        z = a.indexOf(',',v+1);
        
        a1 = a.substring(v+1,z);
        num = a1.toInt();
         
        v = a.indexOf(',',z+1);
       
         
        a = a.substring(z+1,v);
         
        num1 = a.toInt();
        Serial.print("alpha = ");
        Serial.println(num1);
         
        output = map(num,0,999999,0,180);
         
       
       myservo.write(output);             
       delay(15); 
       
      
    }
}
