//===-- AirTargetMachine.cpp - Define TargetMachine for Air ---*- C++ -*-===//
//
//                    The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// Implements the info about Air target spec
//
//===----------------------------------------------------------------------===//

#include "AirTargetMachine.h"
#include "Air.h"

#include "llvm/IR/LegacyPassManager.h"
#include "llvm/CodeGen/Passes.h"
#include "llvm/CodeGen/TargetPassConfig.h"
#include "llvm/Support/TargetRegistry.h"

using namespace llvm;

#define DEBUG_TYPE "air"

extern "C" void LLVMInitializeAirTarget() {
}
