#include <stdio.h>
#include "Vehicle.h"
#include "..\core\Matrix.h"
#include "VehicleModel.h"

#define MAT_MAIN_OFF1 0x15C // Used for cars
#define MAT_MAIN_OFF2 0x54  // Used for bikes
#define MAT_POS_OFF  0x80
#define MAT_VEL_OFF  0x90
#define MAT_DIR_OFF  0xA0
#define MAT_AVEL_OFF 0xC0 

#define THROTTLE_OFF1  0x188 // found in cars, unsure for bikes and other types 
#define RWHEEL_LOOKUP_OFF1 0x2E8 // found in cars, unsure for bikes and other types 
#define BURNOUT_OFF1   0x32C // found in cars, unsure for bikes and other types 
#define PHYSICS_STATE_OFF1   0x33C // found in cars, unsure for bikes and other types 
#define REVERSING_OFF1 0x336 // found in cars, unsure for bikes and other types 

/*
CVehicle::CVehicle()
{
}


CVehicle::~CVehicle()
{
}
*/


#define MAT_MAIN_OFF MAT_MAIN_OFF1

CVehicle* CVehicle::GetPartnerVehicle()
{
	CVehicle* veh = *(CVehicle**)((int)this + 0x30);
	if (GetVehicleHandlingType() != Invalid)
	{
		if (veh != NULL)
		    return veh;
	}
	return NULL;
}

CVehicle* CVehicle::GetVehiclePointer()
{
	CVehicle* veh = *(CVehicle**)((int)this + 0x2C);
	if (this->IsValid())
	{
		if (veh != NULL)
			return veh;
		else
			return this;
	}
	return NULL;
}

VehicleHandlingType CVehicle::GetVehicleHandlingType()
{
	if (this->GetPointer() == NULL)
		return Invalid;

	int handling = *(int*)(this->GetPointer() + 0x2C);
	int vehicle_vtable = *(int*)(this->GetPointer());

	if (vehicle_vtable == 0x6522F8)
		return TowTruck;

	if (vehicle_vtable != 0x653170)
		return Invalid;

	int vtable = *(int*)(handling);
	switch (vtable) {
	case 0x652970:
	{
		return Car;
	}
	case 0x652780:
	{
		return Bike;
	}
	// TODO: implement tow truck and truck detection
	default:
		return Invalid;
	}
}

// *shrugs*
int GetMatrixBaseAddress(CVehicle* veh)
{
	/*
	CVehicle* vehPtr = NULL;
	switch (veh->GetVehicleHandlingType())
	{
	default:
		vehPtr = veh;
		break;
	case Truck:
	case TowTruck:
	case Tank:
		vehPtr = veh->GetVehiclePointer();
		break;
	}
	*/
	int addr1 = *(int*)((int)(veh->GetPointer()) + 0x2C); // m_piQueryHandling 
	int off = 0;
	switch (veh->GetVehicleHandlingType())
	{
	case Car:
		off = MAT_MAIN_OFF;
		break;
	case Bike:
		off = MAT_MAIN_OFF2;
		break;
	}
		int addr2 = *(int*)(addr1 + off);
	return addr2;
}

// 0x5AE587
void CVehicle::GetPosition(Vector4* pos)
{
	//((void(__thiscall*)(CVehicle*, Vector4*))0x5AE520)(this, pos); // 0x5AD71E
	//printf("%.3f, %.3f, %.3f\n", pos->X, pos->Y, pos->Z);
	// deprecated for trucks and other vehicles
	Vector4* ptrVec = (Vector4*)(GetMatrixBaseAddress(this) + MAT_POS_OFF);
	pos->X = ptrVec->X;
	pos->Y = ptrVec->Y;
	pos->Z = ptrVec->Z;
	//return Vector4(ptrVec->X,ptrVec->Y,ptrVec->Z,ptrVec->W);
}

void CVehicle::SetPosition(Vector4 pos)
{
	Vector4* ptrVec = (Vector4*)(GetMatrixBaseAddress(this) + MAT_POS_OFF);
	ptrVec->X = pos.X;
	ptrVec->Y = pos.Y;
	ptrVec->Z = pos.Z;
	ptrVec->W = pos.W;
}

