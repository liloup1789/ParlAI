#!/usr/bin/env python3

# Copyright (c) Facebook, Inc. and its affiliates.
# This source code is licensed under the MIT license found in the
# LICENSE file in the root directory of this source tree.

"""
This is a converter to transform Akios data into FbDialog dataset format. 

TODO : build a Converter() abst class and inherit the ConverterCologne


"""
import re

from abc import  abstractmethod


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
        try :
            return re.search(self.__pattern2, self.__speaking).group(0).replace(" ","").replace(':','')
        except AttributeError :
            return 'userX'

class CologneConversation(Conversation):

    def __init__(self, fic):

        self.__conversation = []
        for line in  open(fic, 'r', encoding='utf-8').readlines () :
            self.__conversation.append(line.rstrip())
        self.__conversation = self.__conversation[:-1]

        if not self.__conversation :

            self.__conversation = ["(00:00) userX : empty"]

        self.__globalSatisfaction = 1

        self.__theme = "Cologne"

        self.speakingTurns = []

        self.__speakingturnsnumber = len(self.__conversation)

        self.__pattern1 = '\\(\\d\\d:\\d\\d\\)'

        self.__pattern2 = re.compile('(?<=(%s)) ?.?\\w+\s?:' % self.__pattern1)

        for elem in self.__conversation:
            self.speakingTurns.append(SpeakingTurn(self.__pattern1, self.__pattern2, elem))

        self.__agent = SpeakingTurn.getSpeaker(self.speakingTurns[0])
        self.__agent = self.__agent.replace(' ','')
        self.__agent = self.__agent.replace(':', '')

        first_user = ""
        x = 0
        if self.__speakingturnsnumber < 3 :
            self.__user = 'userX'
        else :
            for turn in self.speakingTurns[1:]:
                if not SpeakingTurn.getSpeaker(turn) :
                    self.__user = 'userX'
                if SpeakingTurn.getSpeaker(turn) != self.__agent and first_user == "" :
                    first_user = SpeakingTurn.getSpeaker(turn)
                    print("first user = {}".format(first_user))
                    continue
                elif SpeakingTurn.getSpeaker(turn) == self.__agent :
                    x += 1
                    if x > 2 :
                        self.__user ='userX'
                        break
                    else :
                        continue
                if SpeakingTurn.getSpeaker(turn) != "" and SpeakingTurn.getSpeaker(turn) != first_user  and SpeakingTurn.getSpeaker(turn) != self.__agent :
                    print("user inconnu")
                    self.__user = "userX"
                    break
                else :
                    self.__user = SpeakingTurn.getSpeaker(turn)
                    self.__user = self.__user.replace(' ', '')
                    self.__user = self.__user.replace(':', '')
                    break
        if not hasattr(self ,'__user') :
            self.__user = 'userX'
        # print(self.__agent)
        # print(self.__user)
        # print(self.__pattern1)
        # print(self.speakingTurns[0].getSpeaking())
        # print(self.speakingTurns[-1].getSpeaking())
        self.__startTime = re.match(re.compile(self.__pattern1), self.speakingTurns[0].getSpeaking()).group(0)
        # print(re.findall(re.compile(self.__pattern1), "(19:41):)")[0])
        self.__endTime = re.match(re.compile(self.__pattern1), self.speakingTurns[-1].getSpeaking()).group(0)

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

        if isinstance(p2, type(self.__pattern2)):
            self.__pattern2 = p2
        else:
            raise ValueError("pattern must be RE")

    def getSpeakingTurnsNumber(self):

        return self.__speakingturnsnumber

    def getConversationString(self):

        return '\n'.join([elem.getSpeaking() for elem in  self.speakingTurns])

    def getConversationArray(self):

        return self.__conversation

    def getLengthConv(self):

        start = CologneConversation.pattern2time(CologneConversation.__startTime)
        end = CologneConversation.pattern2time(CologneConversation.__endTime)

        return str(60 * (end[0] - start[0]) + (end[1] - start[1]))

    def FirstSpeakingTurn(self):

        return self.speakingTurns[0]

    def LastSpeakingTurn(self):

        return self.speakingTurns[-1]
