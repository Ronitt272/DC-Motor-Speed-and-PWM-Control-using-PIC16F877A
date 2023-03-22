# DC-Motor-Speed-and-PWM-Control-using-PIC16F877A

- This project involves the design and implementation of a DC Motor Speed and PWM control. PIC16F877A has been used for this purpose. The programming for the PIC has been performed on Embedded C (implemented on MPLAB X).
- Separate functions on Embedded C have been designed to perform Pulse Width Modulation, Analog to Digital Conversion (ADC), generate delays etc, and the code designed works in harmony with the Proteus Simulations to give rise to the DC Motor. 
- The speed control works in a way that when the speed of the motor exceeds the maximum speed, the LED glows, thus indicating overflow. 
- The PWM can be visualized using the Digital Oscilloscope. As the speed of the DC Motor is increased, the duty cycle of the PWM increases.
- The change in speed of the DC Motor can be visualized through proteus and also through the digital oscilloscope available. 
- The DC Motor is also capable of rotating in both clockwise and ant-clockwise directions. The direction of rotation can be manipulated using a simple switch provided in the proteus schematic. 
- An LCD Interface has also been provided on the proteus schematic to monitor the current speed of the DC Motor. 
- DC Motor finds vast applications in domains like manufacturing industry, for designing machines like cranes, elevators etc, which involve bi-directional motion.

# Implementation at a glance

![image](https://user-images.githubusercontent.com/68660836/227014602-74fcfc30-5139-4598-963d-e44fb5c2b906.png)

1.	LCD Interface would be implemented using the PORTD pins available.
2.	Analog to Digital Conversion is performed at PORTA<1>, and the digital data is used to drive the motor.
3.	PORTD pins are used to implement the LCD Interface. An LCD Interrupt is generated that allows us to perform LCD Visualisation.
4.	PORTB<4> is used to generate the LED which indicates overflow of current speed beyond the maximum speed of the DC Motor.
5.	PORTC<2>/CCP1 pin is used for Pulse Width Modulation. The oscilloscope will be used in the proteus to provide visualisation of the PWM.
6.	PORTB<0>/INT pin is used to generate an interrupt that allows us to control the direction in which the DC Motor is rotating.

# LCD Display and LED Indicator

An LCD Display is incorporated in the project to show the current speed of the DC Motor and the Maximum Speed that can be attained. As the speed of the motor is changed, it can be visualised through the LCD display available.