void CVehicle::SetPosition(Vector4* pos)
{
	Vector4* ptrVec = (Vector4*)(GetMatrixBaseAddress(this) + MAT_POS_OFF);
	ptrVec->X = pos->X;
	ptrVec->Y = pos->Y;
	ptrVec->Z = pos->Z;
	ptrVec->W = pos->W;
}

void CVehicle::SetPosition(Vector pos)
{
	Vector4* ptrVec = (Vector4*)(GetMatrixBaseAddress(this) + MAT_POS_OFF);
	ptrVec->X = pos.X;
	ptrVec->Y = pos.Y;
	ptrVec->Z = pos.Z;
}

void CVehicle::SetPosition(Vector* pos)
{
	Vector4* ptrVec = (Vector4*)(GetMatrixBaseAddress(this) + MAT_POS_OFF);
	ptrVec->X = pos->X;
	ptrVec->Y = pos->Y;
	ptrVec->Z = pos->Z;
}

// *Deprecated, do not use
Vector4 CVehicle::GetRPM()
{
	Vector4* ptrVec = (Vector4*)(GetMatrixBaseAddress(this) + 0x70);
	return Vector4(ptrVec->X, ptrVec->Y, ptrVec->Z, ptrVec->W);
}

Vector4 CVehicle::GetVelocity()
{
	Vector4* ptrVec = (Vector4*)(GetMatrixBaseAddress(this) + MAT_VEL_OFF);
	return Vector4(ptrVec->X, ptrVec->Y, ptrVec->Z, ptrVec->W);
}

void CVehicle::SetVelocity(Vector4 pos)
{
	Vector4* ptrVec = (Vector4*)(GetMatrixBaseAddress(this) + MAT_VEL_OFF);
	ptrVec->X = pos.X;
	ptrVec->Y = pos.Y;
	ptrVec->Z = pos.Z;
	ptrVec->W = pos.W;
}

void CVehicle::SetVelocity(Vector4* pos)
{
	Vector4* ptrVec = (Vector4*)(GetMatrixBaseAddress(this) + MAT_VEL_OFF);
	ptrVec->X = pos->X;
	ptrVec->Y = pos->Y;
	ptrVec->Z = pos->Z;
	ptrVec->W = pos->W;
}

void CVehicle::SetVelocity(Vector pos)
{
	Vector4* ptrVec = (Vector4*)(GetMatrixBaseAddress(this) + MAT_VEL_OFF);
	ptrVec->X = pos.X;
	ptrVec->Y = pos.Y;
	ptrVec->Z = pos.Z;
}

void CVehicle::SetVelocity(Vector* pos)
{
	Vector4* ptrVec = (Vector4*)(GetMatrixBaseAddress(this) + MAT_VEL_OFF);
	ptrVec->X = pos->X;
	ptrVec->Y = pos->Y;
	ptrVec->Z = pos->Z;
}

// Flip formula: Vector(0, X, 0, X)

// The forward vector of the vehicle that defines the rotation
Vector4 CVehicle::GetDirection()
{
	Vector4* ptrVec = (Vector4*)(GetMatrixBaseAddress(this) + MAT_DIR_OFF);
	return Vector4(ptrVec->X, ptrVec->Y, ptrVec->Z, ptrVec->W);
}

void CVehicle::SetDirection(Vector4 pos)
{
	Vector4* ptrVec = (Vector4*)(GetMatrixBaseAddress(this) + MAT_DIR_OFF);
	ptrVec->X = pos.X;
	ptrVec->Y = pos.Y;
	ptrVec->Z = pos.Z;
	ptrVec->W = pos.W;
}

void CVehicle::SetDirection(Vector4* pos)
{
	Vector4* ptrVec = (Vector4*)(GetMatrixBaseAddress(this) + MAT_DIR_OFF);
	ptrVec->X = pos->X;
	ptrVec->Y = pos->Y;
	ptrVec->Z = pos->Z;
	ptrVec->W = pos->W;
}

