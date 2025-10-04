#pragma once
#include "Character.h"
#include "..\core\Matrix.h"
#include "..\core\Vector.h"
#include "VehicleModel.h"
#include "VehicleManager.h"
#include "AutoPtr.h"
#include "ePartSubType.h"

class CCharacter;
class CVehicleManager;

#define _OLD_TIMES_GETVTYPE
#define PROPER_MATRIX

// Applied to driving type and light type? (shader and simple)
enum eVehicleDrivingType
{
	DRIVING_PLAYER = 1,
	DRIVING_PLAYER_NETWORK = 2, // it was called that in the game's code
	DRIVING_ANY = 4,     // Used for wanders, chasers maybe
	DRIVING_CIVILIAN = 9 // Makes the steering and speed perfect for civilians to turn, the top speed seems to be doubled
};

enum VehicleHandlingType
{
	Invalid = -1,

	Car = 0,
	Bike = 1,
	TowTruck = 2,
	Truck = 3,
	Tank = 4
};

enum eVehicleLightFlags
{
	VEHLIGHTFLAGS_FORCE_ON = 0x01010001,  // The light will be forced to be on at anytime
	VEHLIGHTFLAGS_ON = 0x01000001,        // The light will be on
	VEHLIGHTFLAGS_FORCE_OFF = 0x01010000, // The light will be forced to be off at anytime
	VEHLIGHTFLAGS_OFF = 0x00000000,       // The light will be off

};

struct sDamageWheel {
	float cdamage;
	float nocollide;
	bool bShot;
	bool bOff;

	uint8_t field4_0xa; // undefined
	uint8_t field5_0xb; // undefined
};

struct sDamageWheelHolder {
	struct sDamageWheel damagewheel[8] = {};
	bool bTouched;

	uint8_t field2_0x61; // undefined
	uint8_t field3_0x62; // undefined
	uint8_t field4_0x63; // undefined
};

struct sEngineDamage {
	int pEngineSmoke; // engine smoke pointer

	float engineFireSound;
	float fuse;
	float nocollidetime;
};

struct SVehicleManipulationPacket {
	float fThrust;
	float fSteerValue;
	float fBurnout;
	float fHornVolume;
	float fLeanFB;
	bool bHandbrake;
	bool bNitro;
	bool bAction1;
	bool bBrakeIsPressed;
};

struct sRGBtint {
    unsigned char rgb[3];
};

// Car customization data
struct sCustomCar {
    int version;
    float tunables[6];
    float nitro;
	unsigned int KitParts;
    struct sRGBtint panelcolour[20];
    unsigned char panelversion[20];
	int wheelversion;
	int paintjob;
    struct sRGBtint basetint;
    uint8_t pad;
    uint8_t field10_0x7a; // undefined
    uint8_t field11_0x7b; // undefined
};

struct sValue {
	unsigned int data;
};

struct cVehicleProperties {
	sValue m_TweakVals[293];
};

struct OBobject { // Probably forward declared, but not defined, in a translation unit with symbols.
	uint8_t field0_0x0;
};

struct PHobject { // Probably forward declared, but not defined, in a translation unit with symbols.
	uint8_t field0_0x0;
};

struct cDamageSection {
	struct cDamageSection__vtable *__vtable; // Inherited from IInterface
	float damage[2];
	unsigned short state;
	short flags;
	PHobject *pPhys;
	float autoclosetimer;
	float nocollidetimer;
	float Cdamage; // car paint damage?
	float Bdamage; // bullet damage
	float lastdamage;
	float Cdamage3;
	float Cdamage4;
	
	//uint8_t field12_0x2c;
	//uint8_t field13_0x2d;
	//uint8_t field14_0x2e;
	//uint8_t field15_0x2f;

	int flags2;
};

struct cDamageSectionHolder {
	struct cDamageSection m_DSecs[20];
};

#define VEHLIGHT_DISPLAY_MAX 20
#define VEHLIGHT_DISPLAY_OFF 0x110
#define VEHLIGHT_DISPLAY_SIZE 0xC

