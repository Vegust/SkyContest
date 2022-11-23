// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class SkyContest : ModuleRules
{
	public SkyContest(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[]
		{
			"Core", 
			"CoreUObject", 
			"Engine", 
			"InputCore",
			"Slate",
			"SlateCore",
			"UMG"
		});

		PrivateDependencyModuleNames.AddRange(new string[]
		{
			"Renderer",
			"RenderCore"
		});
	}
}
