#include <X6B.h>
//#include <hardware/uart.h>
#define RX_PIN 9
#define UART_ID uart1
#define BAUD_RATE 115200
#define CHANNELS_TO_READ 9

X6B x6b(RX_PIN, UART_ID, BAUD_RATE, CHANNELS_TO_READ);

void setup() {
  Serial.begin(115200); // Start the serial communication with the baud rate you desire
  delay(3000);
  Serial.println("Setup end..");

  x6b.begin();
}

void loop() {
  x6b.update();

  // Print each channel value to the Serial console
  for (uint8_t j = 0; j < 10; j++) {
    if (j <= 3) {
      Serial.print("Channel ");
      Serial.print(j);
      Serial.print(" : ");
      Serial.print(x6b.getChannelValue(j));
    } else if (j >= 4 && j <= 5) {
      Serial.print("Channel ");
      Serial.print(j);
      Serial.print(" : ");
      Serial.print(x6b.getChannelValue(j));
    } else if (j >= 6 && j <= 8) {
      Serial.print("Channel ");
      Serial.print(j);
      Serial.print(" : ");
      Serial.print(x6b.getRxChannel(j));
    } else {
      Serial.print("Channel ");
      Serial.print(j);
      Serial.print(" : ");
      Serial.println(x6b.getRxChannel(j));
    }
  }

  //delay(100); // Adding delay to not overload the Serial console
}
