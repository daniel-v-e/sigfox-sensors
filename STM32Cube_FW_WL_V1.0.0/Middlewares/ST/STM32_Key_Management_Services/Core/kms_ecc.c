/**
  ******************************************************************************
  * @file    kms_ecc.c
  * @author  MCD Application Team
  * @brief   This file contains utilities for the manipulation of elliptic curves
  *          of Key Management Services (KMS)
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "kms.h"                /* PKCS11 definitions */
#if defined(KMS_ENABLED)
#include "kms_der_x962.h"       /* KMS DER & X9.62 utilities */
#include "kms_objects.h"        /* KMS object management services */
#include "CryptoApi/ca.h"       /* Crypto API services */
#include "kms_ecc.h"            /* KMS ECC utilities */

/** @addtogroup Key_Management_Services Key Management Services (KMS)
  * @{
  */

/** @addtogroup KMS_ECC Elliptic curves utilities
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private function ----------------------------------------------------------*/
/* Exported variables --------------------------------------------------------*/
/* Exported functions --------------------------------------------------------*/

/** @addtogroup KMS_ECC_Exported_Functions Exported Functions
  * @{
  */
#if defined(KMS_ECDSA)
/**
  * @brief  Load the Elliptic Curve matching the CKA_EC_PARAMS
  * @note   CKA_EC_PARAMS is expected in DER format
  * @param  p_EC_Param CKA_EC_PARAMS to look for match
  * @param  p_EC_st Elliptic curve
  * @retval CKR_OK if found
  *         CKR_GENERAL_ERROR otherwise
  */
