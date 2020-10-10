#include"lab4.h"

int main()
{
  char customerCode;
  double usage, cost;
  int begMeterValue, endMeterValue;

  begMeterValue = readMeterValue("beginning");
  endMeterValue = readMeterValue("ending");
  customerCode = readCustomerCode();

  usage = determineUsage(begMeterValue, endMeterValue);
  
  

  cost = determineCost(usage, customerCode);

  printResults(cost, usage, customerCode, begMeterValue, endMeterValue);
  
  
  return 0;   
}// end main

