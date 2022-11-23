// Copyright Epic Games, Inc. All Rights Reserved.

#include "SkyContest.h"
#include "Modules/ModuleManager.h"
#include "Misc/Paths.h"

void FSkyContestModule::StartupModule()
{
	IModuleInterface::StartupModule();
	const FString ShaderDirectory = FPaths::Combine(FPaths::ProjectDir(), TEXT("Shaders"));
	AddShaderSourceDirectoryMapping("/Shaders", ShaderDirectory);
}

void FSkyContestModule::ShutdownModule()
{
	IModuleInterface::ShutdownModule();
	ResetAllShaderSourceDirectoryMappings();
}

IMPLEMENT_PRIMARY_GAME_MODULE( FSkyContestModule, SkyContest, "SkyContest" );
