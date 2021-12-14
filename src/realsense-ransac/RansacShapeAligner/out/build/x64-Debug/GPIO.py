import RPi.GPIO as GPIO
import time

# Pin Definitons:
actuator = 4 # Broadcom pin 4 (pin 7 on pi)

# Pin Setup:
GPIO.setmode(GPIO.BCM) # Broadcom pin-numbering scheme
GPIO.cleanup() # cleanup all GPIO
GPIO.setup(actuator, GPIO.OUT) # LED pin set as output

# 3.3v on pin 7 pi:
GPIO.output(actuator, GPIO.LOW)

time.sleep(10)

GPIO.cleanup() # cleanup all GPIO
