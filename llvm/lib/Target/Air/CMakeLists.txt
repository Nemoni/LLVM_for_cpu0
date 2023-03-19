
set (LLVM_TARGET_DEFINITIONS Air.td)

# Generate AirGenRegisterInfo.inc and AirGenInstrInfo.inc which included by
#  your hand code C++ files.
# AirGenRegisterInfo.inc came from AirRegisterInfo.td, AirGenInstrInfo.inc
#  came from AirInstrInfo.td.
tablegen(LLVM AirGenRegisterInfo.inc -gen-register-info)
tablegen(LLVM AirGenInstrInfo.inc -gen-instr-info)
tablegen(LLVM AirGenSubtargetInfo.inc -gen-subtarget)
tablegen(LLVM AirGenMCPseudoLowering.inc -gen-pseudo-lowering)
tablegen(LLVM AirGenDAGISel.inc -gen-dag-isel)
tablegen(LLVM AirGenCallingConv.inc -gen-callingconv)

# AirCommonTableGen must be defined
add_public_tablegen_target(AirCommonTableGen)

# AirCodeGen should match with LLVMBuild.txt AirCodeGen
add_llvm_target(AirCodeGen
  AirTargetMachine.cpp
  AirInstrInfo.cpp
  AirISelLowering.cpp
  AirMachineFunctionInfo.cpp
  AirRegisterInfo.cpp
  AirFrameLowering.cpp
  AirSEFrameLowering.cpp
  AirSEInstrInfo.cpp
  AirSEISelLowering.cpp
  AirSERegisterInfo.cpp
  AirSubtarget.cpp
  AirTargetObjectFile.cpp
  )

# Should match with "subdirectories = MCTargetDesc TargetInfo" in LLVMBuild.txt
add_subdirectory(TargetInfo)
add_subdirectory(MCTargetDesc)