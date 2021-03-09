# B4R_thermostat

I've just created an Arduino controlled thermostat for fun. I used the awesome B4R framework for native compiled Arduino code. 
Link here: https://www.b4x.com/b4r.html

Feature list:
- Automatic display on function via ultrasonic hand sensor
- Automatic display off after some time
- Left button decreases, right button increases "Comfort" temperature (default hardcoded)
- Led light is blue when current temperature is under Comfort, green if both are the same, red if hotter than Comfort.
- Relay is switching on when current temp is below Comfort, turns off when above comfort.

See it working on Youtube: https://www.youtube.com/watch?v=Ny1QYJJFJws
