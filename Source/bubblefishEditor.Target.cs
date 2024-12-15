// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class bubblefishEditorTarget : TargetRules
{
	public bubblefishEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;

		CppStandard = CppStandardVersion.Cpp20;

		bOverrideBuildEnvironment = true;

		ExtraModuleNames.AddRange( new string[] { "bubblefish" } );
	}
}
