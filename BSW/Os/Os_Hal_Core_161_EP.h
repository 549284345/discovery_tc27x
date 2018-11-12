/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2017 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**
 * \ingroup     Os_Hal
 * \addtogroup  Os_Hal_Core
 *
 * \{
 *
 * \file       Os_Hal_Core_161_EP.h
 * \brief		Primitives function implementation for TriCore Processor Core TC1.6P and TC1.6E
 *
 *********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os_Hal_Os.h.
 **********************************************************************************************************************/

#if !defined(OS_HAL_CORE_161_EP_H)
# define OS_HAL_CORE_161_EP_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Hal_Core_161_EPInt.h"

/* Os kernel module dependencies */

/* Os Hal dependencies */

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/
 
/***********************************************************************************************************************
 *  Os_Hal_CoreStart()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Hal_3219 */
Os_Hal_CoreStart,
(
  P2CONST(Os_Hal_CoreConfigType, AUTOMATIC, OS_CONST) Core
))
{
  /* #10 Write the foreign PC with the startup code symbol for core 1. */
  *((volatile uint32*)Core->ProgramCounterRegister) = (uint32)(Core->StartLabelAddress);                                /* PRQA S 0303 */ /* MD_Os_Hal_0303 */ /* SBSW_OS_HAL_PWA_CORECONFIG_PC */

  /* #20 Get the core out of the HALT state. */
  *((volatile uint32*)Core->DBGSRRegister) = OS_HAL_DBGSR_START_CORE;                                                   /* PRQA S 0303 */ /* MD_Os_Hal_0303 */ /* SBSW_OS_HAL_PWA_CORECONFIG_DBGSR */
}

/***********************************************************************************************************************
 *  Os_Hal_InitializeAccessDPRE()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Hal_3219 */
Os_Hal_InitializeAccessDPRE,
(
  CONST(uint32, AUTOMATIC) Value[OS_HAL_COREMPU_NUM_OF_PS]
))
{
  Os_Hal_Mtcr(OS_HAL_COREMPU_DPRE(0), Value[0]);
  Os_Hal_Mtcr(OS_HAL_COREMPU_DPRE(1), Value[1]);
  Os_Hal_Mtcr(OS_HAL_COREMPU_DPRE(2), Value[2]);
  Os_Hal_Mtcr(OS_HAL_COREMPU_DPRE(3), Value[3]);
}

/***********************************************************************************************************************
 *  Os_Hal_InitializeAccessDPWE()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Hal_3219 */
Os_Hal_InitializeAccessDPWE,
(
  CONST(uint32, AUTOMATIC) Value[OS_HAL_COREMPU_NUM_OF_PS]
))
{
  Os_Hal_Mtcr(OS_HAL_COREMPU_DPWE(0), Value[0]);
  Os_Hal_Mtcr(OS_HAL_COREMPU_DPWE(1), Value[1]);
  Os_Hal_Mtcr(OS_HAL_COREMPU_DPWE(2), Value[2]);
  Os_Hal_Mtcr(OS_HAL_COREMPU_DPWE(3), Value[3]);
}

/***********************************************************************************************************************
 *  Os_Hal_InitializeAccessCPXE()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Hal_3219 */
Os_Hal_InitializeAccessCPXE,
(
  CONST(uint32, AUTOMATIC) Value[OS_HAL_COREMPU_NUM_OF_PS]
))
{
  Os_Hal_Mtcr(OS_HAL_COREMPU_CPXE(0), Value[0]);
  Os_Hal_Mtcr(OS_HAL_COREMPU_CPXE(1), Value[1]);
  Os_Hal_Mtcr(OS_HAL_COREMPU_CPXE(2), Value[2]);
  Os_Hal_Mtcr(OS_HAL_COREMPU_CPXE(3), Value[3]);
}

/***********************************************************************************************************************
 *  Os_Hal_ReadModifyAccessDPRE()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Hal_3219 */
