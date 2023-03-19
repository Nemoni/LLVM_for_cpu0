//===-- AirSERegisterInfo.h - Air32 Register Information ------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the Air32/64 implementation of the TargetRegisterInfo
// class.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIB_TARGET_AIR_AIRSEREGISTERINFO_H
#define LLVM_LIB_TARGET_AIR_AIRSEREGISTERINFO_H

#include "AirRegisterInfo.h"

namespace llvm {
class AirSEInstrInfo;

class AirSERegisterInfo : public AirRegisterInfo {
public:
  AirSERegisterInfo(const AirSubtarget &Subtarget);

  const TargetRegisterClass *intRegClass(unsigned Size) const override;
};

} // end namespace llvm

#endif
