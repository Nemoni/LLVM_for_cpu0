//===-- AirSERegisterInfo.cpp - AIR Register Information ------== -------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the AIR implementation of the TargetRegisterInfo
// class.
//
//===----------------------------------------------------------------------===//

#include "AirSERegisterInfo.h"

using namespace llvm;

#define DEBUG_TYPE "air-reg-info"

AirSERegisterInfo::AirSERegisterInfo(const AirSubtarget &ST)
  : AirRegisterInfo(ST) {}

const TargetRegisterClass *
AirSERegisterInfo::intRegClass(unsigned Size) const {
  return &Air::CPURegsRegClass;
}
