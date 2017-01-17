#include "B4RDefines.h"
namespace B4R {
	void B4RSoftwareSerial::Initialize(ULong BaudRate, Byte ReceivePin, Byte TransmitPin) {
		stream.wrappedStream = serial = new (backend) SoftwareSerial(ReceivePin, TransmitPin);
		serial->begin(BaudRate);
	}
	B4RStream* B4RSoftwareSerial::getStream() {
		return &stream;
	}
	void B4RSoftwareSerial::Close() {
		#ifndef ESP_H
		serial->end();
		#endif
	}
	bool B4RSoftwareSerial::getListening() {
		#ifdef ESP_H
			return false;
		#else
			return serial->isListening();
		#endif
	}
	void B4RSoftwareSerial::setListening(bool b) {
		#ifndef ESP_H
		if (b)
			serial->listen();
		else
			serial->stopListening();
		#endif
		
	}
}