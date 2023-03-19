//===-- AirRegisterInfo.cpp - AIR Register Information -== --------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the AIR implementation of the TargetRegisterInfo class.
//
//===----------------------------------------------------------------------===//

#include "AirRegisterInfo.h"

#include "Air.h"
#include "AirSubtarget.h"
#include "AirMachineFunctionInfo.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/Type.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Support/Debug.h"
#include "llvm/Support/ErrorHandling.h"
#include "llvm/Support/raw_ostream.h"

#define GET_REGINFO_TARGET_DESC
#include "AirGenRegisterInfo.inc"

#define DEBUG_TYPE "air-reg-info"

using namespace llvm;

AirRegisterInfo::AirRegisterInfo(const AirSubtarget &ST)
  : AirGenRegisterInfo(Air::LR), Subtarget(ST) {}

//===----------------------------------------------------------------------===//
// Callee Saved Registers methods
//===----------------------------------------------------------------------===//
/// Air Callee Saved Registers
// In AirCallConv.td, defined CalleeSavedRegs
const MCPhysReg *
AirRegisterInfo::getCalleeSavedRegs(const MachineFunction *MF) const {
  return CSR_032_SaveList;
}

const uint32_t *
AirRegisterInfo::getCallPreservedMask(const MachineFunction &MF,
                                       CallingConv::ID) const {
  return CSR_032_RegMask;
}

BitVector AirRegisterInfo::
getReservedRegs(const MachineFunction &MF) const {
  static const uint16_t ReservedCPURegs[] = {
    Air::ZERO, Air::AT, Air::SP, Air::LR, Air::PC
  };
  BitVector Reserved(getNumRegs());

  for (unsigned I = 0; I < array_lengthof(ReservedCPURegs); ++I)
    Reserved.set(ReservedCPURegs[I]);

  return Reserved;
}

//- If no eliminateFrameIndex(), it will hang on run.
// FrameIndex represent objects inside a abstract stack.
// We must replace FrameIndex with an stack/frame pointer
// direct reference.
void AirRegisterInfo::
eliminateFrameIndex(MachineBasicBlock::iterator II, int SPAdj,
                    unsigned FIOperandNum, RegScavenger *RS) const {
}

bool
AirRegisterInfo::requiresRegisterScavenging(const MachineFunction &MF) const {
  return true;
}

bool
AirRegisterInfo::trackLivenessAfterRegAlloc(const MachineFunction &MF) const {
  return true;
}

unsigned AirRegisterInfo::
getFrameRegister(const MachineFunction &MF) const {
  const TargetFrameLowering *TFI = MF.getSubtarget().getFrameLowering();
  return TFI->hasFP(MF) ? (Air::FP) :
                          (Air::SP);
}
