Task: Convai2
--------------

Kvmemnn Convai2 Model
~~~~~~~~~~~~~~~~~~~~~
`[related project] <https://github.com/facebookresearch/ParlAI/tree/master/projects/convai2/>`__ `[external website] <http://convai.io//>`__ 

KvMemNN trained on the ConvAI2 task, used as a baseline in the competition.

Example invocation(s):

.. code-block:: none

   python -m parlai.scripts.interactive -mf zoo:convai2/kvmemnn/model
   
   Enter Your Message: Hi, what do you think of peanuts?
   there was a kid in the school system my mum works for with a severe peanut allergy

Seq2Seq Convai2 Model
~~~~~~~~~~~~~~~~~~~~~
`[related project] <https://github.com/facebookresearch/ParlAI/tree/master/projects/convai2/>`__ `[external website] <http://convai.io//>`__ 

SeqSeq trained on the ConvAI2 task, used as a baseline in the competition.

Example invocation(s):

.. code-block:: none

   python -m parlai.scripts.interactive -mf zoo:convai2/seq2seq/convai2_self_seq2seq_model -m legacy:seq2seq:0
   
   Enter Your Message: Hi, what do you think of peanuts?
   [Seq2Seq]: i don't have any , but i do not have a favorite .

Controllable Dialogue Convai2 Model
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`[related project] <https://github.com/facebookresearch/ParlAI/tree/master/projects/controllable_dialogue/>`__ 

Seq2Seq model with control trained on ConvAI2

Example invocation(s):

.. code-block:: none

   python -m parlai.scripts.eval_model --model projects.controllable_dialogue.controllable_seq2seq.controllable_seq2seq:ControllableSeq2seqAgent --task projects.controllable_dialogue.tasks.agents -mf zoo:controllable_dialogue/convai2_finetuned_baseline
   
   {'exs': 7801, 'accuracy': 0.0006409, 'f1': 0.1702, 'bleu': 0.005205, 'token_acc': 0.3949, 'loss': 3.129, 'ppl': 22.86}

Poly-Encoder Transformer Convai2 Model
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`[related project] <https://github.com/facebookresearch/ParlAI/tree/master/projects/polyencoder//>`__ 

Polyencoder pretrained on Reddit and fine-tuned on ConvAI2 scoring 89+ hits@1/20. See the pretrained_transformers directory for a list of other available pretrained transformers

Example invocation(s):

.. code-block:: none

   python examples/interactive.py -mf zoo:pretrained_transformers/model_poly/model -t convai2
   
   hi how are you doing ?
   [Polyencoder]: i am alright . i am back from the library .
   Enter Your Message: oh, what do you do for a living?
   [Polyencoder]: i work at the museum downtown . i love it there .
   Enter Your Message: what is your favorite drink?
   [Polyencoder]: i am more of a tea guy . i get my tea from china .

.. code-block:: none

   python examples/eval_model.py -mf zoo:pretrained_transformers/model_poly/model -t convai2 --eval-candidates inline
   
   [ Finished evaluating tasks ['convai2'] using datatype valid ]
   {'exs': 7801, 'accuracy': 0.8942, 'f1': 0.9065, 'hits@1': 0.894, 'hits@5': 0.99, 'hits@10': 0.997, 'hits@100': 1.0, 'bleu': 0.8941, 'lr': 5e-09, 'total_train_updates': 0, 'examples': 7801, 'loss': 3004.0, 'mean_loss': 0.385, 'mean_rank': 1.234, 'mrr': 0.9359}

Bi-Encoder Transformer Convai2 Model
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`[related project] <https://github.com/facebookresearch/ParlAI/tree/master/projects/polyencoder//>`__ 

Bi-encoder pretrained on Reddit and fine-tuned on ConvAI2 scoring ~87 hits@1/20.

Example invocation(s):

