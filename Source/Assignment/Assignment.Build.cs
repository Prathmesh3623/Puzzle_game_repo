// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Assignment : ModuleRules
{
	public Assignment(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"Assignment",
			"Assignment/Variant_Platforming",
			"Assignment/Variant_Platforming/Animation",
			"Assignment/Variant_Combat",
			"Assignment/Variant_Combat/AI",
			"Assignment/Variant_Combat/Animation",
			"Assignment/Variant_Combat/Gameplay",
			"Assignment/Variant_Combat/Interfaces",
			"Assignment/Variant_Combat/UI",
			"Assignment/Variant_SideScrolling",
			"Assignment/Variant_SideScrolling/AI",
			"Assignment/Variant_SideScrolling/Gameplay",
			"Assignment/Variant_SideScrolling/Interfaces",
			"Assignment/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
