#include "gp_timer.h"
#include "SDK_EVAL_Config.h"
#include "S2LP_AUX_EEPROM.h"
#include "S2LP_AUX_Utils.h"
#include "SDK_UTILS_Config.h"
#include "S2LP_Middleware_Config.h"

#define USE_VCOM

/**
* @brief  System main initialization.
* @param  None
* @retval 0 if OK
*/
int ST_Init(void);

/**
* @brief  PUSH BUTTON initialization.
* @param  None
* @retval 1 if PUSH BUTTON is pressed while init
*/
uint8_t ButtonInit(void);

/**
* @brief  PUSH BUTTON IRQ initialization.
* @param  None
* @retval None
*/
void ButtonSetIRQ(void);

/**
* @brief  Returns the state of the PUSH BUTTON
* @param  None
* @retval 1 if button is pressed
*/
uint8_t IsButtonPressed(void);

/**
* @brief  Returns the PA type based on the value defined by the user
* @param  None
* @retval The PA type
*/
RangeExtType DetetctPA(void);