// Reads TMP36 temperature sensors on all 6 analog inputs
const int NUM = 6;    // number of sensors
const float V = 5.0;  // voltage

int ain[NUM];
float vin[NUM];
float tempC[NUM];
float tempF[NUM];

/*
 * setup() - this function runs once when you turn your Arduino on
 * We initialize the serial connection with the computer
 */
void setup() {
  Serial.begin(9600);  //Start the serial connection with the computer
                       //to view the result open the serial monitor
}

void loop()  // run over and over again
{
  //getting the voltage reading from the temperature sensor
  //int reading = analogRead(sensorPin);
  int i;

  for (i = 0; i < NUM; i++) {  // READ SENSORS
    ain[i] = analogRead(i);
    vin[i] = (ain[i] * V / 1024.0);
    tempC[i] = (vin[i] - 0.5) * 100;  //converting from 10 mv per degree wit 500 mV offset
    tempF[i] = (tempC[i] * 9.0 / 5.0) + 32.0;
  }

  for (i = 0; i < NUM; i++) {  // PRINT TO SERIAL MONITOR
    Serial.print(tempF[i]);
    Serial.print(", ");
  }
  Serial.println();

  


  delay(1000);  //waiting a second
}