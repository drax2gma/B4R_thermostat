
#ifndef b4r_main_h
#define b4r_main_h

class b4r_main {
public:

static void initializeProcessGlobals();
static void _appstart();
static void _cold_statechanged(bool _state);
static void _hot_statechanged(bool _state);
static void _process_globals();
static B4R::Serial* _serial1;
static B4R::Pin* _pinred;
static B4R::Pin* _pingreen;
static B4R::Pin* _pinblue;
static B4R::Pin* _dht11pin;
static B4R::B4RDht* _dht11sensor;
static B4R::Pin* _relaypin;
static bool _heateron;
static B4R::B4RLiquidCrystal_I2C* _lcd;
static B4R::Pin* _triggerpin;
static B4R::Pin* _echopin;
static ULong _pulsduration;
static Double _distance;
static B4R::Timer* _sendtriggertimer;
static B4R::Array* _displayrow;
static B4R::Pin* _coldbutton;
static B4R::Pin* _hotbutton;
static B4R::Timer* _timer1;
static Byte _notactivecycles;
static Double _temperature;
static Double _optimaltemp;
static void _sendtriggertimer_tick();
static void _timer1_tick();
static void _writedisplay(B4R::B4RString* _row1,B4R::B4RString* _row2);
};

#endif