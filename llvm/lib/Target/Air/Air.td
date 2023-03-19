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

// Calling Convention
include "AirCallingConv.td"

//===----------------------------------------------------------------------===//
// Air SUbtarget features
//===----------------------------------------------------------------------===//

def FeatureCmp            : SubtargetFeature<"cmp", "HasCmp", "true",
                                             "Enable 'cmp' instructions.">;
def FeatureSlt            : SubtargetFeature<"slt", "HasSlt", "true",
                                             "Enable 'slt' instructions.">;
def FeatureAir32I        : SubtargetFeature<"air32I", "AirArchVersion",
                                             "Air32I", "Air32I ISA Support",
                                             [FeatureCmp]>;
def FeatureAir32II       : SubtargetFeature<"air32II", "AirArchVersion",
                                             "Air32II", "Air32II ISA Support",
                                             [FeatureCmp, FeatureSlt]>;

//===----------------------------------------------------------------------===//
// Air processors supported
//===----------------------------------------------------------------------===//
class Proc<string Name, list<SubtargetFeature> Features>
  : Processor<Name, AirGenericItineraries, Features>;

def : Proc<"air32I", [FeatureAir32I]>;
def : Proc<"air32II", [FeatureAir32II]>;
// Above make AirGenSubtargetInfo.inc set feature bit as the following order:
// enum {
//   FeatureCmp =  1ULL << 0,
//   FeatureAir32I =  1ULL << 1,
//   FeatureAir32II =  1ULL << 2,
//   FeatureSlt =  1ULL << 3
// };
def AirInstrInfo : InstrInfo;

// Whill generate AirGenAsmWrite.inc included by AirInstPrinter.cpp, contents
// as follows,
// void AirInstPrinter::printInstruction(const MCInst *MI, raw_ostream &O) {...}
// const char* AirInstPrinter::getRegisterName(unsigned RegNo) {...}
def Air : Target {
  // def AirInstrInfo : InstrInfo as before.
  let InstructionSet = AirInstrInfo;
}