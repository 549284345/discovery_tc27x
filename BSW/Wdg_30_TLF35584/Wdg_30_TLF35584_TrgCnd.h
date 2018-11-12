/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2016 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!        \file  Wdg_30_TLF35584_TrgCnd.h
 *        \brief  Header file of submodule Wdg_30_TLF35584_TrgCnd
 *
 *      \details  This sub-component manages the trigger condition of the watchdog module.
 *                This is an internal include file - it shall not be included by other modules than Wdg_30_TLF35584.
 *
 *********************************************************************************************************************/

#if !(defined WDG_30_TLF35584_TRGCND_H)
#define WDG_30_TLF35584_TRGCND_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Wdg_30_TLF35584_Cfg.h"
#include "Wdg_30_TLF35584_LL.h"

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define WDG_30_TLF35584_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Wdg_30_TLF35584_TrgCnd_CheckCondition()
 *********************************************************************************************************************/
/*! \brief       This function is used to check if trigger condition is valid.
 *  \pre         -
 *  \return      TRUE if trigger condition is valid
 *               FALSE if trigger condition is invalid
 *  \context     ANY
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \details     This function returns the value of the sub-component local condition flag.
 *  \trace       CREQ-105561, CREQ-105563, DSGN-Wdg22900, DSGN-Wdg22903
 *********************************************************************************************************************/
FUNC(boolean, WDG_30_TLF35584_CODE) Wdg_30_TLF35584_TrgCnd_CheckCondition(void);


/**********************************************************************************************************************
 * Wdg_30_TLF35584_TrgCnd_SetCondition()
 *********************************************************************************************************************/
/*! \anchor      Wdg_30_TLF35584_TrgCnd_SetCondition
 *  \brief       Function to set trigger condition.
 *  \pre         -
 *  \param[in]   timeout       Duration of timeout period in milliseconds
 *  \param[in]   targetMode    Mode for which the trigger condition should be set
 *  \context     ANY
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \details     This function is used to set the trigger condition according to the passed parameters.
 *  \trace       CREQ-105561, DSGN-Wdg22900
 *********************************************************************************************************************/
FUNC(void, WDG_30_TLF35584_CODE) Wdg_30_TLF35584_TrgCnd_SetCondition(uint16 timeout, WdgIf_ModeType targetMode);


/**********************************************************************************************************************
 * Wdg_30_TLF35584_TrgCnd_ResetCondition()
 *********************************************************************************************************************/
/*! \anchor      Wdg_30_TLF35584_TrgCnd_ResetCondition
 *  \brief       Function to set reset the trigger condition
 *  \pre         -
 *  \config      WDG_30_TLF35584_IS_MODE_SUPPORTED(WDG_30_TLF35584_MODE_OFF) && WDG_30_TLF35584_DISABLE_ALLOWED == STD_ON
 *  \context     ANY
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \details     This function is used to reset the trigger condition. This is necessary if the mode is changed to
 *               WDGIF_OFF_MODE.
 *  \trace       CREQ-105561, DSGN-Wdg22900, DSGN-Wdg22902
 *********************************************************************************************************************/

#if(WDG_30_TLF35584_IS_MODE_SUPPORTED(WDG_30_TLF35584_MODE_OFF) && WDG_30_TLF35584_DISABLE_ALLOWED == STD_ON)
FUNC(void, WDG_30_TLF35584_CODE) Wdg_30_TLF35584_TrgCnd_ResetCondition(void);
#endif

#define WDG_30_TLF35584_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#endif /* WDG_30_TLF35584_TRGCND_H */

/**********************************************************************************************************************
 *  END OF FILE: Wdg_30_TLF35584_TrgCnd.h
 *********************************************************************************************************************/
