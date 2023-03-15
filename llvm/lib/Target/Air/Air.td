//===-- Air.td - Describe the Air Target Machine ----*- tablegen -*-===//
//
//                  The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.

//
//===----------------------------------------------------------------------===//
// This is the top level entry point for the Air target.
//===----------------------------------------------------------------------===//

//===----------------------------------------------------------------------===//
// Target-independent interfaces
//===----------------------------------------------------------------------===//

include "llvm/Target/Target.td"

//===----------------------------------------------------------------------===//
// Target-dependent interfaces
//===----------------------------------------------------------------------===//

// Register Infomation
include "AirRegisterInfo.td"

// Calling Conversion
include "AirSchedule.td"

// Instruction Description
include "AirInstrInfo.td"

def AirInstrInfo : InstrInfo;

// Whill generate AirGenAsmWrite.inc included by AirInstPrinter.cpp, contents
// as follows,
// void AirInstPrinter::printInstruction(const MCInst *MI, raw_ostream &O) {...}
// const char* AirInstPrinter::getRegisterName(unsigned RegNo) {...}
def Air : Target {
  // def AirInstrInfo : InstrInfo as before.
  let InstructionSet = AirInstrInfo;
}