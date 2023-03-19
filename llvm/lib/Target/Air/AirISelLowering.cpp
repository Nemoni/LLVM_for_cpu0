//===-- AirISelLowering.cpp - Air DAG Lowering Implementation -*- C++ -*-===//
//
//                    The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file defines the interfaces that Air uses to lower LLVM code into a
// selection DAG.
//
//===----------------------------------------------------------------------===//

#include "AirISelLowering.h"

#include "AirMachineFunctionInfo.h"
#include "AirTargetMachine.h"
#include "AirTargetObjectFile.h"
#include "AirSubtarget.h"
#include "llvm/ADT/Statistic.h"
#include "llvm/CodeGen/CallingConvLower.h"
#include "llvm/CodeGen/MachineFrameInfo.h"
#include "llvm/CodeGen/MachineFunction.h"
#include "llvm/CodeGen/MachineInstrBuilder.h"
#include "llvm/CodeGen/MachineRegionInfo.h"
#include "llvm/CodeGen/SelectionDAG.h"
#include "llvm/CodeGen/ValueTypes.h"
#include "llvm/IR/CallingConv.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/GlobalVariable.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Support/Debug.h"
#include "llvm/Support/ErrorHandling.h"
#include "llvm/Support/raw_ostream.h"

using namespace llvm;

#define DEBUG_TYPE "air-lower"

const char *AirTargetLowering::getTargetNodeName(unsigned Opcode) const {
  switch (Opcode) {
    case AirISD::JmpLink        :  return "AirISD::JmpLink";
    case AirISD::TailCall       :  return "AirISD::TailCall";
    case AirISD::Hi             :  return "AirISD::Hi";
    case AirISD::Lo             :  return "AirISD::Lo";
    case AirISD::GPRel          :  return "AirISD::GPRel";
    case AirISD::Ret            :  return "AirISD::Ret";
    case AirISD::EH_RETURN      :  return "AirISD::EH_RETURN";
    case AirISD::DivRem         :  return "AirISD::DivRem";
    case AirISD::DivRemU        :  return "AirISD::DivRemU";
    case AirISD::Wrapper        :  return "AirISD::Wrapper";
    default                      :  return NULL;
  }
}

AirTargetLowering::AirTargetLowering(const AirTargetMachine &TM,
                                       const AirSubtarget &STI)
    : TargetLowering(TM), Subtarget(STI), ABI(TM.getABI()) { }

const AirTargetLowering *
AirTargetLowering::create(const AirTargetMachine &TM,
                           const AirSubtarget &STI) {
  return createAirSETargetLowering(TM, STI);
}
//===----------------------------------------------------------------------===//
// Lower Helper Functions
//===----------------------------------------------------------------------===//

//===----------------------------------------------------------------------===//
// Misc Lower Operation Implementation
//===----------------------------------------------------------------------===//

#include "AirGenCallingConv.inc"

//===----------------------------------------------------------------------===//
// Formal Arguments Calling Convention Implementation
//===----------------------------------------------------------------------===//

// Transform physical registers into virtual registers and generate load
// operations for arguments places on the stack.
SDValue
AirTargetLowering::LowerFormalArguments(SDValue Chain,
                                         CallingConv::ID CallConv, bool IsVarArg,
                                         const SmallVectorImpl<ISD::InputArg> &Ins,
                                         const SDLoc &DL, SelectionDAG &DAG,
                                         SmallVectorImpl<SDValue> &InVals)
                                         const {
  return Chain;  // Leave empty temporary
}

//===----------------------------------------------------------------------===//
// Return Value Calling Convention Implementation
//===----------------------------------------------------------------------===//

SDValue
AirTargetLowering::LowerReturn(SDValue Chain,
                                CallingConv::ID CallConv, bool IsVarArg,
                                const SmallVectorImpl<ISD::OutputArg> &Outs,
                                const SmallVectorImpl<SDValue> &OutsVals,
                                const SDLoc &DL, SelectionDAG &DAG) const {
  return DAG.getNode(AirISD::Ret, DL, MVT::Other, Chain,
                     DAG.getRegister(Air::LR, MVT::i32));
}
