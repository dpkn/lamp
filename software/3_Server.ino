// This function is called everytime the ESP8266 receives a http request at /api
void handleApi() {

  // Interpret the received JSON
  StaticJsonBuffer<400> jsonBuffer;
  JsonObject& data = jsonBuffer.parseObject(server.arg("plain"));

  int setState = data["state"];
  LED_STRIP_STATE = setState;

  // Set a color if requested
  String setColor = data["color"];
  if(setColor){
    setColor.toLowerCase();

    // Check if it's one of the pre-defined colors
    if(setColor=="red") {
      color = CRGB(255,0,0);
    }else if(setColor=="green"){
      color = CRGB(0,255,0);
    }else if(setColor=="blue"){
      color = CRGB(0,0,255);
    }else if(setColor=="black"){
       color = CRGB(0,0,0);
       brightness = 0;
    }else{
      // In case of a custom color, seperate r g b values should be provided
      int r = data["r"];
      int g = data["g"];
      int b = data["b"];
      color = CRGB(r,g,b);
    }
  }

  // Adjust brightness if requested
  int brightnessData = data["brightness"];
  if(brightnessData){
    brightness = brightnessData;
    Serial.println("brightness set to");
    Serial.println(brightness);
    FastLED.setBrightness(brightness);
  }

  // Set a timer if requested
  int setTimer = data["setTimer"];
  if(setTimer){
    startTimer();
  }

  // Reply with 200 status
  serverSendJson(200,"OK");
}

// Is called everytime root (/) is requested
void handleRoot() {
  String responseString = "OK";
  serverSendJson(200,responseString);
}

// Sends a JSON response back to the received request
void serverSendJson(long status, String response){
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.sendHeader("Access-Control-Allow-Methods", "POST,GET,OPTIONS");
  server.sendHeader("Access-Control-Allow-Headers", "Origin, X-Requested-With, Content-Type, Accept");
  server.send (status, "text/json", response );
}
