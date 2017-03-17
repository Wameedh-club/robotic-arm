
// Coded by T.Ayoub H.Abdelkhalek B.Yacine B.Mehieddine
// Code of Robotic arm using POTs



#include <Servo.h>

Servo my1;
Servo my2;
Servo my3;
Servo my4;

int val1,val2,val3,val4,v1,v2,v3,v4;
int i=0;

byte a[1500];
void setup()
{
  
  Serial.begin(9600);

  my1.attach(3);
  my2.attach(5);
  my3.attach(6);
  my4.attach(9);
  
  v1=analogRead(A0);
  v2=analogRead(A1);
  v3=analogRead(A2);
  v4=analogRead(A3);  

  
  val1 = map(val1, 0, 700, 0, 179);
  val2 = map(val2, 0, 700, 0, 179);
  val3 = map(val3, 0, 700, 0, 179);
  val4 = map(val4, 0, 700, 0, 179);
  
}

void loop()
{
 f:
  i=0;
  v1=(int)map(analogRead(A0), 0, 1023, 0, 179);
  v2=(int)map(analogRead(A1), 0, 1023, 0, 179);
  v3=(int)map(analogRead(A2), 0, 1023, 0, 179);
  v4=(int)map(analogRead(A3), 0, 1023, 0, 179);

  val1=(abs(v1-val1)> 5)?v1:val1;
  val2=(abs(v2-val2)> 5)?v2:val2;
  val3=(abs(v3-val3)> 5)?v3:val3;
  val4=(abs(v4-val4)> 5)?v4:val4;
  
  my1.write(val1);
  my2.write(val2);
  my3.write(val3);
  my4.write(val4);
  Serial.println(String(v1)+":"+String(v2)+":"+String(v3));
    delay(15);
    
  
  Serial.println(String(val1)+":"+String(val2)+":"+String(val3)+":"+String(val4));

  //***************************************************recording **************************************************************///
  
  if(digitalRead(11)==HIGH){
    delay(20);
    n:digitalWrite(8,HIGH);
    
    Serial.println("rec");
  v1=(int)map(analogRead(A0), 0, 1023, 0, 179);
  v2=(int)map(analogRead(A1), 0, 1023, 0, 179);
  v3=(int)map(analogRead(A2), 0, 1023, 0, 179);
  v4=(int)map(analogRead(A3), 0, 1023, 0, 179);

  val1=(abs(v1-val1)> 5)?v1:val1;
  a[i]=val1;
  i=i+1;
  val2=(abs(v2-val2)> 3)?v2:val2;
  a[i]=val2;
  i=i+1;
  val3=(abs(v3-val3)> 3)?v3:val3;
  a[i]=val3;
  i=i+1;
  val4=(abs(v4-val4)> 3)?v4:val4;
  a[i]=val4;
  i=i+1;
  
  my1.write(val1);
  my2.write(val2);
  my3.write(val3);
  my4.write(val4);
  delay(25);
  if(i<1499){
    goto n;
  }
  else if(i==1499){
    digitalWrite(8,LOW);
    i=0;
    goto f ;
  }
  }
  //*********************************************replaying*******************************************//
  
  if(digitalRead(12)==HIGH){
    delay(20);
   i=0;
  o: 
   digitalWrite(7,HIGH);
    
   
   Serial.println("rep");
    my1.write(a[i]);
    i=i+1;
  my2.write(a[i]);
  i=i+1;
  my3.write(a[i]);
  i=i+1;
  my4.write(a[i]);
  i=i+1;
  delay(25);
  if(i<1499){
    goto o;
  }
  else if (i==1499){
    goto f;
  }
  }
}