.. code-block:: none

   python examples/interactive.py -mf zoo:pretrained_transformers/model_bi/model -t convai2
   
   hi how are you doing ?
   [Biencoder]: my mother is from russia .
   Enter Your Message: oh cool, whereabouts ?
   [Biencoder]: no , she passed away when i was 18 . thinking about russian recipes she taught me ,
   Enter Your Message: what do you cook?
   [Biencoder]: like meat mostly , me and my dogs love them , do you like dogs ?

.. code-block:: none

   python examples/eval_model.py -mf zoo:pretrained_transformers/model_bi/model -t convai2 --eval-candidates inline
   
   [ Finished evaluating tasks ['convai2'] using datatype valid ]
   {'exs': 7801, 'accuracy': 0.8686, 'f1': 0.8833, 'hits@1': 0.869, 'hits@5': 0.987, 'hits@10': 0.996, 'hits@100': 1.0, 'bleu': 0.8685, 'lr': 5e-09, 'total_train_updates': 0, 'examples': 7801, 'loss': 28.77, 'mean_loss': 0.003688, 'mean_rank': 1.301, 'mrr': 0.9197}

Task: Squad
------------

Drqa Squad Model
~~~~~~~~~~~~~~~~
`[external website] <https://github.com/facebookresearch/DrQA/>`__ 

DrQA Reader trained on SQuAD

Example invocation(s):

.. code-block:: none

   python -m parlai.scripts.eval_model -mf zoo:drqa/squad/model -t squad -dt test
   
   {'exs': 10570, 'accuracy': 0.6886, 'f1': 0.7821, 'hits@1': 0.689, 'hits@5': 0.689, 'hits@10': 0.689, 'hits@100': 0.689, 'bleu': 0.1364, 'train_loss': 0}

Task: Wikipedia
----------------

Wikipedia Retriever (Used For Open Squad)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`[external website] <https://github.com/facebookresearch/DrQA/>`__ 

Retrieval over Wikipedia dump, used for DrQA on the open squad dataset. This is the dump from the original paper, used for replicating results.

Example invocation(s):

.. code-block:: none

   python -m parlai.scripts.interactive --model tfidf_retriever -mf zoo:wikipedia_2016-12-21/tfidf_retriever/drqa_docs
   
   Enter Your Message: Yann LeCun
   [candidate_scores]: [507.05804682 390.18244433 279.24033928 269.60377042 214.00140589]
   [SparseTfidfRetrieverAgent]:
   Deep learning (also known as deep structured learning, hierarchical learning or deep machine learning) is a branch of machine learning based on a set of algorithms that attempt to model high level abstractions in data. In a simple case, you could have two sets of neurons: ones that receive an input signal and ones that send an output signal. When the input layer receives an input it passes on a modified version of the input to the next layer. In a deep network, there are many layers between the input and output (and the layers are not made of neurons but it can help to think of it that way), allowing the algorithm to use multiple processing layers, composed of multiple linear and non-linear transformations.
   
   Deep learning is part of a broader family of machine learning methods based on ...
   to commonsense reasoning which operates on concepts in terms of production rules of the grammar, and is a basic goal of both human language acquisition and AI. (See also Grammar induction.)

Wikipedia Retriever (Used For Wizard Of Wikipedia)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`[related project] <https://github.com/facebookresearch/ParlAI/tree/master/projects/wizard_of_wikipedia/>`__ 

Retrieval over Wikipedia dump, used for DrQA on the open squad dataset.

Example invocation(s):

.. code-block:: none

   python -m parlai.scripts.interactive --model tfidf_retriever -mf zoo:wikipedia_full/tfidf_retriever/model
   
   Enter Your Message: Yann LeCun
   [candidate_scores]: [454.74038503 353.88863708 307.31353203 280.4501096  269.89960432]
   [SparseTfidfRetrieverAgent]:
   Yann LeCun (; born 1960) is a computer scientist with contributions in machine learning, computer vision, mobile robotics and computational neuroscience. He is well known for his work on optical character recognition and computer vision using convolutional neural networks (CNN), and is a founding father of convolutional nets. He is also one of the main creators of the DjVu image compression technology (together with Léon Bottou and Patrick Haffner). He co-developed the Lush programming language with Léon Bottou.
   
   Yann LeCun was born near Paris, France, in 1960. He received a Diplôme d'Ingénieur from the Ecole Superieure d'Ingénieur en Electrotechnique et Electronique (ESIEE), Paris in 1983, and a PhD in Computer Science from Université Pierre et Marie Curie in 1987 during which he ...
   of Science and Technology in Saudi Arabia because he was considered a terrorist in the country in view of his atheism.
   
   In 2018 Yann LeCun picked a fight with a robot to support Facebook AI goals.

