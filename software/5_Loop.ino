void loop(void) {
  // Process incoming requests
  server.handleClient();

  // Depending on what state the lamp is in,
  // call appropriate function
  if(LED_STRIP_STATE == STATIC){
    setSolid(60);
    FastLED.show();
  }else if(LED_STRIP_STATE == FADE_ON){
    fadeOn();
    FastLED.show();
  }else if(LED_STRIP_STATE == FADE_OFF){
    fadeOff();
    FastLED.show();
  }else if(LED_STRIP_STATE == PULSATING){
    pulseAnimation(10);
    FastLED.show();
  }else if(LED_STRIP_STATE == MOVING_BAR){
    movingBarAnimation();
    FastLED.show();
  }else if(LED_STRIP_STATE == DEMO_CALENDAR){
    demoCalendar();
    FastLED.show();
  }else if(LED_STRIP_STATE == SUNRISE){
    fadeOn();
    FastLED.show();
  }else if(LED_STRIP_STATE == TIMER_RUNNING){
    EVERY_N_SECONDS(1) { updateTimer();  }
  }

  // Delay for performance reasons
  FastLED.delay(10);
}
