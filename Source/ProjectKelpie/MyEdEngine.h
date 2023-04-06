#pragma once


#include "Editor/UnrealEdEngine.h"
#include "MyEdEngine.generated.h"


UCLASS(config=Engine, transient)
class PROJECTKELPIE_API UMyEdEngine : public UUnrealEdEngine
{

public:
	GENERATED_BODY()

public:
	void Init(IEngineLoop* InEngineLoop) override;

};