Task: Wizard_of_wikipedia
--------------------------

Wizard Of Wikipedia (End To End Generator)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`[related project] <https://github.com/facebookresearch/ParlAI/tree/master/projects/wizard_of_wikipedia/>`__ 

End2End Generative model for Wizard of Wikipedia

Example invocation(s):

.. code-block:: none

   python examples/display_model.py -t wizard_of_wikipedia:generator -mf zoo:wizard_of_wikipedia/end2end_generator/model -n 1 --display-ignore-fields knowledge_parsed
   
   [chosen_topic]: Gardening
   [knowledge]: no_passages_used __knowledge__ no_passages_used
   Gardening __knowledge__ Gardening is the practice of growing and cultivating plants as part of horticulture.
   Gardening __knowledge__ In gardens, ornamental plants are often grown for their flowers, foliage, or overall appearance; useful plants, such as root vegetables, leaf vegetables, fruits, and herbs, are grown for consumption, for use as dyes, or for medicinal or cosmetic use.
   Gardening __knowledge__ Gardening is considered by many people to be a relaxing activity.
   Gardening __knowledge__ Gardening ranges in scale from fruit orchards, to long boulevard plantings with one or more different types of shrubs, trees, and herbaceous plants, to residential yards including lawns and foundation plantings, to plants in large or small containers ...
   there had been several other notable gardening magazines in circulation, including the "Gardeners' Chronicle" and "Gardens Illustrated", but these were tailored more for the professional gardener.
   
   [title]: Gardening
   [checked_sentence]: Gardening is considered by many people to be a relaxing activity.
   [eval_labels_choice]: I live on a farm, we garden all year long, it is very relaxing.
   [checked_sentence_parsed]: Gardening __knowledge__ Gardening is considered by many people to be a relaxing activity.
   [WizTeacher]: Gardening
   I like Gardening, even when I've only been doing it for a short time.
   [eval_labels: I live on a farm, we garden all year long, it is very relaxing.]
   [TorchAgent]: i love gardening , it is considered a relaxing activity .

Wizard Of Wikipedia (Full Dialogue Retrieval Model)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`[related project] <https://github.com/facebookresearch/ParlAI/tree/master/projects/wizard_of_wikipedia/>`__ 

Full Dialogue Retrieval Model for Wizard of Wikipedia

Example invocation(s):

.. code-block:: none

   python examples/display_model.py -t wizard_of_wikipedia -mf zoo:wizard_of_wikipedia/full_dialogue_retrieval_model/model -m projects:wizard_of_wikipedia:wizard_transformer_ranker --n-heads 6 --ffn-size 1200 --embeddings-scale False --delimiter ' __SOC__ ' --n-positions 1000 --legacy True 
   
   [chosen_topic]: Gardening
   [knowledge]: Gardening Gardening is the practice of growing and cultivating plants as part of horticulture.
   Gardening In gardens, ornamental plants are often grown for their flowers, foliage, or overall appearance; useful plants, such as root vegetables, leaf vegetables, fruits, and herbs, are grown for consumption, for use as dyes, or for medicinal or cosmetic use.
   Gardening Gardening is considered by many people to be a relaxing activity.
   Gardening Gardening ranges in scale from fruit orchards, to long boulevard plantings with one or more different types of shrubs, trees, and herbaceous plants, to residential yards including lawns and foundation plantings, to plants in large or small containers grown inside or outside.
   Gardening Gardening may be very specialized, with only one type of plant grown, ...
   there had been several other notable gardening magazines in circulation, including the "Gardeners' Chronicle" and "Gardens Illustrated", but these were tailored more for the professional gardener.
   
   [title]: Gardening
   [checked_sentence]: Gardening is considered by many people to be a relaxing activity.
   [eval_labels_choice]: I live on a farm, we garden all year long, it is very relaxing.
   [wizard_of_wikipedia]: Gardening
   I like Gardening, even when I've only been doing it for a short time.
   [label_candidates: OK what's the history?|Right, thats cool. I had no idea they still did the DVD thing, What is Netflix's highest rated show? do you know? |I will definitely check his first album out as he sounds interesting.|I don't know a whole lot about it. I was raised Catholic but don't practice anything now.|Well , this was a good conversation. |...and 95 more]
   [eval_labels: I live on a farm, we garden all year long, it is very relaxing.]
   [TorchAgent]: I live on a farm, we garden all year long, it is very relaxing.

