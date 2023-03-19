//===-- AirMachineFunctionInfo.cpp - Private data used for Air -*- C++ -*-===//
//
//                    The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// Air specific subclass of MachineFunctionInfo.
//
//===----------------------------------------------------------------------===//

#include "AirMachineFunctionInfo.h"

#include "AirInstrInfo.h"
#include "AirSubtarget.h"
#include "llvm/IR/Function.h"
#include "llvm/CodeGen/MachineInstrBuilder.h"
#include "llvm/CodeGen/MachineRegisterInfo.h"

using namespace llvm;

bool FixGlobalBaseReg;

AirMachineFunctionInfo::~AirMachineFunctionInfo() { }

void AirMachineFunctionInfo::anchor() { }
