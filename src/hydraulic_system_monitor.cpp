#include "robot_info/hydraulic_system_monitor.h"

HydraulicSystemMonitor::HydraulicSystemMonitor(std::string temp,
                                               std::string fill_level,
                                               std::string pressure) {
  hydraulic_oil_temperature = temp;
  hydraulic_oil_tank_fill_level = fill_level;
  hydraulic_oil_pressure = pressure;
}

std::string HydraulicSystemMonitor::getOilTemp() {
  return hydraulic_oil_temperature;
}

std::string HydraulicSystemMonitor::getOilFillLevel() {
  return hydraulic_oil_tank_fill_level;
}

std::string HydraulicSystemMonitor::getOilPressure() {
  return hydraulic_oil_pressure;
}