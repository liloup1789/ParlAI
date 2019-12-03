# Copyright 2019-2020 by Akio, Akio Software.
# All rights reserved.
# This file is part of the Akio Chatbot project

"""
    Ce code concerne parfum moins cher et tout un tas de processus pour formater les données ou les traiter. 
    Il peut inclure des librairies externes précisées dans le requirements.txt telles que scikit learn, tensorflow ou encore pandas 

    Il implémente les agents. Un agent est une classe non abstraite. Un interlocteur est une sous-classe d'agent dont le but et l'état interne sont des probabilités. 

"""

class Agent(object) : 

    def __init__(self) :

        self.name = 'Agent_'

        self.role = ''

        self.perception = ''

        self.action = ''

        self.internal = {self.role : "" ,
                         self.updated : 0 ,
                        'history' : [] ,
                        'perception_action' : (self.perception,self.action),
                        'satisfaction' : 0 , 
                        }
        self.memories = {'working': (internal['history'],internal['perception_action'],internal['satisfaction']), 'episodic': {}, 'semantic' : {} }
        

class interloctor(Agent) : 

    def __init__(self) : 

        Agent.__init__(self)

        self.internal = {}

        self.name = 'Interl_'


