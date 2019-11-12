#!/usr/bin/env python3

# Copyright (c) Facebook, Inc. and its affiliates.
# This source code is licensed under the MIT license found in the
# LICENSE file in the root directory of this source tree.

import sys,os

from parlai.core.agents import Agent
from parlai.core.params import ParlaiParser
from parlai.core.worlds import create_task
# schaub@cazotte:~$ source activate parlai
# (parlai) schaub@cazotte:~$ cd Documents/projets/parlai/ParlAI/examples/
# (parlai) schaub@cazotte:~/Documents/projets/parlai/ParlAI/examples$ python shadock.py -t babi

class RepeatLabelAgent(Agent):
    # initialize by setting id
    def __init__(self, opt):
        self.id = 'RepeatLabel'
    # store observation for later, return it unmodified
    def observe(self, observation):
        self.observation = observation
        return observation
    # return label from before if available
    def act(self):
        reply = {'id': self.id}
        if 'labels' in self.observation:
            reply['text'] = ', '.join(self.observation['labels'])
        else:
            reply['text'] = "I don't know."
        return reply
if __name__ == '__main__':

    parser = ParlaiParser()
    opt = parser.parse_args()

    agent = RepeatLabelAgent(opt)

    world = create_task(opt, agent)
    # create task -> world + teachers par défaut
    print(type(world))
    print(world.get_agents())
    # sys.exit()
    for _ in range(10):
        world.parley()
        print(world.display())
        if world.epoch_done():
            print('EPOCH DONE')
            flush()
            print("j'ai fini")
            sys.exit(0)
        else : 
            print("================================")


