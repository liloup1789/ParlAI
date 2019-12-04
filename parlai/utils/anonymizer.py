#!/usr/bin/env python3

# Copyright (c) Facebook, Inc. and its affiliates.
# This source code is licensed under the MIT license found in the
# LICENSE file in the root directory of this source tree.

from abc import ABC, abstractmethod

import re

class Anonymizer(ABC) : 

	def __init__(self,entry,mode,entry_type) : 

		self.entry = entry
		self.mode = mode
		self.entry_type = entry_type
		self.output = ""

	@abstractmethod
	def anonymize(self) : 

		pass

	def transformer(self) : 

		self.output = re.sub(r"\(\d+:\d+\)",'\n',self.output)

	

