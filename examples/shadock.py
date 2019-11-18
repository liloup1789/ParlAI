#!/usr/bin/env python3

# Copyright (c) Facebook, Inc. and its affiliates.
# This source code is licensed under the MIT license found in the
# LICENSE file in the root directory of this source tree.

from parlai.core.agents import Agent
from parlai.core.params import ParlaiParser
from parlai.core.worlds import create_task

import sys
"""
-t babi’ sets up the DefaultTeacher in ‘parlai/core/tasks/babi/agents.py’.

‘-t babi:task1k’ sets up the Task1kTeacher in the babi/agents.py file, which allows you to specify specific settings for certain tasks. For bAbI, this refers to the setting where there are only 1000 unique training examples per task.

‘-t babi:task1k:1’ provides 1 as a parameter to Task1kTeacher, which is interpreted by the Task1kTeacher to mean “I want task 1” (as opposed to the 19 other bAbI tasks).

‘-t babi,squad’ sets up the DefaultTeacher for both babi and squad. Any number of tasks can be chained together with commas to load up each one of them.

‘-t #qa’ specifies the ‘qa’ category, loading up all tasks with that category in the ‘parlai/core/task_list.py’ file.
"""

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

    for _ in range(10):
        teacher = world.get_agents()[0]
        print(teacher.getID())
        sys.exit()
        world.parley()
        # print(world.display())
        if world.epoch_done():
            print('EPOCH DONE')
            break