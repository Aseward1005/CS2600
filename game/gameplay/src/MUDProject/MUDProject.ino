#include <WiFi.h>
#include <Keypad.h>

#include <ArduinoMqttClient.h>

#include <LiquidCrystal_I2C.h>
#include <Wire.h>

#define SDA 13                    //Define SDA pins
#define SCL 14                    //Define SCL pins

const char* ssid = "Seward2";
const char* password = "6616647216";

const uint16_t tcpPort = 8080;
const char * tcpHost = "anthonyseward.duckdns.org";

char const* brokerAddr = "anthonyseward.duckdns.org"; //use the broker address
const int brokerPort = 1883; //port the broker should be active on

WiFiClient wifiClient;
MqttClient mqttClient(wifiClient);

WiFiClient tcpClient;

char *descriptions = "MUD_PROJECT/descriptions";

// define the symbols on the buttons of the keypad
char keys[4][4] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[4] = {2, 27, 26, 25}; // connect to the row pinouts of the keypad
byte colPins[4] = {15, 21, 22, 23};   // connect to the column pinouts of the keypad

// initialize an instance of class NewKeypad
Keypad myKeypad = Keypad(makeKeymap(keys), rowPins, colPins, 4, 4);
//initialize an instance of lcd
LiquidCrystal_I2C lcd(0x27,16,2); 
void setup() {
  wifiInit();
  lcdInit();
  tcpInit();
  brokerInit();

  mqttClient.subscribe(descriptions);
  mqttClient.onMessage(showDesc);
}

void tcpInit(){
  Serial.println("Initializing tcp");
  while (!tcpClient.connect(tcpHost, tcpPort)) {
    Serial.println("...");
  }
  Serial.println("Connected to server successfully");
}

void lcdInit()
{
  Wire.begin(SDA, SCL);           // attach the IIC pin
  if (!i2CAddrTest(0x27)) {
    lcd = LiquidCrystal_I2C(0x3F, 16, 2);
  }
  lcd.init();                     // LCD driver initialization
  lcd.backlight();                // Open the backlight
  lcd.setCursor(0,0);             // Move the cursor to row 0, column 0
}

bool i2CAddrTest(uint8_t addr) {
  Wire.begin();
  Wire.beginTransmission(addr);
  if (Wire.endTransmission() == 0) {
    return true;
  }
  return false;
}

void wifiInit()
{
  // connect to wifi
  Serial.begin(115200);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.println("...");
  }

  Serial.print("WiFi connected.");
}

void brokerInit()
{
  //connect to the broker
  Serial.println("\nMQTT SETUP");
  Serial.println(String("Connecting to ")+brokerAddr);
  if (!mqttClient.connect(brokerAddr, brokerPort))
  {
    Serial.print("MQTT connection failed! Error code = ");
    Serial.println(mqttClient.connectError());
    // The connection to the MQTT broker failed, Arduino is halted.
    while (true);
  }
  Serial.println("\nConnected");

  Serial.println("MQTT SETUP END");
}

void loop() {
  mqttClient.poll();
  // If there is a character input, sent it to the serial port
  
  char keyPressed = myKeypad.getKey();
  if (keyPressed) {
    Serial.println(keyPressed);
    if (keyPressed == '2'){
      tcpClient.print("north");
    }
    if (keyPressed == '4'){
      tcpClient.print("west");
    }
    if (keyPressed == '6'){
      tcpClient.print("east");
    }
    if (keyPressed == '8'){
      tcpClient.print("south");
    }
  }
}

void showDesc(int messageSize) {
  Serial.println("Message");
  lcd.clear();
  lcd.setCursor(0, 0);
  while (mqttClient.available()){
    lcd.print((char)mqttClient.read());
  }
}