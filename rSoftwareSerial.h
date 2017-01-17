#pragma once
#include "B4RDefines.h"
//~dependson: <SoftwareSerial.h>
//~version: 1.00
namespace B4R {
	//~ShortName: SoftwareSerial
	class B4RSoftwareSerial{
		private: 
			B4RStream stream;
			SoftwareSerial* serial;
			uint8_t backend[sizeof(SoftwareSerial)];
		public:
			//Initializes the object.
			//BaudRate - Serial baudrate.
			//RecivePin - The pin used to receive data.
			//TransmitPin - The pin used to transmit data.
			void Initialize (ULong BaudRate, Byte ReceivePin, Byte TransmitPin);
			//Returns the internal stream. This can be used together with AsyncStreams to read or write from the serial.
			B4RStream* getStream();
			//Closes the serial port.
			void Close();
			//Gets or sets whether this object is currently the "listening" serial.
			//Only one software serial object can be listening.
			//Note that this property does nothing on ESP8266.
			bool getListening();
			void setListening(bool b);
	};
}