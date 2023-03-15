//===-- AirTargetInfo.cpp - Air Target Implementation ---------*- C++ -*-===//
//
//                    The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===

#include "Air.h"
#include "llvm/IR/Module.h"
#include "llvm/Support/TargetRegistry.h"

using namespace llvm;

Target &llvm::getTheAirTarget() {
  static Target TheAirTarget;
  return TheAirTarget;
}
Target &llvm::getTheAirelTarget() {
  static Target TheAirelTarget;
  return TheAirelTarget;
}

extern "C" void LLVMInitializeAirTargetInfo() {
  RegisterTarget<Triple::air, /*HasJIT=*/true> X(getTheAirTarget(),
                                                  "air", "Air", "Air");

  RegisterTarget<Triple::airel, /*HasJIT=*/true> Y(getTheAirelTarget(),
                                                    "airel", "Airel", "Air");
}