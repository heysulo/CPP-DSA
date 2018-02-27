#pragma once
#include <iostream>
#include <cstring>

#ifndef _VERBOSE_DYNAMIC_ARRAY_
#define _VERBOSE_DYNAMIC_ARRAY_ 0
#endif //_VERBOSE_DYNAMIC_ARRAY_

using namespace std;

template <typename T>
class DynamicArray {
private:
	T* pt_payload;
	unsigned int ui_InitialSize;
	unsigned int ui_PayloadSize;
	unsigned int ui_IncrementSize;
	DynamicArray(); // Avoid calling the constructor without the parameters
	unsigned int getNewPayloadSize(unsigned int uiRequestedLocation);
	void scalePaylodContainer(const unsigned int uiNewPayloadSize);
public:
	inline DynamicArray(unsigned int uiPayloadSize, unsigned int uiIncrementSize = 0);
	T& operator[](unsigned int location) ;
};

template<typename T>
DynamicArray<T>::DynamicArray(unsigned int uiPayloadSize, unsigned int uiIncrementSize)
{
	ui_PayloadSize = uiPayloadSize;
	ui_InitialSize = uiPayloadSize;
	ui_IncrementSize = uiIncrementSize;
	pt_payload = new T[uiPayloadSize];
	if (_VERBOSE_DYNAMIC_ARRAY_) {
		cout << "Constructing DynamicArray size of " << uiPayloadSize << endl;
	}
}

template<typename T>
void DynamicArray<T>::scalePaylodContainer(const unsigned int uiNewPayloadSize)
{
	T* ptNewScaledPayload = new T[uiNewPayloadSize];
	memcpy(ptNewScaledPayload, pt_payload, sizeof(T) * uiNewPayloadSize);
	delete[] pt_payload;
	pt_payload = ptNewScaledPayload;
	ui_PayloadSize = uiNewPayloadSize;
	if (_VERBOSE_DYNAMIC_ARRAY_) {
		cout << "Scaled DynamicArray size of size " << ui_InitialSize << " from " << ui_InitialSize << " to " << uiNewPayloadSize << endl;
	}
}

template<typename T>
unsigned int DynamicArray<T>::getNewPayloadSize(unsigned int uiRequestedLocation)
{
	unsigned int uiNewIncrementSize = ((uiRequestedLocation - ui_InitialSize) / (ui_IncrementSize ? ui_IncrementSize : ui_PayloadSize)) + 1;
	return ui_InitialSize + ui_IncrementSize * uiNewIncrementSize;
}

template<typename T>
T & DynamicArray<T>::operator[](unsigned int location)
{
	if (location >= ui_PayloadSize) {
		scalePaylodContainer(getNewPayloadSize(location));
	}
	return pt_payload[location];
}
