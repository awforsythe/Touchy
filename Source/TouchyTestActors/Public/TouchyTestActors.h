#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleInterface.h"

class FTouchyTestActors : public IModuleInterface
{
public:
	static inline FTouchyTestActors& Get()
	{
		return FModuleManager::LoadModuleChecked<FTouchyTestActors>("TouchyTestActors");
	}

	static inline bool IsAvailable()
	{
		return FModuleManager::Get().IsModuleLoaded("TouchyTestActors");
	}

	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
