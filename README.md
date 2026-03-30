# SerialScope

A lightweight, browser-based Arduino Serial Plotter. No installation, no drivers — open the HTML file in Chrome or Edge and connect your Arduino over USB.

## Features

- Multi-channel plotting (CH1, CH2, CH3 … auto-detected from serial output)
- Auto-scrolling with manual X/Y zoom and pan via scroll wheel and drag
- Click any channel in the sidebar to show/hide it
- Serial Monitor with raw data log
- CSV export
- Clean white plot — ready for papers and reports

## Usage

In your Arduino sketch, print tab-separated values on one line:

```cpp
Serial.print(value1); Serial.print("\t");
Serial.print(value2); Serial.print("\t");
Serial.println(value3);
```

Open `serialscope.html` in Chrome or Edge, select your baud rate, click **Connect**, and pick your port.

## Demo Sketch

```cpp
// SerialScope Demo — 3 channels
float t = 0;

void setup() {
  Serial.begin(115200);
}

void loop() {
  float ch1 = 5.0 * sin(2.0 * PI * 0.3 * t);
  float ch2 = 3.0 * cos(2.0 * PI * 0.7 * t) + 1.5 * sin(2.0 * PI * 0.1 * t);
  float tri  = 2.0 * abs(fmod(t * 0.15, 1.0) - 0.5);
  float ch3  = (tri * 16.0 - 8.0) + random(-100, 100) / 200.0;

  Serial.print(ch1, 3); Serial.print("\t");
  Serial.print(ch2, 3); Serial.print("\t");
  Serial.println(ch3, 3);

  t += 0.02;
  delay(20); // ~50 Hz
}
```

## Requirements

> Web Serial API is required — Chrome or Edge only.

## License

MIT
