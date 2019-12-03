#!/usr/bin/env python3

# Copyright (c) Facebook, Inc. and its affiliates.
# This source code is licensed under the MIT license found in the
# LICENSE file in the root directory of this source tree.
"""Basic example for understanding minimal functions of the framework"""


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

##    for elem in conv :
##        print(elem)
##        cpt += 1
    return state_0( conv, conversation )
        
def printer(conv) : 
    for elem in conv : 
        print( elem )

conv = ["A: hello how are you ? ","B; good and you ? "]
conv = converter(conv)
# print(conv)
conv2 = converter(["A: hello how are you ? ","A: hello ?? "])
conv3 = converter(["A: hello how are you ? ","B; good and you ? ",'B:are you all right ? '])
conv4 = converter(["B; good and you ? ",'A:good thanks'])

printer(conv)
print("******************\n*****************")
printer(conv2)
print("******************\n*****************")
printer(conv3)
print("******************\n*****************")
printer(conv4)
print( "==============" )
conv = ['A', 'A']
print( converter( conv ))       

