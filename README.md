# Connect-to-Thingspeak-using-arduino-and-Esp8266-without-using-wifiLibraries
This code is an Arduino sketch that uses an ESP8266 Wi-Fi module to send vote counts for two candidates to ThingSpeak, an IoT platform that provides data storage and analytics services. The code is organized into three main parts: includes and definitions, setup function, and loop function. There is also an additional function called sendCommand that is used to send AT commands to the ESP8266 module.

# Includes and Definitions:
The code includes the "SoftwareSerial.h" library, which allows serial communication on other digital pins of the Arduino. It also defines several constants such as RX, TX, AP, PASS, API, HOST, and PORT, which are used for configuring the ESP8266 module and connecting to the ThingSpeak API.

# Setup Function:
The setup function initializes the Serial communication between the Arduino and the computer, as well as the SoftwareSerial communication between the Arduino and the ESP8266 module. It then sends a series of AT commands to configure the ESP8266 module, set it to station mode, and connect it to the specified Wi-Fi network.

# Loop Function:
The loop function first assigns vote counts to the two candidates. It then constructs a GET request to update the ThingSpeak channel with the vote counts. The code sends several AT commands to open a TCP connection to the ThingSpeak API, send the GET request, and close the connection. It then waits for 1 minute before repeating the process.

# sendCommand Function:
The sendCommand function is a helper function that sends a specified AT command to the ESP8266 module and waits for a specified response. It takes three parameters: the command string, the maximum time to wait for the response, and the expected response string. The function sends the command, checks for the expected response within the given time limit, and then prints "Success" or "Fail" to the serial monitor, depending on whether the response was received or not.
