#!/usr/bin/env python3

# Copyright (c) Facebook, Inc. and its affiliates.
# This source code is licensed under the MIT license found in the
# LICENSE file in the root directory of this source tree.
#
# This task simply loads the specified file: useful for quick tests without
# setting up a new task.

from parlai.core.teachers import FbDialogTeacher, ParlAIDialogTeacher

import copy, os

from .build import build

def _path(opt, filtered):
# build the data if it does not exist
    build(opt)

    # set up path to data (specific to each dataset)
    print(opt['datapath'])
    dt = opt['datatype'].split(':')[0]
    print(dt)
    # print(os.path.join(opt['datapath'], 'cologne', 'pmctestparlai.txt'))
    return os.path.join(opt['datapath'], 'cologne', 'pmctestparlai.txt')

class CologneTeacher(ParlAIDialogTeacher):
    """
    This module provides access to data in the ParlAI Text Dialog format.

    See core/teachers.py for more info about the format.
    """


    def __init__(self, opt, shared=None):

        super().__init__(opt, shared)

        opt = copy.deepcopy(opt)

        datafile = _path(opt, '')
        print(datafile)

        if shared is None:
            self._setup_data(datafile)
        # self.id = datafile
        # self.reset()
        print(self.id)
        
class DefaultTeacher(CologneTeacher):

    def init(self, opt, shared=None):
        super().init(opt, shared)
        opt = copy.deepcopy(opt)

        # get datafile
        opt['datafile'] = _path(opt, '')
