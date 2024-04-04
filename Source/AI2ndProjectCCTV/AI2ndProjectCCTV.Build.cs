// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class AI2ndProjectCCTV : ModuleRules
{
	public AI2ndProjectCCTV(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
