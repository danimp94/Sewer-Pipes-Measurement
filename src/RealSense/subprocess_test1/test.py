import subprocess
from subprocess import Popen, PIPE

p = subprocess.Popen([r"/usr/bin/g++", "-Wall", "-o", "test", 'test.cpp'], stdout=PIPE, stdin=PIPE)
p.communicate()
p = subprocess.Popen(["./test"], stdout=PIPE, stdin=PIPE)



#p = Popen(["./test"], shell=True, stdout=PIPE, stdin=PIPE)
for ii in range(10):
    value = str(ii) + '\n'
    value = bytes(value, 'UTF-8')  # Needed in Python 3.
    p.stdin.write(value)
    p.stdin.flush()
    result = p.stdout.readline().strip()
    print(result)
  
#result = subprocess.run(['ls', 'C:\Users\kerns\Documents\GitHub\Sewer-Pipes-Measurement\src\RealSense\subprocess\test'], stdout=subprocess.PIPE, stdin=subprocess.PIPE)

#for a in range(10):
#    value = str(a) + '\n'
#    value = bytes(value, 'UTF-8')  # Needed in Python 3.
#    p.stdin.write(value)
#    p.stdin.flush()
#    result = p.stdout.readline().strip()


#print(result)
#print(result.stdout)