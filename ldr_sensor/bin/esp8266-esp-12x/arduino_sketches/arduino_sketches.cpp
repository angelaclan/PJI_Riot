#include "arduino.hpp"
#include "board.h"

#include "arduino_board.h"
#include "stdlib.h"
#include "/home/angela/riot_workplace/RIOT/examples/hello-world/udp.c"

//extern void send(char *addr_str, char *port_str, char *data, unsigned int num, unsigned int delay);
                 
                 
int ldrPin = ADC_LINE(0);
int ldrStatus = 0;
char str[80];

void setup() {
  Serial.begin(9600);
  pinMode(ldrPin, INPUT);
}
void loop() {
  uint32_t num = 1;
  uint32_t dl = 1000000;


  Serial.println( "hola" ); 
  ldrStatus = analogRead(ldrPin);
  Serial.println(ldrStatus);
  sprintf(str, "Value of LDR = %d", ldrStatus);
  //ldrValue = itoa(ldrStatus, ldrValue, 8*sizeof(int));
  
  send((char*)"fe80::dae9:e933:bf4:48b2", (char *)"8808", (char *)str, num, dl);


  delay(2000);
}

int main(void)
{
    /* run the Arduino setup */
    setup();
    /* and the event loop */
    while (1) {
        loop();
    }
    /* never reached */
    return 0;
}
