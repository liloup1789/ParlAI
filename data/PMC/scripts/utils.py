# Copyright 2019-2020 by Akio, Akio Software.
# All rights reserved.
# This file is part of the Akio Chatbot project

"""
	Ce code concerne parfum moins cher et tout un tas de processus pour formater les données ou les traiter. 
	Il peut inclure des librairies externes précisées dans le requirements.txt telles que scikit learn, tensorflow ou encore pandas 
	code utilitaire pour formater les données

"""

DATA = '../data/'

def extract_pmc_csv (filename) :

	fstream = open(filename,'r',encoding='utf-8')

	head = fstream.readline()

	conversation = ''
	for elem in open(filename,'r',encoding='utf-8').readlines() : 

		if not elem.startswith('"Chat Parfums Moins Chers') : 

			conversation += elem
		else : 
			yield conversation
			conversation = ''


if __name__ == '__main__':
	
	for chose in extract_pmc_csv(DATA+'pmctest.csv') : 
		print(chose)