//===-- AirSEISelLowering.cpp - AirSE DAG Lowering Interface --*- C++ -*-===//
//
//                    The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// Subclass of AirTargetLowering specialized for air32.
//
//===----------------------------------------------------------------------===//
#include "AirMachineFunctionInfo.h"
#include "AirISelLowering.h"
#include "AirSEISelLowering.h"

#include "AirRegisterInfo.h"
#include "AirTargetMachine.h"
#include "llvm/CodeGen/MachineInstrBuilder.h"
#include "llvm/CodeGen/MachineRegionInfo.h"
#include "llvm/IR/Intrinsics.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Support/Debug.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/CodeGen/TargetInstrInfo.h"

using namespace llvm;

#define DEBUG_TYPE "air-isel"

static cl::opt<bool>
EnableAirTailCalls("enable-air-tail-calls", cl::Hidden,
                    cl::desc("AIR: Enable tail calls."),
                    cl::init(false));

AirSETargetLowering::AirSETargetLowering(const AirTargetMachine &TM,
                                           const AirSubtarget &STI)
    : AirTargetLowering(TM, STI) {
  // Set up the register classes
  addRegisterClass(MVT::i32, &Air::CPURegsRegClass);

  // Once all of the register classes are added, this allows us to compute
  // deirved properties we expose.
  computeRegisterProperties(Subtarget.getRegisterInfo());
}

SDValue AirSETargetLowering::LowerOperation(SDValue Op,
                                             SelectionDAG &DAG) const {
  return AirTargetLowering::LowerOperation(Op, DAG);
}

const AirTargetLowering *
llvm::createAirSETargetLowering(const AirTargetMachine &TM,
                           const AirSubtarget &STI) {
  return new AirSETargetLowering(TM, STI);
}