void CVehicle::SetDirection(Vector pos)
{
	Vector4* ptrVec = (Vector4*)(GetMatrixBaseAddress(this) + MAT_DIR_OFF);
	ptrVec->X = pos.X;
	ptrVec->Y = pos.Y;
	ptrVec->Z = pos.Z;
}

void CVehicle::SetDirection(Vector* pos)
{
	Vector4* ptrVec = (Vector4*)(GetMatrixBaseAddress(this) + MAT_DIR_OFF);
	ptrVec->X = pos->X;
	ptrVec->Y = pos->Y;
	ptrVec->Z = pos->Z;
}

Vector4 CVehicle::GetAngularVelocity()
{
	Vector4* ptrVec = (Vector4*)(GetMatrixBaseAddress(this) + MAT_AVEL_OFF);
	return Vector4(ptrVec->X, ptrVec->Y, ptrVec->Z, ptrVec->W);
}

void CVehicle::SetAngularVelocity(Vector4 pos)
{
	Vector4* ptrVec = (Vector4*)(GetMatrixBaseAddress(this) + MAT_AVEL_OFF);
	ptrVec->X = pos.X;
	ptrVec->Y = pos.Y;
	ptrVec->Z = pos.Z;
	ptrVec->W = pos.W;
}

void CVehicle::SetAngularVelocity(Vector4* pos)
{
	Vector4* ptrVec = (Vector4*)(GetMatrixBaseAddress(this) + MAT_AVEL_OFF);
	ptrVec->X = pos->X;
	ptrVec->Y = pos->Y;
	ptrVec->Z = pos->Z;
	ptrVec->W = pos->W;
}

void CVehicle::SetAngularVelocity(Vector pos)
{
	Vector4* ptrVec = (Vector4*)(GetMatrixBaseAddress(this) + MAT_AVEL_OFF);
	ptrVec->X = pos.X;
	ptrVec->Y = pos.Y;
	ptrVec->Z = pos.Z;
}

void CVehicle::SetAngularVelocity(Vector* pos)
{
	Vector4* ptrVec = (Vector4*)(GetMatrixBaseAddress(this) + MAT_AVEL_OFF);
	ptrVec->X = pos->X;
	ptrVec->Y = pos->Y;
	ptrVec->Z = pos->Z;
}

// With read-only values
Matrix* CVehicle::GetMatrix(Matrix* mat)
{
#ifndef PROPER_MATRIX
	return (Matrix*)((*(int*)(this->GetPointer() + 0x2C)) + 0x20);
#else
	return ((Matrix*(__thiscall*)(CVehicle*, Matrix*))*(int*)(GetHandlingVTableAddress() + 8))(this, mat); // 0x58bd65 for cars
#endif
}

void CVehicle::SetColor(float R, float G, float B)
{
	*(float*)(this->GetPointer() + 140) = R;
	*(float*)(this->GetPointer() + 144) = G;
	*(float*)(this->GetPointer() + 148) = B;
}

Vector CVehicle::GetColor()
{
	return Vector(
		*(float*)(this->GetPointer() + 140),
	    *(float*)(this->GetPointer() + 144),
	    *(float*)(this->GetPointer() + 148));
}

static int gInvalidVehicleType = 201;

// from the pointer of the AWHF of this vehicle chunk loaded in memory
#ifndef _OLD_TIMES_GETVTYPE 
int 
#else
int*
#endif
CVehicle::GetVehicleType() 
{
	//return (int*) ( ( *(int*)(this->GetPointer()+ 0x70) ) - 0x11EC );
	//int ptr = (*(int*)(this->GetPointer()+ 0x70));
#ifdef _OLD_TIMES_GETVTYPE
////	int hierachy = *(int*)(this->GetPointer() + 0x40);
////	/*while*/ if (hierachy == NULL)
////	{
////		//hierachy = *(int*)(this->GetPointer() + 0x40);
////		return 0;
////	}
////#ifdef _DEBUG
////		//printf("0x%p -> Vehicle Hierachy of 0x%p\n", hierachy, this);
////#endif
////	return (int*)(hierachy + 0x14);
	int specification = *(int*)(this->GetPointer() + 0x30);
	if (specification == NULL)
		GetVehicleType_RETURN_INVALID_VEHICLE_TYPE:
		return (int*)gInvalidVehicleType;
	int hierarchyHeader = *(int*)(specification + 0xC);
	if (hierarchyHeader == NULL)
		goto GetVehicleType_RETURN_INVALID_VEHICLE_TYPE;

	return (int*)(hierarchyHeader + 0x14);
	//return reinterpret_cast<int>(&ptr-0x11EC);
	//return (int*)((this + 0x70) - 0x11EC);
#else
	int tVar1; 
	tVar1 = 201; // tVehicleModelUID_Invalid=201
	if (&this->m_piSpecification != NULL)
	{
		if (this->m_piSpecification.m_pPointer != NULL)
		{
			IVehicleSpecificationInternal* spec = this->m_piSpecification.m_pPointer;
			if (spec != NULL)
			{
				if (spec->m_pHeader != NULL) {
					tVar1 = spec->m_pHeader->m_nVehicleType;
				}
			}
		}
	}

	return tVar1;
#endif
}

