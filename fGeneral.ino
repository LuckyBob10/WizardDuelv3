void ReadButtonsLoop() {
  //Reset buttons pressed
  
  bButtonPressed = false;
  for (uint8_t p=0; p<2; p++) {
    for (uint8_t b=0; b<4; b++) {
      bButtonsPressed[p][b] = false;
    }
  }
  
  bP1Red.update();
  bP1Yellow.update();
  bP1Blue.update();
  bP1Green.update();
  bP2Red.update();
  bP2Yellow.update();
  bP2Blue.update();
  bP2Green.update();

  if (bP1Red.fallingEdge()) {
    bButtonsPressed[0][0] = true;
    bButtonPressed = true;
  }
  if (bP1Yellow.fallingEdge()) {
    bButtonsPressed[0][1] = true;
    bButtonPressed = true;
  }
  if (bP1Blue.fallingEdge()) {
    bButtonsPressed[0][2] = true;
    bButtonPressed = true;
  }
  if (bP1Green.fallingEdge()) {
    bButtonsPressed[0][3] = true;
    bButtonPressed = true;
  }

  if (bP2Red.fallingEdge()) {
    bButtonsPressed[1][0] = true;
    bButtonPressed = true;
  }
  if (bP2Yellow.fallingEdge()) {
    bButtonsPressed[1][1] = true;
    bButtonPressed = true;
  }
  if (bP2Blue.fallingEdge()) {
    bButtonsPressed[1][2] = true;
    bButtonPressed = true;
  }
  if (bP2Green.fallingEdge()) {
    bButtonsPressed[1][3] = true;
    bButtonPressed = true;
  }
}

void LcdClear(uint8_t iScreenNumber) {
  if (iScreenNumber == 0) {
    Serial2.write(254);
    Serial2.write(1);
  }
  else if (iScreenNumber == 1) {
    Serial3.write(254);
    Serial3.write(1);
  }
}

void LcdClearBoth() {
  for (uint8_t i=1; i<2; i++) {
    LcdClear(i);
  }
}

void LcdPrint(uint8_t iScreenNumber, const char* text) {
  if (iScreenNumber == 0) {
    Serial2.print(text);
    DebugMessage(text);
  }
  else if (iScreenNumber == 1) {
    Serial3.print(text);
  }
}

void LcdPrintBoth(const char* text) {
  LcdPrint(P1, text);
  LcdPrint(P2, text);
}

bool LcdCursor(uint8_t iScreenNumber, uint8_t row, uint8_t col, uint8_t width=16, uint8_t height=2) {
  if (row<0||row>(height-1)) {
    return false;
  }
  if (col<0||col>(width-1)) {
    return false;
  }
  col = col+(row*64)+128;
  if (iScreenNumber == 0) {
    Serial2.write(254);
    Serial2.write(col);
  }
  else if (iScreenNumber == 1) {
    Serial3.write(254);
    Serial3.write(col);
  }
  return true;
}

bool LcdBacklight(uint8_t iScreenNumber, uint8_t bright) {
  if (bright<0||bright>29) {
    return false;
  }
  bright = bright+128;
  if (iScreenNumber == 0) {
    Serial2.write(124);
    Serial2.write(bright);
  }
  else if (iScreenNumber == 1) {
    Serial3.write(124);
    Serial3.write(bright);
  }
  return true;
}

void DebugMessage(const char* text) {
  if (bDebugMode) {
    Serial.print(text);
  }
}

bool CheckGameStateLoop(uint16_t istatetimeout) {
  if (bStateStart) {
    iGameStateTimeout = 0;
    mGameState = 0;
    bStateStart = false;
    return true;
  }
  else {
    return false;
  }
}
