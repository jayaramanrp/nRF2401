/* 
 *   jayaraman.palanichamy@gmail.com

connect LED in pin number 9.
LED blinks while receiving data from Transmitter 
* This can be used to check the range that nrf covers.
* Library: TMRh20/RF24, https://github.com/tmrh20/RF24/
*/

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8); // CE, CSN

const byte address[6] = "10101";

void setup() {
  
  Serial.begin(9600);
  pinMode(9, OUTPUT);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
}

void loop() {
  if (radio.available()) {

    while(radio.available()){
    char text[32] = "";
    radio.read(&text, sizeof(text));
    Serial.println(text);
    
    if(strcmp(text,"ping" ==0) ){
      Serial.println("on");
      digitalWrite(9,HIGH);
      delay(10);
      }
      digitalWrite(9,LOW);
            Serial.println("off");
delay(200);

  }
  }
}
