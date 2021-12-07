import RPi.GPIO as GPIO
import time

# Pin Definitons:
actuator = 4 # Broadcom pin 4 (pin 7 on pi)

# Pin Setup:
GPIO.setmode(GPIO.BCM) # Broadcom pin-numbering scheme
GPIO.setup(actuator, GPIO.OUT) # LED pin set as output

# 3.3v on pin 7 pi:
GPIO.output(actuator, GPIO.HIGH)

time.sleep(30)
# 0v on pin 7 pi:
GPIO.output(actuator, GPIO.LOW)

GPIO.cleanup() # cleanup all GPIO