struct SNewVehicleHierarchyHeader {
	char m_sFileType[4]; // Inherited from SOldVehicleHierarchyHeader
	unsigned int m_dwUID[2]; // Inherited from SOldVehicleHierarchyHeader
	unsigned int m_uiVersion; // Inherited from SOldVehicleHierarchyHeader
	unsigned int m_uiNumParts; // Inherited from SOldVehicleHierarchyHeader
	unsigned int m_nVehicleType; // Inherited from SOldVehicleHierarchyHeader
	unsigned int m_SizeOfPhysics; // Inherited from SOldVehicleHierarchyHeader
	unsigned int pad[1]; // Inherited from SOldVehicleHierarchyHeader
	unsigned short m_uiNumMarkerPoints;
	unsigned short m_uiNumMovingParts;
	unsigned short m_uiNumDamagingParts;
	unsigned short m_uiNumInstanceParts;
	short unsigned int pad16[4];
};

struct SNewVehicleHierarchyPart {
	unsigned short m_eType;
	unsigned short m_eSubType;
	unsigned int m_ChildTypes;
	unsigned int m_PartFlags;
	unsigned short m_nskip;
	unsigned short m_npop;
	unsigned short m_nskip_pop;
	unsigned short m_ModelHandle;
	unsigned short m_PhysicsModelRef;
	short m_MarkerPointRef;
	short m_MovingPartRef;
	short m_DamagePartRef;
	short m_InstancePartRef;
	unsigned short pad16;
};

struct SOldVehicleHierarchyHeader {
	char m_sFileType[4];
	unsigned int m_dwUID[2];
	unsigned int m_uiVersion;
	unsigned int m_uiNumParts;
	unsigned int m_nVehicleType;
	unsigned int m_SizeOfPhysics;
	unsigned int pad[1];
};

struct IHandlingInternal {
	void* vtable;
};

struct IVehicleSpecificationInternal {
	void* vtable;
	int m_factoryType;
	int m_hclass;
	SOldVehicleHierarchyHeader* m_pHeader;
};

class CVehicle {
public:

	// virtual method tables

	int field1_0;
	int field2_4;
	int field3_8;
	int field4_12;
	int field5_16;
	int field6_20;
	int field7_24;
	int field8_28;
	int field9_32;
	int field10_36;
	int field11_40;

	AutoPtr<IHandlingInternal, int> m_piQueryHandling;
	AutoPtr<IVehicleSpecificationInternal, int> m_piSpecification;
	AutoPtr<CVehicleManager, int> m_piManager;
	AutoPtr<void*, int> m_piSFXServer;
	AutoPtr<CVehicle, int> m_piOverride;

	SNewVehicleHierarchyHeader* m_pHierarchy;
	SNewVehicleHierarchyPart *m_pParts;

	void SetColor(float R, float G, float B);
	Vector GetColor();

#ifndef _OLD_TIMES_GETVTYPE 
	int
#else
	int*
#endif 
		GetVehicleType();
	tVehicleModelUID* GetVehicleUID();

	void SetDriver(CCharacter* pDriver, bool unk);
	CCharacter* GetDriver();
	CCharacter* GetPassenger();
	bool BeingDrived();

	void RestoreDamage();
	void ResetDamage();
	void SetDamage(float damage);
	float GetDamage();
	void MakeInfiniteMass();
	void Explode();
	void Kaboom();
	void GetDoorOpenPosition(Vector4* position, int partSubtype, bool unk = false);
	void IsDoorBlocked(bool b, int partSubtype, float unk = 0);
	void SetTint(unsigned int tint);
	bool operator==(CVehicle* other);
	bool operator!=(CVehicle* other);

	int GetPointer();
	int GetVTableAddress();
	int GetHandlingVTableAddress();

	void SendManipulationPacket(SVehicleManipulationPacket* rPacket);
	void ActivateLamp(ePartSubType type, bool onoff, bool over);
	void SendManipulationPacketInternal(SVehicleManipulationPacket* rPacket);

    sCustomCar* GetCustomCarData();
    void SetCustomCarData(sCustomCar *pChav, cVehicleProperties *pProps = NULL, void *pBuffer = NULL); // sometimes required before using GetCustomization()

