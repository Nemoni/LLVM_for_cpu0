//===-- AirFrameLowering.h - Frame Information for Air --------*- C++ -*-===//
//
//                    The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIB_TARGET_AIR_AIRFRAMELOWERING_H
#define LLVM_LIB_TARGET_AIR_AIRFRAMELOWERING_H

#include "Air.h"
#include "llvm/CodeGen/TargetFrameLowering.h"

namespace llvm {
class AirSubtarget;

class AirFrameLowering : public TargetFrameLowering {
protected:
  const AirSubtarget &STI;

public:
  explicit AirFrameLowering(const AirSubtarget &sti, unsigned Alignment)
    : TargetFrameLowering(StackGrowsDown, Alignment, 0, Alignment),
      STI(sti) { }

  static const AirFrameLowering *create(const AirSubtarget &ST);

  bool hasFP(const MachineFunction &MF) const override;

};

// Create AirFrameLowering objects.
const AirFrameLowering *createAirSEFrameLowering(const AirSubtarget &ST);

} // End llvm namespace

#endif
