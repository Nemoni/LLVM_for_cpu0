//===-- AirRegisterInfo.td - Air Register defs -----------*- tablegen -*-===//
//
//                    The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.

//
//===----------------------------------------------------------------------===//

//===----------------------------------------------------------------------===//
// Declarations that describe the AIR register file
//===----------------------------------------------------------------------===//

// We have banks of 16 registers each.
class AirReg<bits<16> Enc, string n> : Register<n> {
  // For tablegen(... -gen-emitter) in CMakeLists.txt
  let HWEncoding = Enc;
  let Namespace = "Air";
}

// Air CPU Registers
class AirGPRReg<bits<16> Enc, string n> : AirReg<Enc, n>;

// Co-processor 0 Registers
class AirC0Reg<bits<16> Enc, string n> : AirReg<Enc, n>;

//===----------------------------------------------------------------------===//
//@Registers
//===----------------------------------------------------------------------===//
// The register string, such as "9" or "gp" will show on "llvm-objdump -d"
//@ All registers dfinition
let Namespace = "Air" in {
  //@ General Purpose Registers
  def ZERO : AirGPRReg<0,   "zero">, DwarfRegNum<[0]>;
  def AT   : AirGPRReg<1,   "1">,    DwarfRegNum<[1]>;
  def V0   : AirGPRReg<2,   "2">,    DwarfRegNum<[2]>;
  def V1   : AirGPRReg<3,   "3">,    DwarfRegNum<[3]>;
  def A0   : AirGPRReg<4,   "4">,    DwarfRegNum<[4]>;
  def A1   : AirGPRReg<5,   "5">,    DwarfRegNum<[5]>;
  def T9   : AirGPRReg<6,   "6">,    DwarfRegNum<[6]>;
  def T0   : AirGPRReg<7,   "7">,    DwarfRegNum<[7]>;
  def T1   : AirGPRReg<8,   "8">,    DwarfRegNum<[8]>;
  def S0   : AirGPRReg<9,   "9">,    DwarfRegNum<[9]>;
  def S1   : AirGPRReg<10,  "10">,   DwarfRegNum<[10]>;
  def GP   : AirGPRReg<11,  "11">,   DwarfRegNum<[11]>;
  def FP   : AirGPRReg<12,  "12">,   DwarfRegNum<[12]>;
  def SP   : AirGPRReg<13,  "13">,   DwarfRegNum<[13]>;
  def LR   : AirGPRReg<14,  "14">,   DwarfRegNum<[14]>;
  def SW   : AirGPRReg<15,  "15">,   DwarfRegNum<[15]>;

  def PC   : AirC0Reg<0, "pc">,    DwarfRegNum<[20]>;
  def EPC  : AirC0Reg<1, "epc">,   DwarfRegNum<[21]>;
}

//===----------------------------------------------------------------------===//
// @Register Classes
//===----------------------------------------------------------------------===//

def CPURegs : RegisterClass<"Air", [i32], 32, (add
  // Reserved
  ZERO, AT,
  // Return Values and Arguments
  V0, V1, A0, A1,
  // Not preserved across procedure calls
  T9, T0, T1,
  // Callee save
  S0, S1,
  // Reserved
  GP, FP,
  SP, LR, SW)>;

// @Status Registers class
def SR : RegisterClass<"Air", [i32], 32, (add SW)>;

// @Co-processor 0 Registers class
def C0Regs : RegisterClass<"Air", [i32], 32, (add PC, EPC)>;

def GPROut : RegisterClass<"Air", [i32], 32, (add (sub CPURegs, SW))>;