CK_RV KMS_ECC_LoadCurve(kms_attr_t *p_EC_Param, CA_EC_stt *p_EC_st)
{
  CK_RV e_ret_status = CKR_GENERAL_ERROR;
#if defined(KMS_EC_SECP192)
  static const uint8_t P_192_a[] = /* coefficient a */
  {
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC
  };
  static const uint8_t P_192_b[] = /* coefficient b */
  {
    0x64, 0x21, 0x05, 0x19, 0xE5, 0x9C, 0x80, 0xE7, 0x0F, 0xA7, 0xE9, 0xAB, 0x72,
    0x24, 0x30, 0x49, 0xFE, 0xB8, 0xDE, 0xEC, 0xC1, 0x46, 0xB9, 0xB1
  };
  static const uint8_t P_192_p[] = /* prime modulus p */
  {
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
  };
  static const uint8_t P_192_n[] = /* order n */
  {
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x99,
    0xDE, 0xF8, 0x36, 0x14, 0x6B, 0xC9, 0xB1, 0xB4, 0xD2, 0x28, 0x31
  };
  static const uint8_t P_192_Gx[] = /* base point Gx */
  {
    0x18, 0x8D, 0xA8, 0x0E, 0xB0, 0x30, 0x90, 0xF6, 0x7C, 0xBF, 0x20, 0xEB, 0x43,
    0xA1, 0x88, 0x00, 0xF4, 0xFF, 0x0A, 0xFD, 0x82, 0xFF, 0x10, 0x12
  };
  static const uint8_t P_192_Gy[] = /* base point Gy */
  {
    0x07, 0x19, 0x2B, 0x95, 0xFF, 0xC8, 0xDA, 0x78, 0x63, 0x10, 0x11, 0xED, 0x6B,
    0x24, 0xCD, 0xD5, 0x73, 0xF9, 0x77, 0xA1, 0x1E, 0x79, 0x48, 0x11
  };
#endif /* KMS_EC_SECP192 */

#if defined(KMS_EC_SECP256)
  static const uint8_t P_256_a[] = /* coefficient a */
  {
    0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC
  };
  static const uint8_t P_256_b[] = /* coefficient b */
  {
    0x5a, 0xc6, 0x35, 0xd8, 0xaa, 0x3a, 0x93, 0xe7, 0xb3, 0xeb, 0xbd, 0x55, 0x76,
    0x98, 0x86, 0xbc, 0x65, 0x1d, 0x06, 0xb0, 0xcc, 0x53, 0xb0, 0xf6, 0x3b, 0xce,
    0x3c, 0x3e, 0x27, 0xd2, 0x60, 0x4b
  };
  static const uint8_t P_256_p[] = /* prime modulus p */
  {
    0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
  };
  static const uint8_t P_256_n[] = /* order n */
  {
    0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xBC, 0xE6, 0xFA, 0xAD, 0xA7, 0x17, 0x9E, 0x84, 0xF3, 0xB9,
    0xCA, 0xC2, 0xFC, 0x63, 0x25, 0x51
  };
  static const uint8_t P_256_Gx[] = /* base point Gx */
  {
    0x6B, 0x17, 0xD1, 0xF2, 0xE1, 0x2C, 0x42, 0x47, 0xF8, 0xBC, 0xE6, 0xE5, 0x63,
    0xA4, 0x40, 0xF2, 0x77, 0x03, 0x7D, 0x81, 0x2D, 0xEB, 0x33, 0xA0, 0xF4, 0xA1,
    0x39, 0x45, 0xD8, 0x98, 0xC2, 0x96
  };
  static const uint8_t P_256_Gy[] = /* base point Gy */
  {
    0x4F, 0xE3, 0x42, 0xE2, 0xFE, 0x1A, 0x7F, 0x9B, 0x8E, 0xE7, 0xEB, 0x4A, 0x7C,
    0x0F, 0x9E, 0x16, 0x2B, 0xCE, 0x33, 0x57, 0x6B, 0x31, 0x5E, 0xCE, 0xCB, 0xB6,
    0x40, 0x68, 0x37, 0xBF, 0x51, 0xF5
  };
#endif /* KMS_EC_SECP256 */

#if defined(KMS_EC_SECP384)
  static const uint8_t P_384_a[] = /* coefficient a */
  {
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFC
  };
  static const uint8_t P_384_b[] = /* coefficient b */
  {
    0xb3, 0x31, 0x2f, 0xa7, 0xe2, 0x3e, 0xe7, 0xe4, 0x98, 0x8e, 0x05, 0x6b, 0xe3,
    0xf8, 0x2d, 0x19, 0x18, 0x1d, 0x9c, 0x6e, 0xfe, 0x81, 0x41, 0x12, 0x03, 0x14,
    0x08, 0x8f, 0x50, 0x13, 0x87, 0x5a, 0xc6, 0x56, 0x39, 0x8d, 0x8a, 0x2e, 0xd1,
    0x9d, 0x2a, 0x85, 0xc8, 0xed, 0xd3, 0xec, 0x2a, 0xef
  };
  static const uint8_t P_384_p[] = /* prime modulus p */
  {
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF
  };
  static const uint8_t P_384_n[] = /* order n */
  {
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xC7, 0x63,
    0x4D, 0x81, 0xF4, 0x37, 0x2D, 0xDF, 0x58, 0x1A, 0x0D, 0xB2, 0x48, 0xB0, 0xA7,
    0x7A, 0xEC, 0xEC, 0x19, 0x6A, 0xCC, 0xC5, 0x29, 0x73
  };
  static const uint8_t P_384_Gx[] = /* base point Gx */
  {
    0xAA, 0x87, 0xCA, 0x22, 0xBE, 0x8B, 0x05, 0x37, 0x8E, 0xB1, 0xC7, 0x1E, 0xF3,
    0x20, 0xAD, 0x74, 0x6E, 0x1D, 0x3B, 0x62, 0x8B, 0xA7, 0x9B, 0x98, 0x59, 0xF7,
    0x41, 0xE0, 0x82, 0x54, 0x2A, 0x38, 0x55, 0x02, 0xF2, 0x5D, 0xBF, 0x55, 0x29,
    0x6C, 0x3A, 0x54, 0x5E, 0x38, 0x72, 0x76, 0x0A, 0xB7
  };
  static const uint8_t P_384_Gy[] = /* base point Gy */
  {
    0x36, 0x17, 0xDE, 0x4A, 0x96, 0x26, 0x2C, 0x6F, 0x5D, 0x9E, 0x98, 0xBF, 0x92,
    0x92, 0xDC, 0x29, 0xF8, 0xF4, 0x1D, 0xBD, 0x28, 0x9A, 0x14, 0x7C, 0xE9, 0xDA,
    0x31, 0x13, 0xB5, 0xF0, 0xB8, 0xC0, 0x0A, 0x60, 0xB1, 0xCE, 0x1D, 0x7E, 0x81,
    0x9D, 0x7A, 0x43, 0x1D, 0x7C, 0x90, 0xEA, 0x0E, 0x5F
  };
#endif /* KMS_EC_SECP384 */

#if defined(KMS_EC_SECP192)
  /* SECP192R1 curve OID */
  static const uint8_t ref_secp192r1[] = {0x06, 0x08, 0x2a, 0x86, 0x48, 0xce, 0x3d, 0x03, 0x01, 0x01};
#endif /* KMS_EC_SECP192 */
#if defined(KMS_EC_SECP256)
  /* SECP256R1 curve OID */
  static const uint8_t ref_secp256r1[] = {0x06, 0x08, 0x2a, 0x86, 0x48, 0xce, 0x3d, 0x03, 0x01, 0x07};
#endif /* KMS_EC_SECP256 */
#if defined(KMS_EC_SECP384)
  /* SECP384R1 curve OID */
  static const uint8_t ref_secp384r1[] = {0x06, 0x05, 0x2b, 0x81, 0x04, 0x00, 0x22};
#endif /* KMS_EC_SECP384 */

  if ((p_EC_Param != NULL) && (p_EC_Param->size > 0UL) && (p_EC_st != NULL))
  {
    uint8_t   u8ParamAttrib[32];

    /* Read value from the structure. Need to be translated from
    (uint32_t*) to (uint8_t *) */
    KMS_Objects_BlobU32_2_u8ptr(&(p_EC_Param->data[0]), p_EC_Param->size, u8ParamAttrib);

    /* CKA_EC_PARAMS is DER encoded OIDs for EC supported curves
           secp192r1 = '06082a8648ce3d030101'x          {1 2 840 10045 3 1 1}
           secp256r1 = '06082a8648ce3d030107'x          {1 2 840 10045 3 1 7}
           secp384r1 = '06052b81040022'x                {1 3 132 0 34}        */

#if defined(KMS_EC_SECP192)
    /* secp192r1 */
    if (memcmp(u8ParamAttrib, ref_secp192r1, p_EC_Param->size) == 0)
    {
      p_EC_st->pmA = P_192_a;
      p_EC_st->pmB = P_192_b;
      p_EC_st->pmP = P_192_p;
      p_EC_st->pmN = P_192_n;
      p_EC_st->pmGx = P_192_Gx;
      p_EC_st->pmGy = P_192_Gy;
      p_EC_st->mAsize = (int32_t)sizeof(P_192_a);
      p_EC_st->mBsize = (int32_t)sizeof(P_192_b);
      p_EC_st->mNsize = (int32_t)sizeof(P_192_n);
      p_EC_st->mPsize = (int32_t)sizeof(P_192_p);
      p_EC_st->mGxsize = (int32_t)sizeof(P_192_Gx);
      p_EC_st->mGysize = (int32_t)sizeof(P_192_Gy);
      e_ret_status = CKR_OK;
    }
#endif /* KMS_EC_SECP192 */
#if defined(KMS_EC_SECP256)
    /* secp256r1 */
    if (memcmp(u8ParamAttrib, ref_secp256r1, p_EC_Param->size) == 0)
    {
      p_EC_st->pmA = P_256_a;
      p_EC_st->pmB = P_256_b;
      p_EC_st->pmP = P_256_p;
      p_EC_st->pmN = P_256_n;
      p_EC_st->pmGx = P_256_Gx;
      p_EC_st->pmGy = P_256_Gy;
      p_EC_st->mAsize = (int32_t)sizeof(P_256_a);
      p_EC_st->mBsize = (int32_t)sizeof(P_256_b);
      p_EC_st->mNsize = (int32_t)sizeof(P_256_n);
      p_EC_st->mPsize = (int32_t)sizeof(P_256_p);
      p_EC_st->mGxsize = (int32_t)sizeof(P_256_Gx);
      p_EC_st->mGysize = (int32_t)sizeof(P_256_Gy);
      e_ret_status = CKR_OK;
    }
#endif /* KMS_EC_SECP256 */
#if defined(KMS_EC_SECP384)
    /* secp384r1 */
    if (memcmp(u8ParamAttrib, ref_secp384r1, p_EC_Param->size) == 0)
    {
      p_EC_st->pmA = P_384_a;
      p_EC_st->pmB = P_384_b;
      p_EC_st->pmP = P_384_p;
      p_EC_st->pmN = P_384_n;
      p_EC_st->pmGx = P_384_Gx;
      p_EC_st->pmGy = P_384_Gy;
      p_EC_st->mAsize = (int32_t)sizeof(P_384_a);
      p_EC_st->mBsize = (int32_t)sizeof(P_384_b);
      p_EC_st->mNsize = (int32_t)sizeof(P_384_n);
      p_EC_st->mPsize = (int32_t)sizeof(P_384_p);
      p_EC_st->mGxsize = (int32_t)sizeof(P_384_Gx);
      p_EC_st->mGysize = (int32_t)sizeof(P_384_Gy);
      e_ret_status = CKR_OK;
    }
#endif /* KMS_EC_SECP384 */
  }
  return e_ret_status;
}
#endif /* KMS_ECDSA */

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

#endif /* KMS_ENABLED */
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
