frame_len = int(input("Enter the length of the frame: "))
b_str = input("Enter the binary string: ")

b_len = len(b_str)
# Zero-padding
# b_str = '0'*(frame_len-(b_len%frame_len)) + b_str if (b_len % frame_len != 0) else b_str
if (b_len % frame_len != 0):
    b_str = '0'*(frame_len-(b_len%frame_len)) + b_str

b_len = len(b_str) # update with new length
# converting to dictionary
# b_dic = {key:b_str[i:i+frame_len] for i,key in zip(range(0,b_len,frame_len),range(b_len//frame_len))}
key=0
b_dic={}
for i in range(0,b_len,frame_len):
    b_dic[key] =b_str[i:i+frame_len]
    key +=1
print(f"The binary string is: {b_str}\nThe framed dictionary is: {b_dic}")

def exOR(a, b) -> str:
    result=''
    for i in range(frame_len):
        if a[i] != b[i]:
            result+='1'
        else:
            result+='0'
    # result = ''.join(['1' if a[i] != b[i] else '0' for i in range(frame_len)])
    return result



b_xor=''
# [b_xor:= exOR(b_dic.get(i) if b_xor=='' else b_xor,b_dic.get(i+1))  for i in range((b_len//frame_len)-1)]

# result = [b_xor := exOR(b_dic.get(i) if b_xor == '' else b_xor, b_dic.get(i+1)) for i in range((b_len // frame_len) - 1)]

for i in range((b_len//frame_len)-1):
    if b_xor=='':
        a=b_dic.get(i)
    else:
        a = b_xor
    b=b_dic.get(i+1)
    b_xor=exOR(a,b)

print(f"the XOR of the framed value is {b_xor}")
