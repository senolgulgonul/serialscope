# SerialScope

A lightweight, browser-based Arduino Serial Plotter. No installation, no drivers — open the HTML file in Chrome or Edge and connect your Arduino over USB.

## Features

- Multi-channel plotting with named channels (auto-detected from serial output)
- Auto-scrolling with manual X/Y zoom and pan via scroll wheel and drag
- Click any channel in the sidebar to show/hide it
- Serial Monitor with raw data log
- Statistics panel (min, max, average, sample rate)
- CSV export
- Clean white plot — ready for papers and reports

## Usage

Open `serialscope.html` in Chrome or Edge, select your baud rate, click **Connect**, and pick your port.

### Serial Format

SerialScope is fully compatible with the Arduino IDE Serial Plotter format.

**Named channels (recommended)** — channel names appear in the sidebar:
```cpp
Serial.print("Temperature:"); Serial.print(temp);
Serial.print(",Humidity:");    Serial.print(hum);
Serial.print(",Pressure:");    Serial.println(pres);
```

**Header line + plain values** — send names once in setup, then just values:
```cpp
void setup() {
  Serial.begin(115200);
  Serial.println("Temperature:\tHumidity:\tPressure:");
}
void loop() {
  Serial.print(temp);  Serial.print("\t");
  Serial.print(hum);   Serial.print("\t");
  Serial.println(pres);
}
```

**Plain values** — falls back to CH1, CH2, CH3 … :
```cpp
Serial.print(val1); Serial.print("\t");
Serial.println(val2);
```

## Demo Sketch

```cpp
// SerialScope Demo — 3 named channels at ~50 Hz

float t = 0;

void setup() {
  Serial.begin(115200);
}

void loop() {
  float sine     = 5.0 * sin(2.0 * PI * 0.3 * t);
  float cosine   = 3.0 * cos(2.0 * PI * 0.7 * t) + 1.5 * sin(2.0 * PI * 0.1 * t);
  float tri      = 2.0 * abs(fmod(t * 0.15, 1.0) - 0.5);
  float triangle = (tri * 16.0 - 8.0) + random(-100, 100) / 200.0;

  Serial.print("Sine:");      Serial.print(sine, 3);
  Serial.print(",Cosine:");   Serial.print(cosine, 3);
  Serial.print(",Triangle:"); Serial.println(triangle, 3);

  t += 0.02;
  delay(20);  // ~50 Hz
}
```

## Requirements

> Web Serial API is required — Chrome or Edge only.

## License

MIT
