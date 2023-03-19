//===-- AirSEInstrInfo.cpp - Air32/64 Instruction Information -----------===//
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

#include "AirSEInstrInfo.h"

#include "AirMachineFunctionInfo.h"
#include "AirTargetMachine.h"
#include "llvm/ADT/STLExtras.h"
#include "llvm/CodeGen/MachineInstrBuilder.h"
#include "llvm/CodeGen/MachineRegisterInfo.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Support/ErrorHandling.h"
#include "llvm/Support/TargetRegistry.h"

using namespace llvm;

AirSEInstrInfo::AirSEInstrInfo(const AirSubtarget &STI)
    : AirInstrInfo(STI),
      RI(STI) {}

const AirRegisterInfo &AirSEInstrInfo::getRegisterInfo() const {
  return RI;
}

const AirInstrInfo *llvm::createAirSEInstrInfo(const AirSubtarget &STI) {
  return new AirSEInstrInfo(STI);
}
