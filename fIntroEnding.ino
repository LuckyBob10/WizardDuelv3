void IntroLoop() {  
  if (bButtonPressed == true) {
    //Start game
    iGameState++;
    bStateStart = true;
  }
}

void ResetGame() {
  iGameState = 0;
  bStateStart = true,
  bStateUpdate = false,
  bStateEnd = false,
  iPlayerWizType[P1] = 0;
  iPlayerWizType[P2] = 0;
  iPlayerTempWizType[P1] = 0;
  iPlayerTempWizType[P2] = 0;
  iPlayerSpellType[P1] = 0;
  iPlayerSpellType[P2] = 0;
  iPlayerHealth[P1] = 100;
  iPlayerHealth[P2] = 100;
  LcdBacklight(P1, 30);
  LcdBacklight(P2, 30);
  delay(100);
  LcdClearBoth();
  iTestScore[P1] = 0;
  iTestScore[P2] = 0;
}

void PickWizardLoop() {
  bStateUpdate = false; 
  
  if (bButtonsPressed[P1][0]) {
    iPlayerTempWizType[P1] = WIZFIRE;
    LcdCursor(P1, 1, 0);
    LcdPrint(P1, "FIRE litng water");
    bStateUpdate = true;
  }
  else if (bButtonsPressed[P1][1]) {
    iPlayerTempWizType[P1] = WIZLITNG;
    LcdCursor(P1, 1, 0);
    LcdPrint(P1, "fire LITNG water");
    bStateUpdate = true;
  }
  else if (bButtonsPressed[P1][2]) {
    iPlayerTempWizType[P1] = WIZWATER;
    LcdCursor(P1, 1, 0);
    LcdPrint(P1, "fire litng WATER");
    bStateUpdate = true;
  }
  
  if (bButtonsPressed[P2][0]) {
    iPlayerTempWizType[P2] = WIZFIRE;
    LcdCursor(P2, 1, 0);
    LcdPrint(P2, "FIRE litng water");
    bStateUpdate = true;  
  }
  else if (bButtonsPressed[P2][1]) {
    iPlayerTempWizType[P2] = WIZLITNG;
    LcdCursor(P2, 1, 0);
    LcdPrint(P2, "fire LITNG water");
    bStateUpdate = true;
  }
  else if (bButtonsPressed[P2][2]) {
    iPlayerTempWizType[P2] = WIZWATER;
    LcdCursor(P2, 1, 0);
    LcdPrint(P2, "fire litng WATER");
    bStateUpdate = true;
  }
  
  if (bStateUpdate) {
    //Somebody pressed a button, make sure first line updates instructions
    LcdCursor(P1, 0, 0);
    LcdPrint(P1,"Green to confirm");
  }
  
  bStateUpdate = false;
  
  if (iPlayerTempWizType[P1] > 0 && bButtonsPressed[P1][3]) {
    //TODO: Fancy animation to lock wizard type and set timeout for second player
    LcdCursor(P1, 0, 0);
    LcdPrint(P1, "Waiting on otherwizard...  30sec");
    iPlayerWizType[P1] = iPlayerTempWizType[P1];
    bStateUpdate = true;
  }
  if (iPlayerTempWizType[P2] > 0 && bButtonsPressed[P2][3]) {
    //TODO: Fancy animation to lock wizard type and set timeout for second player
    LcdCursor(P2, 0, 0);
    LcdPrint(P2, "Waiting on otherwizard...  30sec");
    iPlayerWizType[P2] = iPlayerTempWizType[P2];
    bStateUpdate = true;
  }
  
  if (bStateUpdate) {
    //A wizard confirmed. Check if both confirmed and set up for start of picking spell.
    if (iPlayerWizType[P1] > 0 && iPlayerWizType[P2] > 0) {
      iGameState++;
      bStateStart = true;
    }
  }

}
