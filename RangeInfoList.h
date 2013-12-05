// RangeInfoList.h
//

#ifndef RangeInfoList_h
#define RangeInfoList_h
#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
  #include <pins_arduino.h>
#endif
#include <stdarg.h>

#define ARG_SIZE 8
class IDrawable;


// a list of LED effect lists. Primarily for internal use
class RangeInfoList
{
private:
public:
  RangeInfoList * next;
  IDrawable * listItem;
  int rangeId;
  uint16_t offset;
  uint16_t size;
  uint32_t startTime;
  uint32_t lastRefreshTime;
  uint16_t refreshCount;
  char contextArgs[10];
  bool hasArgs;

  RangeInfoList (int rangeId, uint16_t offset, uint16_t size);
  ~ RangeInfoList ();
  // clears the list and frees any dynamically allocated items.
  void clear ();
 
  // clears any range effects
  void clearAll ();
  // clears the effect on the specified range
  void clearEffect (int rangeId);
  // adds a new item to this list
  void add (int rangeId, uint16_t offset, uint16_t size);
  // removes a range from the list. returns true if it was removed
  bool remove(int rangeId);
  // sets the effect for a particular range
  void setEffect(int rangeId, IDrawable & sequence);
  // sets the effect for a particular range and specifies the any context arguments that
  // should be used for this effect. Only 16 byes of aligned arguments may be used!
  void setEffectWithArgs(int rangeId, IDrawable & effect,va_list va);
  // determines if a sequence with the specified range already exists
  bool containsRange(int rangeId);
  // gets the current effect at the specified range
  IDrawable * getEffect(int rangeId);
};
#endif