tVehicleModelUID* CVehicle::GetVehicleUID() 
{
	return (tVehicleModelUID*)(this->GetVehicleType());
}

void CVehicle::SetDriver(CCharacter* pDriver, bool unk)
{
	((void(__thiscall*)(CVehicle*, CCharacter*, bool))0x5AF036)(this,pDriver, unk);
}

CCharacter* CVehicle::GetDriver()
{
	return *(CCharacter**)((int)this + 0x4E4);
}

CCharacter* CVehicle::GetPassenger()
{
	CCharacter* passenger = *(CCharacter**)((int*)(this + 0x5C0));
	if (*(int*)(this->GetPointer()+ 0x5C0) != 0)
		return passenger;
	else
		return NULL;
}

bool CVehicle::BeingDrived()
{
	return (this->GetDriver() != 0);
}

float CVehicle::GetSpeed()
{
	return ((float (__cdecl*)())0x5AD71E)();
}

// Temp
/*
Vector4* CVehicle::GetVelocity()
{
	return ((Vector4* (__cdecl*)())0x5AE55F)();
}
*/

// with this you can make the car drive
void CVehicle::SendManipulationPacket(SVehicleManipulationPacket* rPacket)
{
	((void(__thiscall*)(CVehicle*, SVehicleManipulationPacket*))*(int*)(GetVTableAddress() + 4))(this, rPacket);
}

void CVehicle::ActivateLamp(ePartSubType type, bool onoff, bool over)
{
	((void(__thiscall*)(CVehicle*, ePartSubType, bool, bool))*(int*)(GetVTableAddress() + 0xDC))(this, type, onoff, over);
}

void CVehicle::SendManipulationPacketInternal(SVehicleManipulationPacket* rPacket)
{
	((void(__thiscall*)(CVehicle*, SVehicleManipulationPacket*))0x59E79A)(this, rPacket);
}

void CVehicle::RestoreDamage()
{
	((void(__thiscall*)(CVehicle*))0x5AF35E)(this);
}

void CVehicle::ResetDamage()
{
	((void(__thiscall*)(CVehicle*))0x5AD2A8)(this);
}

void CVehicle::Step() // update motion?
{
	((void(__thiscall*)(CVehicle*))0x5A9C38)(this);
}

void CVehicle::PostPhysicsStep() // basically, update it's physics in general
{
	((void(__thiscall*)(CVehicle*))0x5A4833)(this);
}

void CVehicle::Draw()
{
	((void(__thiscall*)(CVehicle*))0x5A2F62)(this);
}

void CVehicle::SetPhysicsState(int physicsState)
{
	((void(__thiscall*)(CVehicle*, int))0x5AEB2D)(this, physicsState);
}

bool CVehicle::GetDrawVirtualShadow()
{
	return *(bool*)(this + 0x461);
}

void CVehicle::SetDrawVirtualShadow(bool draw)
{
	*(bool*)(this + 0x461) = draw;
}

sDamageWheelHolder* CVehicle::GetWheelsDamage()
{
	return (sDamageWheelHolder*)(this + 0x464);
}

sEngineDamage* CVehicle::GetEngineDamageSection()
{
	return (sEngineDamage*)(this + 0x4C8);
}

