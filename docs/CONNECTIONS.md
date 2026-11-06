# Wiring and test checklist

| Signal | Arduino UNO | Device |
|---|---|---|
| Mode | D2 | Slide switch common/center |
| Manual setpoint | A0 | Potentiometer wiper (SIG) |
| PWM output | D9 | Green LED + series resistor |
| Auto indicator | D13 | Red LED + series resistor |
| Power | 5V, GND | Potentiometer outer terminals; switch outer terminals |

- Potentiometer: one outer terminal to 5V, the other to GND.
- Slide switch: one outer terminal to 5V, other to GND; center to D2.
- Each LED: output pin -> 220-ohm resistor -> anode; cathode -> GND.
- Manual: switch to 5V, rotate pot, check green LED brightness and serial PWM.
- Auto: switch to GND, green LED at about 50% duty and red LED blinks.
- This is a logic simulation. Do not connect a real motor to D9 directly.