# (parlai) schaub@cazotte:~/Documents/projets/parlai/ParlAI/examples$ python shadock.py -t babi
# [ Main ParlAI Arguments: ] 
# [  batchsize: 1 ]
# [  datapath: /people/schaub/Documents/projets/parlai/ParlAI/data ]
# [  datatype: train ]
# [  download_path: /people/schaub/Documents/projets/parlai/ParlAI/downloads ]
# [  hide_labels: False ]
# [  image_mode: raw ]
# [  init_opt: None ]
# [  multitask_weights: [1] ]
# [  numthreads: 1 ]
# [  show_advanced_args: False ]
# [  task: babi ]
# [ ParlAI Image Preprocessing Arguments: ] 
# [  image_cropsize: 224 ]
# [  image_size: 256 ]
# [ Current ParlAI commit: 92752a344c252f77e468d02524be19c0c233cfbe ]
# [creating task(s): babi]
# [loading fbdialog data:/people/schaub/Documents/projets/parlai/ParlAI/data/bAbI/tasks_1-20_v1-2/en-valid-nosf/qa1_train.txt]
# [loading fbdialog data:/people/schaub/Documents/projets/parlai/ParlAI/data/bAbI/tasks_1-20_v1-2/en-valid-nosf/qa2_train.txt]
# [loading fbdialog data:/people/schaub/Documents/projets/parlai/ParlAI/data/bAbI/tasks_1-20_v1-2/en-valid-nosf/qa3_train.txt]
# [loading fbdialog data:/people/schaub/Documents/projets/parlai/ParlAI/data/bAbI/tasks_1-20_v1-2/en-valid-nosf/qa4_train.txt]
# [loading fbdialog data:/people/schaub/Documents/projets/parlai/ParlAI/data/bAbI/tasks_1-20_v1-2/en-valid-nosf/qa5_train.txt]
# [loading fbdialog data:/people/schaub/Documents/projets/parlai/ParlAI/data/bAbI/tasks_1-20_v1-2/en-valid-nosf/qa6_train.txt]
# [loading fbdialog data:/people/schaub/Documents/projets/parlai/ParlAI/data/bAbI/tasks_1-20_v1-2/en-valid-nosf/qa7_train.txt]
# [loading fbdialog data:/people/schaub/Documents/projets/parlai/ParlAI/data/bAbI/tasks_1-20_v1-2/en-valid-nosf/qa8_train.txt]
# [loading fbdialog data:/people/schaub/Documents/projets/parlai/ParlAI/data/bAbI/tasks_1-20_v1-2/en-valid-nosf/qa9_train.txt]
# [loading fbdialog data:/people/schaub/Documents/projets/parlai/ParlAI/data/bAbI/tasks_1-20_v1-2/en-valid-nosf/qa10_train.txt]
# [loading fbdialog data:/people/schaub/Documents/projets/parlai/ParlAI/data/bAbI/tasks_1-20_v1-2/en-valid-nosf/qa11_train.txt]
# [loading fbdialog data:/people/schaub/Documents/projets/parlai/ParlAI/data/bAbI/tasks_1-20_v1-2/en-valid-nosf/qa12_train.txt]
# [loading fbdialog data:/people/schaub/Documents/projets/parlai/ParlAI/data/bAbI/tasks_1-20_v1-2/en-valid-nosf/qa13_train.txt]
# [loading fbdialog data:/people/schaub/Documents/projets/parlai/ParlAI/data/bAbI/tasks_1-20_v1-2/en-valid-nosf/qa14_train.txt]
# [loading fbdialog data:/people/schaub/Documents/projets/parlai/ParlAI/data/bAbI/tasks_1-20_v1-2/en-valid-nosf/qa15_train.txt]
# [loading fbdialog data:/people/schaub/Documents/projets/parlai/ParlAI/data/bAbI/tasks_1-20_v1-2/en-valid-nosf/qa16_train.txt]
# [loading fbdialog data:/people/schaub/Documents/projets/parlai/ParlAI/data/bAbI/tasks_1-20_v1-2/en-valid-nosf/qa17_train.txt]
# [loading fbdialog data:/people/schaub/Documents/projets/parlai/ParlAI/data/bAbI/tasks_1-20_v1-2/en-valid-nosf/qa18_train.txt]
# [loading fbdialog data:/people/schaub/Documents/projets/parlai/ParlAI/data/bAbI/tasks_1-20_v1-2/en-valid-nosf/qa19_train.txt]
# [loading fbdialog data:/people/schaub/Documents/projets/parlai/ParlAI/data/bAbI/tasks_1-20_v1-2/en-valid-nosf/qa20_train.txt]
# <class 'parlai.core.worlds.DialogPartnerWorld'>
# [<parlai.tasks.babi.agents.DefaultTeacher object at 0x7fd37b43b588>, <__main__.RepeatLabelAgent object at 0x7fd37b3b48d0>]
# [babi:Task1k:3]: Mary moved to the office.
# Sandra went back to the kitchen.
# Sandra went to the office.
# John went to the bathroom.
# Sandra went back to the bathroom.
# Mary picked up the football there.
# Sandra journeyed to the garden.
# Mary discarded the football.
# Sandra got the apple.
# Sandra dropped the apple.
# John travelled to the kitchen.
# Mary got the football.
# Sandra took the apple.
# Sandra dropped the apple.
# Mary journeyed to the garden.
# Mary took the apple.
# John went to the bedroom.
# John journeyed to the hallway.
# Mary left the apple.
# Sandra travelled to the bedroom.
# John went to the garden.
# John journeyed to the bedroom.
# Mary moved to the kitchen.
# Mary travelled to the garden.
# Mary went to the bathroom.
# John journeyed to the bathroom.
# Sandra moved to the garden.
# Mary left the football.
# Where was the football before the garden?
# [labels: kitchen]
# [label_candidates: bathroom|hallway|garden|kitchen|bedroom|...and 1 more]
#    [RepeatLabel]: kitchen
# ================================
# [babi:Task1k:3]: Sandra took the apple.
# Mary went back to the office.
# Where was the football before the garden?
# [labels: kitchen]
# [label_candidates: bathroom|hallway|garden|kitchen|bedroom|...and 1 more]
#    [RepeatLabel]: kitchen
# ================================
# [babi:Task1k:3]: Sandra journeyed to the bathroom.
# Daniel moved to the kitchen.
# Where was the football before the kitchen?
# [labels: garden]
# [label_candidates: bathroom|hallway|garden|kitchen|bedroom|...and 1 more]
#    [RepeatLabel]: garden
# ================================
# [babi:Task1k:3]: Sandra left the apple there.
# Daniel travelled to the bedroom.
# Sandra travelled to the bedroom.
# John went back to the hallway.
# Daniel travelled to the garden.
# Mary travelled to the bedroom.
# Sandra went to the kitchen.
# Mary went to the garden.
# Sandra went back to the office.
# John moved to the office.
# Daniel went back to the office.
# Sandra journeyed to the kitchen.
# John went to the bedroom.
# Daniel journeyed to the garden.
# John journeyed to the kitchen.
# John went to the hallway.
# John picked up the milk.
# Daniel went back to the kitchen.
# John journeyed to the garden.
# John went to the bathroom.
# Where was the milk before the bathroom?
# [labels: garden]
# [label_candidates: bathroom|hallway|garden|kitchen|bedroom|...and 1 more]
#    [RepeatLabel]: garden
# ================================
# [babi:Task1k:3]: Mary travelled to the hallway.
# John took the apple.
# John dropped the milk.
# Daniel went back to the hallway.
# Where was the milk before the bathroom?
# [labels: garden]
# [label_candidates: bathroom|hallway|garden|kitchen|bedroom|...and 1 more]
#    [RepeatLabel]: garden
# - - - - - - - - - - - - - - - - - - - - -
# ================================
# [babi:Task1k:9]: Mary is no longer in the kitchen.
# Mary is not in the garden.
# Is Mary in the garden?
# [labels: no]
# [label_candidates: yes|no]
#    [RepeatLabel]: no
# ================================
# [babi:Task1k:9]: Daniel is in the office.
# John is not in the bedroom.
# Is John in the bedroom?
# [labels: no]
# [label_candidates: yes|no]
#    [RepeatLabel]: no
# ================================
# [babi:Task1k:9]: Sandra moved to the kitchen.
# Mary is no longer in the bedroom.
# Is Mary in the bedroom?
# [labels: no]
# [label_candidates: yes|no]
#    [RepeatLabel]: no
# ================================
# [babi:Task1k:9]: Sandra journeyed to the hallway.
# Daniel went back to the bathroom.
# Is Mary in the bedroom?
# [labels: no]
# [label_candidates: yes|no]
#    [RepeatLabel]: no
# ================================
# [babi:Task1k:9]: Daniel went back to the bedroom.
# John is in the garden.
# Is John in the kitchen?
# [labels: no]
# [label_candidates: yes|no]
#    [RepeatLabel]: no
# - - - - - - - - - - - - - - - - - - - - -
# ================================
