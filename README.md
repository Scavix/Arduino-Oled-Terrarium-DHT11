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

The arduino check every 2 second the temperature and the humidity from the dht11 sensor. This numbers are shown in the display. if the temperature is too low the relay is turned on so the heatpad also turn on, else if it's too hot the relay is turned off.
