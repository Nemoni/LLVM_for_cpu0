//===-- AirSEISelLowering.h - AirSE DAG Lowering Interface ---*- C++ -*-===//
//
//                    The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIB_TARGET_AIR_AIRSEISELLOWERING_H
#define LLVM_LIB_TARGET_AIR_AIRSEISELLOWERING_H

#include "AirISelLowering.h"
#include "AirRegisterInfo.h"

namespace llvm {
class AirSETargetLowering : public AirTargetLowering {
public:
  explicit AirSETargetLowering(const AirTargetMachine &TM,
                                const AirSubtarget &STI);

  SDValue LowerOperation(SDValue Op, SelectionDAG &DAG) const override;
};

}// End llvm namespace

#endif
