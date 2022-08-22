# ESND-On-demand-Traffic-light-control
This is an On-demand Traffic light control system for the EgFWD Embedded Systems Professional NanoDegree Scholarship. This project was written in C using Microchip Studio and Proteus 8 professional.

## Demonstration

Here, I used Proteus 8 Professional in order to simulate AVR Atmega32. I have the wiring labeled below. <br></br>
![image](https://user-images.githubusercontent.com/62207434/185999906-98b91a0e-28eb-4b4b-9db9-d5c393d37160.png)

This is a video for the system running on the simulator. More details about behaviour  in the [system-functionality](https://github.com/FahdSeddik/ESND-On-demand-Traffic-light-control#system-functionality) section.



https://user-images.githubusercontent.com/62207434/186000173-a4a9c387-57c7-41ba-85e6-941e10dca15f.mp4

## System Functionality
- The system handles 6 LEDs
- Car LEDs switch every 10s (each switch includes 5s yellow light blinking interval)
- `Button`: the button acts as a request for a pedestrian to cross the street
  * The system will stop cars if not already on red light as per request

## Details & Program Flow Chart
You can find system details and program flow chart in project documentation [here](https://github.com/FahdSeddik/ESND-On-demand-Traffic-light-control/blob/main/Project%20Documentation.pdf).
