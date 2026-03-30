// SerialScope Demo — 3 channels
// Upload this to your Arduino, then connect at 115200 baud

float t = 0;

void setup() {
  Serial.begin(115200);
}

void loop() {
  // CH1: sine wave  (amplitude 5, freq ~0.3 Hz)
  float ch1 = 5.0 * sin(2.0 * PI * 0.3 * t);

  // CH2: cosine wave with drift  (amplitude 3, freq ~0.7 Hz)
  float ch2 = 3.0 * cos(2.0 * PI * 0.7 * t) + 1.5 * sin(2.0 * PI * 0.1 * t);

  // CH3: noisy triangle wave  (amplitude 8, freq ~0.15 Hz)
  float tri  = 2.0 * abs(fmod(t * 0.15, 1.0) - 0.5);   // 0..1 triangle
  float ch3  = (tri * 16.0 - 8.0) + random(-100, 100) / 200.0;

  // Send all 3 values on one line, tab-separated
  Serial.print(ch1, 3);
  Serial.print("\t");
  Serial.print(ch2, 3);
  Serial.print("\t");
  Serial.println(ch3, 3);

  t += 0.02;          // time step
  delay(20);          // ~50 Hz sample rate
}