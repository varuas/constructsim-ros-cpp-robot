#pragma once
#include <string>

class HydraulicSystemMonitor {

public:
  HydraulicSystemMonitor() = default;
  HydraulicSystemMonitor(std::string temp, std::string fill_level,
                         std::string pressure);
  std::string getOilTemp();
  std::string getOilFillLevel();
  std::string getOilPressure();

private:
  std::string hydraulic_oil_temperature;
  std::string hydraulic_oil_tank_fill_level;
  std::string hydraulic_oil_pressure;
};