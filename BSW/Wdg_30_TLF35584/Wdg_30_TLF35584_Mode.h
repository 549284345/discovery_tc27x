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
/*!        \file  Wdg_30_TLF35584_Mode.h
 *        \brief  Header file of Wdg_30_TLF35584_Mode
 *
 *      \details  This sub-component provides mode-specific services to other sub-component.
 *                This is an internal include file - it shall not be included by other modules than Wdg_30_TLF35584.
 *
 *********************************************************************************************************************/

#if !(defined WDG_30_TLF35584_MODE_H)
#define WDG_30_TLF35584_MODE_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Wdg_30_TLF35584_Cfg.h"
#include "Wdg_30_TLF35584_LL.h"

 /*********************************************************************************************************************
 * FUNCTION MACROS
 *********************************************************************************************************************/
/* PRQA S 3453 1 */ /* MD_MSR_19.7 */
#define Wdg_30_TLF35584_Mode_IsModeAllowed(modeIdx) ((boolean)(((WDG_30_TLF35584_SUPPORTED_MODES) >> ((uint8)(modeIdx))) & (0x1)))

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define WDG_30_TLF35584_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Wdg_30_TLF35584_Mode_GetMode()
 *********************************************************************************************************************/
/*! \anchor      Wdg_30_TLF35584_Mode_GetMode
 *  \brief       Function returns the current watchdog mode
 *  \pre         -
 *  \return      Current mode of the of the watchdog
 *  \context     ANY
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \details     The function returns the current mode of the module. Depending on the configuration this could be:\n
 *               -WDGIF_OFF_MODE
 *               -WDGIF_SLOW_MODE
 *               -WDGIF_FAST_MODE
 *  \trace       CREQ-105560, DSGN-Wdg22902
 *********************************************************************************************************************/
FUNC(WdgIf_ModeType, WDG_30_TLF35584_CODE) Wdg_30_TLF35584_Mode_GetMode(void);

/**********************************************************************************************************************
 * Wdg_30_TLF35584_Mode_SetMode()
 *********************************************************************************************************************/
/*! \anchor      Wdg_30_TLF35584_Mode_SetMode
 *  \brief       This function coordinates a mode change
 *  \pre         -
 *  \param[in]   Mode   Valid mode to which the watchdog shall switch.
 *  \return      E_OK on success
 *               E_NOT_OK otherwise
 *  \context     ANY
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \details     This function sets the watchdog hardware to the correct mode and resets the timing setup (which
 *               includes watchdog triggering and trigger condition) properly.
 *  \trace       CREQ-105560, DSGN-Wdg22902, DSGN-Wdg22983
 *********************************************************************************************************************/
FUNC(Std_ReturnType, WDG_30_TLF35584_CODE) Wdg_30_TLF35584_Mode_SetMode(WdgIf_ModeType Mode);


#define WDG_30_TLF35584_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#endif /* WDG_30_TLF35584_MODE_H */

/**********************************************************************************************************************
 *  END OF FILE: Wdg_30_TLF35584_Mode.h
 *********************************************************************************************************************/
