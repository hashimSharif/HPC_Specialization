/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|*Machine Code Emitter                                                        *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

uint64_t SparcCodeEmitter::getBinaryCodeForInstr(const MachineInstr &MI) const {
  static const uint64_t InstBits[] = {
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(2155880448),	// ADDCCri
    UINT64_C(2155872256),	// ADDCCrr
    UINT64_C(2160074752),	// ADDXri
    UINT64_C(2160066560),	// ADDXrr
    UINT64_C(2147491840),	// ADDri
    UINT64_C(2147483648),	// ADDrr
    UINT64_C(0),	// ADJCALLSTACKDOWN
    UINT64_C(0),	// ADJCALLSTACKUP
    UINT64_C(2150113280),	// ANDNri
    UINT64_C(2150105088),	// ANDNrr
    UINT64_C(2148016128),	// ANDri
    UINT64_C(2148007936),	// ANDrr
    UINT64_C(276824064),	// BA
    UINT64_C(8388608),	// BCOND
    UINT64_C(2176851968),	// BINDri
    UINT64_C(2176843776),	// BINDrr
    UINT64_C(8388608),	// BPXCC
    UINT64_C(1073741824),	// CALL
    UINT64_C(2157977600),	// CMPri
    UINT64_C(2157969408),	// CMPrr
    UINT64_C(2174746944),	// FABSD
    UINT64_C(2174746976),	// FABSQ
    UINT64_C(2174746912),	// FABSS
    UINT64_C(2174748736),	// FADDD
    UINT64_C(2174748768),	// FADDQ
    UINT64_C(2174748704),	// FADDS
    UINT64_C(25165824),	// FBCOND
    UINT64_C(2175273536),	// FCMPD
    UINT64_C(2175273568),	// FCMPQ
    UINT64_C(2175273504),	// FCMPS
    UINT64_C(2174749120),	// FDIVD
    UINT64_C(2174749152),	// FDIVQ
    UINT64_C(2174749088),	// FDIVS
    UINT64_C(2174750144),	// FDMULQ
    UINT64_C(2174753344),	// FDTOI
    UINT64_C(2174750144),	// FDTOQ
    UINT64_C(2174752960),	// FDTOS
    UINT64_C(2174750784),	// FDTOX
    UINT64_C(2174753024),	// FITOD
    UINT64_C(2174753152),	// FITOQ
    UINT64_C(2174752896),	// FITOS
    UINT64_C(2170028032),	// FLUSHW
    UINT64_C(2174746688),	// FMOVD
    UINT64_C(2175270976),	// FMOVD_FCC
    UINT64_C(2175279168),	// FMOVD_ICC
    UINT64_C(0),	// FMOVD_XCC
    UINT64_C(2174746720),	// FMOVQ
    UINT64_C(2175271008),	// FMOVQ_FCC
    UINT64_C(2175279200),	// FMOVQ_ICC
    UINT64_C(2174746656),	// FMOVS
    UINT64_C(2175270944),	// FMOVS_FCC
    UINT64_C(2175279136),	// FMOVS_ICC
    UINT64_C(0),	// FMOVS_XCC
    UINT64_C(2174748992),	// FMULD
    UINT64_C(2174749024),	// FMULQ
    UINT64_C(2174748960),	// FMULS
    UINT64_C(2174746816),	// FNEGD
    UINT64_C(2174746848),	// FNEGQ
    UINT64_C(2174746784),	// FNEGS
    UINT64_C(2174753120),	// FQTOD
    UINT64_C(2174753376),	// FQTOI
    UINT64_C(2174752992),	// FQTOS
    UINT64_C(2174750816),	// FQTOX
    UINT64_C(2174749984),	// FSMULD
    UINT64_C(2174747968),	// FSQRTD
    UINT64_C(2174748000),	// FSQRTQ
    UINT64_C(2174747936),	// FSQRTS
    UINT64_C(2174753056),	// FSTOD
    UINT64_C(2174753312),	// FSTOI
    UINT64_C(2174753184),	// FSTOQ
    UINT64_C(2174750752),	// FSTOX
    UINT64_C(2174748864),	// FSUBD
    UINT64_C(2174748896),	// FSUBQ
    UINT64_C(2174748832),	// FSUBS
    UINT64_C(2174750976),	// FXTOD
    UINT64_C(2174751104),	// FXTOQ
    UINT64_C(2174750848),	// FXTOS
    UINT64_C(0),	// GETPCX
    UINT64_C(2680168448),	// JMPLri
    UINT64_C(2680160256),	// JMPLrr
    UINT64_C(3239583744),	// LDDFri
    UINT64_C(3239575552),	// LDDFrr
    UINT64_C(3238010880),	// LDFri
    UINT64_C(3238002688),	// LDFrr
    UINT64_C(3239059456),	// LDQFri
    UINT64_C(3239051264),	// LDQFrr
    UINT64_C(3225952256),	// LDSBri
    UINT64_C(3225944064),	// LDSBrr
    UINT64_C(3226476544),	// LDSHri
    UINT64_C(3226468352),	// LDSHrr
    UINT64_C(3227000832),	// LDSWri
    UINT64_C(3226992640),	// LDSWrr
    UINT64_C(3221757952),	// LDUBri
    UINT64_C(3221749760),	// LDUBrr
    UINT64_C(3222282240),	// LDUHri
    UINT64_C(3222274048),	// LDUHrr
    UINT64_C(3227000832),	// LDXri
    UINT64_C(3226992640),	// LDXrr
    UINT64_C(3221233664),	// LDri
    UINT64_C(3221225472),	// LDrr
    UINT64_C(2147491840),	// LEAX_ADDri
    UINT64_C(2147491840),	// LEA_ADDri
    UINT64_C(2170560512),	// MOVFCCri
    UINT64_C(2170552320),	// MOVFCCrr
    UINT64_C(2170822656),	// MOVICCri
    UINT64_C(2170814464),	// MOVICCrr
    UINT64_C(0),	// MOVXCCri
    UINT64_C(0),	// MOVXCCrr
    UINT64_C(2152210432),	// MULXri
    UINT64_C(2152202240),	// MULXrr
    UINT64_C(16777216),	// NOP
    UINT64_C(2150637568),	// ORNri
    UINT64_C(2150629376),	// ORNrr
    UINT64_C(2148540416),	// ORri
    UINT64_C(2148532224),	// ORrr
    UINT64_C(2171600896),	// POPCrr
    UINT64_C(2168455168),	// RDY
    UINT64_C(2179473408),	// RESTOREri
    UINT64_C(2179465216),	// RESTORErr
    UINT64_C(2177359872),	// RET
    UINT64_C(2177097728),	// RETL
    UINT64_C(2178949120),	// SAVEri
    UINT64_C(2178940928),	// SAVErr
    UINT64_C(2171084800),	// SDIVXri
    UINT64_C(2171076608),	// SDIVXrr
    UINT64_C(2155356160),	// SDIVri
    UINT64_C(2155347968),	// SDIVrr
    UINT64_C(0),	// SELECT_CC_DFP_FCC
    UINT64_C(0),	// SELECT_CC_DFP_ICC
    UINT64_C(0),	// SELECT_CC_FP_FCC
    UINT64_C(0),	// SELECT_CC_FP_ICC
    UINT64_C(0),	// SELECT_CC_Int_FCC
    UINT64_C(0),	// SELECT_CC_Int_ICC
    UINT64_C(0),	// SELECT_CC_QFP_FCC
    UINT64_C(0),	// SELECT_CC_QFP_ICC
    UINT64_C(16777216),	// SETHIi
    UINT64_C(2166894592),	// SLLXri
    UINT64_C(2166886400),	// SLLXrr
    UINT64_C(2166890496),	// SLLri
    UINT64_C(2166882304),	// SLLrr
    UINT64_C(2153259008),	// SMULri
    UINT64_C(2153250816),	// SMULrr
    UINT64_C(2167943168),	// SRAXri
    UINT64_C(2167934976),	// SRAXrr
    UINT64_C(2167939072),	// SRAri
    UINT64_C(2167930880),	// SRArr
    UINT64_C(2167418880),	// SRLXri
    UINT64_C(2167410688),	// SRLXrr
    UINT64_C(2167414784),	// SRLri
    UINT64_C(2167406592),	// SRLrr
    UINT64_C(3223855104),	// STBri
    UINT64_C(3223846912),	// STBrr
    UINT64_C(3241680896),	// STDFri
    UINT64_C(3241672704),	// STDFrr
    UINT64_C(3240108032),	// STFri
    UINT64_C(3240099840),	// STFrr
    UINT64_C(3224379392),	// STHri
    UINT64_C(3224371200),	// STHrr
    UINT64_C(3241156608),	// STQFri
    UINT64_C(3241148416),	// STQFrr
    UINT64_C(3228573696),	// STXri
    UINT64_C(3228565504),	// STXrr
    UINT64_C(3223330816),	// STri
    UINT64_C(3223322624),	// STrr
    UINT64_C(2157977600),	// SUBCCri
    UINT64_C(2157969408),	// SUBCCrr
    UINT64_C(2162163712),	// SUBXCCrr
    UINT64_C(2162171904),	// SUBXri
    UINT64_C(2162163712),	// SUBXrr
    UINT64_C(2149588992),	// SUBri
    UINT64_C(2149580800),	// SUBrr
    UINT64_C(2177916931),	// TA3
    UINT64_C(2147483648),	// TLS_ADDrr
    UINT64_C(1073741824),	// TLS_CALL
    UINT64_C(3226992640),	// TLS_LDXrr
    UINT64_C(3221225472),	// TLS_LDrr
    UINT64_C(2154307584),	// UDIVXri
    UINT64_C(2154299392),	// UDIVXrr
    UINT64_C(2154831872),	// UDIVri
    UINT64_C(2154823680),	// UDIVrr
    UINT64_C(2152734720),	// UMULri
    UINT64_C(2152726528),	// UMULrr
    UINT64_C(0),	// UNIMP
    UINT64_C(2172657664),	// WRYri
    UINT64_C(2172649472),	// WRYrr
    UINT64_C(2151161856),	// XNORri
    UINT64_C(2151153664),	// XNORrr
    UINT64_C(2149064704),	// XORri
    UINT64_C(2149056512),	// XORrr
    UINT64_C(0)
  };
  const unsigned opcode = MI.getOpcode();
  uint64_t Value = InstBits[opcode];
  uint64_t op = 0;
  (void)op;  // suppress warning
  switch (opcode) {
    case SP::FLUSHW:
    case SP::NOP:
    case SP::TA3: {
      break;
    }
    case SP::CALL:
    case SP::TLS_CALL: {
      // op: disp
      op = getMachineOpValue(MI, MI.getOperand(0));
      Value |= op & UINT64_C(1073741823);
      break;
    }
    case SP::BA:
    case SP::UNIMP: {
      // op: imm22
      op = getMachineOpValue(MI, MI.getOperand(0));
      Value |= op & UINT64_C(4194303);
      break;
    }
    case SP::BCOND:
    case SP::BPXCC:
    case SP::FBCOND: {
      // op: imm22
      op = getMachineOpValue(MI, MI.getOperand(0));
      Value |= op & UINT64_C(4194303);
      // op: cond
      op = getMachineOpValue(MI, MI.getOperand(1));
      Value |= (op & UINT64_C(15)) << 25;
      break;
    }
    case SP::SETHIi: {
      // op: imm22
      op = getMachineOpValue(MI, MI.getOperand(1));
      Value |= op & UINT64_C(4194303);
      // op: rd
      op = getMachineOpValue(MI, MI.getOperand(0));
      Value |= (op & UINT64_C(31)) << 25;
      break;
    }
    case SP::ADJCALLSTACKDOWN:
    case SP::ADJCALLSTACKUP:
    case SP::FMOVD_XCC:
    case SP::FMOVS_XCC:
    case SP::GETPCX:
    case SP::MOVXCCri:
    case SP::MOVXCCrr:
    case SP::SELECT_CC_DFP_FCC:
    case SP::SELECT_CC_DFP_ICC:
    case SP::SELECT_CC_FP_FCC:
    case SP::SELECT_CC_FP_ICC:
    case SP::SELECT_CC_Int_FCC:
    case SP::SELECT_CC_Int_ICC:
    case SP::SELECT_CC_QFP_FCC:
    case SP::SELECT_CC_QFP_ICC: {
      // op: op
      op = getMachineOpValue(MI, MI.getOperand(0));
      Value |= (op & UINT64_C(3)) << 30;
      break;
    }
    case SP::RDY: {
      // op: rd
      op = getMachineOpValue(MI, MI.getOperand(0));
      Value |= (op & UINT64_C(31)) << 25;
      break;
    }
    case SP::FMOVD_FCC:
    case SP::FMOVD_ICC:
    case SP::FMOVQ_FCC:
    case SP::FMOVQ_ICC:
    case SP::FMOVS_FCC:
    case SP::FMOVS_ICC:
    case SP::MOVFCCrr:
    case SP::MOVICCrr: {
      // op: rd
      op = getMachineOpValue(MI, MI.getOperand(0));
      Value |= (op & UINT64_C(31)) << 25;
      // op: cond
      op = getMachineOpValue(MI, MI.getOperand(3));
      Value |= (op & UINT64_C(15)) << 14;
      // op: rs2
      op = getMachineOpValue(MI, MI.getOperand(1));
      Value |= op & UINT64_C(31);
      break;
    }
    case SP::MOVFCCri:
    case SP::MOVICCri: {
      // op: rd
      op = getMachineOpValue(MI, MI.getOperand(0));
      Value |= (op & UINT64_C(31)) << 25;
      // op: cond
      op = getMachineOpValue(MI, MI.getOperand(3));
      Value |= (op & UINT64_C(15)) << 14;
      // op: simm11
      op = getMachineOpValue(MI, MI.getOperand(1));
      Value |= op & UINT64_C(2047);
      break;
    }
    case SP::SLLXrr:
    case SP::SRAXrr:
    case SP::SRLXrr: {
      // op: rd
      op = getMachineOpValue(MI, MI.getOperand(0));
      Value |= (op & UINT64_C(31)) << 25;
      // op: rs1
      op = getMachineOpValue(MI, MI.getOperand(0));
      Value |= (op & UINT64_C(31)) << 14;
      // op: rs2
      op = getMachineOpValue(MI, MI.getOperand(2));
      Value |= op & UINT64_C(31);
      break;
    }
    case SP::SLLXri:
    case SP::SRAXri:
    case SP::SRLXri: {
      // op: rd
      op = getMachineOpValue(MI, MI.getOperand(0));
      Value |= (op & UINT64_C(31)) << 25;
      // op: rs1
      op = getMachineOpValue(MI, MI.getOperand(0));
      Value |= (op & UINT64_C(31)) << 14;
      // op: shcnt
      op = getMachineOpValue(MI, MI.getOperand(2));
      Value |= op & UINT64_C(63);
      break;
    }
    case SP::ADDCCrr:
    case SP::ADDXrr:
    case SP::ADDrr:
    case SP::ANDNrr:
    case SP::ANDrr:
    case SP::FADDD:
    case SP::FADDQ:
    case SP::FADDS:
    case SP::FDIVD:
    case SP::FDIVQ:
    case SP::FDIVS:
    case SP::FDMULQ:
    case SP::FMULD:
    case SP::FMULQ:
    case SP::FMULS:
    case SP::FSMULD:
    case SP::FSUBD:
    case SP::FSUBQ:
    case SP::FSUBS:
    case SP::LDDFrr:
    case SP::LDFrr:
    case SP::LDQFrr:
    case SP::LDSBrr:
    case SP::LDSHrr:
    case SP::LDSWrr:
    case SP::LDUBrr:
    case SP::LDUHrr:
    case SP::LDXrr:
    case SP::LDrr:
    case SP::MULXrr:
    case SP::ORNrr:
    case SP::ORrr:
    case SP::RESTORErr:
    case SP::SAVErr:
    case SP::SDIVXrr:
    case SP::SDIVrr:
    case SP::SLLrr:
    case SP::SMULrr:
    case SP::SRArr:
    case SP::SRLrr:
    case SP::STXrr:
    case SP::SUBCCrr:
    case SP::SUBXCCrr:
    case SP::SUBXrr:
    case SP::SUBrr:
    case SP::TLS_ADDrr:
    case SP::TLS_LDXrr:
    case SP::TLS_LDrr:
    case SP::UDIVXrr:
    case SP::UDIVrr:
    case SP::UMULrr:
    case SP::XNORrr:
    case SP::XORrr: {
      // op: rd
      op = getMachineOpValue(MI, MI.getOperand(0));
      Value |= (op & UINT64_C(31)) << 25;
      // op: rs1
      op = getMachineOpValue(MI, MI.getOperand(1));
      Value |= (op & UINT64_C(31)) << 14;
      // op: rs2
      op = getMachineOpValue(MI, MI.getOperand(2));
      Value |= op & UINT64_C(31);
      break;
    }
    case SP::MULXri:
    case SP::SDIVXri:
    case SP::UDIVXri: {
      // op: rd
      op = getMachineOpValue(MI, MI.getOperand(0));
      Value |= (op & UINT64_C(31)) << 25;
      // op: rs1
      op = getMachineOpValue(MI, MI.getOperand(1));
      Value |= (op & UINT64_C(31)) << 14;
      // op: simm13
      op = getMachineOpValue(MI, MI.getOperand(0));
      Value |= op & UINT64_C(8191);
      break;
    }
    case SP::ADDCCri:
    case SP::ADDXri:
    case SP::ADDri:
    case SP::ANDNri:
    case SP::ANDri:
    case SP::LDDFri:
    case SP::LDFri:
    case SP::LDQFri:
    case SP::LDSBri:
    case SP::LDSHri:
    case SP::LDSWri:
    case SP::LDUBri:
    case SP::LDUHri:
    case SP::LDXri:
    case SP::LDri:
    case SP::LEAX_ADDri:
    case SP::LEA_ADDri:
    case SP::ORNri:
    case SP::ORri:
    case SP::RESTOREri:
    case SP::SAVEri:
    case SP::SDIVri:
    case SP::SLLri:
    case SP::SMULri:
    case SP::SRAri:
    case SP::SRLri:
    case SP::STXri:
    case SP::SUBCCri:
    case SP::SUBXri:
    case SP::SUBri:
    case SP::UDIVri:
    case SP::UMULri:
    case SP::XNORri:
    case SP::XORri: {
      // op: rd
      op = getMachineOpValue(MI, MI.getOperand(0));
      Value |= (op & UINT64_C(31)) << 25;
      // op: rs1
      op = getMachineOpValue(MI, MI.getOperand(1));
      Value |= (op & UINT64_C(31)) << 14;
      // op: simm13
      op = getMachineOpValue(MI, MI.getOperand(2));
      Value |= op & UINT64_C(8191);
      break;
    }
    case SP::FABSD:
    case SP::FABSQ:
    case SP::FABSS:
    case SP::FDTOI:
    case SP::FDTOQ:
    case SP::FDTOS:
    case SP::FDTOX:
    case SP::FITOD:
    case SP::FITOQ:
    case SP::FITOS:
    case SP::FMOVD:
    case SP::FMOVQ:
    case SP::FMOVS:
    case SP::FNEGD:
    case SP::FNEGQ:
    case SP::FNEGS:
    case SP::FQTOD:
    case SP::FQTOI:
    case SP::FQTOS:
    case SP::FQTOX:
    case SP::FSQRTD:
    case SP::FSQRTQ:
    case SP::FSQRTS:
    case SP::FSTOD:
    case SP::FSTOI:
    case SP::FSTOQ:
    case SP::FSTOX:
    case SP::FXTOD:
    case SP::FXTOQ:
    case SP::FXTOS:
    case SP::POPCrr: {
      // op: rd
      op = getMachineOpValue(MI, MI.getOperand(0));
      Value |= (op & UINT64_C(31)) << 25;
      // op: rs2
      op = getMachineOpValue(MI, MI.getOperand(1));
      Value |= op & UINT64_C(31);
      break;
    }
    case SP::STBrr:
    case SP::STDFrr:
    case SP::STFrr:
    case SP::STHrr:
    case SP::STQFrr:
    case SP::STrr: {
      // op: rd
      op = getMachineOpValue(MI, MI.getOperand(2));
      Value |= (op & UINT64_C(31)) << 25;
      // op: rs1
      op = getMachineOpValue(MI, MI.getOperand(0));
      Value |= (op & UINT64_C(31)) << 14;
      // op: rs2
      op = getMachineOpValue(MI, MI.getOperand(1));
      Value |= op & UINT64_C(31);
      break;
    }
    case SP::STBri:
    case SP::STDFri:
    case SP::STFri:
    case SP::STHri:
    case SP::STQFri:
    case SP::STri: {
      // op: rd
      op = getMachineOpValue(MI, MI.getOperand(2));
      Value |= (op & UINT64_C(31)) << 25;
      // op: rs1
      op = getMachineOpValue(MI, MI.getOperand(0));
      Value |= (op & UINT64_C(31)) << 14;
      // op: simm13
      op = getMachineOpValue(MI, MI.getOperand(1));
      Value |= op & UINT64_C(8191);
      break;
    }
    case SP::BINDrr:
    case SP::CMPrr:
    case SP::FCMPD:
    case SP::FCMPQ:
    case SP::FCMPS:
    case SP::JMPLrr:
    case SP::WRYrr: {
      // op: rs1
      op = getMachineOpValue(MI, MI.getOperand(0));
      Value |= (op & UINT64_C(31)) << 14;
      // op: rs2
      op = getMachineOpValue(MI, MI.getOperand(1));
      Value |= op & UINT64_C(31);
      break;
    }
    case SP::BINDri:
    case SP::CMPri:
    case SP::JMPLri:
    case SP::WRYri: {
      // op: rs1
      op = getMachineOpValue(MI, MI.getOperand(0));
      Value |= (op & UINT64_C(31)) << 14;
      // op: simm13
      op = getMachineOpValue(MI, MI.getOperand(1));
      Value |= op & UINT64_C(8191);
      break;
    }
    case SP::RET:
    case SP::RETL: {
      // op: simm13
      op = getMachineOpValue(MI, MI.getOperand(0));
      Value |= op & UINT64_C(8191);
      break;
    }
  default:
    std::string msg;
    raw_string_ostream Msg(msg);
    Msg << "Not supported instr: " << MI;
    report_fatal_error(Msg.str());
  }
  return Value;
}

