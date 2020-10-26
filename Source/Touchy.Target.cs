using UnrealBuildTool;

public class TouchyTarget : TargetRules
{
	public TouchyTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		ExtraModuleNames.AddRange( new string[] { "TouchyCore" } );
	}
}
