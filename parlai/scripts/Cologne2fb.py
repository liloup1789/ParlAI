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

def state_0( conv, conversation ):
    print( 'state 0 conv= ' + str ( conv ) + ' converstion= ' + str( conversation ))
    if( len( conv )> 0):
        current_turn = conv[0]
        if( len( current_turn) > 0 ):
            current_speaker = current_turn[0]
            if( current_speaker == user ):
                return state_1( conv[1:], conversation + [ current_turn ])
            else:
                assert( current_speaker == bot )
                return state_2( conv[1:], conversation + [ silence_user ] + [ current_turn ])
            
        else:
            print( 'ERROR untagger speech turn ' + current_turn )
            exit( 1 )
    else:
        return conversation

def state_1( conv, conversation ):
    print( 'state 1 conv= ' + str ( conv ) + ' converstion= ' + str( conversation ))
    if( len( conv )> 0 ):
        current_turn = conv[0]
        if( len( current_turn ) > 0 ):
            current_speaker = current_turn[0]
            if( current_speaker == user):
                return state_1( conv[1:], conversation + [ silence_bot ]+ [ current_turn ])
            else:
                assert( current_speaker == bot )
                return state_2( conv[1:], conversation + [ current_turn ])
            
        else:
            print( 'ERROR untagger speech turn ' + current_turn )
            exit( 1 )
    else:
        # one bot_silence missing
        return state_2( [], conversation + [ silence_bot ])

def state_2( conv, conversation ):
    print( 'state 2 conv= ' + str ( conv ) + ' converstion= ' + str( conversation ))
    if( len( conv )> 0 ):
        current_turn = conv[0]
        if( len( current_turn ) > 0 ):
            current_speaker = current_turn[0]
            if( current_speaker == user):
                return state_1( conv[1:], conversation + [ current_turn ])
            else:
                assert( current_speaker == bot )
                return state_2( conv[1:], conversation + [ silence_user ]+[ current_turn ])
            
        else:
            print( 'ERROR untagger speech turn ' + current_turn )
            exit( 1 )
    else:
        return conversation

    
def converter( conv ):
    print( '==========' )
    conversation = []
    current_turn = ""
    buffer_turn = ""
    turn_complete = False
    cpt = 0
    return state_0( conv, conversation )
def find_current(elem) :

    return elem[0]


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