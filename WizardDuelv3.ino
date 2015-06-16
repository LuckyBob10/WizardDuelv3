#include <Bounce.h>
#include <FastLED.h>
#include "pins.h"
#include "vars.h"


Bounce bP1Red =    Bounce(pPlayerButtons[0][0], iDebounceTimeout);
Bounce bP1Yellow = Bounce(pPlayerButtons[0][1], iDebounceTimeout);
Bounce bP1Blue =   Bounce(pPlayerButtons[0][2], iDebounceTimeout);
Bounce bP1Green =  Bounce(pPlayerButtons[0][3], iDebounceTimeout);
Bounce bP2Red =    Bounce(pPlayerButtons[1][0], iDebounceTimeout);
Bounce bP2Yellow = Bounce(pPlayerButtons[1][1], iDebounceTimeout);
Bounce bP2Blue =   Bounce(pPlayerButtons[1][2], iDebounceTimeout);
Bounce bP2Green =  Bounce(pPlayerButtons[1][3], iDebounceTimeout);


void setup() {
  randomSeed(analogRead(0));
  
  for (uint8_t p=0; p<1; p++) {
    for (uint8_t b=0; b<4; b++) {
      pinMode(pPlayerButtons[p][b], INPUT_PULLUP);
    }
  }
  
  Serial.begin(9600);
  Serial1.begin(9600);
  Serial2.begin(9600);
  Serial3.begin(9600);
  delay(1000);
  ResetGame();
}

void loop() {
  ReadButtonsLoop();
  
  switch (iGameState) {
    case 0: {
      //No game running - teaser loop
      CheckGameStateLoop(0);
      IntroLoop();
    } break;
    
    case 1: {
      //Game start intro
      CheckGameStateLoop(1000);
      //TODO: fancy game start sounds/lights
    } break;
    
    case 2: {
      //Pick wizard loop
      CheckGameStateLoop(0);
    } break;
    
    case 3: {
      //Pick wizard outro
      CheckGameStateLoop(1000);
    } break;
    
    case 4: {
      //Pick spell loop
      CheckGameStateLoop(0);
    } break;
    
    case 5: {
      //Pick spell outro / skill challenge intro
      CheckGameStateLoop(1000);
    } break;
    
    case 6: {
      //Skill challenge loop
      CheckGameStateLoop(0);
    } break;
    
    case 7: {
      //Slill challenge outro
      CheckGameStateLoop(0);
    } break;
    
    case 8: {
      //Battle
      CheckGameStateLoop(5000);
    } break;
    
    case 9: {
      //PLACEHOLDER - Battle over, go back to pick spell
      iGameState = 4;
    } break;
    
    //---- End regular game play states ----//
    
    case 10: {
      //Game over outro
      if (CheckGameStateLoop(5000)) {
        if (iPlayerHealth[P1] <=0 && iPlayerHealth[P2] > 0) {
          //Player 1 wins
        }
        else if (iPlayerHealth[P1] <= 0 && iPlayerHealth[P2] > 0) {
          //Player 2 wins
        }
        else if (iPlayerHealth[P1] <= 0 && iPlayerHealth[P2] <= 0) {
          //Tie
        }            
      }
    } break;
    
    case 11: {
      //PLACEHOLDER - Reset game
      ResetGame();
    }
  }
  
  if (iGameStateTimeout != 0 && iGameStateTimeout > mGameState) {
    //If the game state has an inherent timeout, advance if the duration has passed.
    iGameState++;
    bStateStart = true;
  }
  
  if (iPlayerHealth[P1] <= 0 || iPlayerHealth[P2] <= 0) { 
    //Game over
    iGameState = 10;
    bStateStart = true;
  }
  
  LcdLoop();
  LedLoop();
}
