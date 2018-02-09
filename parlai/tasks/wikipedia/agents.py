# Copyright (c) 2017-present, Facebook, Inc.
# All rights reserved.
# This source code is licensed under the BSD-style license found in the
# LICENSE file in the root directory of this source tree. An additional grant
# of patent rights can be found in the PATENTS file in the same directory.

from parlai.core.teachers import DialogTeacher
from .build import build

import json
import os


class AllTeacher(DialogTeacher):
    """Reads Wikipedia pages one at a time
    """
    def __init__(self, opt, shared=None):
        opt['task'] = 'wikipedia:all'
        success = build(opt)
        self.opt = opt
        if not success:
            '''Need to extract the rest of the data'''
            raise RuntimeError(self.get_instructions())
        opt['datafile'] = os.path.join(
            opt['datapath'],
            'wikipedia/full/wiki_full_extracted')
        self.id = 'wikipedia'
        super().__init__(opt, shared)

    def setup_data(self, path):
        print('loading: ' + path)
        if not os.path.exists(path):
            '''Need to extract the rest of the data'''
            raise RuntimeError(self.get_instructions())
        for subdir in os.listdir(path):
            subdir_path = os.path.join(path, subdir)
            for wiki_file in os.listdir(subdir_path):
                wiki_file_path = os.path.join(subdir_path, wiki_file)
                with open(wiki_file_path) as wf:
                    for article_json in wf:
                        article = json.loads(article_json)
                        title = article['title']
                        text = article['text']
                        yield (title + '\n' + text, None), True

    def get_instructions(self):
        dpath = os.path.join(self.opt['datapath'], 'wikipedia', 'full')
        fname = 'enwiki-latest-pages-articles.xml.bz2'
        instructions = """
        To complete the data extraction, please run the following:
        \n
        mkdir -p {download}  && git clone https://github.com/attardi/wikiextractor  {download}/wikiextract && cd {download}/wikiextract && python WikiExtractor.py {wikifile} --filter_disambig_pages -o {output} --json
        """.format(
            download=self.opt['download_path'],
            wikifile=dpath + '/' + fname,
            output=dpath + '/' + 'wiki_extracted'
            )

        return instructions


class SummaryTeacher(DialogTeacher):
    """Reads Wikipedia pages one at a time, only uses summaries
    """
    def __init__(self, opt, shared=None):
        build(opt)
        opt['datafile'] = os.path.join(
            opt['datapath'],
            'wikipedia/summary/summaries.json')
        self.id = 'wikipedia'
        super().__init__(opt, shared)

    def setup_data(self, path):
        print('loading: ' + path)
        with open(path) as wf:
            for article_json in wf:
                article = json.loads(article_json)
                title = article['title']
                text = article['text']
                yield (title + '\n' + text, None), True


class DefaultTeacher(SummaryTeacher):
    pass