Os_Hal_ReadModifyAccessDPRE,
(
  CONST(uint8, AUTOMATIC) ProtectionSet,
  CONST(uint32, AUTOMATIC) Mask,
  CONST(uint32, AUTOMATIC) Value
))
{
  switch(ProtectionSet)
  {
    case 0:                                                                                                             /* COV_OS_UNSUPPORTED88830 */
      Os_Hal_Mtcr(OS_HAL_COREMPU_DPRE(0), (Os_Hal_Mfcr(OS_HAL_COREMPU_DPRE(0)) & ~(Mask)) | (Value));
      break;
    case 1:
      Os_Hal_Mtcr(OS_HAL_COREMPU_DPRE(1), (Os_Hal_Mfcr(OS_HAL_COREMPU_DPRE(1)) & ~(Mask)) | (Value));
      break;
    case 2:                                                                                                             /* COV_OS_HALCOREASSEMBLERINSTRUCTIONDATACASE */
      Os_Hal_Mtcr(OS_HAL_COREMPU_DPRE(2), (Os_Hal_Mfcr(OS_HAL_COREMPU_DPRE(2)) & ~(Mask)) | (Value));
      break;
    case 3:                                                                                                             /* COV_OS_HALCOREASSEMBLERINSTRUCTIONDATACASE */
      Os_Hal_Mtcr(OS_HAL_COREMPU_DPRE(3), (Os_Hal_Mfcr(OS_HAL_COREMPU_DPRE(3)) & ~(Mask)) | (Value));
      break;
    default:                                                                                                            /* COV_OS_INVSTATE */
      break;
  }
}

/***********************************************************************************************************************
 *  Os_Hal_ReadModifyAccessDPWE()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Hal_3219 */
Os_Hal_ReadModifyAccessDPWE,
(
  CONST(uint8, AUTOMATIC) ProtectionSet,
  CONST(uint32, AUTOMATIC) Mask,
  CONST(uint32, AUTOMATIC) Value
))
{
  switch(ProtectionSet)
  {
    case 0:                                                                                                             /* COV_OS_UNSUPPORTED88830 */
      Os_Hal_Mtcr(OS_HAL_COREMPU_DPWE(0), (Os_Hal_Mfcr(OS_HAL_COREMPU_DPWE(0)) & ~(Mask)) | (Value));
      break;
    case 1:
      Os_Hal_Mtcr(OS_HAL_COREMPU_DPWE(1), (Os_Hal_Mfcr(OS_HAL_COREMPU_DPWE(1)) & ~(Mask)) | (Value));
      break;
    case 2:                                                                                                             /* COV_OS_HALCOREASSEMBLERINSTRUCTIONDATACASE */
      Os_Hal_Mtcr(OS_HAL_COREMPU_DPWE(2), (Os_Hal_Mfcr(OS_HAL_COREMPU_DPWE(2)) & ~(Mask)) | (Value));
      break;
    case 3:                                                                                                             /* COV_OS_HALCOREASSEMBLERINSTRUCTIONDATACASE */
      Os_Hal_Mtcr(OS_HAL_COREMPU_DPWE(3), (Os_Hal_Mfcr(OS_HAL_COREMPU_DPWE(3)) & ~(Mask)) | (Value));
      break;
    default:                                                                                                            /* COV_OS_INVSTATE */
      break;
  }
}

/***********************************************************************************************************************
 *  Os_Hal_ReadModifyAccessCPXE()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* COV_OS_HALUNSUPPORTEDCODEREGIONS *//* PRQA S 3219 */ /* MD_Os_Hal_3219 */
Os_Hal_ReadModifyAccessCPXE,
(
  CONST(uint8, AUTOMATIC) ProtectionSet,
  CONST(uint32, AUTOMATIC) Mask,
  CONST(uint32, AUTOMATIC) Value
))
{
  switch(ProtectionSet)
  {
    case 0:
      Os_Hal_Mtcr(OS_HAL_COREMPU_CPXE(0), (Os_Hal_Mfcr(OS_HAL_COREMPU_CPXE(0)) & ~(Mask)) | (Value));
      break;
    case 1:
      Os_Hal_Mtcr(OS_HAL_COREMPU_CPXE(1), (Os_Hal_Mfcr(OS_HAL_COREMPU_CPXE(1)) & ~(Mask)) | (Value));
      break;
    case 2:
      Os_Hal_Mtcr(OS_HAL_COREMPU_CPXE(2), (Os_Hal_Mfcr(OS_HAL_COREMPU_CPXE(2)) & ~(Mask)) | (Value));
      break;
    case 3:
      Os_Hal_Mtcr(OS_HAL_COREMPU_CPXE(3), (Os_Hal_Mfcr(OS_HAL_COREMPU_CPXE(3)) & ~(Mask)) | (Value));
      break;
    default:
      break;
  }
}

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */  /* MD_MSR_19.1 */

#endif /* OS_HAL_CORE_161_EP_H */

/*!
 * \}
 */
/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_Core_161_EP.h
 *********************************************************************************************************************/
