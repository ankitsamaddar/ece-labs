"""day4.py: Python Program to perform Cyclic Redundancy Check using both with error and without error."""
__author__ = "Ankit Samaddar"

def exor(a, b) -> str:
    frame_len = len(a)
    result = ''
    for i in range(frame_len):
        if a[i] != b[i]:
            result += '1'
        else:
            result += '0'
    # result = ''.join(['1' if a[i] != b[i] else '0' for i in range(frame_len)])
    return result


def mod2div(key, data):
    dlen = len(data)
    klen = len(key)
    rem = exor(key, data[:klen])
    for i in range(klen, dlen):
        if rem[1] == '1':
            k_frame = rem[1:]+data[i]
            rem = exor(key, k_frame)
        elif rem[1] == '0':
            key_0 = '0'*klen
            k_frame = rem[1:]+data[i]
            rem = exor(key_0, k_frame)
    return rem


def control(data, key, cr=0):
    k_data = data+'0'*(len(key)-1)
    rem = mod2div(key, k_data)
    s_data = data+rem[1:]
    if cr == 1:  # trigger error
        s_data = data+'110'+rem[1:]
    print(
        f"Sender:\nOriginal data: {data}\nKey is: {key} \nData with zeros added: {k_data} \nCRC encoded data: {s_data}")
    r_rem = mod2div(key, s_data)
    if int(r_rem) == 0:
        print(
            f"\nReciever:\nRecieved data: {s_data}\nRemainder is: {r_rem}\nSuccess!!Data Recieved Without Error.")
    else:
        print(
            f"\nReciever:\nRecieved data: {s_data}\nRemainder is: {r_rem}\nError!!Resend Data.")


def main():
    print("\nDATA WITHOUT ERROR:")
    data = '1101011011'
    key = '10011'
    control(data, key)
    print("\nDATA WITH ERROR:")
    control(data, key, cr=1)  # cr=1 will trigger error in data


if __name__ == "__main__":
    main()
