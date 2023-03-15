//===-- AirTargetDesc.h - Air Target Descriptions -------------*- C++ -*-===//
//
//                    The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file provides Air specific target descriptions.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIB_TARGET_AIR_MCTARGETDESC_AIRMCTARGETDESC_H
#define LLVM_LIB_TARGET_AIR_MCTARGETDESC_AIRMCTARGETDESC_H

#include "llvm/Support/DataTypes.h"

namespace llvm {
  class Target;
  class Triple;

  Target &getTheAirTarget();
  Target &getTheAirelTarget();
}

// Defines symbolic names for Air registers. This defines a mapping from
//  register name to register number.
#define GET_REGINFO_ENUM
#include "AirGenRegisterInfo.inc"

// Defines symbolic names for Air instructions.
#define GET_INSTRINFO_ENUM
#include "AirGenInstrInfo.inc"

#define GET_SUBTARGETINFO_ENUM
//#include "AirGenSubtargetInfo.inc"

#endif
