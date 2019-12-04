#!/usr/bin/env python3

# Copyright (c) Facebook, Inc. and its affiliates.
# This source code is licensed under the MIT license found in the
# LICENSE file in the root directory of this source tree.

"""
This is a converter to transform Akios data into FbDialog dataset format. 

TODO : build a Converter() abst class and inherit the ConverterCologne


"""
user ='A'
bot = 'B'

def state0(current) : 

    if current == user :
        # print("going to state 1 : all good")
        return True,1 
    # print("not good staying in 0")
    return False,0

def state1(current) : 

    if current == bot :
        # print("going to state 0 : all good")
        return True,0 
    # print("not good staying in 1")
    return False,1

def finalstate(current_state,turn,conv) :

    if current_state == 0 :

        conv.append(turn)

    else : 
        conv.append(turn+'\tsilence')


def find_current(elem) :

    return elem[0]

def converter(conv) : 
    conversation = []
    current_state = 0
    current_turn = ""
    buffer_turn = ""
    turn_complete = False
    cpt = 0
    for elem in conv : 
        # print(elem)
        cpt += 1 

        # print("turn number {}".format(cpt))     


        if turn_complete : 

            conversation.append(current_turn)
            current_turn = ""
            turn_complete = False
   
        current = find_current(elem)
        # print(current)

        if current_state == 0 :


            goodness,current_state = state0(current)

            if goodness  : 

                current_turn = elem

            else : 
            
                current_turn = "silence\t"+elem
                turn_complete = True

        else : 

            goodness,current_state = state1(current)

            if buffer_turn : 

                print("there was a buffer !")
                
                current_turn = buffer_turn               
                buffer_turn = ""

            if goodness : 

                current_turn += elem
                turn_complete = True
            
            else : 

                current_turn += '\tsilence'
                conversation.append(current_turn)
                turn_complete = True
                buffer_turn = elem

        if elem == conv[-1] :

            if buffer_turn : 
                current_turn = buffer_turn
            finalstate(current_state,current_turn,conversation)

    return conversation

def printer(conv) : 
    for elem in conv : 
        print(elem)

if __name__ == '__main__':
    
    conv = ["A: hello how are you ? ","B; good and you ? "]
    conv = converter(conv)
    # print(conv)
    conv2 = converter(["A: hello how are you ? ","A: hello ?? "])
    conv3 = converter(["A: hello how are you ? ","B; good and you ? ",'B:are you all right ? '])
    conv4 = converter(["B; good and you ? ",'A:good thanks'])
    conv5 = converter(["A","A"])
    conv6 = converter(["A","B"])
    conv7 = converter(["A","B","A"])
    conv8 = converter(["B","B"])
    convs = []
    convs.append(conv5)
    convs.append(conv6)
    convs.append(conv7)
    convs.append(conv8)
    for elem in convs : 
        printer(elem)
        print("******************\n*****************")
            
    # printer(conv)
    # print("******************\n*****************")
    # printer(conv2)
    # print("******************\n*****************")
    # printer(conv3)
    # print("******************\n*****************")
    # printer(conv4)