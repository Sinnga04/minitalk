# MiniTalk Project

## Overview

Welcome to the MiniTalk Project! This project is a simple interprocess communication application implemented in C using the MiniTalk protocol. It provides a lightweight communication mechanism between processes using signals.

## Features

- **Signal Communication:** Implement communication between processes using signals.
- **Message Encoding:** Develop a protocol for encoding and decoding messages.
- **Reliable Communication:** Enhance communication reliability and error handling.

## Project Details

MiniTalk is designed to facilitate communication between different processes on a Unix-like operating system. It leverages the use of signals to transmit messages between a server and multiple client processes. This lightweight approach allows for quick and efficient interprocess communication.

### Signal Communication

The core of MiniTalk relies on the use of signals for communication. The server and clients exchange signals to convey messages, and each signal corresponds to a specific piece of information.

### Message Encoding

To ensure seamless communication, a simple message encoding and decoding protocol have been implemented. Messages are encoded into signals, transmitted between processes, and then decoded to extract the original message.

### Reliable Communication

Reliability is a crucial aspect of any communication system. MiniTalk includes error-handling mechanisms to deal with issues such as signal loss or misinterpretation, ensuring a robust communication channel.


### To test the project

Clone the repository:

   ```bash
   git clone https://github.com/your-username/minitalk.git
