// LED Strip settings
const int numberOfLeds = 60;       // The amount of LEDS in the strip
const int ledDataPin = 2;          // The PIN no. to which the strips data cable is connected
const int masterBrightness = 50;   // Overall brightness of the lamp (0-255)

// Wifi Settings
const char* ssid = "demonetwork";
const char* password = "demopassword";

const IPAddress staticIp(192, 168, 178, 101);  // The desired static local IP of the device
const IPAddress gateway(192, 168, 178, 1); // Gateway IP of the modem
const IPAddress subnet(255, 255, 255, 0); // Subnet of the modem

// Server Settings
const int serverPort = 300; // Port on which the server will be adressable

// Initial color
CRGB color = CRGB(180,160,140);

///////////////////////////////////


// Defining the block of memory that will be used for storing and manipulating the led data:
CRGB ledArray[numberOfLeds];

// Start the WebServer
ESP8266WebServer server(serverPort);
