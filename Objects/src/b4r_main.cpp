#include "B4RDefines.h"

B4R::Serial* b4r_main::_serial1;
B4R::Pin* b4r_main::_pinred;
B4R::Pin* b4r_main::_pingreen;
B4R::Pin* b4r_main::_pinblue;
B4R::Pin* b4r_main::_dht11pin;
B4R::B4RDht* b4r_main::_dht11sensor;
B4R::Pin* b4r_main::_relaypin;
bool b4r_main::_heateron;
B4R::B4RLiquidCrystal_I2C* b4r_main::_lcd;
B4R::Pin* b4r_main::_triggerpin;
B4R::Pin* b4r_main::_echopin;
ULong b4r_main::_pulsduration;
Double b4r_main::_distance;
B4R::Timer* b4r_main::_sendtriggertimer;
B4R::Array* b4r_main::_displayrow;
B4R::Pin* b4r_main::_coldbutton;
B4R::Pin* b4r_main::_hotbutton;
B4R::Timer* b4r_main::_timer1;
Byte b4r_main::_notactivecycles;
Double b4r_main::_temperature;
Double b4r_main::_optimaltemp;
static B4R::Serial be_gann1_3;
static B4R::Pin be_gann2_3;
static B4R::Pin be_gann2_7;
static B4R::Pin be_gann2_11;
static B4R::Pin be_gann3_3;
static B4R::B4RDht be_gann4_3;
static B4R::Pin be_gann5_3;
static B4R::B4RLiquidCrystal_I2C be_gann7_3;
static B4R::Pin be_gann8_3;
static B4R::Pin be_gann8_7;
static B4R::Timer be_gann11_3;
static B4R::B4RString be_gann12_4e1[2];
static B4R::Array be_gann12_4e2;
static B4R::B4RString* be_gann12_4e3[2];
static B4R::Pin be_gann13_3;
static B4R::Pin be_gann14_3;
static B4R::Timer be_gann15_3;


 void pulseins (B4R::Object* o) {
   b4r_main::_pulsduration = pulseIn(o->toULong(),HIGH);
}
void b4r_main::_appstart(){
const UInt cp = B4R::StackMemory::cp;
B4R::B4RString be_ann46_13;
B4R::B4RString be_ann46_17;
B4R::B4RString* be_ann46_18e1[3];
B4R::Array be_ann46_18e2;
B4R::B4RString be_ann47_13;
B4R::B4RString be_ann47_17;
B4R::B4RString* be_ann47_18e1[3];
B4R::Array be_ann47_18e2;
 //BA.debugLineNum = 45;BA.debugLine="Private Sub AppStart";
 //BA.debugLineNum = 46;BA.debugLine="Serial1.Initialize(115200)";
b4r_main::_serial1->Initialize((ULong) (115200));
 //BA.debugLineNum = 47;BA.debugLine="Log(\"AppStart\")";
B4R::Common::LogHelper(1,102,F("AppStart"));
 //BA.debugLineNum = 49;BA.debugLine="OptimalTemp = 25";
b4r_main::_optimaltemp = 25;
 //BA.debugLineNum = 50;BA.debugLine="HeaterON = False";
b4r_main::_heateron = Common_False;
 //BA.debugLineNum = 52;BA.debugLine="pinRed.Initialize(2, pinRed.MODE_OUTPUT)";
b4r_main::_pinred->Initialize((Byte) (2),Pin_MODE_OUTPUT);
 //BA.debugLineNum = 53;BA.debugLine="pinGreen.Initialize(3, pinGreen.MODE_OUTPUT)";
b4r_main::_pingreen->Initialize((Byte) (3),Pin_MODE_OUTPUT);
 //BA.debugLineNum = 54;BA.debugLine="pinBlue.Initialize(4, pinBlue.MODE_OUTPUT)";
b4r_main::_pinblue->Initialize((Byte) (4),Pin_MODE_OUTPUT);
 //BA.debugLineNum = 56;BA.debugLine="DHT11pin.Initialize(5,DHT11pin.MODE_INPUT)";
b4r_main::_dht11pin->Initialize((Byte) (5),Pin_MODE_INPUT);
 //BA.debugLineNum = 57;BA.debugLine="RelayPin.Initialize(6, RelayPin.MODE_OUTPUT)";
b4r_main::_relaypin->Initialize((Byte) (6),Pin_MODE_OUTPUT);
 //BA.debugLineNum = 59;BA.debugLine="triggerpin.Initialize(9,triggerpin.MODE_OUTPUT)";
b4r_main::_triggerpin->Initialize((Byte) (9),Pin_MODE_OUTPUT);
 //BA.debugLineNum = 60;BA.debugLine="echopin.Initialize(8,echopin.MODE_INPUT)";
b4r_main::_echopin->Initialize((Byte) (8),Pin_MODE_INPUT);
 //BA.debugLineNum = 61;BA.debugLine="echopin.DigitalWrite(False)";
b4r_main::_echopin->DigitalWrite(Common_False);
 //BA.debugLineNum = 63;BA.debugLine="SendTriggerTimer.Initialize(\"SendTriggerTimer_Tic";
b4r_main::_sendtriggertimer->Initialize(_sendtriggertimer_tick,(ULong) (1000));
 //BA.debugLineNum = 64;BA.debugLine="SendTriggerTimer.Enabled = True";
b4r_main::_sendtriggertimer->setEnabled(Common_True);
 //BA.debugLineNum = 66;BA.debugLine="Timer1.Initialize(\"Timer1_Tick\", 2000)";
b4r_main::_timer1->Initialize(_timer1_tick,(ULong) (2000));
 //BA.debugLineNum = 67;BA.debugLine="Timer1.Enabled=True";
b4r_main::_timer1->setEnabled(Common_True);
 //BA.debugLineNum = 69;BA.debugLine="ColdButton.Initialize(ColdButton.A1, ColdButto";
b4r_main::_coldbutton->Initialize(Pin_A1,Pin_MODE_INPUT_PULLUP);
 //BA.debugLineNum = 70;BA.debugLine="ColdButton.AddListener(\"COLD_StateChanged\")";
b4r_main::_coldbutton->AddListener(_cold_statechanged);
 //BA.debugLineNum = 71;BA.debugLine="HotButton.Initialize(HotButton.A0, HotButton.M";
b4r_main::_hotbutton->Initialize(Pin_A0,Pin_MODE_INPUT_PULLUP);
 //BA.debugLineNum = 72;BA.debugLine="HotButton.AddListener(\"HOT_StateChanged\")";
b4r_main::_hotbutton->AddListener(_hot_statechanged);
 //BA.debugLineNum = 74;BA.debugLine="Delay(2000)";
Common_Delay((ULong) (2000));
 //BA.debugLineNum = 76;BA.debugLine="DHT11sensor.Read11(DHT11pin.PinNumber)";
b4r_main::_dht11sensor->Read11(b4r_main::_dht11pin->PinNumber);
 //BA.debugLineNum = 77;BA.debugLine="temperature = DHT11sensor.GetTemperature";
b4r_main::_temperature = b4r_main::_dht11sensor->GetTemperature();
 //BA.debugLineNum = 79;BA.debugLine="lcd.Initialize(0x27, 16, 2)";
b4r_main::_lcd->Initialize((Byte) (0x27),(Byte) (16),(Byte) (2));
 //BA.debugLineNum = 80;BA.debugLine="lcd.Clear";
b4r_main::_lcd->Clear();
 //BA.debugLineNum = 82;BA.debugLine="DisplayRow(0) = JoinStrings(Array As String(\"Temp";
((B4R::B4RString**)b4r_main::_displayrow->getData((UInt) (0)))[B4R::Array::staticIndex] = B4R::__c->JoinStrings(be_ann46_18e2.create(be_ann46_18e1,3,100,be_ann46_13.wrap("Temp: "),B4R::B4RString::fromNumber((Double)(b4r_main::_temperature)),be_ann46_17.wrap(" C")));
 //BA.debugLineNum = 83;BA.debugLine="DisplayRow(1) = JoinStrings(Array As String(\"Comf";
((B4R::B4RString**)b4r_main::_displayrow->getData((UInt) (1)))[B4R::Array::staticIndex] = B4R::__c->JoinStrings(be_ann47_18e2.create(be_ann47_18e1,3,100,be_ann47_13.wrap("Comfort: "),B4R::B4RString::fromNumber((Double)(b4r_main::_optimaltemp)),be_ann47_17.wrap(" C")));
 //BA.debugLineNum = 84;BA.debugLine="WriteDisplay(DisplayRow(0), DisplayRow(1))";
_writedisplay(((B4R::B4RString**)b4r_main::_displayrow->getData((UInt) (0)))[B4R::Array::staticIndex],((B4R::B4RString**)b4r_main::_displayrow->getData((UInt) (1)))[B4R::Array::staticIndex]);
 //BA.debugLineNum = 86;BA.debugLine="NotActiveCycles = 0";
b4r_main::_notactivecycles = (Byte) (0);
 //BA.debugLineNum = 88;BA.debugLine="End Sub";
B4R::StackMemory::cp = cp;
}
void b4r_main::_cold_statechanged(bool _state){
const UInt cp = B4R::StackMemory::cp;
B4R::B4RString be_ann94_13;
B4R::B4RString be_ann94_17;
B4R::B4RString* be_ann94_18e1[3];
B4R::Array be_ann94_18e2;
B4R::B4RString be_ann95_13;
B4R::B4RString be_ann95_17;
B4R::B4RString* be_ann95_18e1[3];
B4R::Array be_ann95_18e2;
 //BA.debugLineNum = 137;BA.debugLine="Sub COLD_StateChanged (State As Boolean)";
 //BA.debugLineNum = 138;BA.debugLine="If State = True Then";
if (_state==Common_True) { 
 //BA.debugLineNum = 139;BA.debugLine="OptimalTemp = OptimalTemp - 1";
b4r_main::_optimaltemp = b4r_main::_optimaltemp-1;
 //BA.debugLineNum = 140;BA.debugLine="DisplayRow(0) = JoinStrings(Array As String(\"Tem";
((B4R::B4RString**)b4r_main::_displayrow->getData((UInt) (0)))[B4R::Array::staticIndex] = B4R::__c->JoinStrings(be_ann94_18e2.create(be_ann94_18e1,3,100,be_ann94_13.wrap("Temp: "),B4R::B4RString::fromNumber((Double)(b4r_main::_temperature)),be_ann94_17.wrap(" C")));
 //BA.debugLineNum = 141;BA.debugLine="DisplayRow(1) = JoinStrings(Array As String(\"Com";
((B4R::B4RString**)b4r_main::_displayrow->getData((UInt) (1)))[B4R::Array::staticIndex] = B4R::__c->JoinStrings(be_ann95_18e2.create(be_ann95_18e1,3,100,be_ann95_13.wrap("Comfort: "),B4R::B4RString::fromNumber((Double)(b4r_main::_optimaltemp)),be_ann95_17.wrap(" C")));
 //BA.debugLineNum = 142;BA.debugLine="WriteDisplay(DisplayRow(0), DisplayRow(1))";
_writedisplay(((B4R::B4RString**)b4r_main::_displayrow->getData((UInt) (0)))[B4R::Array::staticIndex],((B4R::B4RString**)b4r_main::_displayrow->getData((UInt) (1)))[B4R::Array::staticIndex]);
 //BA.debugLineNum = 143;BA.debugLine="NotActiveCycles = 0";
b4r_main::_notactivecycles = (Byte) (0);
 };
 //BA.debugLineNum = 145;BA.debugLine="End Sub";
B4R::StackMemory::cp = cp;
}
void b4r_main::_hot_statechanged(bool _state){
const UInt cp = B4R::StackMemory::cp;
B4R::B4RString be_ann103_13;
B4R::B4RString be_ann103_17;
B4R::B4RString* be_ann103_18e1[3];
B4R::Array be_ann103_18e2;
B4R::B4RString be_ann104_13;
B4R::B4RString be_ann104_17;
B4R::B4RString* be_ann104_18e1[3];
B4R::Array be_ann104_18e2;
 //BA.debugLineNum = 147;BA.debugLine="Sub HOT_StateChanged (State As Boolean)";
 //BA.debugLineNum = 148;BA.debugLine="If State = True Then";
if (_state==Common_True) { 
 //BA.debugLineNum = 149;BA.debugLine="OptimalTemp = OptimalTemp + 1";
b4r_main::_optimaltemp = b4r_main::_optimaltemp+1;
 //BA.debugLineNum = 150;BA.debugLine="DisplayRow(0) = JoinStrings(Array As String(\"Tem";
((B4R::B4RString**)b4r_main::_displayrow->getData((UInt) (0)))[B4R::Array::staticIndex] = B4R::__c->JoinStrings(be_ann103_18e2.create(be_ann103_18e1,3,100,be_ann103_13.wrap("Temp: "),B4R::B4RString::fromNumber((Double)(b4r_main::_temperature)),be_ann103_17.wrap(" C")));
 //BA.debugLineNum = 151;BA.debugLine="DisplayRow(1) = JoinStrings(Array As String(\"Com";
((B4R::B4RString**)b4r_main::_displayrow->getData((UInt) (1)))[B4R::Array::staticIndex] = B4R::__c->JoinStrings(be_ann104_18e2.create(be_ann104_18e1,3,100,be_ann104_13.wrap("Comfort: "),B4R::B4RString::fromNumber((Double)(b4r_main::_optimaltemp)),be_ann104_17.wrap(" C")));
 //BA.debugLineNum = 152;BA.debugLine="WriteDisplay(DisplayRow(0), DisplayRow(1))";
_writedisplay(((B4R::B4RString**)b4r_main::_displayrow->getData((UInt) (0)))[B4R::Array::staticIndex],((B4R::B4RString**)b4r_main::_displayrow->getData((UInt) (1)))[B4R::Array::staticIndex]);
 //BA.debugLineNum = 153;BA.debugLine="NotActiveCycles = 0";
b4r_main::_notactivecycles = (Byte) (0);
 };
 //BA.debugLineNum = 155;BA.debugLine="End Sub";
B4R::StackMemory::cp = cp;
}

