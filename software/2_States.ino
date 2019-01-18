// Helper variables used by some states
int brightness = 0;
long steps = 0;
int timer = 60;
int previous = 0;
int activeLed = 0;

// Fade off
void fadeOff(){
  fadeToBlackBy(ledArray, numberOfLeds, steps);
  steps++;
  if(steps > 255){
    steps = 0;
    LED_STRIP_STATE = OFF;
  }
}

// Fade on
void fadeOn(){
  for (int i = 0; i < numberOfLeds; i++) {
    ledArray[i] = color;
    ledArray[i].maximizeBrightness(steps);
  }
  steps++;
  if(steps > 255){
    steps = 0;
    LED_STRIP_STATE = STATIC;
  }
}

// Animation of a bar moving back and forth
void movingBarAnimation(){
   fadeToBlackBy(ledArray, numberOfLeds, 15);
   int pos = beatsin16(20, 0, numberOfLeds-1 );
   ledArray[pos] += color;
}

// Pulsate the Led on and off in sinus wave
void pulseAnimation(long speed){
  brightness = sin8(millis()/speed);

  for(int i = 0; i < numberOfLeds; i++ )
   {
   ledArray[i] = color;
   ledArray[i].fadeLightBy(brightness);
  }

}

// Fill the whole strip with a solid color
void setSolid(int numberOfLeds){
   fill_solid(ledArray, numberOfLeds, color);
}

// Demo of calendar feature
// Yes, this part isn't actually looking at real calendar data yet.
// Life is a lie. 
void demoCalendar(){
   fill_solid(ledArray, 60, CRGB::Red);
   fill_solid(ledArray, 55, CRGB::Orange);
   fill_solid(ledArray, 40, CRGB::Blue);
   fill_solid(ledArray, 25, CRGB::Green);
   fill_solid(ledArray, 5, CRGB::Red);
}


// Start the timer
void startTimer(){

  timer = 60;

  LED_STRIP_STATE = TIMER_START;


   for(int i = 0; i < numberOfLeds; i++) {

      ledArray[i] = color;
      FastLED.show();
      delay(15);

   }

  LED_STRIP_STATE = TIMER_RUNNING;
}

// Timer update (called every n seconds when timer is running)
void updateTimer(){
  timer--;
  
  fill_solid(ledArray, 60, CRGB::Black);
  fill_solid(ledArray, timer, color);

  // If done, go back to static
  if(timer<1){
    LED_STRIP_STATE = PULSATING;
  }
}
