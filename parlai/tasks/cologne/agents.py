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

def _path(opt):
# build the data if it does not exist
    build(opt)
    prefix = os.path.join(opt['datapath'], 'cologne')
    print("prefix = {}".format(prefix))
# set up path to data (specific to each dataset)
    print(opt['datapath'])
    suffix = ''
    dt = opt['datatype'].split(':')[0]
    if dt == 'train':
        suffix = 'trn'
    elif dt == 'test':
        suffix = 'tst'
    elif dt == 'valid':
        suffix = 'dev'
    datafile = os.path.join(prefix,
       'cologne-{type}.txt'.format( type=suffix)
    )
    print("datafile = {}".format(datafile))
    print(dt)
    cands_datafile = os.path.join(prefix,'cologne-cands.txt')
    print(cands_datafile)
    # print(os.path.join(opt['datapath'], 'cologne', 'pmctestparlai.txt'))
    return datafile, cands_datafile


class TaskTeacher(FbDialogTeacher):
    def __init__(self, opt, shared=None):
        paths = _path(opt)
        opt['datafile'], opt['cands_datafile'] = paths
        super().__init__(opt, shared)

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
        
class DefaultTeacher(TaskTeacher):

    def init(self, opt, shared=None):
        super().init(opt, shared)
        opt = copy.deepcopy(opt)

        # get datafile
        opt['datafile'] = _path(opt)
