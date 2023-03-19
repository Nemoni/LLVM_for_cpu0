//===-- AirCallingConv.td - Calling Conventions for Air --*- tablegen -*-===//
//
//                    The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This describes the calling conventions for Air architecture.
//
//===----------------------------------------------------------------------===//

// Match if the current subtarget has a feature F.
class CCIfSubtarget<string F, CCAction A>
  : CCIf<!strconcat("State.getTarget().getSubtarget<AirSubtarget>().", F), A>;

def CSR_032 : CalleeSavedRegs<(add LR, FP, (sequence "S%u", 1, 0))>;
