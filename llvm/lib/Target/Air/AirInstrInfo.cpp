//===-- AirInstrInfo.cpp - Air Instruction Information --------*- C++ -*-===//
//
//                    The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the Air implementation of the TargetInstrInfo class.
//
//===----------------------------------------------------------------------===//

#include "AirInstrInfo.h"

#include "AirTargetMachine.h"
#include "AirMachineFunctionInfo.h"
#include "llvm/ADT/STLExtras.h"
#include "llvm/CodeGen/MachineInstrBuilder.h"
#include "llvm/Support/ErrorHandling.h"
#include "llvm/Support/TargetRegistry.h"

using namespace llvm;

#define GET_INSTRINFO_CTOR_DTOR
#include "AirGenInstrInfo.inc"

// Pin the vtable to this file
void AirInstrInfo::anchor() { }

AirInstrInfo::AirInstrInfo(const AirSubtarget &STI)
  : Subtarget(STI) { }

const AirInstrInfo *AirInstrInfo::create(AirSubtarget &STI) {
  return llvm::createAirSEInstrInfo(STI);
}

unsigned AirInstrInfo::GetInstSizeInBytes(const MachineInstr &MI) const {
  switch (MI.getOpcode()) {
    default:
      return MI.getDesc().getSize();
  }
}
