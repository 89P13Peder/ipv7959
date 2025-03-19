// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ipv7959 : ModuleRules
{
	public ipv7959(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
