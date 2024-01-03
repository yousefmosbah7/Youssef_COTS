#include "STD_TYPES.h"
#include "REMAPPING.h"

sint32 MAP(sint32 Copy_s32InputMin,sint32 Copy_s32InputMax,sint32 Copy_s32OutputMin,sint32 Copy_s32OutputMax,sint32 Copy_s32InputVal)
{
	sint32 Local_s32OutputVal;
	
	Local_s32OutputVal = (Copy_s32OutputMax*(Copy_s32InputMax - Copy_s32InputVal)) / Copy_s32InputMax;
	
	return Local_s32OutputVal;
}
