#include <SoftwareSerial.h>

#define RX 7
#define TX 8

String AP = "Galaxy A1217D2";
String PASS = "1234567890";
String API = "UFXQ8UQ3N4RGEZUW";
String HOST = "api.thingspeak.com";
String PORT = "80";

SoftwareSerial esp8266(RX, TX);

void setup() {
  Serial.begin(9600);
  esp8266.begin(115200);
  sendCommand("AT", 5, "OK");
  sendCommand("AT+CWMODE=1", 5, "OK");
  sendCommand("AT+CWJAP=\"" + AP + "\",\"" + PASS + "\"", 20, "OK");
}

void loop() {
  // Replace these with the actual vote counts
  int candidate1_votes = 10;
  int candidate2_votes = 15;

  String getData = "GET /update?api_key=" + API + "&field1=" + candidate1_votes + "&field2=" + candidate2_votes;
  sendCommand("AT+CIPMUX=1", 5, "OK");
  sendCommand("AT+CIPSTART=0,\"TCP\",\"" + HOST + "\"," + PORT, 15, "OK");
  sendCommand("AT+CIPSEND=0," + String(getData.length() + 4), 4, ">");
  esp8266.println(getData);
  delay(1500);
  sendCommand("AT+CIPCLOSE=0", 5, "OK");

  delay(60000); // Wait for 1 minute before uploading again
}

void sendCommand(String command, int maxTime, char readReplay[]) {
  int countTimeCommand = 0;
  boolean found = false;

  while (countTimeCommand < (maxTime * 1)) {
    esp8266.println(command);
    if (esp8266.find(readReplay)) {
      found = true;
      break;
    }

    countTimeCommand++;
  }

  if (found) {
    Serial.println("Success");
  } else {
    Serial.println("Fail");
  }
}
