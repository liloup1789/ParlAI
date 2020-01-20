#!/usr/bin/env python3

# Copyright (c) Facebook, Inc. and its affiliates.
# This source code is licensed under the MIT license found in the
# LICENSE file in the root directory of this source tree.

"""
This is a converter to transform Akios data into FbDialog dataset format. 

TODO : build a Converter() abst class and inherit the ConverterCologne


"""
import re

from abc import ABC, abstractmethod


class Conversation(object):

    conversation = []
    anonymized = True

    def setMode(mode):

        if isinstance(mode, bool):
            Conversation.anonymized = mode
        else:
            raise ValueError("mode is not bool ")

    @abstractmethod
    def getUser(self):
        pass

    @abstractmethod
    def getAgent(self):
        pass

    @abstractmethod
    def getSpeakingTurnsNumber(self):
        pass

    @abstractmethod
    def getConversation(self):
        pass

    @abstractmethod
    def getLengthConv(self):
        pass

    @abstractmethod
    def FirstSpeakingTurn(self):
        pass

    @abstractmethod
    def LastSpeakingTurn(self):
        pass

    # @abstractmethod
    # def setEndConversation() : 


class SpeakingError(Exception):
    pass


class SpeakingTurn(object):

    def __init__(self, pattern1, pattern2, speaking):
        self.__speaking = speaking

        self.__length = len(speaking)

        self.__pattern1 = pattern1
        self.__pattern2 = pattern2
    def checkSpeaking(self):
        if len(re.findall(re.compile(self.__pattern1), self.__speaking)) != 1:
            raise SpeakingError("The speaking turn is not in a valid format")

    def getLength(self):
        return self.__length

    def getSpeaking(self):
        return self.__speaking

    def getSpeaker(self):
        return re.search(self.__pattern2, self.__speaking).group(0)


class CologneConversation(Conversation):

    def __init__(self, fic):

        print(fic)
        self.__conversation = []
        for line in  open(fic, 'r', encoding='utf-8').readlines () :
            print(line)
            self.__conversation.append(line)
        print(self.__conversation)

        self.__globalSatisfaction = 1

        self.__theme = "Cologne"

        self.speakingTurns = []

        self.__speakingturnsnumber = len(self.__conversation)

        self.__pattern1 = '\\(\\d\\d:\\d\\d\\) '

        self.__pattern2 = re.compile('(?<=(%s))\\w+' % self.__pattern1)

        for elem in self.__conversation:
            self.speakingTurns.append(SpeakingTurn(self.__pattern1, self.__pattern2, elem))

        self.__agent = SpeakingTurn.getSpeaker(self.speakingTurns[0])

        for turn in self.speakingTurns:

            if SpeakingTurn.getSpeaker(turn) != self.__agent:
                self.__user = SpeakingTurn.getSpeaker(turn)

                break

        self.__startTime = re.match(re.compile(self.__pattern1), self.speakingTurns[0])

        self.__endTime = re.match(re.compile(self.__pattern1), self.speakingTurns[-1]).group(0)

        def pattern2time(time):

            new_time = time.replace('(', '')
            new_time = time.replace(')', '')
            return [int(i) for i in new_time.split(':')]

        def getUser(self):

            return self.__user

        def getAgent(self):

            return self.__agent

        def getPattern1(self):

            return self.__pattern1

        def getPattern2(self):

            return self.__pattern2

        def setPattern1(self, p1):

            if isinstance(p1, str):
                self.__pattern1 = p1
            else:
                raise ValueError("pattern must be string")

        def setPattern2(self, p2):

            if isinstance(p2, '_sre.SRE_Pattern'):
                self.__pattern2 = p2
            else:
                raise ValueError("pattern must be RE")

        def getSpeakingTurnsNumber(self):

            return self.__speakingturnsnumber

        def getConversation(self):

            return '\n'.join(self.speakingTurns)

        def getLengthConv(self):

            start = pattern2time(self.__startTime)
            end = pattern2time(self.__endTime)

            return str(60 * (end[0] - start[0]) + (end[1] - start[1]))

        def FirstSpeakingTurn():

            return self.speakingTurns[0]

        def LastSpeakingTurn():

            return self.speakingTurns[-1]

if __name__ == '__main__':


    fic = "/home/tf/Documents/Leon/dev_gil/PMC/data/clean/conv1"
    conv = CologneConversation(fic)
    print(conv)
   # conversation = conv.getConversation()