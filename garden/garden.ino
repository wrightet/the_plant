int soilPin = A0;
int soilVal;
int waterLevelPin = A1;
int waterVal;
int pump = 8;
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
}

void loop()
{
    if (soilVal > 550)
    {
        digitalWrite(pump, LOW);
        delay(timeon);
        digitalWrite(pump, HIGH);
    }
    //    waterVal = analogRead(waterLevelPin);
    soilVal = analogRead(soilPin);
    //    Serial.print("Water Level: ");
    //    Serial.print(waterVal);
    Serial.print(" Soil Value: ");
    Serial.println(soilVal);
    delay(timeoff);
}
