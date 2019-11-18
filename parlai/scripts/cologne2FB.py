#!/usr/bin/env python3

# Copyright (c) Facebook, Inc. and its affiliates.
# This source code is licensed under the MIT license found in the
# LICENSE file in the root directory of this source tree.

""" 
This code provides a converter from cologne data format to fbdialog format (deprecated nevertheless)

Entry is a datafile. Output is a tranformered datafile with 'fb_' prefix. 

"""

import re
from pprint import pprint
import argparse

parser = argparse.ArgumentParser(description='Process some integers.')
parser.add_argument('input', type=str, nargs='+',
                   help='input datafile')


args = parser.parse_args()
print(args)
input_f = args.input[0]

def reader(filepath) : 

    f = open(filepath,'r',encoding='utf-8')
    conversations = []
    conversation = {}
    x = 0
    turn = ""
    p = re.compile(r"^\(\d+:\d+\)")
    for line in f.readlines() :
        if "real_time_queue_name" in line : 
            print("new conver")
            if conversation :

                x += 1 
                conversation[x] = turn

                conversations.append(conversation)
            x = 0
            conversation = {}
            turn = ""
        else : 
            if p.match(line) : 
                if turn : 
                    x += 1 
                    if x not in conversation : 
                        conversation[x] = turn
                    turn = line

                else : 
                    turn += line    
            elif '"Chat Parfums' in line or re.compile(r'\"(;\d*)+').match(line) : 
                pass

            else : 
                turn += line
    if conversation : 
        x += 1 
        conversation[x] = turn
        conversations.append(conversation)
    return conversations

def cleaner(string,mode ='name') : 

    if mode == 'name'
        return string.replace(" ","").replace(":","")
    elif mode == "utterance" : 
        return string.split(p.match(string).group(1))[1].split(p.match(string).group(2))[1]

def parser (conv) : 

    conversation = []
    turn = ""
    bot = ""
    user = ""
    beginning = conv[1]
    second = conv[2]
    p = re.compile(r"(^\(\d+:\d+\)) ([a-zA-zéâêîôûàç]+ ?:)")
    bot = p.match(beginning).group(2)
    try : 
        user = p.match(second).group(2)
    except AttributeError : 
        user = "Unknwown"
    bot = cleaner(bot)
    user = cleaner(user)
    conversation.append('<SILENCE>\t'+beginning.split(p.match(beginning).group(1))[1].split(p.match(beginning).group(2))[1])
    turn = []
    cpt = 0
    for utterance in conv : 
        if cpt == 0 : 
            turn = [cleaner(utterance,'utterance')]
            cpt += 1 
            current = user
        else : 
            if turn :
                new = cleaner(p.match(utterance).group(2))
                if current != new : 
                        turn.append(cleaner(utterance,'utterance'))
                        conversation.append(turn)
                        turn = []
                    else : 








    # for i in range(3,len(conv)) : 



    # locutor = re.search(be)


def printer(conversations) : 

    for conversation in conversations : 
        pprint(conversation)

if __name__ == '__main__':
    
    convs = reader(input_f)

    # printer(convs)

    for conv in convs : 
        parser(conv)
