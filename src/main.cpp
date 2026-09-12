#include <Arduino.h>

// RGB LED patterns for Arduino Uno (common-cathode)
const int PIN_R = 9;   // PWM pin for Red
const int PIN_G = 10;  // PWM pin for Green
const int PIN_B = 11;  // PWM pin for Blue

struct Color { uint8_t r, g, b; };

// Preset colors (you can add more)
Color presets[] = {
  {20, 0, 0},    // Red (reduced)
  {255, 165, 0},  // Orange
  {255, 255, 0},  // Yellow
  {0, 255, 0},    // Green
  {0, 255, 255},  // Cyan
  {0, 0, 255},    // Blue
  {128, 0, 128},  // Purple
  {255, 192, 203} // Pink
};
const int PRESET_COUNT = sizeof(presets) / sizeof(presets[0]);

void setup() {
  pinMode(PIN_R, OUTPUT);
  pinMode(PIN_G, OUTPUT);
  pinMode(PIN_B, OUTPUT);
  Serial.begin(9600);
  Serial.println("RGB patterns ready");
}

void setColor(uint8_t r, uint8_t g, uint8_t b) {
  analogWrite(PIN_R, r);
  analogWrite(PIN_G, g);
  analogWrite(PIN_B, b);
}

// Smoothly fade from current color to target color over steps
void fadeTo(Color from, Color to, int steps = 50, int stepDelay = 12) {
  for (int i = 1; i <= steps; ++i) {
    uint8_t r = from.r + (int)((to.r - from.r) * i / (float)steps + 0.5);
    uint8_t g = from.g + (int)((to.g - from.g) * i / (float)steps + 0.5);
    uint8_t b = from.b + (int)((to.b - from.b) * i / (float)steps + 0.5);
    setColor(r, g, b);
    delay(stepDelay);
  }
}

// Parse simple serial commands: "preset N" or "r,g,b"
void handleSerial() {
  if (!Serial.available()) return;
  String s = Serial.readStringUntil('\n');
  s.trim();
  if (s.length() == 0) return;
  if (s.startsWith("preset")) {
    int n = s.substring(6).toInt();
    if (n >= 0 && n < PRESET_COUNT) {
      Color c = presets[n];
      setColor(c.r, c.g, c.b);
      Serial.print("Set preset "); Serial.println(n);
    }
  } else {
    // expected format: R,G,B
    int idx1 = s.indexOf(',');
    int idx2 = s.indexOf(',', idx1 + 1);
    if (idx1 > 0 && idx2 > idx1) {
      int r = s.substring(0, idx1).toInt();
      int g = s.substring(idx1 + 1, idx2).toInt();
      int b = s.sub      cd /Users/shwetam/projects/cpp-learning && ~/.platformio/penv/bin/platformio run --target uploadstring(idx2 + 1).toInt();
      r = constrain(r, 0, 255);
      g = constrain(g, 0, 255);
      b = constrain(b, 0, 255);
      setColor(r, g, b);
      Serial.print("Set RGB "); Serial.print(r); Serial.print(","); Serial.print(g); Serial.print(","); Serial.println(b);
    }
  }
}

void loop() {
  // Cycle through presets with fades
  for (int i = 0; i < PRESET_COUNT; ++i) {
    Color from = presets[i];
    Color to = presets[(i + 1) % PRESET_COUNT];
    Serial.print("Transition "); Serial.print(i); Serial.print(" -> "); Serial.println((i + 1) % PRESET_COUNT);
    fadeTo(from, to, 80, 8);
    delay(400);
    handleSerial();
  }
}
