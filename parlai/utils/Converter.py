#!/usr/bin/env python3

# Copyright (c) Facebook, Inc. and its affiliates.
# This source code is licensed under the MIT license found in the
# LICENSE file in the root directory of this source tree.

"""Basic example for understanding minimal functions of the framework"""

from parlai.utils.Conversation import CologneConversation

from pprint import pprint
from glob import glob
import sys

class Converter(object):
    silence_user = "<SILENCE>"
    silence_bot = "<SILENCE>"


    def __init__(self, fic):

        self.cologne = CologneConversation(fic)
        self.conversation = self.cologne.speakingTurns
        self.user = self.cologne.getUser()
        self.agent = self.cologne.getAgent()
        self.starting = self.conversation[0].getSpeaking()
        self.conversation = self.conversation[1:]

    def state_0(self,conv, conversation):
        #print('state 0 conv= ' + conv + ' converstion= ' + str(conversation))
        if len(conv) > 0:
            current_turn = conv[0]
            speaking = current_turn.getSpeaking()
            speaker = current_turn.getSpeaker()
            if len(speaking) > 0:
                current_speaker = speaker
                if (current_speaker == self.user or self.user == 'userX') and current_speaker != self.agent:
                    print("Normal process : User + Agent")
                    return Converter.state_1(self,conv[1:], conversation + [speaking])
                else:
                    assert (current_speaker == self.agent)
                    return Converter.state_2(self,conv[1:],
                                             conversation + [Converter.silence_user] + [speaking])

            else:
                print('ERROR untagger speech turn ' + speaking)
                exit(1)
        else:
            return conversation

    def state_1(self,conv, conversation):
       # print('state 1 conv= ' + str(conv) + ' converstion= ' + str(conversation))
        if len(conv) > 0:
            current_turn = conv[0]
            speaking = current_turn.getSpeaking()
            speaker = current_turn.getSpeaker()
            if len(speaking) > 0:
                current_speaker = speaker
                if (current_speaker == self.user or self.user == 'userX') and current_speaker != self.agent:
                    return Converter.state_1(self,conv[1:], conversation + [Converter.silence_bot] + [speaking])
                else:
                    assert (current_speaker == self.agent or len(conv) < 2)
                    return Converter.state_2(self,conv[1:], conversation + [speaking])

            else:
                print('ERROR untagger speech turn ' + speaking)
                exit(1)
        else:
            # one bot_silence missing
            return Converter.state_2(self,[], conversation + [Converter.silence_bot])

    def state_2(self, conv, conversation):
        #print('state 2 conv= ' + str(conv) + ' converstion= ' + str(conversation))
        if len(conv) > 0:
            current_turn = conv[0]
            speaking = current_turn.getSpeaking()
            speaker = current_turn.getSpeaker()
            if len(speaking) > 0:
                current_speaker = speaker
                if (current_speaker == self.user or self.user == 'userX') and current_speaker != self.agent:
                    return Converter.state_1(self,conv[1:], conversation + [speaking])
                else:
                    assert (current_speaker == self.agent or len(conv) < 2)
                    return Converter.state_2(self,conv[1:],
                                             conversation + [Converter.silence_user] + [speaking])

            else:
                print('ERROR untagger speech turn ' + speaking)
                exit(1)
        else:
            return conversation

    def converter(self):
        print('==========')
        conversation = []
        current_turn = ""
        buffer_turn = ""
        turn_complete = False
        cpt = 0
        conv = self.conversation
        return Converter.state_0(self,conv, conversation)

    def printer(conv) :
        current = []
        full  = ""
        x = 0
        for elem in conv :
            current.append(elem)
            if len(current) == 2 :
                x += 1
                full += str(x)+" "+"\t".join(current)+'\n'
                current = []
        print(full)
        return full

    def writer(full,out):
        outstream = open(out,'w',encoding='utf-8')
        outstream.write(full)
# conv = ["A: hello how are you ? ","B; good and you ? "]
# conv = converter(conv)
# # print(conv)
# conv2 = converter(["A: hello how are you ? ","A: hello ?? "])
# conv3 = converter(["A: hello how are you ? ","B; good and you ? ",'B:are you all right ? '])
# conv4 = converter(["B; good and you ? ",'A:good thanks'])

# printer(conv)
# print("******************\n*****************")
# printer(conv2)
# print("******************\n*****************")
# printer(conv3)
# print("******************\n*****************")
# printer(conv4)
# print( "==============" )
# conv = ['A', 'A']
# print( converter( conv ))

if __name__ == '__main__':
    CONVER_DIR  = "/home/tf/Documents/Leon/projekt/PMC/data/"
    CLEAN = CONVER_DIR+"clean/"
    FB = CONVER_DIR+"fbFormat/"
    for fic in glob(CLEAN+'*') :
        print(fic)
        co = Converter(fic)
        # if co == 1 :
        #     continue
        if len(co.conversation) < 4 :
            continue
        converted = co.converter()
        full = Converter.printer(converted)
        out = FB+fic.split('/')[-1]
        Converter.writer(full,out)

# print(converter.conversation.getConversationString())