.. code-block:: none

   examples/interactive.py -m projects:wizard_of_wikipedia:interactive_retrieval -t wizard_of_wikipedia
   
   [ Your chosen topic is: Teapot ]
   Enter Your Message: do you like tea?
   [WizardRetrievalInteractiveAgent]: Yes!  I only use teapots that have a little air hole in the lid. That prevents the spout from dripping or splashing when the tea is poured. Most teapots have this though.
   Enter Your Message: what about kettles?
   [WizardRetrievalInteractiveAgent]: I would think you could use them to heat any type of liquid! I use my teapots with a tea cosy. It's a thermal cover that helps keep the tea hot.
   Enter Your Message: do you like earl grey?
   [WizardRetrievalInteractiveAgent]: I think I'll try some Lipton, I love their green tea!

Task: Light_dialog
-------------------

Light Bert-Biranker Dialogue Model
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`[related project] <https://github.com/facebookresearch/ParlAI/tree/master/projects/light/>`__ 

LIGHT Dialogue task, replicating the numbers from the paper.

Example invocation(s):

.. code-block:: none

   python examples/eval_model.py -t light_dialog -mf zoo:light/biranker_dialogue/model
   
   {'exs': 6623, 'accuracy': 0.7586, 'f1': 0.7802, 'hits@1': 0.759, 'hits@5': 0.965,'hits@10': 0.994, 'hits@100': 1.0, 'bleu': 0.7255, 'lr': 5e-05, 'total_train_updates': 15050,'examples': 6623, 'loss': 5307.0, 'mean_loss': 0.8013, 'mean_rank': 1.599, 'train_accuracy': 0}

Task: Personality_captions
---------------------------

Transresnet (Resnet 152) Personality-Captions Model
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`[related project] <https://github.com/facebookresearch/ParlAI/tree/master/projects/personality_captions/>`__ 

Transresnet Model pretrained on the Personality-Captions task

Example invocation(s):

.. code-block:: none

   python examples/eval_model.py -t personality_captions -mf zoo:personality_captions/transresnet/model --num-test-labels 5 -dt test
   
   {'exs': 10000, 'accuracy': 0.5113, 'f1': 0.5951, 'hits@1': 0.511, 'hits@5': 0.816, 'hits@10': 0.903, 'hits@100': 0.998, 'bleu': 0.4999, 'hits@1/100': 1.0, 'loss': -0.002, 'med_rank': 1.0}

Task: Image_chat
-----------------

Transresnet (Resnet152) Image-Chat Model
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`[related project] <https://github.com/facebookresearch/ParlAI/tree/master/projects/image_chat/>`__ 

Transresnet Multimodal Model pretrained on the Image-Chat task

Example invocation(s):

.. code-block:: none

   python examples/eval_model.py -t image_chat -mf zoo:image_chat/transresnet_multimodal/model -dt test
   
   {'exs': 29991, 'accuracy': 0.4032, 'f1': 0.4432, 'hits@1': 0.403, 'hits@5': 0.672, 'hits@10': 0.779, 'hits@100': 1.0, 'bleu': 0.3923,'first_round': {'hits@1/100': 0.3392, 'loss': -0.002001, 'med_rank': 3.0},'second_round': {'hits@1/100': 0.4558, 'loss': -0.002001, 'med_rank': 2.0},'third_round+': {'hits@1/100': 0.4147, 'loss': -0.002001, 'med_rank': 2.0}}'hits@10': 0.903, 'hits@100': 0.998, 'bleu': 0.4999, 'hits@1/100': 1.0, 'loss': -0.002, 'med_rank': 1.0}

