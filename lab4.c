#include "lab4.h"

int readMeterValue(char * str)
{
  if (str == NULL)
  {
    perror("Nothing\n");
    exit(-99);

  }
  int value;

  printf("Please enter the %s meter value ", str );
  scanf("%d",&value);
 
  while(fgetc(stdin) != '\n'){}

  if (value <= 999999999)
  {
    return value;
    
  }
  else 
  {
    perror("Please type 9-digit code\n");
    exit(-99);
  }

  return value;
}

char readCustomerCode()
{
  char c, C,i,I,r,R,customerCode;
  printf("Please enter the customer's code: ");
  scanf("%c",&customerCode);

  if (customerCode == 'c' || customerCode == 'C')
  {
    printf("\nThe customer's code is c\n");
  }
  else if (customerCode == 'i' || customerCode == 'I')
  {
    printf("\nThe customer's code is i\n");
  }
  else if (customerCode == 'r' || customerCode == 'R')
  {
    printf("\nThe customer's code is r\n");
  }
  else 
  {
    perror("Only c,i,r or C,I,R for customer code");
    exit(-99);
  }
  return customerCode;


}

  
  
double determineUsage(int begMeterValue,int endMeterValue)
{
  double usage;
  if (begMeterValue < endMeterValue)
  {
    usage= (endMeterValue - begMeterValue)/10;
    return usage;
  }
  else if (begMeterValue > endMeterValue)
  {
    usage= (1000000000 - begMeterValue + endMeterValue);
    usage= usage/10;
    return usage;

  }

  


  return usage;
}

double determineCost(double usage, char customerCode)
{
  double cost;
  if (customerCode == 'r' || customerCode == 'R')
  {
    cost= 15.00 + (0.0005*usage);
    return cost;

  }
  else if (customerCode == 'c' || customerCode == 'C')
  {
    cost= 1000.00 + (0.00002*usage);
    return cost;
  }
  else if (customerCode == 'i' || customerCode == 'I')
  {
    if (usage <= 4*(10^6))
    {
      cost= 1000.00 + (0.00002*usage);
      return cost;
    }
    else if (usage > 4*(10^6) && usage <= 10*(10^6))
    {
      cost= 2000.00 +(0.00001*usage);
      return cost;
    }
    else if (usage > 10*(10^6))
    {
      cost= 2500.00 + (0.0025*usage);
      return cost;
    }

  return cost;
  }
  return cost;
}


void printResults(double cost, double usage, char customerCode, int begMeterValue, int endMeterValue)
{
  printf("The customer's meter reading at the beginning of the month was %09d\n", begMeterValue);
  printf("The customer's meter reading at the ending of the month was %09d\n", endMeterValue);
  printf("The amount of water the customer used is %.1lf gallons\n", usage);
  printf("The customer is being billed for $%.2lf\n", cost);

}



//5 functions