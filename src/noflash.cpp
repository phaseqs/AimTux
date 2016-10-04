#include "noflash.h"

bool Settings::Noflash::enabled = true;
float Settings::Noflash::value = 255.0f;

void Noflash::FrameStageNotify(ClientFrameStage_t stage)
{
	if (!Settings::Noflash::enabled)
		return;

	C_BasePlayer* localPlayer = (C_BasePlayer*)entitylist->GetClientEntity(engine->GetLocalPlayer());
	if (!localPlayer)
		return;

	*localPlayer->GetFlashMaxAlpha() = 255.0f - Settings::Noflash::value;
}