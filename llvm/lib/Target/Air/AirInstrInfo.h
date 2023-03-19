//===-- AirInstrInfo.h - Air Instruction Information ----------*- C++ -*-===//
//
//                    The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the Air implementation of the TargetInstrInfo class.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIB_TARGET_AIR_AIRINSTRINFO_H
#define LLVM_LIB_TARGET_AIR_AIRINSTRINFO_H

#include "Air.h"
#include "AirRegisterInfo.h"
#include "llvm/CodeGen/MachineInstrBuilder.h"
#include "llvm/CodeGen/TargetInstrInfo.h"

#define GET_INSTRINFO_HEADER
#include "AirGenInstrInfo.inc"

namespace llvm {

class AirInstrInfo : public AirGenInstrInfo {
  virtual void anchor();
protected:
  const AirSubtarget &Subtarget;
public:
  explicit AirInstrInfo(const AirSubtarget &STI);

  static const AirInstrInfo *create(AirSubtarget &STI);

  // TargetInstrInfo is a superset of MRegister info. As such, whenever a client
  // has an instance of instruction info, it should always be able to get
  // register info as well (through this method).
  virtual const AirRegisterInfo &getRegisterInfo() const = 0;

  // Return the number of bytes of code the specified instruction maybe.
  unsigned GetInstSizeInBytes(const MachineInstr &MI) const;

};

const AirInstrInfo *createAirSEInstrInfo(const AirSubtarget &STI);
}

#endif
