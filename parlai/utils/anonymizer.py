#!/usr/bin/env python3

# Copyright (c) Facebook, Inc. and its affiliates.
# This source code is licensed under the MIT license found in the
# LICENSE file in the root directory of this source tree.

from abc import ABC, abstractmethod

import re

from py4j.java_gateway import JavaGateway

class Anonymizer(ABC) : 

	def __init__(self,entry,mode,entry_type,ano_type) : 

		self.entry = entry
		self.mode = int(mode)
		self.entry_type = entry_type
		self.output = ""
		self.ano = ano_type

		assert self.mode == 0 or self.mode == 1

		assert self.ano == "ano" or self.ano == "pseudo" 

		if mode == 0 : 
			self.namemode = "full"
		elif mode == 1 : 
			self.namemode = "memory"

		print("mode is {}".format(self.namemode)) 


	@abstractmethod
	def anonymize(self) : 

		pass

	def transformer(self) : 

		self.output = re.sub(r"\(\d+:\d+\)",'\n',self.output)



class FullAnonymizer(Anonymizer) : 

	def __init__(self,entry,mode,entry_type,javanonymizer) : 

		super.__init__(self)

		self.anonymizer = javanonymizer

		if self.mode != 0 :  

			raise ValueError("You chose the wrong mode") 


	def anonymize(self) : 

		self.output = self.anonymizer(self.entry,self.mode)

		if self.entry_type == "conversation" : 

			self.output.Anonymizer.transformer()

			return self.output

class MemoriesAnonymizer(Anonymizer) : 

	def __init__(self,entry,mode,entry_type,javanonymizer) : 

		super.__init__(self)

		self.anonymizer = javanonymizer

		if self.mode != 1 :  

			raise ValueError("You chose the wrong mode") 

		if self.entry_type != "conversation" : 

			raise ModeError("You can't use this anonymizer with speaking turns")

	def anonymize(self) : 

		self.output = self.anonymizer(self.entry,self.mode)

		if self.entry_type == "conversation" : 

			self.output.Anonymizer.transformer()

			return self.output

def main(inpt,mode,entry_type,funct) : 

	if mode == 0 : 

		anonymizer = FullAnonymizer(inpt,mode,entry_type,funct)

	elif mode == 1 : 

		anonymizer = MemoriesAnonymizer(inpt,mode,entry_type,funct) 




	out = anonymizer.anonymize()

	print(out) 

if __name__ == '__main__':
	
	inpt = "Hello c'est B20. Je suis Léon-Paul Schaub et mon mail est schaub@limsi.fr"

	mode = 1 

	entry_type = "conversation"

	anonymizer = 0 

	not_pseudo = 1

	gateway = JavaGateway() 

	funct = gateway.jvm.com.ta.Anonymizer(Language.fr,False,True)
	

	main()