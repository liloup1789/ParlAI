#!/usr/bin/env python3

# Copyright (c) Facebook, Inc. and its affiliates.
# This source code is licensed under the MIT license found in the
# LICENSE file in the root directory of this source tree.
"""Basic example for understanding minimal functions of the framework"""



from parlai.core.agents import Agent
from parlai.core.params import ParlaiParser
from parlai.core.worlds import create_task
import random,time,sys

class RepeatLabelAgent(Agent):
    # initialize by setting id
    def __init__(self, opt):
        super().__init__(opt)
        self.id = 'RepeatLabel'
        self.returnOneRandomAnswer = opt.get('return_one_random_answer', True)
        self.cantAnswerPercent = opt.get('cant_answer_percent', 0)
        self.cantAnswerMessage = opt.get('cant_answer_message', "I don't know.")
        # self.id = 'RepeatLabelAgent'
    # store observation for later, return it unmodified
    def observe(self, observation):
        self.observation = observation
        return observation
    # return label from before if available
    def act(self):
        obs = self.observation
        if obs is None:
         return {'text': 'Nothing to repeat yet.'}
        reply = {}
        reply['id'] = self.getID()
        labels = obs.get('labels', obs.get('eval_labels', None))
        if labels:
         if random.random() >= self.cantAnswerPercent:
             if self.returnOneRandomAnswer:
                 reply['text'] = labels[random.randrange(len(labels))]
             else:
                 reply['text'] = ', '.join(labels)
         else:
             # Some 'self.cantAnswerPercent' percentage of the time
             # the agent does not answer.
             reply['text'] = self.cantAnswerMessage
        else:
         reply['text'] = self.cantAnswerMessage

        return reply


if __name__ == '__main__':
    parser = ParlaiParser()
    opt = parser.parse_args()

    agent = RepeatLabelAgent(opt)
    world = create_task(opt, agent)

    for i in range(10):


        world.parley()


        print("Turn number {}".format(i))
        # for a in world.acts:
            # print(type(a))
            # print(world.agents[0])
        teacher = world.agents[0]
        student = world.agents[1]
            # print("teacher is : {}".format(teacher.getID()))
            # print("student is : {}".format(student.getID()))

            # print("teacher's observation : {}".format(teacher.observation))
            # print(student.observe(a))
            # print the actions from each agent
            # print("agent action : "+str(a))
            # print(world.update_counters())
        for t in teacher.tasks : 
            print(t)
        # sys.exit()
        if world.epoch_done():
            print('EPOCH DONE')
            break

""" 
TODO : update dict Agent to parameter any language



"""