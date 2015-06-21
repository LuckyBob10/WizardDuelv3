void LcdLoop() {
  if (mLcdUpdate > iLcdUpdateTimeout) {
    mLcdUpdate = 0;
    iLcdUpdatePhrase++;
    if (iLcdUpdatePhrase > iLcdUpdatePhrases[iGameState]) {
      iLcdUpdatePhrase = 0;
    }
    switch (iGameState) {
      case 0: {
        LcdClearBoth();
        LcdPrintBoth(cIntroText[iLcdUpdatePhrase]);
      } break;
      
      
      case 1: {
      } break;
      
      
      case 2: {
      } break;
      
      
      case 3: {
      } break;
      
      
      case 4: {
      } break;
      
    }
  }
}
