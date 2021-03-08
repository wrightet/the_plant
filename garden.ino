int soilPin = A0;
int soilVal;
int waterLevelPin = A1;
int waterVal;
int dt = 10000;
void setup()
{
    Serial.begin(9600);
    pinMode(soilPin, INPUT);
    pinMode(waterLevelPin, INPUT);
}

void loop()
{
    waterVal = analogRead(waterLevelPin);
    soilVal = analogRead(soilPin);
    Serial.print("Water Level: ");
    Serial.print(waterVal);
    Serial.print(" Soil Value: ");
    Serial.println(soilVal);
    delay(dt);
}