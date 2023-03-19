//===-- AirSubtarget.cpp - Air Subtarget Information --------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file implements the Air specific subclass of TargetSubtargetInfo.
//
//===----------------------------------------------------------------------===//

#include "AirSubtarget.h"

#include "AirMachineFunctionInfo.h"
#include "Air.h"
#include "AirRegisterInfo.h"

#include "AirTargetMachine.h"
#include "llvm/IR/Attributes.h"
#include "llvm/IR/Function.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Support/ErrorHandling.h"
#include "llvm/Support/TargetRegistry.h"

using namespace llvm;

#define DEBUG_TYPE "air-subtarget"

#define GET_SUBTARGETINFO_TARGET_DESC
#define GET_SUBTARGETINFO_CTOR
#include "AirGenSubtargetInfo.inc"

extern bool FixGlobalBaseReg;

void AirSubtarget::anchor() { }

AirSubtarget::AirSubtarget(const Triple &TT, const std::string &CPU,
                             const std::string &FS, bool little,
                             const AirTargetMachine &_TM) :
  // AirGenSubtargetInfo will display features by llc -march=air -mcpu=help
  AirGenSubtargetInfo(TT, CPU, FS),
  IsLittle(little), TM(_TM), TargetTriple(TT), TSInfo(),
      InstrInfo(
          AirInstrInfo::create(initializeSubtargetDependencies(CPU, FS, TM))),
      FrameLowering(AirFrameLowering::create(*this)),
      TLInfo(AirTargetLowering::create(TM, *this)) {

}

bool AirSubtarget::isPositionIndependent() const {
  return TM.isPositionIndependent();
}

AirSubtarget &
AirSubtarget::initializeSubtargetDependencies(StringRef CPU, StringRef FS,
                                               const TargetMachine &TM) {
  if (TargetTriple.getArch() == Triple::air || TargetTriple.getArch() == Triple::airel) {
    if (CPU.empty() || CPU == "generic") {
      CPU = "air32II";
    }
    else if (CPU == "help") {
      CPU = "";
      return *this;
    }
    else if (CPU != "air32I" && CPU != "air32II") {
      CPU = "air32II";
    }
  }
  else {
    errs() << "!!!Error, TargetTriple.getArch() = " << TargetTriple.getArch()
           <<  "CPU = " << CPU << "\n";
    exit(0);
  }

  if (CPU == "air32I")
    AirArchVersion = Air32I;
  else if (CPU == "air32II")
    AirArchVersion = Air32II;

  if (isAir32I()) {
    HasCmp = true;
    HasSlt = false;
  }
  else if (isAir32II()) {
    HasCmp = true;
    HasSlt = true;
  }
  else {
    errs() << "-mcpu must be empty(default:air32II), air32I or air32II" << "\n";
  }

  // Parse features string.
  ParseSubtargetFeatures(CPU, FS);
  // Initialize scheduling itinerary for the specified CPU.
  InstrItins = getInstrItineraryForCPU(CPU);

  return *this;
}

bool AirSubtarget::abiUsesSoftFloat() const {
//  return TM->Options.UseSoftFloat;
  return true;
}

const AirABIInfo &AirSubtarget::getABI() const { return TM.getABI(); }
