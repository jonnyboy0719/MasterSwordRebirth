#include <fmod/fmod_errors.h>
#include "hud.h"
#include "cl_util.h"
#include "clglobal.h"

#include "soundengine.h"

// Starts FMOD
bool CSoundEngine::InitFMOD( void )
{
	FMOD_RESULT	result = FMOD::System_Create( &m_pSystem ); // Create the main system object.
	if (result != FMOD_OK)
	{
		gEngfuncs.Con_Printf("FMOD ERROR: System creation failed!\n");
		return false;
	}
	else
		gEngfuncs.Con_Printf("FMOD system successfully created.\n");
		
	result = m_pSystem->init(100, FMOD_INIT_NORMAL, 0);   // Initialize FMOD system.
	if (result != FMOD_OK)
	{
		gEngfuncs.Con_Printf("FMOD ERROR: Failed to initialize properly!\n");
		return false;
	}
	else
		gEngfuncs.Con_Printf("FMOD initialized successfully.\n");

	return true;
}

// Stops FMOD
bool CSoundEngine::ExitFMOD( void )
{
	FMOD_RESULT	result = m_pSystem->release();

	if (result != FMOD_OK)
	{
		gEngfuncs.Con_Printf("FMOD ERROR: System did not terminate properly!\n");
		return false;
	}
	else
		gEngfuncs.Con_Printf("FMOD system terminated successfully.\n");

	return true;
}
