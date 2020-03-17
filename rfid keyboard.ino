 
//RFID 
#include <SPI.h>
#include <MFRC522.h>
 
#define SS_PIN 20
#define RST_PIN 4
#define MOSI_PIN 22
#define MISO_PIN 23
#define SCK_PIN 21
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.

byte masterCard[4]; 

//OLED
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

//OTHER
#include <Base64.h>

int ledPin = 6; //Teensy Onboard LED
//const int ledGreen = 14; //IRL Green LED
 
void setup() 
{
  //OLED
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3C (for the 128x32)
  delay(2000);
  display.setTextColor(WHITE);  
  
  //RFID
  Serial.begin(9600);
  SPI.begin(); // Init SPI bus
  mfrc522.PCD_Init(); // Init MFRC522 
  Serial.println("Teensy Device by BetterWayElectronics");
  Serial.println();

  //OTHER
  pinMode(ledPin, OUTPUT);

}
void loop() 
{
  // Main Message
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println("Teensy Device");

  display.setCursor(0, 10);
  display.println("BetterWayElectronics");
  
  display.display(); 
  
//  display.startscrollright(0x00, 0x05);
//  delay(4800);
//  display.stopscroll();
//  delay(1000);
//  display.startscrollleft(0x00, 0x05);
//  delay(4800);
//  display.stopscroll();
//  delay(1000);

  //Other
  //pinMode(ledGreen, OUTPUT); //Set IRL LED as Output (PWM)
  
  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  
  //Show UID on serial monitor
  Serial.print("UID tag :");
  String content= "";
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Message : ");
  content.toUpperCase();
  
  if (content.substring(1) == "00 00 00 00") // RFID Card/Device UID
  {
    display.clearDisplay();
    display.setCursor(0, 0);
    display.println("Authorized Access:");
    display.setCursor(0, 10);
    display.println("Windows Login");
    display.display();

    Serial.println("Authorized Access: Windows Login");
    Serial.println();

    digitalWrite(ledPin, HIGH);
    display.invertDisplay(true);

    // Do It!
    char inputString[] = "BASE64PASSWORD";  
    int inputStringLength = sizeof(inputString);
    int decodedLength = Base64.decodedLength(inputString, inputStringLength);
    char decodedString[decodedLength];
    Base64.decode(decodedString, inputString, inputStringLength);
    
    Keyboard.begin();
    Keyboard.releaseAll();
    delay(400);
    Keyboard.write(decodedString);
    Keyboard.press(KEY_RETURN);
    Keyboard.releaseAll();
    Keyboard.end();

     // Pause & Clear Display
    delay(2000);
    display.clearDisplay();
    digitalWrite(ledPin, LOW);
    display.invertDisplay(false);
    //
    
  }
  else if (content.substring(1) == "00 00 00 00") // RFID Card/Device UID
  {
    display.clearDisplay();
    display.setCursor(0, 0);
    display.println("Authorized Access:");
    display.setCursor(0, 10);
    display.println("Windows Login");
    display.display();

    Serial.println("Authorized Access: Windows Login");
    Serial.println();

    digitalWrite(ledPin, HIGH);
    display.invertDisplay(true);
  

    // Do It!
    char inputString[] = "BASE64PASSWORD"; 
    int inputStringLength = sizeof(inputString);
    int decodedLength = Base64.decodedLength(inputString, inputStringLength);
    char decodedString[decodedLength];
    Base64.decode(decodedString, inputString, inputStringLength);
    
    Keyboard.begin();
    Keyboard.releaseAll();
    delay(400);
    Keyboard.write(decodedString);
    Keyboard.press(KEY_RETURN);
    Keyboard.releaseAll();
    Keyboard.end();

     // Pause & Clear Display
    delay(2000);
    display.clearDisplay();
    digitalWrite(ledPin, LOW);
    display.invertDisplay(false);
    //
  }

  else if (content.substring(1) == "00 00 00 00") // RFID Card/Device UID
  {
    display.clearDisplay();
    display.setCursor(0, 0);
    display.println("Authorized Access:");
    display.setCursor(0, 10);
    display.println("Windows Login");
    display.display();

    Serial.println("Authorized Access: Windows Login");
    Serial.println();


    digitalWrite(ledPin, HIGH);
    display.invertDisplay(true);
  

    // Do It!
    char inputString[] = "BASE64PASSWORD"; 
    int inputStringLength = sizeof(inputString);
    int decodedLength = Base64.decodedLength(inputString, inputStringLength);
    char decodedString[decodedLength];
    Base64.decode(decodedString, inputString, inputStringLength);
    
    Keyboard.begin();
    Keyboard.releaseAll();
    delay(400);
    Keyboard.write(decodedString);
    Keyboard.press(KEY_RETURN);
    Keyboard.releaseAll();
    Keyboard.end();

     // Pause & Clear Display
    delay(2000);
    display.clearDisplay();
    digitalWrite(ledPin, LOW);
    display.invertDisplay(false);
    //
  }

  else if (content.substring(1) == "00 00 00 00") // RFID Card/Device UID
  {
    display.clearDisplay();
    display.setCursor(0, 0);
    display.println("Authorized Access:");
    display.setCursor(0, 10);
    display.println("Windows Login");
    display.display();

    Serial.println("Authorized Access: Windows Login");
    Serial.println();

    digitalWrite(ledPin, HIGH);
    display.invertDisplay(true);

    // Do It!
    char inputString[] = "BASE64PASSWORD"; 
    int inputStringLength = sizeof(inputString);
    int decodedLength = Base64.decodedLength(inputString, inputStringLength);
    char decodedString[decodedLength];
    Base64.decode(decodedString, inputString, inputStringLength);
    
    Keyboard.begin();
    Keyboard.releaseAll();
    delay(400);
    Keyboard.write(decodedString);
    Keyboard.press(KEY_RETURN);
    Keyboard.releaseAll();
    Keyboard.end();

     // Pause & Clear Display
    delay(2000);
    display.clearDisplay();
    digitalWrite(ledPin, LOW);
    display.invertDisplay(false);
  //
  }
 
 else   {
    Keyboard.begin();
    Keyboard.releaseAll();
    delay(400);
    Keyboard.press(KEY_RIGHT_GUI);
    delay(400);
    Keyboard.press('r');
    delay(400);
    Keyboard.write("shutdown -r -t 1 -c 'yikes'");
    delay(400);
    Keyboard.press(KEY_RETURN);
    delay(400);
    Keyboard.press(KEY_RIGHT_GUI);
    delay(400);
    Keyboard.press('l');
    delay(400);
    Keyboard.releaseAll();
    Keyboard.end();

    fail();
    
  }
} 

void fail() {

    display.clearDisplay();
    display.setCursor(45, 5);
    display.println("ACCESS");
    display.setCursor(45, 15);
    display.println("DENIED!");
    display.display();

    Serial.println(" Access Denied!");
  
    digitalWrite(ledPin, HIGH);
    display.invertDisplay(true);
    delay(400);
    digitalWrite(ledPin, LOW);
    display.invertDisplay(false);
    delay(400);
    digitalWrite(ledPin, HIGH);
    display.invertDisplay(true);
    delay(400);
    digitalWrite(ledPin, LOW);
    display.invertDisplay(false);
    delay(400);
    digitalWrite(ledPin, HIGH);
    display.invertDisplay(true);
    delay(400);
    digitalWrite(ledPin, LOW);
    display.invertDisplay(false);
    delay(400);

    fail();
    
}

