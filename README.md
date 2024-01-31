Minitalk Project README
Overview
This project entails creating a communication program involving a client and a server. Communication between these components is exclusively achieved through UNIX signals. The server must be initiated first, displaying its process ID (PID). The client, accepting two parameters – the server PID and a string to send – interacts with the server by transmitting the specified string. Upon receiving the string, the server prints it.

Project Structure
Executable Files
client: Executable file for the client.
server: Executable file for the server.
Makefile
Include a Makefile for seamless compilation. The Makefile should compile source files without relinking.

Mandatory Part
Server Launch

The server must be launched first, printing its PID.
Client Parameters

The client requires two parameters:
The server PID.
The string to send.
String Communication

The client transmits the specified string to the server.
Upon receiving the string, the server promptly prints it.
Quick Display

The server should rapidly display the received string.
Bit-Shifting Explanation
To implement signal communication, bit-shifting can encode and decode information in signals. A loop can iterate through the bits of each character, sending specific signals for 0 or 1.

Sending a String (Client)
Obtain the server's PID and the string to send.
Iterate through each character in the string.
For each character, iterate through its bits.
Send SIGUSR1 or SIGUSR2 signals to the server for each bit.
Utilize the kill function to send signals.
Receiving and Printing (Server)
Set up signal handlers using sigaction for SIGUSR1 and SIGUSR2.
Decode the received signals, reconstructing bits.
Convert bits back to characters.
Print the received string.
This process ensures signal communication using bit-shifting. Adjust timing and error handling to meet project requirements.
