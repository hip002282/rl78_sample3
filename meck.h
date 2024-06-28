/*******************************************************************************
* File Name    : meck.h
* Description  : This file implements main function.
* Creation Date: 2024/06/17
*******************************************************************************/

#ifndef _MECK_H_
#define _MECK_H_
/*******************************************************************************
Exported global variables and functions (to be accessed by other files)
*******************************************************************************/
/*	Function Prototype	*/
// void	panel_init0( void );
// void	panel( void );

/*******************************************************************************
Includes <System Includes> , "Project Includes"
*******************************************************************************/
#define CONFIGURE_OUTPUTS(a_in, b_in, c_in, d_in, e_in, f_in, g_in, 								\
							h_in, a_out, b_out, c_out)						\
{																\
	UCHAR ucret = CALCULATE_JUDGE_PATTERN(a_in, b_in, c_in, d_in, e_in, f_in, g_in, h_in);					\
	switch (ucret & 0x0f) {													\
		case 0x01:														\
			a_out = 0x00;													\
			b_out = 0x00;													\
			c_out = 0x01;													\
			break;														\
		case 0x02:														\
			a_out = 0x00;													\
			b_out = 0x01;													\
			c_out = 0x00;													\
			break;														\
		case 0x04:														\
			a_out = 0x01;													\
			b_out = 0x00;													\
			c_out = 0x00;													\
			break;														\
		case 0x08:														\
			a_out = 0x00;													\
			b_out = 0x00;													\
			c_out = 0x00;													\
			break;														\
		default:														\
			break;														\
	}															\
}

/*******************************************************************************
Typedef definitions
*******************************************************************************/

/*******************************************************************************
Imported global variables and functions (from other files)
*******************************************************************************/

/*******************************************************************************
Exported global variables and functions (to be accessed by other files)
*******************************************************************************/
/*	Function Prototype	*/
UCHAR CALCULATE_JUDGE_PATTERN( UCHAR digit0, UCHAR digit1, UCHAR digit2, UCHAR digit3, 
			UCHAR digit4, UCHAR digit5, UCHAR digit6, UCHAR digit7 );

#endif /*_MECK_H_*/