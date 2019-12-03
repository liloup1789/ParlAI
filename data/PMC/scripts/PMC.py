# Copyright 2019-2020 by Akio, Akio Software.
# All rights reserved.
# This file is part of the Akio Chatbot project

"""
    Ce code concerne parfum moins cher et tout un tas de processus pour formater les données ou les traiter. 
    Il peut inclure des librairies externes précisées dans le requirements.txt telles que scikit learn, tensorflow ou encore pandas 

"""
from abc import ABC, abstractmethod

from Agent import Agent, interlocutor

class Conversation(object) :

    def __init__(self,debut,fin) : 

        self.debut = debut
        self.fin = fin
        self.nb_tours = 0
        self.tours = {}
        self.agent = Agent()
        self.interlocteur = Interloctor()
        self.langue = 'fr'
        self.succes_global = False
        self.succes_locaux = {}



    @abstractmethod
    def format(self) : 
        pass
    @abstractmethod
    def read_conversation(self,string) :
        pass



class PMC(Conversation) : 

""" 

    Constructor : 
    Reads a file or a directory 
    args : mode, file/dir name

"""

    def __init__(self,filename) : 

        Conversation.__init__(self,debut,fin,nb_tours,duree,agent,interlocuteur)

        self.nb_tours = nb_tours
        self.duree = duree 
        self.agent.name += agent
        self.interlocuteur.name += interlocuteur 


    def read_conversation(self,string) :

