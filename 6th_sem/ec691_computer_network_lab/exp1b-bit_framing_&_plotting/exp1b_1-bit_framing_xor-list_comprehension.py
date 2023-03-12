frame_len = int(input("Enter the length of the frame: "))
b_str = input("Enter the binary string: ")
# Zero-padding
b_str = '0'*(frame_len-(len(b_str)%frame_len)) + b_str  if (len(b_str) % frame_len != 0) else b_str
b_len = len(b_str)
# converting to dictionary
b_dic = {key:b_str[i:i+frame_len] for i,key in zip(range(0,b_len,frame_len),range(b_len//frame_len))}
print(f"The binary string is: {b_str}\nThe framed dictionary is: {b_dic}")
def exOR(a, b) -> str: return ''.join(['1' if a[i] != b[i] else '0' for i in range(frame_len)]) #XOR function
# Calculating XOR of all the keys in the dictionary using list comprehension
b_xor=''
[b_xor:= exOR(b_dic.get(i) if b_xor=='' else b_xor,b_dic.get(i+1))  for i in range((b_len//frame_len)-1)]
print(f"the XOR of the framed value is {b_xor}")