void b4r_main::initializeProcessGlobals() {
     B4R::StackMemory::buffer = (byte*)malloc(STACK_BUFFER_SIZE);
     b4r_main::_process_globals();

   
}
void b4r_main::_process_globals(){
const UInt cp = B4R::StackMemory::cp;
 //BA.debugLineNum = 13;BA.debugLine="Sub Process_Globals";
 //BA.debugLineNum = 14;BA.debugLine="Public Serial1 As Serial";
b4r_main::_serial1 = &be_gann1_3;
 //BA.debugLineNum = 16;BA.debugLine="Private pinRed, pinGreen, pinBlue As Pin";
b4r_main::_pinred = &be_gann2_3;
b4r_main::_pingreen = &be_gann2_7;
b4r_main::_pinblue = &be_gann2_11;
 //BA.debugLineNum = 18;BA.debugLine="Private DHT11pin As Pin";
b4r_main::_dht11pin = &be_gann3_3;
 //BA.debugLineNum = 19;BA.debugLine="Private DHT11sensor As dht";
b4r_main::_dht11sensor = &be_gann4_3;
 //BA.debugLineNum = 21;BA.debugLine="Private RelayPin As Pin";
b4r_main::_relaypin = &be_gann5_3;
 //BA.debugLineNum = 22;BA.debugLine="Private HeaterON As Boolean";
b4r_main::_heateron = false;
 //BA.debugLineNum = 24;BA.debugLine="Private lcd As LiquidCrystal_I2C";
b4r_main::_lcd = &be_gann7_3;
 //BA.debugLineNum = 26;BA.debugLine="Private triggerpin,	echopin As Pin";
b4r_main::_triggerpin = &be_gann8_3;
b4r_main::_echopin = &be_gann8_7;
 //BA.debugLineNum = 28;BA.debugLine="Dim pulsduration As ULong             'Pulse Widt";
b4r_main::_pulsduration = 0L;
 //BA.debugLineNum = 29;BA.debugLine="Dim distance As Double";
b4r_main::_distance = 0;
 //BA.debugLineNum = 30;BA.debugLine="Dim SendTriggerTimer As Timer";
b4r_main::_sendtriggertimer = &be_gann11_3;
 //BA.debugLineNum = 32;BA.debugLine="Dim DisplayRow(2) As String";
b4r_main::_displayrow =be_gann12_4e2.wrapObjects((void**)be_gann12_4e3,be_gann12_4e1,2, sizeof(B4R::B4RString));
 //BA.debugLineNum = 34;BA.debugLine="Private ColdButton As Pin";
b4r_main::_coldbutton = &be_gann13_3;
 //BA.debugLineNum = 35;BA.debugLine="Private HotButton As Pin";
b4r_main::_hotbutton = &be_gann14_3;
 //BA.debugLineNum = 37;BA.debugLine="Private Timer1 As Timer";
b4r_main::_timer1 = &be_gann15_3;
 //BA.debugLineNum = 39;BA.debugLine="Public NotActiveCycles As Byte";
b4r_main::_notactivecycles = 0;
 //BA.debugLineNum = 40;BA.debugLine="Public temperature As Double";
b4r_main::_temperature = 0;
 //BA.debugLineNum = 41;BA.debugLine="Public OptimalTemp As Double";
b4r_main::_optimaltemp = 0;
 //BA.debugLineNum = 43;BA.debugLine="End Sub";
}
void b4r_main::_sendtriggertimer_tick(){
const UInt cp = B4R::StackMemory::cp;
B4R::Object be_ann119_8;
B4R::B4RString be_ann122_13;
B4R::B4RString be_ann122_17;
B4R::B4RString* be_ann122_18e1[3];
B4R::Array be_ann122_18e2;
B4R::B4RString be_ann123_13;
B4R::B4RString be_ann123_17;
B4R::B4RString* be_ann123_18e1[3];
B4R::Array be_ann123_18e2;
 //BA.debugLineNum = 165;BA.debugLine="Sub SendTriggerTimer_Tick";
 //BA.debugLineNum = 167;BA.debugLine="triggerpin.DigitalWrite(True)";
b4r_main::_triggerpin->DigitalWrite(Common_True);
 //BA.debugLineNum = 168;BA.debugLine="triggerpin.DigitalWrite(False)";
b4r_main::_triggerpin->DigitalWrite(Common_False);
 //BA.debugLineNum = 170;BA.debugLine="RunNative(\"pulseins\",echopin.PinNumber)";
Common_RunNative(pulseins,be_ann119_8.wrapNumber((Long)b4r_main::_echopin->PinNumber));
 //BA.debugLineNum = 171;BA.debugLine="distance=(0.5*pulsduration)/29.1";
b4r_main::_distance = (0.5*b4r_main::_pulsduration)/(Double)29.1;
 //BA.debugLineNum = 173;BA.debugLine="If (distance< 30) And (distance>2) Then";
if ((b4r_main::_distance<30) && (b4r_main::_distance>2)) { 
 //BA.debugLineNum = 174;BA.debugLine="DisplayRow(0) = JoinStrings(Array As String(\"Tem";
((B4R::B4RString**)b4r_main::_displayrow->getData((UInt) (0)))[B4R::Array::staticIndex] = B4R::__c->JoinStrings(be_ann122_18e2.create(be_ann122_18e1,3,100,be_ann122_13.wrap("Temp: "),B4R::B4RString::fromNumber((Double)(b4r_main::_temperature)),be_ann122_17.wrap(" C")));
 //BA.debugLineNum = 175;BA.debugLine="DisplayRow(1) = JoinStrings(Array As String(\"Com";
((B4R::B4RString**)b4r_main::_displayrow->getData((UInt) (1)))[B4R::Array::staticIndex] = B4R::__c->JoinStrings(be_ann123_18e2.create(be_ann123_18e1,3,100,be_ann123_13.wrap("Comfort: "),B4R::B4RString::fromNumber((Double)(b4r_main::_optimaltemp)),be_ann123_17.wrap(" C")));
 //BA.debugLineNum = 176;BA.debugLine="WriteDisplay(DisplayRow(0), DisplayRow(1))";
_writedisplay(((B4R::B4RString**)b4r_main::_displayrow->getData((UInt) (0)))[B4R::Array::staticIndex],((B4R::B4RString**)b4r_main::_displayrow->getData((UInt) (1)))[B4R::Array::staticIndex]);
 //BA.debugLineNum = 177;BA.debugLine="NotActiveCycles = 0";
b4r_main::_notactivecycles = (Byte) (0);
 //BA.debugLineNum = 178;BA.debugLine="Log(\"Distance Sensor TRUE\")";
B4R::Common::LogHelper(1,102,F("Distance Sensor TRUE"));
 };
 //BA.debugLineNum = 181;BA.debugLine="End Sub";
B4R::StackMemory::cp = cp;
}
void b4r_main::_timer1_tick(){
const UInt cp = B4R::StackMemory::cp;
 //BA.debugLineNum = 90;BA.debugLine="Sub Timer1_Tick";
 //BA.debugLineNum = 91;BA.debugLine="DHT11sensor.Read11(DHT11pin.PinNumber)";
b4r_main::_dht11sensor->Read11(b4r_main::_dht11pin->PinNumber);
 //BA.debugLineNum = 92;BA.debugLine="temperature = DHT11sensor.GetTemperature";
b4r_main::_temperature = b4r_main::_dht11sensor->GetTemperature();
 //BA.debugLineNum = 93;BA.debugLine="NotActiveCycles = NotActiveCycles + 1";
b4r_main::_notactivecycles = (Byte) (b4r_main::_notactivecycles+1);
 //BA.debugLineNum = 95;BA.debugLine="If temperature < OptimalTemp Then			' Cold";
if (b4r_main::_temperature<b4r_main::_optimaltemp) { 
 //BA.debugLineNum = 96;BA.debugLine="pinRed.DigitalWrite(False)";
b4r_main::_pinred->DigitalWrite(Common_False);
 //BA.debugLineNum = 97;BA.debugLine="pinGreen.DigitalWrite(False)";
b4r_main::_pingreen->DigitalWrite(Common_False);
 //BA.debugLineNum = 98;BA.debugLine="pinBlue.Digitalwrite(True)";
b4r_main::_pinblue->DigitalWrite(Common_True);
 //BA.debugLineNum = 99;BA.debugLine="If HeaterON = False Then";
if (b4r_main::_heateron==Common_False) { 
 //BA.debugLineNum = 100;BA.debugLine="RelayPin.DigitalWrite(True)";
b4r_main::_relaypin->DigitalWrite(Common_True);
 //BA.debugLineNum = 101;BA.debugLine="HeaterON = True";
b4r_main::_heateron = Common_True;
 //BA.debugLineNum = 102;BA.debugLine="NotActiveCycles = 0";
b4r_main::_notactivecycles = (Byte) (0);
 //BA.debugLineNum = 103;BA.debugLine="Log(\"Heater ON\")";
B4R::Common::LogHelper(1,102,F("Heater ON"));
 };
 }else if(b4r_main::_temperature==b4r_main::_optimaltemp) { 
 //BA.debugLineNum = 107;BA.debugLine="pinRed.DigitalWrite(False)";
b4r_main::_pinred->DigitalWrite(Common_False);
 //BA.debugLineNum = 108;BA.debugLine="pinGreen.DigitalWrite(True)";
b4r_main::_pingreen->DigitalWrite(Common_True);
 //BA.debugLineNum = 109;BA.debugLine="pinBlue.Digitalwrite(False)";
b4r_main::_pinblue->DigitalWrite(Common_False);
 }else if(b4r_main::_temperature>b4r_main::_optimaltemp) { 
 //BA.debugLineNum = 112;BA.debugLine="pinRed.DigitalWrite(True)";
b4r_main::_pinred->DigitalWrite(Common_True);
 //BA.debugLineNum = 113;BA.debugLine="pinGreen.DigitalWrite(False)";
b4r_main::_pingreen->DigitalWrite(Common_False);
 //BA.debugLineNum = 114;BA.debugLine="pinBlue.Digitalwrite(False)";
b4r_main::_pinblue->DigitalWrite(Common_False);
 //BA.debugLineNum = 115;BA.debugLine="If HeaterON = True Then";
if (b4r_main::_heateron==Common_True) { 
 //BA.debugLineNum = 116;BA.debugLine="RelayPin.DigitalWrite(False)";
b4r_main::_relaypin->DigitalWrite(Common_False);
 //BA.debugLineNum = 117;BA.debugLine="HeaterON = False";
b4r_main::_heateron = Common_False;
 //BA.debugLineNum = 118;BA.debugLine="NotActiveCycles = 0";
b4r_main::_notactivecycles = (Byte) (0);
 //BA.debugLineNum = 119;BA.debugLine="Log(\"Heater OFF\")";
B4R::Common::LogHelper(1,102,F("Heater OFF"));
 };
 }else {
 //BA.debugLineNum = 122;BA.debugLine="pinRed.DigitalWrite(False)";
b4r_main::_pinred->DigitalWrite(Common_False);
 //BA.debugLineNum = 123;BA.debugLine="pinGreen.DigitalWrite(False)";
b4r_main::_pingreen->DigitalWrite(Common_False);
 //BA.debugLineNum = 124;BA.debugLine="pinBlue.Digitalwrite(False)";
b4r_main::_pinblue->DigitalWrite(Common_False);
 };
 //BA.debugLineNum = 127;BA.debugLine="If NotActiveCycles > 3 Then";
if (b4r_main::_notactivecycles>3) { 
 //BA.debugLineNum = 128;BA.debugLine="lcd.Backlight = False";
b4r_main::_lcd->setBacklight(Common_False);
 };
 //BA.debugLineNum = 131;BA.debugLine="If NotActiveCycles > 50 Then";
if (b4r_main::_notactivecycles>50) { 
 //BA.debugLineNum = 132;BA.debugLine="NotActiveCycles = 5";
b4r_main::_notactivecycles = (Byte) (5);
 };
 //BA.debugLineNum = 135;BA.debugLine="End Sub";
B4R::StackMemory::cp = cp;
}
void b4r_main::_writedisplay(B4R::B4RString* _row1,B4R::B4RString* _row2){
const UInt cp = B4R::StackMemory::cp;
B4R::Object be_ann112_4;
B4R::Object be_ann114_4;
 //BA.debugLineNum = 157;BA.debugLine="Sub WriteDisplay(row1 As String, row2 As String)";
 //BA.debugLineNum = 158;BA.debugLine="lcd.Backlight = True";
b4r_main::_lcd->setBacklight(Common_True);
 //BA.debugLineNum = 159;BA.debugLine="lcd.SetCursor(0,0)";
b4r_main::_lcd->SetCursor((Byte) (0),(Byte) (0));
 //BA.debugLineNum = 160;BA.debugLine="lcd.Write(row1)";
b4r_main::_lcd->Write(be_ann112_4.wrapPointer(_row1->data));
 //BA.debugLineNum = 161;BA.debugLine="lcd.SetCursor(0,1)";
b4r_main::_lcd->SetCursor((Byte) (0),(Byte) (1));
 //BA.debugLineNum = 162;BA.debugLine="lcd.Write(row2)";
b4r_main::_lcd->Write(be_ann114_4.wrapPointer(_row2->data));
 //BA.debugLineNum = 163;BA.debugLine="End Sub";
B4R::StackMemory::cp = cp;
}
