/*
* @Author: Ubi de Feo | Future Tailors
* @Date:   2017-07-05 07:15:42
* @Last Modified by:   ubi
* @Last Modified time: 2017-07-07 21:40:41
*/

/*	Future Tailors' Debouncer Library 											*/
/*	No more manually tracking milliseconds and writing spaghetti monsters		*/

#include "Arduino.h"
extern void pinActivated(uint8_t);
extern void pinDeactivated(uint8_t);

struct debounceItem {
	uint8_t pinNumber;
	uint8_t restState;
	uint8_t currentState;
	uint8_t previousState;
	uint8_t currentDebouncedState;
	uint8_t previousDebouncedState;
	uint32_t lastTimeChecked;
	debounceItem *nextItem = NULL;
};
class FTDebouncer {
private:
	debounceItem *firstDebounceItem, *lastDebounceItem;
	uint8_t debounceDelay;
	void readPins();
	void debouncePins();
	void checkStateChange();

public:
	FTDebouncer();
	FTDebouncer(uint16_t _debounceTime);
	~FTDebouncer();
	void run();
	void addPin(uint8_t _pinNr, uint8_t _restState);
	void addPin(uint8_t _pinNr, uint8_t _restState, uint8_t _pullUpMode);
	void init();
};



