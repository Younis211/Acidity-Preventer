  int WATERPUMP =13 ; //motor pump connected to pin 13
  int mois_sens= 8; //sensor digital pin vonnected to pin 8
  const int pin_red = 2;
  const int pin_green = 3;
  const int buzzer = 10; //buzzer to arduino pin 9
  int val; //This variable stores the value received from Soil moisture sensor.

void setup() {
  pinMode(pin_red,OUTPUT);
  pinMode(pin_green,OUTPUT);  
  pinMode(WATERPUMP,OUTPUT);
  pinMode(mois_sens,INPUT);
  pinMode(buzzer, OUTPUT); // Set buzzer - pin 9 as an output
  Serial.begin(9600);
  while (! Serial);
  Serial.println("Speed 0 to 255");
}

void loop()
  { 
  if (Serial.available()) 
  {
    int speed = Serial.parseInt();  
    if (speed >= 0 && speed <= 255)
    {
      analogWrite(WATERPUMP, speed);// tuns on the motor at specified speed 
    }
  }
  val = digitalRead(mois_sens);  //Read data from soil moisture sensor  
  if(val == HIGH) 
  {
  digitalWrite(WATERPUMP,LOW); //if soil moisture sensor provides LOW value send LOW value to motor pump and motor pump goes off
  digitalWrite(3, HIGH); //Output red color if pump is not working
  digitalWrite(2, LOW); //Output green color if pump is working
  digitalWrite(buzzer, 110);
  }
  else
  {
  digitalWrite(WATERPUMP,HIGH); //if soil moisture sensor provides HIGH value send HIGH value to motor pump and motor pump get on
  digitalWrite(3, LOW); //Close the red color if pump is working
  digitalWrite(2, HIGH); //Output green color if pump is working
  digitalWrite(buzzer, LOW);
  }
}





/*  int WATERPUMP = 13;  
  int sensor = 8;
  const int pin_red = 2;
  const int pin_green = 3;
  int val; //This variable stores the value received from Soil moisture sensor.
    void setup() 
    {
      pinMode(pin_red,OUTPUT);
      pinMode(pin_green,OUTPUT);
      pinMode(13,OUTPUT); //Set pin 13 as OUTPUT pin, to send signal to relay
      pinMode(8,INPUT); //Set pin 8 as input pin, to receive data from Soil moisture sensor.
    }
    void loop() { 
     int val = 8; //Read data from soil moisture sensor  
      if(val == LOW) 
    {
    digitalWrite(13,LOW); //if soil moisture sensor provides LOW value send LOW value to relay
    digitalWrite(2, HIGH); //Output red color if it is not working
    delay(1500);//Wait for a 1.5 second then repeat the glowing again. 
    }
    else
    {
    digitalWrite(13,HIGH); //if soil moisture sensor provides HIGH value send HIGH value to relay
    digitalWrite(2, LOW); // if the soil moisure is reading a high value, then turn off the red led
    digitalWrite(3, HIGH); //When the soil moisture orders water, and the system is working, green led will glow on. 
    delay(10000);
    digitalWrite(3, LOW);
    }
    
    }
       void set_outputs_plus_ground(int pin_plus, int pin_ground) 
    {
        //set both pins low first so you don't have them pushing 5 volts into eachother
    digitalWrite(pin_plus,LOW);  
    digitalWrite(pin_ground,LOW);
    //set output pin as high
    digitalWrite(pin_plus,HIGH);  
    }           */
