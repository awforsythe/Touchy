#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleInterface.h"

class FTouchyCore : public IModuleInterface
{
public:
	static inline FTouchyCore& Get()
	{
		return FModuleManager::LoadModuleChecked<FTouchyCore>("TouchyCore");
	}

	static inline bool IsAvailable()
	{
		return FModuleManager::Get().IsModuleLoaded("TouchyCore");
	}

	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
