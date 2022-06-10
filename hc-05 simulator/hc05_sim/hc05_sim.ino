void setup()
{
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  
}

void loop() 
{

delay(18000);
   Serial.write('1');
   digitalWrite(13,HIGH);
   delay(2000);
   digitalWrite(13,LOW);
   delay(2000);
   
  Serial.write('2');
    digitalWrite(13,HIGH);
   delay(2000);
   digitalWrite(13,LOW);
   delay(2000);
   
  Serial.write('3');
   digitalWrite(13,HIGH);
   delay(2000);
   digitalWrite(13,LOW);
   delay(2000);
   
  Serial.write('4');
    digitalWrite(13,HIGH);
   delay(800);
   digitalWrite(13,LOW);
   delay(2000);

  Serial.write('5');
    digitalWrite(13,HIGH);
   delay(2000);
   digitalWrite(13,LOW);
   delay(2000);


 Serial.write('6');
    digitalWrite(13,HIGH);
   delay(2000);
   digitalWrite(13,LOW);
   delay(2000);
   
  Serial.write('7');
    digitalWrite(13,HIGH);
   delay(2000);
   digitalWrite(13,LOW);
   delay(2000);
   
  Serial.write('8');
    digitalWrite(13,HIGH);
   delay(2000);
   digitalWrite(13,LOW);
   delay(2000);

  Serial.write('9');
    digitalWrite(13,HIGH);
   delay(2000);
   digitalWrite(13,LOW);
   delay(2000);

    Serial.write(':');
    digitalWrite(13,HIGH);
   delay(2000);
   digitalWrite(13,LOW);
   delay(2000);



}
