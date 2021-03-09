#include "B4RDefines.h"
namespace B4R {
	void B4RLiquidCrystal_I2C::Initialize(Byte Address, Byte Columns, Byte Rows) {
		lcd = new (beLcd) LiquidCrystal_I2C(Address, Columns, Rows);
		lcd->init();
	}
	void B4RLiquidCrystal_I2C::Write(Object* Message) {
		B4RStream::Print(lcd, Message);
	}
	void B4RLiquidCrystal_I2C::SetCursor(Byte Column, Byte Row) {
		lcd->setCursor(Column, Row);
	}
	void B4RLiquidCrystal_I2C::Clear() {
		lcd->clear();
	}
	void B4RLiquidCrystal_I2C::setBlink(bool b) {
		if (b)
			lcd->blink();
		else
			lcd->noBlink();
	}
	void B4RLiquidCrystal_I2C::setCursorOn(bool b) {
		if (b)
			lcd->cursor();
		else
			lcd->noCursor();
	}
	void B4RLiquidCrystal_I2C::setBacklight(bool b) {
		if (b)
			lcd->backlight();
		else
			lcd->noBacklight();
	}
}