import subprocess
from subprocess import Popen, PIPE
import os

p = subprocess.Popen([r'C:\\MinGW\\bin\\g++.exe','-Wall', '-o', 'test', 'test.cpp'], stdout=PIPE, stdin=PIPE, shell=True) # g++ -o <execname> <filename> 
print('compiled')
p.communicate() # .communicate() writes input
#p = subprocess.Popen(['test'], stdout=PIPE, stdin=PIPE, shell=True) 
p = subprocess.Popen(['test', '-f', 'test.ply'], stdout=PIPE, stdin=PIPE, shell=True) 
result = p.stdout.readline().strip()
print(result) 

#work all, manual compiling:
#p = Popen(['test.exe'], shell=True, stdout=PIPE, stdin=PIPE)
#p = Popen([r'D:\\subprocess_test3\\test.exe'], shell=True, stdout=PIPE, stdin=PIPE)
#p = Popen([r'C:\\Users\\kerns\\Documents\\GitHub\\Sewer-Pipes-Measurement\\src\\RealSense\\subprocess_test3\test.exe'], shell=True, stdout=PIPE, stdin=PIPE)


#for ii in range(10):
#    value = str(ii) + '\n'
#    value = bytes(value, 'UTF-8')
#    p.stdin.write(value)
#     p.stdin.flush()
#    result = p.stdout.readline().strip()
#    print(result) 
