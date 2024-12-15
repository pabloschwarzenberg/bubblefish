// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class bubblefishTarget : TargetRules
{
	public bubblefishTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;

		CppStandard = CppStandardVersion.Cpp20;

		ExtraModuleNames.AddRange( new string[] { "bubblefish" } );
	}
}
