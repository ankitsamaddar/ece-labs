"""Exp4a: Stop & Wait ARQ Protocol"""
__author__ = "Ankit Samaddar"

import random
def mod2add(bit, check_bit):
    return (bit + check_bit) % 2

def sender(data):
    i = 0
    received_data = ''
    max_retry=0
    pos=0
    while i < len(data):
        print("\nSender->")
        bit = data[i]
        print("Sending bit... ")
        pos_r, received_data = receiver(bit, pos, received_data)
        pos = mod2add(pos,1) # next bit position
        if pos == pos_r:  # if successful will send the next bit
            print("\nSender->")
            print(f"Received POS: {pos}")
            i += 1
        else:
            print("\nSender->")
            print(
                f"ACK Recieved: {pos}\nError in transmission. Resending previous bit !")
            if max_retry>10:
                print("Max retry Exceeded. Exiting !!")
                exit()
            max_retry+=1

    return received_data


def receiver(bit, pos_r, received_data): #recieved_data is memory of reciever
    pos_s = pos_r # previous
    pos = random.randint(0, 1) # error if pos != pos_r
    if pos == pos_r:
        received_data += bit
        pos_r = mod2add(pos_r,1)
        print("Bit received successfully!")
    else:
        print("Bit lost. Resending previous bit.")
    return pos_r, received_data


def main():
    data = '1101011011'
    print("Sending data: ", data)
    print("\nFinal Received data: ", sender(data))

if __name__ == "__main__":
    main()
