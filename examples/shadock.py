#!/usr/bin/env python3

# Copyright (c) Facebook, Inc. and its affiliates.
# This source code is licensed under the MIT license found in the
# LICENSE file in the root directory of this source tree.


from parlai.core.agents import Agent
from parlai.core.params import ParlaiParser
from parlai.core.worlds import create_task

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
        world.parley()
        print(world.display())
        if world.epoch_done():
            print('EPOCH DONE')
            break
