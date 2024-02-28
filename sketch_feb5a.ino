#include <Wire.h>
#include <U8glib.h>

// Constants:
const int flexPin1 = A1; // Pin A1 to read analog input
const int flexPin2 = A2; // Pin A2 to read analog input

// Variables:
int value1; // Save analog value 1
int value2; // Save analog value 2
int x = 0;   // Position x on the OLED display
int y = 20;  // Position y on the OLED display
U8GLIB_SSD1306_128X64 oled(U8G_I2C_OPT_NO_ACK);

void setup() {
  Serial.begin(9600); // Begin serial communication
  Wire.begin();
  oled.setFont(u8g_font_helvB10); // Set font
}

void loop() {
  value1 = analogRead(flexPin1); // Read and save analog value from flex sensor 1
  value2 = analogRead(flexPin2); // Read and save analog value from flex sensor 2
  Serial.println(String(value1) + " " + String(value2)); // Print values to serial monitor

  if (value1 >= 450) {
    UpdateOled("BEHÖVER VATTEN", x, y); // Display "BEHÖVER VATTEN" on OLED display
  } else if (value2 >= 500 ) {
    UpdateOled("BEHOVER MAT", x, y); // Display "Ingen input" on OLED display
  }  else {
    UpdateOled("Behover inget tack", x, y);
  }

  delay(500); // Delay for stability, adjust as needed
}

void UpdateOled(String text, int posx, int posy) {
  oled.firstPage();
  do {
    oled.drawStr(0, 20, text.c_str()); // Draw text on OLED display at specified position
  } while (oled.nextPage());
}
