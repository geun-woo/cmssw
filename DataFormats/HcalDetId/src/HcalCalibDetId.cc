#include "DataFormats/HcalDetId/interface/HcalCalibDetId.h"


HcalCalibDetId::HcalCalibDetId() {
}


HcalCalibDetId::HcalCalibDetId(uint32_t rawid) : DetId(rawid) {
}

HcalCalibDetId::HcalCalibDetId(SectorId sector, int rbx, int channel) : DetId(Hcal,HcalCalibration) {
  id_|=(CalibrationBox<<20);
  id_|=(rbx&0x1F)|((sector&0xF)<<5)|((channel&0xF)<<9);
}

HcalCalibDetId::HcalCalibDetId(const DetId& gen) {
  if (gen.det()!=Hcal || gen.subdetId()!=HcalCalibration) {
    throw new std::exception();
  }
  id_=gen.rawId();
}

HcalCalibDetId& HcalCalibDetId::operator=(const DetId& gen) {
  if (gen.det()!=Hcal || gen.subdetId()!=HcalCalibration) {
    throw new std::exception();
  }
  id_=gen.rawId();
  return *this;
}

int HcalCalibDetId::rbx() const {
  return (calibFlavor()==CalibrationBox)?(id_&0x1F):(0);
}

HcalCalibDetId::SectorId HcalCalibDetId::sector() const {
  return (SectorId)((calibFlavor()==CalibrationBox)?((id_>>5)&0xF):(0));
}

std::string HcalCalibDetId::sectorString() const {
  switch (sector()) {
  case(HBplus): return "HB+";
  case(HBminus): return "HB-";
  case(HEplus): return "HE+";
  case(HEminus): return "HE-";
  case(HFplus): return "HF+";
  case(HFminus): return "HF-";
  case(HO2plus): return "HO2+";
  case(HO1plus): return "HO1+";
  case(HOzero): return "HO0";
  case(HO1minus): return "HO1-";
  case(HO2minus): return "HO2-";
  default : return "";
  }
}

int HcalCalibDetId::cboxChannel() const {
  return (calibFlavor()==CalibrationBox)?((id_>>9)&0xF):(0);
}

std::ostream& operator<<(std::ostream& s,const HcalCalibDetId& id) {
  switch (id.calibFlavor()) {
  case(HcalCalibDetId::CalibrationBox):
    return s << "(HcalCalibBox " << id.sectorString() << ' ' << id.rbx() 
	     << ':' << id.cboxChannel() << ')';
  default: return s;
  };
}


