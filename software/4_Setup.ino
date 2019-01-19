void setup(void) {
  Serial.begin(115200);

  // Initialize the FastLED library
  FastLED.addLeds<NEOPIXEL, ledDataPin>(ledArray, numberOfLeds);
  FastLED.setBrightness(masterBrightness);

  // Set up WiFi in station mode, with a static IP, and connect to network
  WiFi.mode(WIFI_STA); 
  WiFi.config(staticIp,gateway,subnet);
  WiFi.begin(ssid, password);

  Serial.println("Trying to connect...");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  // When connection is succesfull, print details
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  // Register callbacks for http requests
  server.on("/", handleRoot);       // Root is used as a status/ping check
  server.on("/api", handleApi);     // Handles the requests for controlling the LEDs

  server.begin();
  Serial.println("HTTP server started");

  // When connection is made, fade on the lamp
  LED_STRIP_STATE = FADE_ON;
}
