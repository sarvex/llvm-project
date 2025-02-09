//===- CGPassBuilderOption.h - Options for pass builder ---------*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file declares the CCState and CCValAssign classes, used for lowering
// and implementing calling conventions.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_TARGET_CGPASSBUILDEROPTION_H
#define LLVM_TARGET_CGPASSBUILDEROPTION_H

#include "llvm/Target/TargetOptions.h"
#include <optional>

namespace llvm {

enum class RunOutliner { TargetDefault, AlwaysOutline, NeverOutline };
enum class RegAllocType { Default, Basic, Fast, Greedy, PBQP };

// Not one-on-one but mostly corresponding to commandline options in
// TargetPassConfig.cpp.
struct CGPassBuilderOption {
  std::optional<bool> OptimizeRegAlloc;
  std::optional<bool> EnableIPRA;
  bool DebugPM = false;
  bool DisableVerify = false;
  bool EnableImplicitNullChecks = false;
  bool EnableBlockPlacementStats = false;
  bool MISchedPostRA = false;
  bool EarlyLiveIntervals = false;

  bool DisableLSR = false;
  bool DisableCGP = false;
  bool PrintLSR = false;
  bool DisableMergeICmps = false;
  bool DisablePartialLibcallInlining = false;
  bool DisableConstantHoisting = false;
  bool DisableSelectOptimize = true;
  bool PrintISelInput = false;
  bool PrintGCInfo = false;
  bool RequiresCodeGenSCCOrder = false;

  RunOutliner EnableMachineOutliner = RunOutliner::TargetDefault;
  RegAllocType RegAlloc = RegAllocType::Default;
  std::optional<GlobalISelAbortMode> EnableGlobalISelAbort;

  std::optional<bool> VerifyMachineCode;
  std::optional<bool> EnableFastISelOption;
  std::optional<bool> EnableGlobalISelOption;
};

CGPassBuilderOption getCGPassBuilderOption();

} // namespace llvm

#endif // LLVM_TARGET_CGPASSBUILDEROPTION_H
