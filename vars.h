#define WIZFIRE 1
#define WIZLITNG 2
#define WIZWATER 3
#define SPELLFIR 1
#define SPELLLIT 2
#define SPELLWATR 3
#define SPELLBLK 4
#define P1 0
#define P2 1

bool
  bDebugMode = true,
  bStateStart = true,
  bStateUpdate = false,
  bStateEnd = false,

  bButtonsPressed[2][4],
  bButtonPressed = false
;

uint8_t
  iGameState,
  iGameStateTimeout = 0,

  iPlayerWizType[2],
  iPlayerTempWizType[2],
  iPlayerHealth[2],
  
  iPlayerSpellType[2],
  iPlayerTempSpellType[2],
  iPlayerSpellStrength[2],
  
  iDebounceTimeout = 10,
  
  iChallengeLastType = 2,
  iChallengeType = 0,
  
  iTestTargetButton[2],
  iTestTargetLastButton[2] = {4, 4}
;

uint16_t
  iLcdUpdateTimeout = 500,
  iLcdUpdate2Timeout = 1000,
  
  iSpellTestTimeout = 10000,
  iSpellTestEventTimeout[2] = {1000, 1000},
  iTestScore[2],
  iTestGrade[4][4] = {
    //Spin cycle
    {100, 50, 25, 10},
    //Button mash
    {20, 40, 60, 80},
    //Simon says
    {3, 5, 6, 7},
    //Gopher hunt
    {5, 10, 17, 25}
  }
;

elapsedMillis
  mGameState,
  mLcdUpdate,
  mLcdUpdate2,
  mSpellTest,
  mSpellTestEvent[2]
;
