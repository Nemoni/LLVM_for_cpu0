//===-- AirABIInfo.cpp - Information about Air ABI ------------*- C++ -*-===//
//
//                    The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// Design for Air Application Binary Interface.
//
//===----------------------------------------------------------------------===//

#include "AirABIInfo.h"
#include "AirRegisterInfo.h"
#include "llvm/ADT/StringRef.h"
#include "llvm/ADT/StringSwitch.h"
#include "llvm/MC/MCTargetOptions.h"
#include "llvm/Support/CommandLine.h"

using namespace llvm;

static cl::opt<bool>
EnableAirS32Calls("air-s32-calls", cl::Hidden,
                   cl::desc("AIR S32 call: use stack only to pass arguments."),
                   cl::init(false));

namespace {
  static const MCPhysReg O32IntRegs[4] = {Air::A0, Air::A1};
  static const MCPhysReg S32IntRegs = {};
}

const ArrayRef<MCPhysReg> AirABIInfo::GetByValArgRegs() const {
  if (IsO32())
    return makeArrayRef(O32IntRegs);
  if (IsS32())
    return makeArrayRef(S32IntRegs);

  llvm_unreachable("Unhandled ABI");
}

const ArrayRef<MCPhysReg> AirABIInfo::GetVarArgRegs() const {
  if (IsO32())
    return makeArrayRef(O32IntRegs);
  if (IsS32())
    return makeArrayRef(S32IntRegs);

  llvm_unreachable("Unhandled ABI");
}

unsigned AirABIInfo::GetCalleeAllocdArgSizeInBytes(CallingConv::ID CC) const {
  if (IsO32())
    return CC != 0;
  if (IsS32())
    return 0;

  llvm_unreachable("Unhandled ABI");
}

AirABIInfo AirABIInfo::computeTargetABI() {
  AirABIInfo abi(ABI::Unknown);

  if (EnableAirS32Calls)
    abi = ABI::S32;
  else
    abi = ABI::O32;

  // Assert exactly one ABI was chosen.
  assert(abi.ThisABI != ABI::Unknown);

  return abi;
}

unsigned AirABIInfo::GetStackPtr() const { return Air::SP; }

unsigned AirABIInfo::GetFramePtr() const { return Air::FP; }

unsigned AirABIInfo::GetNullPtr() const { return Air::ZERO; }

unsigned AirABIInfo::GetEhDataReg(unsigned I) const {
  static const unsigned EhDataReg[] = { Air::A0, Air::A1 };

  return EhDataReg[I];
}

int AirABIInfo::EhDataRegSize() const {
  if (ThisABI == ABI::S32)
    return 0;
  else
    return 2;
}
