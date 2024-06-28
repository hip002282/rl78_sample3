/*******************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only
* intended for use with Renesas products. No other uses are authorized. This
* software is owned by Renesas Electronics Corporation and is protected under
* all applicable laws, including copyright laws.
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING
* THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT
* LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE
* AND NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.
* TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS
* ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE
* FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR
* ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE
* BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software
* and to discontinue the availability of this software. By using this software,
* you agree to the additional terms and conditions found by accessing the
* following link:
* http://www.renesas.com/disclaimer
*
* Copyright (C) 2016 Renesas Electronics Corporation. All rights reserved.
*******************************************************************************/

/*******************************************************************************
* File Name    : meck.c
* Description  : This file implements main function.
* Creation Date: 2024/06/27
*******************************************************************************/

/*******************************************************************************
Includes <System Includes> , "Project Includes"
*******************************************************************************/
#include "sfr.h"
#include "common.h"
#include "config.h"
#include "meck.h"

/*******************************************************************************
Macro definitions
*******************************************************************************/

/*******************************************************************************
Typedef definitions
*******************************************************************************/

/*******************************************************************************
Imported global variables and functions (from other files)
*******************************************************************************/

/*******************************************************************************
Exported global variables and functions (to be accessed by other files)
*******************************************************************************/
UCHAR CALCULATE_JUDGE_PATTERN( UCHAR digit0, UCHAR digit1, UCHAR digit2, UCHAR digit3, 
			UCHAR digit4, UCHAR digit5, UCHAR digit6, UCHAR digit7 )
{
	UCHAR judge_patn = 0x00;
	
	judge_patn += (~(digit0 & digit4)) & 0x01;
	judge_patn <<= 1;
	judge_patn += (~(digit1 & digit5)) & 0x01;
	judge_patn <<= 1;
	judge_patn += (~(digit2 & digit6)) & 0x01;
	judge_patn <<= 1;
	judge_patn += (~(digit3 & digit7)) & 0x01;
	
	return judge_patn;
}

/*******************************************************************************
Private variables and functions
*******************************************************************************/