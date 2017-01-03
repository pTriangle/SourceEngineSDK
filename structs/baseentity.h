#pragma once
#include "../../Utils.h"
class CBaseEntity
{
public:
	float Friction()
	{

		static int offset = netVars->GetOffset("DT_BasePlayer", "m_flFriction");
		return *(float*)(this + offset);
	}
	int GetTeamNum()
	{

		static int offset = netVars->GetOffset("DT_BasePlayer", "m_iTeamNum");
		return *(int*)(this + offset);
	}
	Vector Velocity()
	{
		static int offset = netVars->GetOffset("DT_BasePlayer", "m_vecVelocity[0]");
		return *(Vector*)(this + offset);
	}

	int Health()
	{
		static int offset = netVars->GetOffset("DT_BasePlayer", "m_iHealth");
		return *(int*)(this + offset);
	}

	int Index()
	{
		
		return *(int*)((DWORD)this + 64);
	}

	int GetFlags()
	{
		static int offset = netVars->GetOffset("DT_BasePlayer", "m_fFlags");
		return *(int*)(this + offset);
	}

	Vector GetEyePosition()
	{

		static int offset = netVars->GetOffset("DT_BasePlayer", "m_vecViewOffset[0]");
		Vector vecViewOffset = *(Vector*)(this + offset);
		return GetAbsOrigin() + vecViewOffset;
	}

	Vector& GetAbsOrigin()
	{
		typedef Vector& (__thiscall* OriginalFn)(void*);
		return ((OriginalFn)VMT.GetFunction(this, 10))(this);
	}

	Vector& GetAbsAngles()
	{
		typedef Vector& (__thiscall* OriginalFn)(void*);
		return ((OriginalFn)VMT.GetFunction(this, 11))(this);
	}

	void* GetClientClass()
	{
		void* Networkable = (void*)(this + 0x8);
		typedef void* (__thiscall* OriginalFn)(void*);
		return ((OriginalFn)VMT.GetFunction(Networkable, 2))(Networkable);
	}
	
	bool IsDormant()
	{
		return *reinterpret_cast<bool*>((DWORD)this + 0xE9);
	}


	bool isAlive()
	{

		static int offset = netVars->GetOffset("DT_BasePlayer", "m_lifeState");
		BYTE lifestate = *(BYTE*)((DWORD)this + offset);
		return (lifestate == 0);
	}

	int GetIndex()
	{
		void* networkable = (void*)(this + 0x8);
		typedef int(__thiscall* OriginalFn)(PVOID);
		return ((OriginalFn)VMT.GetFunction(this, 8))(this);
	}

	bool SetupBones(VMatrix *pBoneToWorldOut, int nMaxBones, int boneMask, float currentTime)
	{
		void *pRenderable = (void*)(this + 0x4);
		typedef bool(__thiscall* OriginalFn)(PVOID, VMatrix*, int, int, float);
		return ((OriginalFn)VMT.GetFunction(pRenderable, 16))(pRenderable, pBoneToWorldOut, nMaxBones, boneMask, currentTime);
	}

	void* GetModel()
	{
		void *pRenderable = (void*)(this + 0x4);
		typedef void*(__thiscall* OriginalFn)(PVOID);
		return VMT.getvfunc<OriginalFn>(pRenderable, 9)(pRenderable);
	}

};