﻿#pragma once

#include "FFunctionDescriptor.h"

class FCSharpFunctionDescriptor final : public FFunctionDescriptor
{
public:
	typedef FFunctionDescriptor Super;

public:
	explicit FCSharpFunctionDescriptor(const FString& InName, UFunction* InFunction);

	virtual ~FCSharpFunctionDescriptor() override;

public:
	virtual void Deinitialize() override;

public:
	bool CallCSharp(FFrame& InStack, RESULT_DECL);

private:
	static FOutParmRec* FindOutParmRec(FOutParmRec* OutParam, const FProperty* OutProperty);

private:
	friend class FCSharpBind;

	FString Name;

	TWeakObjectPtr<UFunction> OriginalFunction;

	EFunctionFlags OriginalFunctionFlags;

	FNativeFuncPtr OriginalNativeFuncPtr;
};
