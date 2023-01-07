#include<stdio.h>
#include<stdint.h>
#include<stdbool.h>

struct keyInfo{
  uint32_t keyLen;
  uint8_t keyType;
  bool isprivate;
};

struct status{
  
  uint8_t coreNo;
  bool core;
};

struct susApp{
  uint16_t appId;
  uint8_t priority;
  uint8_t appType;
};

union serviceParser
{
  /* data */
struct keyInfo ki;
struct status stat;
struct susApp sa;
};
