//===-- Air.h - Top-level interface for Air representation ----*- C++ -*-===//
//
//                    The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===
//
// This file contains the entry points for global functions defined in
//  the LLVM Air backend.
//
//===----------------------------------------------------------------------===
#ifndef LLVM_LIB_TARGET_AIR_AIR_H
#define LLVM_LIB_TARGET_AIR_AIR_H

#include "MCTargetDesc/AirMCTargetDesc.h"
#include "llvm/Target/TargetMachine.h"

namespace llvm {
  class AirTargetMachine;
  class FunctionPass;
}

#define ENABLE_GPRESTORE  // The $gp register caller saved register enable

#endif
