//===-- AirSEFrameLowering.h - AirSE Frame Lowering --------*- C++ -*-===//
//
//                    The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIB_TARGET_AIR_AIRSEFRAMELOWERING_H
#define LLVM_LIB_TARGET_AIR_AIRSEFRAMELOWERING_H

#include "AirFrameLowering.h"

namespace llvm {
class AirSEFrameLowering : public AirFrameLowering {
public:
  explicit AirSEFrameLowering(const AirSubtarget &STI);

  // These methods insert prolog and epilog code into the function.
  void emitPrologue(MachineFunction &MF, MachineBasicBlock &MBB) const override;
  void emitEpilogue(MachineFunction &MF, MachineBasicBlock &MBB) const override;

};

} // End llvm namespace

#endif
