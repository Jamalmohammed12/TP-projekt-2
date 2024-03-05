/*
 Namn :Jamal_Mohammed 
 Klass:2B 
 Projekt: Handrörelse förståelses system 
 Beskrivning: Mitt projekt ska med hjälp av sensorer och dess värden ge mig olika meningar på en display och för att vara säker på att mina sensorer ger rätt värden så har jag printat
 ut värderna utav sensorerna.


*/



#include <Wire.h>
#include <U8glib.h>

// Constants:
const int flexPin1 = A1; // Pin A1 to read analog input from flex sensor 1
const int flexPin2 = A2; // Pin A2 to read analog input from flex sensor 2

// Variables:
int value1; // Variable to store analog value from flex sensor 1
int value2; // Variable to store analog value from flex sensor 2
int x = 0;   // Position x on the OLED display
int y = 20;  // Position y on the OLED display

// Create an instance of the U8glib class for the OLED display
U8GLIB_SSD1306_128X64 oled(U8G_I2C_OPT_NO_ACK);

void setup() {
  Serial.begin(9600); // Begin serial communication
  Wire.begin(); // Initialize I2C communication
  oled.setFont(u8g_font_helvB10); // Set font for OLED display
}

void loop() {
  // Read analog values from flex sensors
  value1 = analogRead(flexPin1); // Read and store analog value from flex sensor 1
  value2 = analogRead(flexPin2); // Read and store analog value from flex sensor 2
  
  // Print analog values to the serial monitor
  Serial.println(String(value1) + " " + String(value2));

  // Check the values of the flex sensors and display appropriate messages on the OLED display
  if (value1 >= 450) {
    TextToScreen("BEHÖVER VATTEN", x, y); // Display "BEHÖVER VATTEN" on OLED display if flex sensor 1 value is greater than or equal to 450
  } else if (value2 >= 500) {
    TextToScreen("BEHÖVER MAT", x, y); // Display "BEHÖVER MAT" on OLED display if flex sensor 2 value is greater than or equal to 500
  }  else {
    TextToScreen("Behover inget tack", x, y); // Display "Behover inget tack" on OLED display if none of the conditions are met
  }

  delay(500); // Delay for stability, adjust as needed
}

// Function to display text on OLED screen at specified position
void TextToScreen(String text, int posx, int posy) {
  oled.firstPage();
  do {
    oled.drawStr(0, 20, text.c_str()); // Draw text on OLED display at specified position
  } while (oled.nextPage());
}