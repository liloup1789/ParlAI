#!/usr/bin/env python3

# Copyright (c) Facebook, Inc. and its affiliates.
# This source code is licensed under the MIT license found in the
# LICENSE file in the root directory of this source tree.
"""
Allows a model to self-chat on a given task.
"""
from parlai.core.params import ParlaiParser
from parlai.core.agents import create_agent
from parlai.core.worlds import create_task
from parlai.utils.world_logging import WorldLogger
from parlai.utils.misc import TimeLogger

import random


def setup_args(parser=None):
    if parser is None:
        parser = ParlaiParser(True, True, 'Self chat with a model')
    parser.add_argument('--seed', type=int, default=42)
    parser.add_argument('-d', '--display-examples', type='bool', default=True)
    parser.add_argument('-n', '-ne', '--num-examples', type=int, default=10)
    parser.add_argument('-ltim', '--log-every-n-secs', type=float, default=2)
    parser.add_argument(
        '--display-ignore-fields',
        type=str,
        default='label_candidates,text_candidates',
        help='Do not display these fields',
    )
    parser.add_argument(
        '-it',
        '--interactive-task',
        type='bool',
        default=True,
        help='Create interactive version of task',
    )
    parser.add_argument(
        '--selfchat-max-turns',
        type=int,
        default=10,
        help="The number of dialogue turns before self chat ends.",
    )
    parser.add_argument(
        '--seed-messages-from-task',
        action='store_true',
        help="Automatically seed conversation with messages from task dataset.",
    )
    parser.add_argument('--outfile', type=str, default='/tmp/selfchat.json')
    parser.add_argument(
        '--format', type=str, default='json', choices={'parlai', 'json'}
    )
    parser.set_defaults(interactive_mode=True, task='self_chat')
    WorldLogger.add_cmdline_args(parser)
    return parser


def self_chat(opt, print_parser=None):
    if print_parser is not None:
        if print_parser is True and isinstance(opt, ParlaiParser):
            print_parser = opt
        elif print_parser is False:
            print_parser = None
    if isinstance(opt, ParlaiParser):
        print('[ Deprecated Warning: self_chat should be passed opt not Parser ]')
        opt = opt.parse_args()

    random.seed(opt['seed'])
    # Create models
    agent1 = create_agent(opt, requireModelExists=True)
    agent2 = agent1.clone()
    if hasattr(agent2, 'id'):
        agent2.id = agent2.id + "2"

    world = create_task(opt, [agent1, agent2])

    if print_parser:
        # Show arguments after loading model
        print_parser.opt = agent1.opt
        print_parser.print_args()

    # set up logging
    log_every_n_secs = opt.get('log_every_n_secs', -1)
    if log_every_n_secs <= 0:
        log_every_n_secs = float('inf')
    log_time = TimeLogger()
    logger = WorldLogger(opt)

    # Run some self chats.
    max_cnt = opt['num_examples']
    cnt = 0
    while cnt < max_cnt:
        cnt += opt.get('batchsize', 1)
        world.parley()
        logger.log(world)

        if opt.get('display_examples'):
<<<<<<< HEAD
=======
<<<<<<< HEAD
<<<<<<< HEAD
=======
            print("---")
>>>>>>> 4f6b99642d60aff1a41b9eae8bd2ccd9e40ebba4
>>>>>>> origin/master
=======
            print("---")
>>>>>>> 4f6b99642d60aff1a41b9eae8bd2ccd9e40ebba4
>>>>>>> ef574cebef2a8d5aa38b73176b1e71a919d6670f
            print(world.display())
        if log_time.time() > log_every_n_secs:
            text = log_time.log(cnt, max_cnt)
            print(text)

<<<<<<< HEAD
    if opt.get('display_examples'):
        print('-- end of episode --')

=======
<<<<<<< HEAD
<<<<<<< HEAD
    if opt.get('display_examples'):
        print('-- end of episode --')

=======
>>>>>>> 4f6b99642d60aff1a41b9eae8bd2ccd9e40ebba4
>>>>>>> origin/master
=======
>>>>>>> 4f6b99642d60aff1a41b9eae8bd2ccd9e40ebba4
>>>>>>> ef574cebef2a8d5aa38b73176b1e71a919d6670f
    logger.write(opt['outfile'], opt['format'])


if __name__ == '__main__':
    parser = setup_args()
    self_chat(parser.parse_args(print_args=False), print_parser=parser)
