import binascii
import base64 

with open('RPC_Stub.dll', 'rb') as f:
    hexdata = binascii.hexlify(f.read())

result = []
result2 = ""

for i in range(0, len(hexdata), 2):
    result.append(hexdata[i : i + 2])
    
for i in result:
    result2 += str(i)

print(result2)