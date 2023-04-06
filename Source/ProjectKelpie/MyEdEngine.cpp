#include "MyEdEngine.h"
#include "ISourceControlModule.h"
#include "ISourceControlProvider.h"
#include "Logging/LogCategory.h"
#include "Logging/LogMacros.h"


#if WITH_EDITOR

DEFINE_LOG_CATEGORY_STATIC(MyEdEngine, Log, All);

/*
* See 'Status Branches' - https://github.com/ProjectBorealis/UEGitPlugin
* Allows working with git LFS and being notified of upstream changes before attempting to lock a file (which locally is behind in revisions).
*/
void UMyEdEngine::Init(IEngineLoop* InEngineLoop)
{
	Super::Init(InEngineLoop);

	// Register state branches
	const ISourceControlModule& SourceControlModule = ISourceControlModule::Get();
	{
		ISourceControlProvider& SourceControlProvider = SourceControlModule.GetProvider();
		// Order matters. Lower values are lower in the hierarchy, i.e., changes from higher branches get automatically merged down.
		// (Automatic merging requires an appropriately configured CI pipeline)
		// With this paradigm, the higher the branch is, the stabler it is, and has changes manually promoted up.
		const TArray<FString> Branches{ "origin/master" };
		SourceControlProvider.RegisterStateBranches(Branches, TEXT("Content"));

		UE_LOG(MyEdEngine, Log, TEXT("Initializing MyEdEngine for use with git LFS Status Branches."));
	}
}

#endif // WITH_EDITOR