Task: Self_feeding
-------------------

Self-Feeding Chatbot
~~~~~~~~~~~~~~~~~~~~
`[related project] <https://github.com/facebookresearch/ParlAI/tree/master/projects/self_feeding/>`__ 

The self-feeding chatbot of Hancock, et al., 2019 (https://arxiv.org/abs/1901.05415). This model learns from is mistakes when actually talking with users. This particular model corresponds to the model with 131k human-human chats + 60k human-bot chats + 60k feedback chats.

Example invocation(s):

.. code-block:: none

   python projects/self_feeding/interactive.py --model-file zoo:self_feeding/hh131k_hb60k_fb60k_st1k/model --no-cuda true
   
   Enter Your Message: hi, my name is stephen. what's yours?
   [SelfFeeding]: hi there greg . do you have pets ? i've 2 cats named milo and fio .
   Enter Your Message: sadly, i have no pets. my landlord isn't a fan.
   [SelfFeeding]: sorry to hear that . i always had bad allergies when i liven on my farm in kansas .

.. code-block:: none

   python examples/eval_model.py -mf zoo:self_feeding/hh131k_hb60k_fb60k_st1k/model -t self_feeding:all
   
   [ Finished evaluating tasks ['self_feeding:all'] using datatype valid ]
   {'exs': 3500, 'dia_rank': 4.654, 'dia_acc': 0.3525, 'fee_rank': 1.0, 'fee_acc': 1.0, 'fee_exs': 1000, 'sat_re': 0.4607, 'sat_f1': 0.5605, 'sat_acc': 0.724}

Task: Dialogue_safety
----------------------

Transformer Classifier Single-Turn Dialogue Safety Model
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`[related project] <https://github.com/facebookresearch/ParlAI/tree/master/projects/dialogue_safety/>`__ 

Classifier trained on both the standard and adversarial safety tasks in addition to Wikipedia Toxic Comments.

Example invocation(s):

.. code-block:: none

   python examples/eval_model.py -t dialogue_safety:adversarial --round 3 -dt test -mf zoo:dialogue_safety/single_turn/model -bs 40
   
   {'exs': 3000, 'accuracy': 0.9627, 'f1': 0.9627, 'bleu': 9.627e-10, 'lr': 5e-09, 'total_train_updates': 0, 'examples': 3000, 'mean_loss': 0.005441, 'class___notok___recall': 0.7833, 'class___notok___prec': 0.8333, 'class___notok___f1': 0.8076, 'class___ok___recall': 0.9826, 'class___ok___prec': 0.9761, 'class___ok___f1': 0.9793, 'weighted_f1': 0.9621}

Bert Classifier Multi-Turn Dialogue Safety Model
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`[related project] <https://github.com/facebookresearch/ParlAI/tree/master/projects/dialogue_safety/>`__ 

Classifier trained on the multi-turn adversarial safety task in addition to both the single-turn standard and adversarial safety tasks and Wikipedia Toxic Comments.

Example invocation(s):

.. code-block:: none

   python examples/eval_model.py -t dialogue_safety:multiturn -dt test -mf zoo:dialogue_safety/multi_turn/model --split-lines True -bs 40
   
   {'exs': 3000, 'accuracy': 0.9317, 'f1': 0.9317, 'bleu': 9.317e-10, 'lr': 5e-09, 'total_train_updates': 0, 'examples': 3000, 'mean_loss': 0.008921, 'class___notok___recall': 0.7067, 'class___notok___prec': 0.6444, 'class___notok___f1': 0.6741, 'class___ok___recall': 0.9567, 'class___ok___prec': 0.9671, 'class___ok___f1': 0.9618, 'weighted_f1': 0.9331}

