//===-- AirMCTargetDesc.cpp - Air Target Descriptions ---------*- C++ -*-===//
//
//                    The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file provides Air specific target descirptions.
//
//===----------------------------------------------------------------------===//

#include "AirMCTargetDesc.h"
#include "llvm/MC/MachineLocation.h"
#include "llvm/MC/MCELFStreamer.h"
#include "llvm/MC/MCInstrAnalysis.h"
#include "llvm/MC/MCInstPrinter.h"
#include "llvm/MC/MCInstrInfo.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/MC/MCSubtargetInfo.h"
#include "llvm/MC/MCSymbol.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Support/ErrorHandling.h"
#include "llvm/Support/FormattedStream.h"
#include "llvm/Support/TargetRegistry.h"

using namespace llvm;

#define GET_INSTRINFO_MC_DESC
#include "AirGenInstrInfo.inc"

#define GET_SUBTARGETINFO_MC_DESC
//#include "AirGenSubtargetInfo.inc"

#define GET_REGINFO_MC_DESC
#include "AirGenRegisterInfo.inc"

extern "C" void LLVMInitializeAirTargetMC() {
}