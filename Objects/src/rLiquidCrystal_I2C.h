#pragma once
#include "B4RDefines.h"
#include "LiquidCrystal_I2C.h"
//~version: 1.01
namespace B4R {
	//~shortname: LiquidCrystal_I2C
	class B4RLiquidCrystal_I2C {
		private:
			uint8_t beLcd[sizeof(LiquidCrystal_I2C)];
			LiquidCrystal_I2C* lcd;
		public:
			void Initialize(Byte Address, Byte Columns, Byte Rows);
			/**
			*Writes the message. The message can be a string, a number or an array of bytes.
			*/
			void Write(Object* Message);
			/**
			*Sets the cursor position.
			*/
			void SetCursor(Byte Column, Byte Row);
			//Clears the screen and sets the cursor to (0,0).
			void Clear();
			//Sets whether the cursor should blink.
			void setBlink(bool b);
			//Sets the cursor state.
			void setCursorOn(bool b);
			//Sets the backlight state.
			void setBacklight(bool b);
			
	};
}