cDamageSectionHolder* CVehicle::GetDamageSection()
{
	return (cDamageSectionHolder*)(this + 0x10C);
}

bool CVehicle::GetIsUsingNitro()
{
	return *(bool*)(this + 0x460);
}

void CVehicle::SetIsUsingNitro(bool use)
{
	*(bool*)(this + 0x460) = use;
}

// Can be used to activate the vehicle's horn, just set it to 1.0
void CVehicle::SetHornVolume(float volume)
{
	*(float*)(this + 0x4F0) = volume;
}

float CVehicle::GetHornVolume()
{
	return *(float*)(this + 0x4F0);
}

// In other words this will set the parts damage multiplier
void CVehicle::SetSoftness(float softness)
{
	*(float*)(this + 0x4F4) = softness;
}

float CVehicle::GetSoftness()
{
	return *(float*)(this + 0x4F4);
}

void CVehicle::SetFragility(float frag)
{
	*(float*)(this + 0x4FC) = frag;
}

float CVehicle::GetFragility()
{
	return *(float*)(this + 0x4FC);
}

void CVehicle::SetBonnetDetacher(float bd)
{
	*(float*)(this + 0x508) = bd;
}

float CVehicle::GetBonnetDetacher()
{
	return *(float*)(this + 0x508);
}

uint8_t CVehicle::GetTintIndex()
{
	return *(uint8_t*)(this + 0x55D);
}

void CVehicle::SetTintIndex(uint8_t tintidx)
{
	*(float*)(this + 0x55D) = tintidx;
}

// If the vehicle is initialised.
bool CVehicle::GetIsInitialised()
{
	return *(bool*)(this + 0x556);
}

void CVehicle::SetIsInitialised(bool init)
{
	*(bool*)(this + 0x556) = init;
}

// Get if the tyres are invincible to shots or anything
bool CVehicle::GetInvincibleTyres()
{
	return *(bool*)(this + 0x554);
}

void CVehicle::SetInvincibleTyres(bool invincibility)
{
	*(bool*)(this + 0x554) = invincibility;
}

// Get if the vehicle does not blow up when shot up
bool CVehicle::GetDoesntBlowUpWhenShotUp()
{
	return *(bool*)(this + 0x553);
}

void CVehicle::SetDoesntBlowUpWhenShotUp(bool state)
{
	*(bool*)(this + 0x553) = state;
}

bool CVehicle::GetIsRecordedVehicle()
{
	return *(bool*)(this + 0x551);
}

void CVehicle::SetIsRecordedVehicle(bool state)
{
	*(bool*)(this + 0x551) = state;
}

SVehicleManipulationPacket* CVehicle::GetForcedInputs()
{
	return (SVehicleManipulationPacket*)(this + 0x538);
}

sCustomCar* CVehicle::GetCustomCarData()
{
	return (sCustomCar*)(this + 0x5A4);
}

// 0x461382 <- also called here
void CVehicle::SetCustomCarData(sCustomCar *pChav, cVehicleProperties *pProps, void *pBuffer) // SetCustomCarData__8CVehicleP10sCustomCarPC18cVehiclePropertiesPv(CVehicle *this,sCustomCar *pChav,cVehicleProperties *pProps,void *pBuffer)
{
#ifdef CALL_SETCUSTOMCAR
	((void(__thiscall*)(CVehicle*, sCustomCar*, cVehicleProperties*, void*))0x5AE726)(this, pChav, pProps, pBuffer);
#else
	*(sCustomCar**)(this->GetPointer() + 0x5A4) = pChav;
#endif
}

float CVehicle::GetThrottle()
{
	return *(float*)(this + THROTTLE_OFF1);
}

// Setting this to true will make the vehicle not drivable by the player but forced input
// 0x005AE520
void CVehicle::SetForcedControl(bool state)
{
	*(bool*)(this + 0x550) = state;
}

void CVehicle::SetIsDead(bool state)
{
	*(bool*)(this + 0x557) = state;
}

bool CVehicle::GetForcedControl()
{
	return *(bool*)(this + 0x550);
}

bool CVehicle::GetIsDead()
{
	return *(bool*)(this + 0x557);
}

