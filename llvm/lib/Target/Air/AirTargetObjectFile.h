//===-- AirTargetObjectFile.h - Air Object Info ---------------*- C++ -*-===//
//
//                    The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
#ifndef LLVM_LIB_TARGET_AIR_AIRTARGETOBJECTFILE_H
#define LLVM_LIB_TARGET_AIR_AIRTARGETOBJECTFILE_H

#include "AirTargetMachine.h"
#include "llvm/CodeGen/TargetLoweringObjectFileImpl.h"

namespace llvm {
class AirTargetMachine;
class AirTargetObjectFile : public TargetLoweringObjectFileELF {
  MCSection *SmallDataSection;
  MCSection *SmallBSSSection;
  const AirTargetMachine *TM;
public:
  void Initialize(MCContext &Ctx, const TargetMachine &TM) override;

};
} // end namespace llvm

#endif
