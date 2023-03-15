# STM32F103xx-Simple-UART

This project contains the code required to get working serial (RS-232) character IO via the STM32 USART.<br>
<br>
USART2 of the STM32F103xx is used because USART1 might be used for serial programming of the device.<br>
<br>
Wiring<br>
USB to Serial Dongle Rx pin to STM32F103xx pin A2 (USART2-Tx)<br>
USB to Serial Dongle Tx pin to STM32F103xx pin A3 (USART2-Rx)<br>
USB to Serial Dongle Gnd pin to STM32F103xx Gnd (G) pin<br>
<br>
Setup<br>
Open a terminal program of your choice with the following settings:<br>
       Com Port: Whatever port the USB to Serial Dongle connected to USART2 is on.<br>
Comm Parameters: 115,200 baud, 8 bits, no parity, 1 stop-bit<br>
<br>
Example for minicom under Linux:<br>
`minicom -b 115200 -D /dev/ttyUSB2`<br>
<br>
When the program is first run, the letter 'H' from 'Hello World!' will be output as a single character and then the rest of the the line ('ellow World!') will be output as a string. Then a string prompting the user for input will be output. From this point, any user input is echoed back to the terminal. Hitting a new line (enter) will cause '<RETURN>' to be output to the terminal.<br>
Requires the following for your OS, and the Path variable must be set to point to these binaries:<br>
The makefile will have to be edited as follows: Make sure the FLASHER path variable to the STM32_Programmer_CLI.exe file points to the program in your system, or that the program bin folder is included in your default path. Also, the FLASHPORT variable will have to be updated to to point to the COM port of the attached programmer.
Requires:<br>
<hr>
Editor of your choice<br>
arm-none-eabi-gcc toolchain<br>
make<br>
git-bash (for windows)<br>
STM32_Programmer_CLI.exe Program to upload .elf file to the microcontroller / Blue Pill<br>
<hr>
To compile, navigate to the directory containing main.c (using git-bash in Windows) and type 'make'. Make will also attempt to upload the code to the microcontroller, so, make sure it is connected and ready to accept code before performing the make command. Optionally, the .elf file can be uploaded manually as a separate process.
