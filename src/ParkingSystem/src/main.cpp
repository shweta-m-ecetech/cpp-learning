#include <Arduino.h>
#include <Servo.h>

Servo gate;

const int trigPin = 7;
const int echoPin = 6;
const int servoPin = 9;

const int CLOSED = 0;
const int OPEN = 90;

const int DETECT_DISTANCE = 25;  // vehicle detected within 25 cm
const int CLEAR_DISTANCE = 35;   // vehicle considered gone above 35 cm

const unsigned long MIN_OPEN_TIME = 5000; // keep gate open at least 5 seconds

bool gateIsOpen = false;
unsigned long gateOpenedTime = 0;

long getDistance()
{
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);

    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);

    digitalWrite(trigPin, LOW);

    long duration = pulseIn(echoPin, HIGH, 30000);

    if (duration == 0)
        return 999;

    return duration * 0.0343 / 2;
}

void setup()
{
    Serial.begin(9600);

    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);

    gate.attach(servoPin);
    gate.write(CLOSED);

    Serial.println("SMART PARKING BARRIER READY");
}

void loop()
{
    long distance = getDistance();

    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    // -------------------------
    // VEHICLE APPROACHING
    // -------------------------
    if (!gateIsOpen && distance <= DETECT_DISTANCE)
    {
        Serial.println("Vehicle detected!");
        Serial.println("Opening barrier...");

        gate.write(OPEN);

        gateIsOpen = true;
        gateOpenedTime = millis();
    }

    // -------------------------
    // CHECK WHETHER VEHICLE PASSED
    // -------------------------
    if (gateIsOpen)
    {
        unsigned long openTime = millis() - gateOpenedTime;

        // Keep gate open for minimum 5 seconds
        if (openTime >= MIN_OPEN_TIME && distance >= CLEAR_DISTANCE)
        {
            Serial.println("Vehicle passed.");
            Serial.println("Closing barrier...");

            gate.write(CLOSED);

            gateIsOpen = false;

            Serial.println("Barrier closed.");
        }
    }

    delay(50);
}