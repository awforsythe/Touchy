using UnrealBuildTool;

public class TouchyEditorTarget : TargetRules
{
	public TouchyEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		ExtraModuleNames.AddRange( new string[] { "TouchyCore", "TouchyTestActors" } );
	}
}
