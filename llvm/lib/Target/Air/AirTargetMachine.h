//===-- AirTargetMachine.h - Define TargetMachine for Air -----*- C++ -*-===//
//
//                    The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===
//
// This file declares the Air specific subclass of TargetMachine.
//
//===----------------------------------------------------------------------===

#ifndef LLVM_LIB_TARGET_AIR_AIRTARGETMACHINE_H
#define LLVM_LIB_TARGET_AIR_AIRTARGETMACHINE_H

#include "MCTargetDesc/AirABIInfo.h"
#include "AirSubtarget.h"
#include "llvm/CodeGen/Passes.h"
#include "llvm/CodeGen/SelectionDAGISel.h"
#include "llvm/CodeGen/TargetFrameLowering.h"
#include "llvm/Target/TargetMachine.h"

namespace llvm {
class formatted_raw_ostream;
class AirRegisterInfo;

class AirTargetMachine : public LLVMTargetMachine {
  bool isLittle;
  std::unique_ptr<TargetLoweringObjectFile> TLOF;
  AirABIInfo ABI;
  AirSubtarget DefaultSubtarget;

  mutable StringMap<std::unique_ptr<AirSubtarget>> SubtargetMap;
public:
  AirTargetMachine(const Target &T, const Triple &TT, StringRef CPU,
                    StringRef FS, const TargetOptions &Options,
                    Optional<Reloc::Model> RM, Optional<CodeModel::Model> CM,
                    CodeGenOpt::Level OL, bool JIT, bool isLittle);
  ~AirTargetMachine() override;

  const AirSubtarget *getSubtargetImpl() const {
    return &DefaultSubtarget;
  }

  // Can use this interface to fetch subtarget
  const AirSubtarget *getSubtargetImpl(const Function &F) const override;

  // Pass Pipeline Configuration
  TargetPassConfig *createPassConfig(PassManagerBase &PM) override;

  TargetLoweringObjectFile *getObjFileLowering() const override {
    return TLOF.get();
  }
  bool isLittleEndian() const { return isLittle; }
  const AirABIInfo &getABI() const { return ABI; }
};

// This is big endian type Air32 target machine.
class AirebTargetMachine : public AirTargetMachine {
  virtual void anchor();
public:
  AirebTargetMachine(const Target &T, const Triple &TT, StringRef CPU,
                      StringRef FS, const TargetOptions &Options,
                      Optional<Reloc::Model> RM,
                      Optional<CodeModel::Model> CM,
                      CodeGenOpt::Level OL, bool JIT);
};
// This is default little endian Air32 target machine.
class AirelTargetMachine : public AirTargetMachine {
  virtual void anchor();
public:
  AirelTargetMachine(const Target &T, const Triple &TT, StringRef CPU,
                      StringRef FS, const TargetOptions &Options,
                      Optional<Reloc::Model> RM,
                      Optional<CodeModel::Model> CM,
                      CodeGenOpt::Level OL, bool JIT);
};
} // End llvm namespace

#endif