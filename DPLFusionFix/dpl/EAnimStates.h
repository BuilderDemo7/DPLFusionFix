#pragma once

enum EnumAnimCondition {
	eACond_Undef = -2,
	eACond_Bad = -1,
	eACond_Invalid = -1,
	eACond_None = 0,
	eACond_Default = 1,
	eACond_Floor = 1,
	eACond_Crouch = 2,
	eACond_Jumping = 3,
	eACond_Sitting = 4,
	eACond_Frozen = 5,
	eACond_End = 6
};

typedef enum eAnimState {
	eAState_Undef = -2,
	eAState_Bad = -1,
	eAState_Invalid = -1,
	eAState_None = 0,
	eAState_Default = 1,
	eAState_Idle = 1,
	eAState_Drive = 2,
	eAState_Dead = 3,
	eAState_End = 4
};