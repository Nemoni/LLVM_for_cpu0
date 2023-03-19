//===-- AirSEFrameLowering.cpp - AirSE Frame Information ----*- C++ -*-===//
//
//                    The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the Air implementation of TargetFrameLowering class.
//
//===----------------------------------------------------------------------===//

#include "AirSEFrameLowering.h"

#include "AirMachineFunctionInfo.h"
#include "AirSEInstrInfo.h"
#include "AirSubtarget.h"
#include "llvm/CodeGen/MachineFrameInfo.h"
#include "llvm/CodeGen/MachineFunction.h"
#include "llvm/CodeGen/MachineInstrBuilder.h"
#include "llvm/CodeGen/MachineModuleInfo.h"
#include "llvm/CodeGen/MachineRegionInfo.h"
#include "llvm/CodeGen/RegisterScavenging.h"
#include "llvm/IR/DataLayout.h"
#include "llvm/IR/Function.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Target/TargetOptions.h"

using namespace llvm;

AirSEFrameLowering::AirSEFrameLowering(const AirSubtarget &STI)
  : AirFrameLowering(STI, STI.stackAlignment()) { }

void AirSEFrameLowering::emitPrologue(MachineFunction &MF,
                                       MachineBasicBlock &MBB) const {
  /* Leave empty temporary */
}

void AirSEFrameLowering::emitEpilogue(MachineFunction &MF,
                                       MachineBasicBlock &MBB) const {
  /* Leave empty temporary */
}

const AirFrameLowering *llvm::createAirSEFrameLowering(const AirSubtarget
                                                                   &ST) {
  return new AirSEFrameLowering(ST);
}