	Matrix* GetMatrix(Matrix* mat);

	void GetPosition(Vector4* pos);

	void SetPosition(Vector4 pos);
	void SetPosition(Vector4* pos);
	void SetPosition(Vector pos);
	void SetPosition(Vector* pos);

	float GetSpeed();
	Vector4 GetVelocity();

	void SetVelocity(Vector4 pos);
	void SetVelocity(Vector4* pos);
	void SetVelocity(Vector pos);
	void SetVelocity(Vector* pos);

	Vector4 GetDirection();
	
	void SetDirection(Vector4 pos);
	void SetDirection(Vector4* pos);
	void SetDirection(Vector pos);
	void SetDirection(Vector* pos);
	
	Vector4 GetAngularVelocity();

	void SetAngularVelocity(Vector4 pos);
	void SetAngularVelocity(Vector4* pos);
	void SetAngularVelocity(Vector pos);
	void SetAngularVelocity(Vector* pos);

	Vector4 GetRPM();

	int GetDrivingType(bool getLightType = false);
	void SetDrivingType(int type, bool changeLightType = true);

	void SetPhysicsState(int physicsState);

	bool GetDrawVirtualShadow(); // get if the game will draw a "shadow box" underneath this vehicle
	void SetDrawVirtualShadow(bool draw); // set if the game will draw a "shadow box" underneath this vehicle

	// The wheels damage, such as popped/shot, no collision, etc.
	sDamageWheelHolder* GetWheelsDamage();

	cDamageSectionHolder* GetDamageSection();
	sEngineDamage* GetEngineDamageSection();

	bool GetIsUsingNitro(); // get if this vehicle is using nitro
	void SetIsUsingNitro(bool use); // set if this vehicle is using nitro

	float* GetSteer();
	void SetLightDisplayFlags(int lightId, int flags);
	int GetLightDisplayFlags(int lightId);
	void SetLightDisplayBrightness(int lightId, float brightness);

	void MakeStatic(); // this freezes the vehicle in it's current position until it gets pushed or touched
	void MakeDynamic(); // this unfreezes the vehicle depending on the physics state

	void Step();
	void PostPhysicsStep();

	// Can be used to activate the vehicle's horn, just set it to 1.0
	void SetHornVolume(float volume);
	float GetHornVolume();

	// In other words this will set the parts damage multiplier
	void SetSoftness(float softness);
	float GetSoftness();

	void SetFragility(float frag);
	float GetFragility();

	void SetBonnetDetacher(float bd);
	float GetBonnetDetacher();

	uint8_t GetTintIndex();
	void SetTintIndex(uint8_t tintidx);

	bool GetIsInitialised();
	void SetIsInitialised(bool init);

	// Get if the tyres are invincible to shots or anything
	bool GetInvincibleTyres();
	void SetInvincibleTyres(bool invincibility);

	// Get if the vehicle does not blow up when shot up
	bool GetDoesntBlowUpWhenShotUp();
	void SetDoesntBlowUpWhenShotUp(bool state);

	bool GetIsRecordedVehicle();
	void SetIsRecordedVehicle(bool state);

	SVehicleManipulationPacket* GetForcedInputs();

	float GetThrottle();

	// Setting this to true will make the vehicle not drivable by the player
	void SetForcedControl(bool state);
	bool GetForcedControl();

	void SetIsDead(bool state);
	bool GetIsDead();

	void Draw();

	CVehicle* GetVehiclePointer(); // use it to get the real vehicle pointer from tow truck, wagons & war tank
	CVehicle* GetPartnerVehicle(); // tow truck only
	VehicleHandlingType GetVehicleHandlingType();

	bool IsValid();

	/*
	CVehicle();
	virtual ~CVehicle();
	*/
};

static int MaxVehicles = 256;
static CVehicle* Vehicles[256] = { NULL };
static int VehiclesCount = 0;
CVehicle* GetVehicle(int id);
CVehicle* GetNearestVehicleOnPoint(Vector4 point, float radius);