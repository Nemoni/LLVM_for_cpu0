//===-- AirSEInstrInfo.h - Air32/64 Instruction Information ---*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the Air32/64 implementation of the TargetInstrInfo class.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIB_TARGET_AIR_AIRSEINSTRINFO_H
#define LLVM_LIB_TARGET_AIR_AIRSEINSTRINFO_H

#include "AirInstrInfo.h"
#include "AirSERegisterInfo.h"
#include "AirMachineFunctionInfo.h"

namespace llvm {

class AirSEInstrInfo : public AirInstrInfo {
  const AirSERegisterInfo RI;

public:
  explicit AirSEInstrInfo(const AirSubtarget &STI);

  const AirRegisterInfo &getRegisterInfo() const override;

};
} // End llvm namespace

#endif
