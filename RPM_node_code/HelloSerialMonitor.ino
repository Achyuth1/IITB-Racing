
/*
 CAN part needs to be attached
 */

#define RPM1 6
#define RPM2 7
#define LED 13

int prev_pos_1=0,prev_pos_2= 0;
int pos_1 = 0, pos_2 = 0;
int TIME1,TIME2;

void ISR_RPM_1(void)
{
 cli();
 pos_1 = micros();
 TIME1 = pos_1-prev_pos_1-11;
 Serial.print("TIME1 = ");
 Serial.println(TIME1);
 prev_pos_1 = pos_1;
 sei();
}

void ISR_RPM_2(void)
{
 cli();
 pos_2 = micros();
 TIME2 = pos_2-prev_pos_2-11;
 Serial.print("TIME2 = ");
 Serial.println(TIME2);
 prev_pos_2 = pos_2;
 sei();
}

void setup()   
{                
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  
  pinMode(RPM1, INPUT);
  pinMode(RPM2, INPUT);
  
  attachInterrupt(RPM1, ISR_RPM_1, RISING);
  attachInterrupt(RPM2, ISR_RPM_2, RISING);  
}

void loop()                     
{
  digitalWrite(LED, HIGH);
  delay(100);
}

