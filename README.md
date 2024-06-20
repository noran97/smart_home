# smart_home

the key components and features:

The system uses two Atmega32 microcontrollers connected via SPI protocol.
Other components include a 4x3 keypad, 16x2 LCD display, ADC, LM35 temperature sensor, and DC motors.

The main features include:

1-Login system with password protection. After 3 failed attempts, the system locks out the user.
2-Automated door control - the door opens when the correct password is entered, stays open for 2 seconds, then closes.
3-Room-level control of lighting, air conditioning, and TV.
4-Temperature monitoring and alarm if it exceeds a certain threshold.

