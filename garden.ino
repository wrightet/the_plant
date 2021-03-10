int soilPin = A0;
int soilVal;
int waterLevelPin = A1;
int waterVal;
int dt = 10000;
int pump = 8;
// the pump should be off for at least 3 days to let soil dry;
int timeoff = 259200000; 
// the hose and the pump put out about 2 tsps in 1 sec which is enough for the cactus
int timeon = 1000; 
void setup()
{
    Serial.begin(9600);
    pinMode(soilPin, INPUT);
    pinMode(waterLevelPin, INPUT);
    // pinMode(pump, OUTPUT);
    // digitalWrite(pump, HIGH);
}

void loop()
{
    // digitalWrite(pump, LOW);
    // dt(timeon);
    // digitalwrite(pump, HIGH);
    // dt(timeoff);
    waterVal = analogRead(waterLevelPin);
    soilVal = analogRead(soilPin);
    Serial.print("Water Level: ");
    Serial.print(waterVal);
    Serial.print(" Soil Value: ");
    Serial.println(soilVal);
    delay(dt);
}