void CVehicle::SetDamage(float damage)
{
	*(float*)(this + 0x574) = damage;
}

float CVehicle::GetDamage()
{
	return *(float*)(this + 0x574);
}

int CVehicle::GetDrivingType(bool getLightType)
{
	return *(int*)(this->GetPointer()+ 0x528);
}

void CVehicle::SetDrivingType(int type, bool changeLightType)
{
	*(int*)(this->GetPointer()+ 0x528) = type;
	if (changeLightType)
	{
		*(int*)(this->GetPointer()+ 0x9C) = type;
	}
}

// Unsure if this set the steer properly? 0x00590433

float* CVehicle::GetSteer()
{
	return (float*)(this + 0xB4);
}

void CVehicle::SetLightDisplayFlags(int lightId, int flags)
{
	int offset = VEHLIGHT_DISPLAY_OFF + (VEHLIGHT_DISPLAY_SIZE * lightId);
	*(int*)(this->GetPointer()+ offset) = flags;
}

int CVehicle::GetLightDisplayFlags(int lightId)
{
	int offset = VEHLIGHT_DISPLAY_OFF + (VEHLIGHT_DISPLAY_SIZE * lightId);
	return *(int*)(this->GetPointer() + offset);
}

void CVehicle::SetLightDisplayBrightness(int lightId, float brightness)
{
	int offset = VEHLIGHT_DISPLAY_OFF + (VEHLIGHT_DISPLAY_SIZE * lightId);
	*(float*)(this + (offset + 4)) = brightness;
}

bool CVehicle::operator==(CVehicle* other) {
	if (this == other)
		return true;
	return false;
}

bool CVehicle::operator!=(CVehicle* other) {
	return !(*this == other);
}

void CVehicle::MakeStatic()
{
	((void(__thiscall*)(CVehicle*))0x57F4C6)(this);
}

void CVehicle::MakeDynamic()
{
	((void(__thiscall*)(CVehicle*))0x57F4CE)(this);
}

void CVehicle::MakeInfiniteMass()
{
	((void(__thiscall*)(CVehicle*))0x57F4D6)(this);
}

void CVehicle::Explode()
{
	((void(__thiscall*)(CVehicle*))0x5AB787)(this);
}

void CVehicle::Kaboom()
{
	((void(__thiscall*)(CVehicle*))0x59D417)(this);
}

// 0x5AE599:
//   CVehicle::DetachWheel(const SNewVehicleHierarchyPart &, const MAm4 &)
// 0x5AE610:
//   CVehicle::RegisterBulletHit(const MAv4 &, const MAv4 &, float, float, float, float)

void CVehicle::GetDoorOpenPosition(Vector4* position, int partSubtype, bool unk)
{
	((void(__thiscall*)(CVehicle*, Vector4*, int, bool))0x5AE86F)(this, position, partSubtype, unk);
}

void CVehicle::IsDoorBlocked(bool b, int partSubtype, float unk)
{
	((void(__thiscall*)(CVehicle*, bool, int, float))0x5AE888)(this, b, partSubtype, unk);
}

void CVehicle::SetTint(unsigned int tint)
{
	((void(__thiscall*)(CVehicle*, unsigned int))0x5AF2B3)(this, tint);
}

int CVehicle::GetPointer()
{
	return (int)(this);
}

int CVehicle::GetVTableAddress()
{
	return *(int*)(this);
}

int CVehicle::GetHandlingVTableAddress()
{
	return *(int*)(this->m_piQueryHandling.m_pPointer);
}

bool CVehicle::IsValid()
{
	if (this->GetPointer() == 0 || this == nullptr)
		return false;
	if (&this->m_piSpecification == NULL)
		return false;
	if (this->m_piSpecification.m_pPointer == NULL)
		return false;
	if (&this->m_piQueryHandling == NULL)
		return false;
	if (this->m_piQueryHandling.m_pPointer == NULL)
		return false;
	try {
		return ((this->GetPointer() != 0 && this != nullptr) && *(int*)(this->GetPointer()) == 0x653170);
	}
	catch (std::exception ex)
	{
		return false;
	}
}
