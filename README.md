# Arduino-Oled-Terrarium-DHT11
Project with Arduino to keep a Tarantula Terrarium Warm with a dht11 and a heatpad.

# What You need:

- Arduino
- DHT11 (temperature and humidity) sensor
- Oled Display 0.96 inch
- Some Jumper
- Relay
- HeatPad

# How does it Work:

The Arduino board checks every X seconds (your choiche) the temperature and the humidity from the dht11 sensor.
This numbers are shown in the OLED display.
If the temperature is too low (your choiche) the relay activated and the heatpad also turn on, otherwise if it's too hot (your choiche) the relay is turned off.
