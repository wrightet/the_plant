int soilPin = A0;
int soilVal;
int waterLevelPin = A1;
int waterVal;
int pump = 8;
int blue = 3;
int green = 4;
int white = 5;
int yellow = 6;
int buttonup = 10;
int buttondown = 11;
int buttonupval;
int buttondownval;
int water_freq = 0;
int red = 7;
int timeoff = 1000;
// the hose and the pump put out about 2 tsps in 1 sec which is enough for the cactus
int timeon = 1000;
void setup()
{
    Serial.begin(9600);
    pinMode(soilPin, INPUT);
    pinMode(waterLevelPin, INPUT);
    pinMode(pump, OUTPUT);
    digitalWrite(pump, HIGH);
    digitalWrite(buttonup, HIGH);
    digitalWrite(buttondown, HIGH);
}

void loop()
{
    if (soilVal >= water_freq)
    {
        digitalWrite(pump, LOW);
        delay(timeon);
        digitalWrite(pump, HIGH);
    }
    //    waterVal = analogRead(waterLevelPin);
    soilVal = analogRead(soilPin);
    //    Serial.print("Water Level: ");
    //    Serial.print(waterVal);
    buttonupval= digitalRead(buttonup);
    buttondownval= digitalRead(buttondown);
    if(water_freq >= 820){
      digitalWrite(red, HIGH);
      digitalWrite(yellow, LOW);
      digitalWrite(white, LOW);
      digitalWrite(green, LOW);
      digitalWrite(blue, LOW);
    }

      if(water_freq >= 615 && water_freq < 820){
      digitalWrite(red, LOW);
      digitalWrite(yellow, HIGH);
      digitalWrite(white, LOW);
      digitalWrite(green, LOW);
      digitalWrite(blue, LOW);
    }

      if(water_freq >= 410 && water_freq < 615){
      digitalWrite(red, LOW);
      digitalWrite(yellow, LOW);
      digitalWrite(white, HIGH);
      digitalWrite(green, LOW);
      digitalWrite(blue, LOW);
    }

      if(water_freq >= 205 && water_freq < 410){
      digitalWrite(red, LOW);
      digitalWrite(yellow, LOW);
      digitalWrite(white, LOW);
      digitalWrite(green, HIGH);
      digitalWrite(blue, LOW);
    }

     if(water_freq >= 0 && water_freq < 205){
      digitalWrite(red, LOW);
      digitalWrite(yellow, LOW);
      digitalWrite(white, LOW);
      digitalWrite(green, LOW);
      digitalWrite(blue, HIGH);
    }

    if (buttonupval == 1){
      water_freq += 50;
      }
    if (buttondownval == 1){
      water_freq -= 50;
      }
      if(water_freq <0){
        water_freq = 0;
      }
        if(water_freq >1023){
        water_freq = 1023;
      }
    Serial.print("water_freq: ");
    Serial.print(water_freq);
    Serial.print(" up: ");
    Serial.print(buttonupval);
    Serial.print(" Down: ");
    Serial.print(buttondownval);
    Serial.print(" Soil Value: ");
    Serial.println(soilVal);
    delay(timeoff);
}
