//===-- AirMachineFunctionInfo.h - Private data used for Air --*- C++ -*-===//
//
//                    The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIB_TARGET_AIR_AIRMACHINEFUNCTIONINFO_H
#define LLVM_LIB_TARGET_AIR_AIRMACHINEFUNCTIONINFO_H

#include "llvm/CodeGen/MachineFrameInfo.h"
#include "llvm/CodeGen/MachineFunction.h"
#include "llvm/CodeGen/MachineMemOperand.h"
#include "llvm/CodeGen/PseudoSourceValue.h"
#include "llvm/CodeGen/TargetFrameLowering.h"
#include "llvm/Target/TargetMachine.h"
#include <map>

namespace llvm {
  // This class is derived from MachienFunction private Air target-specific
  // information for each MachineFunction.
  class AirMachineFunctionInfo : public MachineFunctionInfo {
  public:
    AirMachineFunctionInfo(MachineFunction &MF)
        : MF(MF), VarArgsFrameIndex(0), MaxCallFrameSize(0) { }

    ~AirMachineFunctionInfo();

    int getVarArgsFrameIndex() const { return VarArgsFrameIndex; }
    void setVarArgsFrameIndex(int Index) { VarArgsFrameIndex = Index; }

  private:
    virtual void anchor();

    MachineFunction &MF;

    // Frame index for start of varargs area
    int VarArgsFrameIndex;

    unsigned MaxCallFrameSize;
  };
} // End llvm namespace
#endif