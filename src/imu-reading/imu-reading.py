import smbus
import math
 
# Register
power_mgmt_1 = 0x6b
power_mgmt_2 = 0x6c
 
def read_byte(reg):
    return bus.read_byte_data(address, reg)
 
def read_word(reg):
    h = bus.read_byte_data(address, reg)
    l = bus.read_byte_data(address, reg+1)
    value = (h << 8) + l
    return value
 
def read_word_2c(reg):
    val = read_word(reg)
    if (val >= 0x8000):
        return -((65535 - val) + 1)
    else:
        return val
 
def dist(a,b):
    return math.sqrt((a*a)+(b*b))
 
def get_y_rotation(x,y,z):
    radians = math.atan2(x, dist(y,z))
    return -math.degrees(radians)
 
def get_x_rotation(x,y,z):
    radians = math.atan2(y, dist(x,z))
    return math.degrees(radians)
 
bus = smbus.SMBus(1) # bus = smbus.SMBus(0) for Revision 1
address = 0x68       # via i2cdetect
 
# Activate to be able to address the module
bus.write_byte_data(address, power_mgmt_1, 0)
 
print "Gyroscope"
print "--------"
 
gyroscope_xout = read_word_2c(0x43)
gyroscope_yout = read_word_2c(0x45)
gyroscope_zout = read_word_2c(0x47)
 
print "gyroscope_xout: ", ("%5d" % gyroscope_xout), " scaled: ", (gyroscope_xout / 131)
print "gyroscope_yout: ", ("%5d" % gyroscope_yout), " scaled: ", (gyroscope_yout / 131)
print "gyroscope_zout: ", ("%5d" % gyroscope_zout), " scaled: ", (gyroscope_zout / 131)
 
print
print "Acceleration-sensor"
print "---------------------"
 
acceleration_xout = read_word_2c(0x3b)
acceleration_yout = read_word_2c(0x3d)
acceleration_zout = read_word_2c(0x3f)
 
acceleration_xout_scaled = acceleration_xout / 16384.0
acceleration_yout_scaled = acceleration_yout / 16384.0
acceleration_zout_scaled = acceleration_zout / 16384.0
 
print "acceleration_xout: ", ("%6d" % acceleration_xout), " scaled: ", acceleration_xout_scaled
print "acceleration_yout: ", ("%6d" % acceleration_yout), " scaled: ", acceleration_yout_scaled
print "acceleration_zout: ", ("%6d" % acceleration_zout), " scaled: ", acceleration_zout_scaled
 
print "X Rotation: " , get_x_rotation(acceleration_xout_scaled, acceleration_yout_scaled, acceleration_zout_scaled)
print "Y Rotation: " , get_y_rotation(acceleration_xout_scaled, acceleration_yout_scaled, acceleration_