frame = input("Enter the data frame(without any flag):")
flag = input("Enter the flag:")

fl_len = len(flag)
frame = flag+frame
fr_len = len(frame)
l = []
print(f"The frame is {frame}")
#Bit-Stuffing
c=0
for i in range(fl_len,fr_len):
    if(frame[i]=='1'):
        c+=1
    else:
        c=0
    if(c==5):
        frame=frame[:i+1]+'0'+frame[i:]
        c=0
        l.append(i+1)
    else:
        i=i+1

print(f"The stuffed frame is {frame}\n the list is{l}")
#De-Stuffing
pos=0
l_len=len(l)
while(l_len>0):
    frame=frame[:l[pos]-1]+frame[l[pos]+1:]
    l_len-=1
    pos+=1
print(f"The destuffed frame is {frame}")
