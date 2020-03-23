# notfier
This simple app for ESP8266 was created to call children from other living place.
The hardware consist of Wemos D1 mini as a base, AdaFruit OLED .96" display with I2C connection and standard buzzer.
Logic is the following: every 20 second app tries to GET from host. If response is like /^Ok.*/ it will read the rest after "Ok"  string and find the message with the same index, as passed in host's response
Additionally to show the work state of hardware, the blinking dot appears at different coordinates time to time.