class CologneConversation(Conversation):

    def __init__(self, fic):

        self.__conversation = []
        for line in  open(fic, 'r', encoding='utf-8').readlines () :
            self.__conversation.append(line.rstrip())
        self.__conversation = self.__conversation[:-1]

        if not self.__conversation :

            self.__conversation = ["(00:00) userX : empty"]

        self.__globalSatisfaction = 1

        self.__theme = "Cologne"

        self.speakingTurns = []

        self.__speakingturnsnumber = len(self.__conversation)

        self.__pattern1 = '\\(\\d\\d:\\d\\d\\)'

        self.__pattern2 = re.compile('(?<=(%s)) ?.?\\w+\s?:' % self.__pattern1)

        for elem in self.__conversation:
            self.speakingTurns.append(SpeakingTurn(self.__pattern1, self.__pattern2, elem))

        self.__agent = SpeakingTurn.getSpeaker(self.speakingTurns[0])
        self.__agent = self.__agent.replace(' ','')
        self.__agent = self.__agent.replace(':', '')

        first_user = ""
        x = 0
        if self.__speakingturnsnumber < 3 :
            self.__user = 'userX'
        else :
            for turn in self.speakingTurns[1:]:
                if not SpeakingTurn.getSpeaker(turn) :
                    self.__user = 'userX'
                if SpeakingTurn.getSpeaker(turn) != self.__agent and first_user == "" :
                    first_user = SpeakingTurn.getSpeaker(turn)
                    print("first user = {}".format(first_user))
                    continue
                elif SpeakingTurn.getSpeaker(turn) == self.__agent :
                    x += 1
                    if x > 2 :
                        self.__user ='userX'
                        break
                    else :
                        continue
                if SpeakingTurn.getSpeaker(turn) != "" and SpeakingTurn.getSpeaker(turn) != first_user  and SpeakingTurn.getSpeaker(turn) != self.__agent :
                    print("user inconnu")
                    self.__user = "userX"
                    break
                else :
                    self.__user = SpeakingTurn.getSpeaker(turn)
                    self.__user = self.__user.replace(' ', '')
                    self.__user = self.__user.replace(':', '')
                    break
        if not hasattr(self ,'__user') :
            self.__user = 'userX'
        # print(self.__agent)
        # print(self.__user)
        # print(self.__pattern1)
        # print(self.speakingTurns[0].getSpeaking())
        # print(self.speakingTurns[-1].getSpeaking())
        self.__startTime = re.match(re.compile(self.__pattern1), self.speakingTurns[0].getSpeaking()).group(0)
        # print(re.findall(re.compile(self.__pattern1), "(19:41):)")[0])
        self.__endTime = re.match(re.compile(self.__pattern1), self.speakingTurns[-1].getSpeaking()).group(0)

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

        if isinstance(p2, type(self.__pattern2)):
            self.__pattern2 = p2
        else:
            raise ValueError("pattern must be RE")

    def getSpeakingTurnsNumber(self):

        return self.__speakingturnsnumber

    def getConversationString(self):

        return '\n'.join([elem.getSpeaking() for elem in  self.speakingTurns])

    def getConversationArray(self):

        return self.__conversation

    def getLengthConv(self):

        start = CologneConversation.pattern2time(CologneConversation.__startTime)
        end = CologneConversation.pattern2time(CologneConversation.__endTime)

        return str(60 * (end[0] - start[0]) + (end[1] - start[1]))

    def FirstSpeakingTurn(self):

        return self.speakingTurns[0]

    def LastSpeakingTurn(self):

        return self.speakingTurns[-1]

    class FbCologneConversation(Conversation):

        def __init__(self, fic):

            self.__conversation = []
            for line in open(fic, 'r', encoding='utf-8').readlines():
                self.__conversation.append(line.rstrip())

            self.__globalSatisfaction = 1

            self.__theme = "Cologne"

            self.speakingTurns = []

            self.__speakingturnsnumber = len(self.__conversation)

            self.__pattern1 = '\\(\\d\\d:\\d\\d\\)'

            self.__pattern2 = re.compile('(?<=(%s)) ?.?\\w+\s?:' % self.__pattern1)

            for elem in self.__conversation:
                self.speakingTurns.append(SpeakingTurn(self.__pattern1, self.__pattern2, elem))

            self.__agent = SpeakingTurn.getSpeaker(self.speakingTurns[0])
            self.__agent = self.__agent.replace(' ', '')
            self.__agent = self.__agent.replace(':', '')

            first_user = ""
            x = 0
            if self.__speakingturnsnumber < 3:
                self.__user = 'userX'
            else:
                for turn in self.speakingTurns[1:]:
                    if not SpeakingTurn.getSpeaker(turn):
                        self.__user = 'userX'
                    if SpeakingTurn.getSpeaker(turn) != self.__agent and first_user == "":
                        first_user = SpeakingTurn.getSpeaker(turn)
                        print("first user = {}".format(first_user))
                        continue
                    elif SpeakingTurn.getSpeaker(turn) == self.__agent:
                        x += 1
                        if x > 2:
                            self.__user = 'userX'
                            break
                        else:
                            continue
                    if SpeakingTurn.getSpeaker(turn) != "" and SpeakingTurn.getSpeaker(
                            turn) != first_user and SpeakingTurn.getSpeaker(turn) != self.__agent:
                        print("user inconnu")
                        self.__user = "userX"
                        break
                    else:
                        self.__user = SpeakingTurn.getSpeaker(turn)
                        self.__user = self.__user.replace(' ', '')
                        self.__user = self.__user.replace(':', '')
                        break
            if not hasattr(self, '__user'):
                self.__user = 'userX'
            # print(self.__agent)
            # print(self.__user)
            # print(self.__pattern1)
            # print(self.speakingTurns[0].getSpeaking())
            # print(self.speakingTurns[-1].getSpeaking())
            self.__startTime = re.match(re.compile(self.__pattern1), self.speakingTurns[0].getSpeaking()).group(0)
            # print(re.findall(re.compile(self.__pattern1), "(19:41):)")[0])
            self.__endTime = re.match(re.compile(self.__pattern1), self.speakingTurns[-1].getSpeaking()).group(0)

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

            if isinstance(p2, type(self.__pattern2)):
                self.__pattern2 = p2
            else:
                raise ValueError("pattern must be RE")

        def getSpeakingTurnsNumber(self):

            return self.__speakingturnsnumber

        def getConversationString(self):

            return '\n'.join([elem.getSpeaking() for elem in self.speakingTurns])

        def getConversationArray(self):

            return self.__conversation

        def getLengthConv(self):

            start = CologneConversation.pattern2time(CologneConversation.__startTime)
            end = CologneConversation.pattern2time(CologneConversation.__endTime)

            return str(60 * (end[0] - start[0]) + (end[1] - start[1]))

        def FirstSpeakingTurn(self):

            return self.speakingTurns[0]

        def LastSpeakingTurn(self):

            return self.speakingTurns[-1]
#if __name__ == '__main__':


    #fic = "/home/tf/Documents/Leon/dev_gil/PMC/data/clean/conv1"
    #conv = CologneConversation(fic)
    #conversation = conv.getConversationString()
    #print(conversation)
    #print(conv.getConversationArray())