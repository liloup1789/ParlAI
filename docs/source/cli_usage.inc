display_data
------------
.. automodule:: parlai.scripts.display_data

CLI help
~~~~~~~~


.. code-block:: text

    usage: python -m parlai.scripts.display_data [-h] [-o INIT_OPT] [-v] [-t TASK]
                                                 [-dt {train,train:stream,train:ordered,train:ordered:stream,train:stream:ordered,train:evalmode,train:evalmode:stream,train:evalmode:ordered,train:evalmode:ordered:stream,train:evalmode:stream:ordered,valid,valid:stream,test,test:stream}]
                                                 [-nt NUMTHREADS] [-bs BATCHSIZE] [-dp DATAPATH] [-m MODEL] [-mf MODEL_FILE]
                                                 [-im INIT_MODEL] [-pyt PYTORCH_TEACHER_TASK] [-pytd PYTORCH_TEACHER_DATASET]
                                                 [-n NUM_EXAMPLES] [-mdl MAX_DISPLAY_LEN]
                                                 [--display-ignore-fields DISPLAY_IGNORE_FIELDS]
    
    Display data from a task
    
    optional arguments:
      -h, --help
            show this help message and exit
      -n, -ne, --num-examples NUM_EXAMPLES
      -mdl, --max-display-len MAX_DISPLAY_LEN
      --display-ignore-fields DISPLAY_IGNORE_FIELDS
    
    Main ParlAI Arguments:
      -o, --init-opt INIT_OPT
            Path to json file of options. Note: Further Command-line arguments override file-based options. (default: None)
      -v, --show-advanced-args
            Show hidden command line options (advanced users only) (default: False)
      -t, --task TASK
            ParlAI task(s), e.g. "babi:Task1" or "babi,cbt" (default: None)
      -dt, --datatype {train,train:stream,train:ordered,train:ordered:stream,train:stream:ordered,train:evalmode,train:evalmode:stream,train:evalmode:ordered,train:evalmode:ordered:stream,train:evalmode:stream:ordered,valid,valid:stream,test,test:stream}
            choose from: train, train:ordered, valid, test. to stream data add ":stream" to any option (e.g., train:stream). by
            default: train is random with replacement, valid is ordered, test is ordered. (default: train:stream)
      -nt, --numthreads NUMTHREADS
            number of threads. Used for hogwild if batchsize is 1, else for number of threads in threadpool loading, (default: 1)
      -bs, --batchsize BATCHSIZE
            batch size for minibatch training schemes (default: 1)
      -dp, --datapath DATAPATH
            path to datasets, defaults to {parlai_dir}/data (default: None)
    
    ParlAI Model Arguments:
      -m, --model MODEL
            the model class name. can match parlai/agents/<model> for agents in that directory, or can provide a fully specified
            module for `from X import Y` via `-m X:Y` (e.g. `-m parlai.agents.seq2seq.seq2seq:Seq2SeqAgent`) (default: None)
      -mf, --model-file MODEL_FILE
            model file name for loading and saving models (default: None)
      -im, --init-model INIT_MODEL
            load model weights and dict from this file (default: None)
    
    PytorchData Arguments:
      -pyt, --pytorch-teacher-task PYTORCH_TEACHER_TASK
            Use the PytorchDataTeacher for multiprocessed data loading with a standard ParlAI task, e.g. "babi:Task1k" (default: None)
      -pytd, --pytorch-teacher-dataset PYTORCH_TEACHER_DATASET
            Use the PytorchDataTeacher for multiprocessed data loading with a pytorch Dataset, e.g. "vqa_1" or "flickr30k" (default:
            None)

train_model
-----------
.. automodule:: parlai.scripts.train_model

CLI help
~~~~~~~~


.. code-block:: text

    usage: python -m parlai.scripts.train_model [-h] [-o INIT_OPT] [-v] [-t TASK]
                                                [-dt {train,train:stream,train:ordered,train:ordered:stream,train:stream:ordered,train:evalmode,train:evalmode:stream,train:evalmode:ordered,train:evalmode:ordered:stream,train:evalmode:stream:ordered,valid,valid:stream,test,test:stream}]
                                                [-nt NUMTHREADS] [-bs BATCHSIZE] [-dp DATAPATH] [-m MODEL] [-mf MODEL_FILE]
                                                [-im INIT_MODEL] [-et EVALTASK] [-eps NUM_EPOCHS] [-ttim MAX_TRAIN_TIME]
                                                [-vtim VALIDATION_EVERY_N_SECS] [-stim SAVE_EVERY_N_SECS] [-sval SAVE_AFTER_VALID]
                                                [-veps VALIDATION_EVERY_N_EPOCHS] [-vp VALIDATION_PATIENCE] [-vmt VALIDATION_METRIC]
                                                [-vmm {max,min}] [-micro AGGREGATE_MICRO] [-mcs METRICS] [-tblog TENSORBOARD_LOG]
                                                [-pyt PYTORCH_TEACHER_TASK] [-pytd PYTORCH_TEACHER_DATASET]
    
    Train a model
    
    optional arguments:
      -h, --help
            show this help message and exit
    
    Main ParlAI Arguments:
      -o, --init-opt INIT_OPT
            Path to json file of options. Note: Further Command-line arguments override file-based options. (default: None)
      -v, --show-advanced-args
            Show hidden command line options (advanced users only) (default: False)
      -t, --task TASK
            ParlAI task(s), e.g. "babi:Task1" or "babi,cbt" (default: None)
      -dt, --datatype {train,train:stream,train:ordered,train:ordered:stream,train:stream:ordered,train:evalmode,train:evalmode:stream,train:evalmode:ordered,train:evalmode:ordered:stream,train:evalmode:stream:ordered,valid,valid:stream,test,test:stream}
            choose from: train, train:ordered, valid, test. to stream data add ":stream" to any option (e.g., train:stream). by
            default: train is random with replacement, valid is ordered, test is ordered. (default: train)
      -nt, --numthreads NUMTHREADS
            number of threads. Used for hogwild if batchsize is 1, else for number of threads in threadpool loading, (default: 1)
      -bs, --batchsize BATCHSIZE
            batch size for minibatch training schemes (default: 1)
      -dp, --datapath DATAPATH
            path to datasets, defaults to {parlai_dir}/data (default: None)
    
    ParlAI Model Arguments:
      -m, --model MODEL
            the model class name. can match parlai/agents/<model> for agents in that directory, or can provide a fully specified
            module for `from X import Y` via `-m X:Y` (e.g. `-m parlai.agents.seq2seq.seq2seq:Seq2SeqAgent`) (default: None)
      -mf, --model-file MODEL_FILE
            model file name for loading and saving models (default: None)
      -im, --init-model INIT_MODEL
            load model weights and dict from this file (default: None)
    
    Training Loop Arguments:
      -et, --evaltask EVALTASK
            task to use for valid/test (defaults to the one used for training) (default: None)
      -eps, --num-epochs NUM_EPOCHS
      -ttim, --max-train-time MAX_TRAIN_TIME
      -vtim, --validation-every-n-secs VALIDATION_EVERY_N_SECS
            Validate every n seconds. Saves model to model_file (if set) whenever best val metric is found (default: -1)
      -stim, --save-every-n-secs SAVE_EVERY_N_SECS
            Saves the model to model_file.checkpoint after every n seconds (default -1, never). (default: -1)
      -sval, --save-after-valid SAVE_AFTER_VALID
            Saves the model to model_file.checkpoint after every validation (default False).
      -veps, --validation-every-n-epochs VALIDATION_EVERY_N_EPOCHS
            Validate every n epochs. Saves model to model_file (if set) whenever best val metric is found (default: -1)
      -vp, --validation-patience VALIDATION_PATIENCE
            number of iterations of validation where result does not improve before we stop training (default: 10)
      -vmt, --validation-metric VALIDATION_METRIC
            key into report table for selecting best validation (default: accuracy)
      -vmm, --validation-metric-mode {max,min}
            how to optimize validation metric (max or min) (default: None)
      -micro, --aggregate-micro AGGREGATE_MICRO
            If multitasking, average metrics over the number of examples. If false, averages over the number of tasks. (default:
            False)
      -mcs, --metrics METRICS
            list of metrics to show/compute, e.g. all, default,or give a list split by , like ppl,f1,accuracy,hits@1,rouge,bleuthe
            rouge metrics will be computed as rouge-1, rouge-2 and rouge-l (default: default)
    
    Tensorboard Arguments:
      -tblog, --tensorboard-log TENSORBOARD_LOG
            Tensorboard logging of metrics, default is False
    
    PytorchData Arguments:
      -pyt, --pytorch-teacher-task PYTORCH_TEACHER_TASK
            Use the PytorchDataTeacher for multiprocessed data loading with a standard ParlAI task, e.g. "babi:Task1k" (default: None)
      -pytd, --pytorch-teacher-dataset PYTORCH_TEACHER_DATASET
            Use the PytorchDataTeacher for multiprocessed data loading with a pytorch Dataset, e.g. "vqa_1" or "flickr30k" (default:
            None)

interactive_rank
----------------
.. automodule:: parlai.scripts.interactive_rank

CLI help
~~~~~~~~


.. code-block:: text

    usage: python -m parlai.scripts.interactive_rank [-h] [-o INIT_OPT] [-v] [-t TASK]
                                                     [-dt {train,train:stream,train:ordered,train:ordered:stream,train:stream:ordered,train:evalmode,train:evalmode:stream,train:evalmode:ordered,train:evalmode:ordered:stream,train:evalmode:stream:ordered,valid,valid:stream,test,test:stream}]
                                                     [-nt NUMTHREADS] [-bs BATCHSIZE] [-dp DATAPATH] [-pyt PYTORCH_TEACHER_TASK]
                                                     [-pytd PYTORCH_TEACHER_DATASET]
    
    ParlAI parser
    
    optional arguments:
      -h, --help
            show this help message and exit
    
    Main ParlAI Arguments:
      -o, --init-opt INIT_OPT
            Path to json file of options. Note: Further Command-line arguments override file-based options. (default: None)
      -v, --show-advanced-args
            Show hidden command line options (advanced users only) (default: False)
      -t, --task TASK
            ParlAI task(s), e.g. "babi:Task1" or "babi,cbt" (default: None)
      -dt, --datatype {train,train:stream,train:ordered,train:ordered:stream,train:stream:ordered,train:evalmode,train:evalmode:stream,train:evalmode:ordered,train:evalmode:ordered:stream,train:evalmode:stream:ordered,valid,valid:stream,test,test:stream}
            choose from: train, train:ordered, valid, test. to stream data add ":stream" to any option (e.g., train:stream). by
            default: train is random with replacement, valid is ordered, test is ordered. (default: train)
      -nt, --numthreads NUMTHREADS
            number of threads. Used for hogwild if batchsize is 1, else for number of threads in threadpool loading, (default: 1)
      -bs, --batchsize BATCHSIZE
            batch size for minibatch training schemes (default: 1)
      -dp, --datapath DATAPATH
            path to datasets, defaults to {parlai_dir}/data (default: None)
    
    PytorchData Arguments:
      -pyt, --pytorch-teacher-task PYTORCH_TEACHER_TASK
            Use the PytorchDataTeacher for multiprocessed data loading with a standard ParlAI task, e.g. "babi:Task1k" (default: None)
      -pytd, --pytorch-teacher-dataset PYTORCH_TEACHER_DATASET
            Use the PytorchDataTeacher for multiprocessed data loading with a pytorch Dataset, e.g. "vqa_1" or "flickr30k" (default:
            None)

display_model
-------------
.. automodule:: parlai.scripts.display_model

CLI help
~~~~~~~~


.. code-block:: text

    usage: python -m parlai.scripts.display_model [-h] [-o INIT_OPT] [-v] [-t TASK]
                                                  [-dt {train,train:stream,train:ordered,train:ordered:stream,train:stream:ordered,train:evalmode,train:evalmode:stream,train:evalmode:ordered,train:evalmode:ordered:stream,train:evalmode:stream:ordered,valid,valid:stream,test,test:stream}]
                                                  [-nt NUMTHREADS] [-bs BATCHSIZE] [-dp DATAPATH] [-m MODEL] [-mf MODEL_FILE]
                                                  [-im INIT_MODEL] [-n NUM_EXAMPLES] [--display-ignore-fields DISPLAY_IGNORE_FIELDS]
    
    Display model predictions.
    
    optional arguments:
      -h, --help
            show this help message and exit
      -n, -ne, --num-examples NUM_EXAMPLES
      --display-ignore-fields DISPLAY_IGNORE_FIELDS
    
    Main ParlAI Arguments:
      -o, --init-opt INIT_OPT
            Path to json file of options. Note: Further Command-line arguments override file-based options. (default: None)
      -v, --show-advanced-args
            Show hidden command line options (advanced users only) (default: False)
      -t, --task TASK
            ParlAI task(s), e.g. "babi:Task1" or "babi,cbt" (default: None)
      -dt, --datatype {train,train:stream,train:ordered,train:ordered:stream,train:stream:ordered,train:evalmode,train:evalmode:stream,train:evalmode:ordered,train:evalmode:ordered:stream,train:evalmode:stream:ordered,valid,valid:stream,test,test:stream}
            choose from: train, train:ordered, valid, test. to stream data add ":stream" to any option (e.g., train:stream). by
            default: train is random with replacement, valid is ordered, test is ordered. (default: valid)
      -nt, --numthreads NUMTHREADS
            number of threads. Used for hogwild if batchsize is 1, else for number of threads in threadpool loading, (default: 1)
      -bs, --batchsize BATCHSIZE
            batch size for minibatch training schemes (default: 1)
      -dp, --datapath DATAPATH
            path to datasets, defaults to {parlai_dir}/data (default: None)
    
    ParlAI Model Arguments:
      -m, --model MODEL
            the model class name. can match parlai/agents/<model> for agents in that directory, or can provide a fully specified
            module for `from X import Y` via `-m X:Y` (e.g. `-m parlai.agents.seq2seq.seq2seq:Seq2SeqAgent`) (default: None)
      -mf, --model-file MODEL_FILE
            model file name for loading and saving models (default: None)
      -im, --init-model INIT_MODEL
            load model weights and dict from this file (default: None)

build_dict
----------
.. automodule:: parlai.scripts.build_dict

CLI help
~~~~~~~~


.. code-block:: text

    usage: python -m parlai.scripts.build_dict [-h] [-o INIT_OPT] [-v] [-t TASK]
                                               [-dt {train,train:stream,train:ordered,train:ordered:stream,train:stream:ordered,train:evalmode,train:evalmode:stream,train:evalmode:ordered,train:evalmode:ordered:stream,train:evalmode:stream:ordered,valid,valid:stream,test,test:stream}]
                                               [-nt NUMTHREADS] [-bs BATCHSIZE] [-dp DATAPATH] [-m MODEL] [-mf MODEL_FILE]
                                               [-im INIT_MODEL] [-pyt PYTORCH_TEACHER_TASK] [-pytd PYTORCH_TEACHER_DATASET]
    
    Build a dictionary.
    
    optional arguments:
      -h, --help
            show this help message and exit
    
    Main ParlAI Arguments:
      -o, --init-opt INIT_OPT
            Path to json file of options. Note: Further Command-line arguments override file-based options. (default: None)
      -v, --show-advanced-args
            Show hidden command line options (advanced users only) (default: False)
      -t, --task TASK
            ParlAI task(s), e.g. "babi:Task1" or "babi,cbt" (default: None)
      -dt, --datatype {train,train:stream,train:ordered,train:ordered:stream,train:stream:ordered,train:evalmode,train:evalmode:stream,train:evalmode:ordered,train:evalmode:ordered:stream,train:evalmode:stream:ordered,valid,valid:stream,test,test:stream}
            choose from: train, train:ordered, valid, test. to stream data add ":stream" to any option (e.g., train:stream). by
            default: train is random with replacement, valid is ordered, test is ordered. (default: train)
      -nt, --numthreads NUMTHREADS
            number of threads. Used for hogwild if batchsize is 1, else for number of threads in threadpool loading, (default: 1)
      -bs, --batchsize BATCHSIZE
            batch size for minibatch training schemes (default: 1)
      -dp, --datapath DATAPATH
            path to datasets, defaults to {parlai_dir}/data (default: None)
    
    ParlAI Model Arguments:
      -m, --model MODEL
            the model class name. can match parlai/agents/<model> for agents in that directory, or can provide a fully specified
            module for `from X import Y` via `-m X:Y` (e.g. `-m parlai.agents.seq2seq.seq2seq:Seq2SeqAgent`) (default: None)
      -mf, --model-file MODEL_FILE
            model file name for loading and saving models (default: None)
      -im, --init-model INIT_MODEL
            load model weights and dict from this file (default: None)
    
    PytorchData Arguments:
      -pyt, --pytorch-teacher-task PYTORCH_TEACHER_TASK
            Use the PytorchDataTeacher for multiprocessed data loading with a standard ParlAI task, e.g. "babi:Task1k" (default: None)
      -pytd, --pytorch-teacher-dataset PYTORCH_TEACHER_DATASET
            Use the PytorchDataTeacher for multiprocessed data loading with a pytorch Dataset, e.g. "vqa_1" or "flickr30k" (default:
            None)

extract_image_feature
---------------------
.. automodule:: parlai.scripts.extract_image_feature

CLI help
~~~~~~~~


.. code-block:: text

    usage: python -m parlai.scripts.extract_image_feature [-h] [-o INIT_OPT] [-v] [-t TASK]
                                                          [-dt {train,train:stream,train:ordered,train:ordered:stream,train:stream:ordered,train:evalmode,train:evalmode:stream,train:evalmode:ordered,train:evalmode:ordered:stream,train:evalmode:stream:ordered,valid,valid:stream,test,test:stream}]
                                                          [-nt NUMTHREADS] [-bs BATCHSIZE] [-dp DATAPATH] [-pyt PYTORCH_TEACHER_TASK]
                                                          [-pytd PYTORCH_TEACHER_DATASET] [--dataset DATASET] [-at]
                                                          [--use-hdf5-extraction USE_HDF5_EXTRACTION]
    
    Load/extract image features
    
    optional arguments:
      -h, --help
            show this help message and exit
    
    Main ParlAI Arguments:
      -o, --init-opt INIT_OPT
            Path to json file of options. Note: Further Command-line arguments override file-based options. (default: None)
      -v, --show-advanced-args
            Show hidden command line options (advanced users only) (default: False)
      -t, --task TASK
            ParlAI task(s), e.g. "babi:Task1" or "babi,cbt" (default: None)
      -dt, --datatype {train,train:stream,train:ordered,train:ordered:stream,train:stream:ordered,train:evalmode,train:evalmode:stream,train:evalmode:ordered,train:evalmode:ordered:stream,train:evalmode:stream:ordered,valid,valid:stream,test,test:stream}
            choose from: train, train:ordered, valid, test. to stream data add ":stream" to any option (e.g., train:stream). by
            default: train is random with replacement, valid is ordered, test is ordered. (default: train)
      -nt, --numthreads NUMTHREADS
            number of threads. Used for hogwild if batchsize is 1, else for number of threads in threadpool loading, (default: 1)
      -bs, --batchsize BATCHSIZE
            batch size for minibatch training schemes (default: 1)
      -dp, --datapath DATAPATH
            path to datasets, defaults to {parlai_dir}/data (default: None)
    
    PytorchData Arguments:
      -pyt, --pytorch-teacher-task PYTORCH_TEACHER_TASK
            Use the PytorchDataTeacher for multiprocessed data loading with a standard ParlAI task, e.g. "babi:Task1k" (default: None)
      -pytd, --pytorch-teacher-dataset PYTORCH_TEACHER_DATASET
            Use the PytorchDataTeacher for multiprocessed data loading with a pytorch Dataset, e.g. "vqa_1" or "flickr30k" (default:
            None)
    
    Image Extraction:
      --dataset DATASET
            Pytorch Dataset; if specified, will save the images in one hdf5 file according to how they are returned by the specified
            dataset (default: None)
      -at, --attention
            Whether to extract image features with attention (Note - this is specifically for the mlb_vqa model) (default: False)
      --use-hdf5-extraction USE_HDF5_EXTRACTION
            Whether to extract images into an hdf5 dataset (default: False)

eval_ppl
--------
.. automodule:: parlai.scripts.eval_ppl

CLI help
~~~~~~~~


.. code-block:: text

    usage: python -m parlai.scripts.eval_ppl [-h] [-o INIT_OPT] [-v] [-t TASK]
                                             [-dt {train,train:stream,train:ordered,train:ordered:stream,train:stream:ordered,train:evalmode,train:evalmode:stream,train:evalmode:ordered,train:evalmode:ordered:stream,train:evalmode:stream:ordered,valid,valid:stream,test,test:stream}]
                                             [-nt NUMTHREADS] [-bs BATCHSIZE] [-dp DATAPATH] [-m MODEL] [-mf MODEL_FILE]
                                             [-im INIT_MODEL] [-pyt PYTORCH_TEACHER_TASK] [-pytd PYTORCH_TEACHER_DATASET]
    
    Evaluate perplexity
    
    optional arguments:
      -h, --help
            show this help message and exit
    
    Main ParlAI Arguments:
      -o, --init-opt INIT_OPT
            Path to json file of options. Note: Further Command-line arguments override file-based options. (default: None)
      -v, --show-advanced-args
            Show hidden command line options (advanced users only) (default: False)
      -t, --task TASK
            ParlAI task(s), e.g. "babi:Task1" or "babi,cbt" (default: None)
      -dt, --datatype {train,train:stream,train:ordered,train:ordered:stream,train:stream:ordered,train:evalmode,train:evalmode:stream,train:evalmode:ordered,train:evalmode:ordered:stream,train:evalmode:stream:ordered,valid,valid:stream,test,test:stream}
            choose from: train, train:ordered, valid, test. to stream data add ":stream" to any option (e.g., train:stream). by
            default: train is random with replacement, valid is ordered, test is ordered. (default: valid)
      -nt, --numthreads NUMTHREADS
            number of threads. Used for hogwild if batchsize is 1, else for number of threads in threadpool loading, (default: 1)
      -bs, --batchsize BATCHSIZE
            batch size for minibatch training schemes (default: 1)
      -dp, --datapath DATAPATH
            path to datasets, defaults to {parlai_dir}/data (default: None)
    
    ParlAI Model Arguments:
      -m, --model MODEL
            the model class name. can match parlai/agents/<model> for agents in that directory, or can provide a fully specified
            module for `from X import Y` via `-m X:Y` (e.g. `-m parlai.agents.seq2seq.seq2seq:Seq2SeqAgent`) (default: None)
      -mf, --model-file MODEL_FILE
            model file name for loading and saving models (default: None)
      -im, --init-model INIT_MODEL
            load model weights and dict from this file (default: None)
    
    PytorchData Arguments:
      -pyt, --pytorch-teacher-task PYTORCH_TEACHER_TASK
            Use the PytorchDataTeacher for multiprocessed data loading with a standard ParlAI task, e.g. "babi:Task1k" (default: None)
      -pytd, --pytorch-teacher-dataset PYTORCH_TEACHER_DATASET
            Use the PytorchDataTeacher for multiprocessed data loading with a pytorch Dataset, e.g. "vqa_1" or "flickr30k" (default:
            None)

eval_wordstat
-------------
.. automodule:: parlai.scripts.eval_wordstat

CLI help
~~~~~~~~


.. code-block:: text

    usage: python -m parlai.scripts.eval_wordstat [-h] [-o INIT_OPT] [-v] [-t TASK]
                                                  [-dt {train,train:stream,train:ordered,train:ordered:stream,train:stream:ordered,train:evalmode,train:evalmode:stream,train:evalmode:ordered,train:evalmode:ordered:stream,train:evalmode:stream:ordered,valid,valid:stream,test,test:stream}]
                                                  [-nt NUMTHREADS] [-bs BATCHSIZE] [-dp DATAPATH] [-m MODEL] [-mf MODEL_FILE]
                                                  [-im INIT_MODEL] [-pyt PYTORCH_TEACHER_TASK] [-pytd PYTORCH_TEACHER_DATASET]
                                                  [-ne NUM_EXAMPLES] [-ltim LOG_EVERY_N_SECS] [-ed EXTERNAL_DICT] [-fb FREQ_BINS]
                                                  [-dup DUMP_PREDICTIONS_PATH] [-cun COMPUTE_UNIQUE] [-tblog TENSORBOARD_LOG]
    
    compute statistics from model predictions
    
    optional arguments:
      -h, --help
            show this help message and exit
      -ne, --num-examples NUM_EXAMPLES
      -ltim, --log-every-n-secs LOG_EVERY_N_SECS
      -ed, --external-dict EXTERNAL_DICT
            External dictionary for stat computation (default: None)
      -fb, --freq-bins FREQ_BINS
            Bins boundaries for rare words stat (default: 0,100,1000,10000)
      -dup, --dump-predictions-path DUMP_PREDICTIONS_PATH
            Dump predictions into file (default: None)
      -cun, --compute-unique COMPUTE_UNIQUE
            Compute % of unique responses from the model (default: True)
    
    Main ParlAI Arguments:
      -o, --init-opt INIT_OPT
            Path to json file of options. Note: Further Command-line arguments override file-based options. (default: None)
      -v, --show-advanced-args
            Show hidden command line options (advanced users only) (default: False)
      -t, --task TASK
            ParlAI task(s), e.g. "babi:Task1" or "babi,cbt" (default: None)
      -dt, --datatype {train,train:stream,train:ordered,train:ordered:stream,train:stream:ordered,train:evalmode,train:evalmode:stream,train:evalmode:ordered,train:evalmode:ordered:stream,train:evalmode:stream:ordered,valid,valid:stream,test,test:stream}
            choose from: train, train:ordered, valid, test. to stream data add ":stream" to any option (e.g., train:stream). by
            default: train is random with replacement, valid is ordered, test is ordered. (default: valid)
      -nt, --numthreads NUMTHREADS
            number of threads. Used for hogwild if batchsize is 1, else for number of threads in threadpool loading, (default: 1)
      -bs, --batchsize BATCHSIZE
            batch size for minibatch training schemes (default: 1)
      -dp, --datapath DATAPATH
            path to datasets, defaults to {parlai_dir}/data (default: None)
    
    ParlAI Model Arguments:
      -m, --model MODEL
            the model class name. can match parlai/agents/<model> for agents in that directory, or can provide a fully specified
            module for `from X import Y` via `-m X:Y` (e.g. `-m parlai.agents.seq2seq.seq2seq:Seq2SeqAgent`) (default: repeat_label)
      -mf, --model-file MODEL_FILE
            model file name for loading and saving models (default: None)
      -im, --init-model INIT_MODEL
            load model weights and dict from this file (default: None)
    
    PytorchData Arguments:
      -pyt, --pytorch-teacher-task PYTORCH_TEACHER_TASK
            Use the PytorchDataTeacher for multiprocessed data loading with a standard ParlAI task, e.g. "babi:Task1k" (default: None)
      -pytd, --pytorch-teacher-dataset PYTORCH_TEACHER_DATASET
            Use the PytorchDataTeacher for multiprocessed data loading with a pytorch Dataset, e.g. "vqa_1" or "flickr30k" (default:
            None)
    
    Tensorboard Arguments:
      -tblog, --tensorboard-log TENSORBOARD_LOG
            Tensorboard logging of metrics, default is False

interactive
-----------
.. automodule:: parlai.scripts.interactive

CLI help
~~~~~~~~


.. code-block:: text

    usage: python -m parlai.scripts.interactive [-h] [-o INIT_OPT] [-v] [-t TASK]
                                                [-dt {train,train:stream,train:ordered,train:ordered:stream,train:stream:ordered,train:evalmode,train:evalmode:stream,train:evalmode:ordered,train:evalmode:ordered:stream,train:evalmode:stream:ordered,valid,valid:stream,test,test:stream}]
                                                [-nt NUMTHREADS] [-bs BATCHSIZE] [-dp DATAPATH] [-m MODEL] [-mf MODEL_FILE]
                                                [-im INIT_MODEL] [-d DISPLAY_EXAMPLES] [--display-prettify DISPLAY_PRETTIFY]
                                                [--display-ignore-fields DISPLAY_IGNORE_FIELDS] [-it INTERACTIVE_TASK]
                                                [-fixedCands LOCAL_HUMAN_CANDIDATES_FILE] [--single-turn SINGLE_TURN]
    
    Interactive chat with a model
    
    optional arguments:
      -h, --help
            show this help message and exit
      -d, --display-examples DISPLAY_EXAMPLES
      --display-prettify DISPLAY_PRETTIFY
            Set to use a prettytable when displaying examples with text candidates (default: False)
      --display-ignore-fields DISPLAY_IGNORE_FIELDS
            Do not display these fields (default: label_candidates,text_candidates)
      -it, --interactive-task INTERACTIVE_TASK
            Create interactive version of task (default: True)
    
    Main ParlAI Arguments:
      -o, --init-opt INIT_OPT
            Path to json file of options. Note: Further Command-line arguments override file-based options. (default: None)
      -v, --show-advanced-args
            Show hidden command line options (advanced users only) (default: False)
      -t, --task TASK
            ParlAI task(s), e.g. "babi:Task1" or "babi,cbt" (default: interactive)
      -dt, --datatype {train,train:stream,train:ordered,train:ordered:stream,train:stream:ordered,train:evalmode,train:evalmode:stream,train:evalmode:ordered,train:evalmode:ordered:stream,train:evalmode:stream:ordered,valid,valid:stream,test,test:stream}
            choose from: train, train:ordered, valid, test. to stream data add ":stream" to any option (e.g., train:stream). by
            default: train is random with replacement, valid is ordered, test is ordered. (default: train)
      -nt, --numthreads NUMTHREADS
            number of threads. Used for hogwild if batchsize is 1, else for number of threads in threadpool loading, (default: 1)
      -bs, --batchsize BATCHSIZE
            batch size for minibatch training schemes (default: 1)
      -dp, --datapath DATAPATH
            path to datasets, defaults to {parlai_dir}/data (default: None)
    
    ParlAI Model Arguments:
      -m, --model MODEL
            the model class name. can match parlai/agents/<model> for agents in that directory, or can provide a fully specified
            module for `from X import Y` via `-m X:Y` (e.g. `-m parlai.agents.seq2seq.seq2seq:Seq2SeqAgent`) (default: None)
      -mf, --model-file MODEL_FILE
            model file name for loading and saving models (default: None)
      -im, --init-model INIT_MODEL
            load model weights and dict from this file (default: None)
    
    Local Human Arguments:
      -fixedCands, --local-human-candidates-file LOCAL_HUMAN_CANDIDATES_FILE
            File of label_candidates to send to other agent (default: None)
      --single-turn SINGLE_TURN
            If on, assumes single turn episodes. (default: False)

detect_offensive_language
-------------------------
.. automodule:: parlai.scripts.detect_offensive_language

CLI help
~~~~~~~~


.. code-block:: text

    usage: python -m parlai.scripts.detect_offensive_language [-h] [-o INIT_OPT] [-v] [-t TASK]
                                                              [-dt {train,train:stream,train:ordered,train:ordered:stream,train:stream:ordered,train:evalmode,train:evalmode:stream,train:evalmode:ordered,train:evalmode:ordered:stream,train:evalmode:stream:ordered,valid,valid:stream,test,test:stream}]
                                                              [-nt NUMTHREADS] [-bs BATCHSIZE] [-dp DATAPATH] [-m MODEL]
                                                              [-mf MODEL_FILE] [-im INIT_MODEL] [-pyt PYTORCH_TEACHER_TASK]
                                                              [-pytd PYTORCH_TEACHER_DATASET] [-ltim LOG_EVERY_N_SECS]
                                                              [-d DISPLAY_EXAMPLES]
    
    Check task for offensive language
    
    optional arguments:
      -h, --help
            show this help message and exit
      -ltim, --log-every-n-secs LOG_EVERY_N_SECS
      -d, --display-examples DISPLAY_EXAMPLES
    
    Main ParlAI Arguments:
      -o, --init-opt INIT_OPT
            Path to json file of options. Note: Further Command-line arguments override file-based options. (default: None)
      -v, --show-advanced-args
            Show hidden command line options (advanced users only) (default: False)
      -t, --task TASK
            ParlAI task(s), e.g. "babi:Task1" or "babi,cbt" (default: None)
      -dt, --datatype {train,train:stream,train:ordered,train:ordered:stream,train:stream:ordered,train:evalmode,train:evalmode:stream,train:evalmode:ordered,train:evalmode:ordered:stream,train:evalmode:stream:ordered,valid,valid:stream,test,test:stream}
            choose from: train, train:ordered, valid, test. to stream data add ":stream" to any option (e.g., train:stream). by
            default: train is random with replacement, valid is ordered, test is ordered. (default: train:ordered)
      -nt, --numthreads NUMTHREADS
            number of threads. Used for hogwild if batchsize is 1, else for number of threads in threadpool loading, (default: 1)
      -bs, --batchsize BATCHSIZE
            batch size for minibatch training schemes (default: 1)
      -dp, --datapath DATAPATH
            path to datasets, defaults to {parlai_dir}/data (default: None)
    
    ParlAI Model Arguments:
      -m, --model MODEL
            the model class name. can match parlai/agents/<model> for agents in that directory, or can provide a fully specified
            module for `from X import Y` via `-m X:Y` (e.g. `-m parlai.agents.seq2seq.seq2seq:Seq2SeqAgent`) (default: repeat_query)
      -mf, --model-file MODEL_FILE
            model file name for loading and saving models (default: None)
      -im, --init-model INIT_MODEL
            load model weights and dict from this file (default: None)
    
    PytorchData Arguments:
      -pyt, --pytorch-teacher-task PYTORCH_TEACHER_TASK
            Use the PytorchDataTeacher for multiprocessed data loading with a standard ParlAI task, e.g. "babi:Task1k" (default: None)
      -pytd, --pytorch-teacher-dataset PYTORCH_TEACHER_DATASET
            Use the PytorchDataTeacher for multiprocessed data loading with a pytorch Dataset, e.g. "vqa_1" or "flickr30k" (default:
            None)

verify_data
-----------
.. automodule:: parlai.scripts.verify_data

CLI help
~~~~~~~~


.. code-block:: text

    usage: python -m parlai.scripts.verify_data [-h] [-o INIT_OPT] [-v] [-t TASK]
                                                [-dt {train,train:stream,train:ordered,train:ordered:stream,train:stream:ordered,train:evalmode,train:evalmode:stream,train:evalmode:ordered,train:evalmode:ordered:stream,train:evalmode:stream:ordered,valid,valid:stream,test,test:stream}]
                                                [-nt NUMTHREADS] [-bs BATCHSIZE] [-dp DATAPATH] [-m MODEL] [-mf MODEL_FILE]
                                                [-im INIT_MODEL] [-pyt PYTORCH_TEACHER_TASK] [-pytd PYTORCH_TEACHER_DATASET]
                                                [-ltim LOG_EVERY_N_SECS] [-d DISPLAY_EXAMPLES]
    
    Lint for ParlAI tasks
    
    optional arguments:
      -h, --help
            show this help message and exit
      -ltim, --log-every-n-secs LOG_EVERY_N_SECS
      -d, --display-examples DISPLAY_EXAMPLES
    
    Main ParlAI Arguments:
      -o, --init-opt INIT_OPT
            Path to json file of options. Note: Further Command-line arguments override file-based options. (default: None)
      -v, --show-advanced-args
            Show hidden command line options (advanced users only) (default: False)
      -t, --task TASK
            ParlAI task(s), e.g. "babi:Task1" or "babi,cbt" (default: None)
      -dt, --datatype {train,train:stream,train:ordered,train:ordered:stream,train:stream:ordered,train:evalmode,train:evalmode:stream,train:evalmode:ordered,train:evalmode:ordered:stream,train:evalmode:stream:ordered,valid,valid:stream,test,test:stream}
            choose from: train, train:ordered, valid, test. to stream data add ":stream" to any option (e.g., train:stream). by
            default: train is random with replacement, valid is ordered, test is ordered. (default: train:stream)
      -nt, --numthreads NUMTHREADS
            number of threads. Used for hogwild if batchsize is 1, else for number of threads in threadpool loading, (default: 1)
      -bs, --batchsize BATCHSIZE
            batch size for minibatch training schemes (default: 1)
      -dp, --datapath DATAPATH
            path to datasets, defaults to {parlai_dir}/data (default: None)
    
    ParlAI Model Arguments:
      -m, --model MODEL
            the model class name. can match parlai/agents/<model> for agents in that directory, or can provide a fully specified
            module for `from X import Y` via `-m X:Y` (e.g. `-m parlai.agents.seq2seq.seq2seq:Seq2SeqAgent`) (default: None)
      -mf, --model-file MODEL_FILE
            model file name for loading and saving models (default: None)
      -im, --init-model INIT_MODEL
            load model weights and dict from this file (default: None)
    
    PytorchData Arguments:
      -pyt, --pytorch-teacher-task PYTORCH_TEACHER_TASK
            Use the PytorchDataTeacher for multiprocessed data loading with a standard ParlAI task, e.g. "babi:Task1k" (default: None)
      -pytd, --pytorch-teacher-dataset PYTORCH_TEACHER_DATASET
            Use the PytorchDataTeacher for multiprocessed data loading with a pytorch Dataset, e.g. "vqa_1" or "flickr30k" (default:
            None)

multiprocessing_train
---------------------
.. automodule:: parlai.scripts.multiprocessing_train

CLI help
~~~~~~~~


.. code-block:: text

    usage: python -m parlai.scripts.multiprocessing_train [-h] [-o INIT_OPT] [-v] [-t TASK]
                                                          [-dt {train,train:stream,train:ordered,train:ordered:stream,train:stream:ordered,train:evalmode,train:evalmode:stream,train:evalmode:ordered,train:evalmode:ordered:stream,train:evalmode:stream:ordered,valid,valid:stream,test,test:stream}]
                                                          [-nt NUMTHREADS] [-bs BATCHSIZE] [-dp DATAPATH] [-m MODEL] [-mf MODEL_FILE]
                                                          [-im INIT_MODEL] [-et EVALTASK] [-eps NUM_EPOCHS] [-ttim MAX_TRAIN_TIME]
                                                          [-vtim VALIDATION_EVERY_N_SECS] [-stim SAVE_EVERY_N_SECS]
                                                          [-sval SAVE_AFTER_VALID] [-veps VALIDATION_EVERY_N_EPOCHS]
                                                          [-vp VALIDATION_PATIENCE] [-vmt VALIDATION_METRIC] [-vmm {max,min}]
                                                          [-micro AGGREGATE_MICRO] [-mcs METRICS] [-tblog TENSORBOARD_LOG]
                                                          [-pyt PYTORCH_TEACHER_TASK] [-pytd PYTORCH_TEACHER_DATASET]
                                                          [--distributed-world-size DISTRIBUTED_WORLD_SIZE]
    
    Train a model
    
    optional arguments:
      -h, --help
            show this help message and exit
    
    Main ParlAI Arguments:
      -o, --init-opt INIT_OPT
            Path to json file of options. Note: Further Command-line arguments override file-based options. (default: None)
      -v, --show-advanced-args
            Show hidden command line options (advanced users only) (default: False)
      -t, --task TASK
            ParlAI task(s), e.g. "babi:Task1" or "babi,cbt" (default: None)
      -dt, --datatype {train,train:stream,train:ordered,train:ordered:stream,train:stream:ordered,train:evalmode,train:evalmode:stream,train:evalmode:ordered,train:evalmode:ordered:stream,train:evalmode:stream:ordered,valid,valid:stream,test,test:stream}
            choose from: train, train:ordered, valid, test. to stream data add ":stream" to any option (e.g., train:stream). by
            default: train is random with replacement, valid is ordered, test is ordered. (default: train)
      -nt, --numthreads NUMTHREADS
            number of threads. Used for hogwild if batchsize is 1, else for number of threads in threadpool loading, (default: 1)
      -bs, --batchsize BATCHSIZE
            batch size for minibatch training schemes (default: 1)
      -dp, --datapath DATAPATH
            path to datasets, defaults to {parlai_dir}/data (default: None)
    
    ParlAI Model Arguments:
      -m, --model MODEL
            the model class name. can match parlai/agents/<model> for agents in that directory, or can provide a fully specified
            module for `from X import Y` via `-m X:Y` (e.g. `-m parlai.agents.seq2seq.seq2seq:Seq2SeqAgent`) (default: None)
      -mf, --model-file MODEL_FILE
            model file name for loading and saving models (default: None)
      -im, --init-model INIT_MODEL
            load model weights and dict from this file (default: None)
    
    Training Loop Arguments:
      -et, --evaltask EVALTASK
            task to use for valid/test (defaults to the one used for training) (default: None)
      -eps, --num-epochs NUM_EPOCHS
      -ttim, --max-train-time MAX_TRAIN_TIME
      -vtim, --validation-every-n-secs VALIDATION_EVERY_N_SECS
            Validate every n seconds. Saves model to model_file (if set) whenever best val metric is found (default: -1)
      -stim, --save-every-n-secs SAVE_EVERY_N_SECS
            Saves the model to model_file.checkpoint after every n seconds (default -1, never). (default: -1)
      -sval, --save-after-valid SAVE_AFTER_VALID
            Saves the model to model_file.checkpoint after every validation (default False).
      -veps, --validation-every-n-epochs VALIDATION_EVERY_N_EPOCHS
            Validate every n epochs. Saves model to model_file (if set) whenever best val metric is found (default: -1)
      -vp, --validation-patience VALIDATION_PATIENCE
            number of iterations of validation where result does not improve before we stop training (default: 10)
      -vmt, --validation-metric VALIDATION_METRIC
            key into report table for selecting best validation (default: accuracy)
      -vmm, --validation-metric-mode {max,min}
            how to optimize validation metric (max or min) (default: None)
      -micro, --aggregate-micro AGGREGATE_MICRO
            If multitasking, average metrics over the number of examples. If false, averages over the number of tasks. (default:
            False)
      -mcs, --metrics METRICS
            list of metrics to show/compute, e.g. all, default,or give a list split by , like ppl,f1,accuracy,hits@1,rouge,bleuthe
            rouge metrics will be computed as rouge-1, rouge-2 and rouge-l (default: default)
    
    Tensorboard Arguments:
      -tblog, --tensorboard-log TENSORBOARD_LOG
            Tensorboard logging of metrics, default is False
    
    PytorchData Arguments:
      -pyt, --pytorch-teacher-task PYTORCH_TEACHER_TASK
            Use the PytorchDataTeacher for multiprocessed data loading with a standard ParlAI task, e.g. "babi:Task1k" (default: None)
      -pytd, --pytorch-teacher-dataset PYTORCH_TEACHER_DATASET
            Use the PytorchDataTeacher for multiprocessed data loading with a pytorch Dataset, e.g. "vqa_1" or "flickr30k" (default:
            None)
    
    Distributed Training:
      --distributed-world-size DISTRIBUTED_WORLD_SIZE
            Number of workers. (default: 0)

interactive_web
---------------
.. automodule:: parlai.scripts.interactive_web

CLI help
~~~~~~~~


.. code-block:: text

    usage: python -m parlai.scripts.interactive_web [-h] [-o INIT_OPT] [-v] [-t TASK]
                                                    [-dt {train,train:stream,train:ordered,train:ordered:stream,train:stream:ordered,train:evalmode,train:evalmode:stream,train:evalmode:ordered,train:evalmode:ordered:stream,train:evalmode:stream:ordered,valid,valid:stream,test,test:stream}]
                                                    [-nt NUMTHREADS] [-bs BATCHSIZE] [-dp DATAPATH] [-m MODEL] [-mf MODEL_FILE]
                                                    [-im INIT_MODEL] [-d DISPLAY_EXAMPLES] [--display-prettify DISPLAY_PRETTIFY]
                                                    [--display-ignore-fields DISPLAY_IGNORE_FIELDS] [-it INTERACTIVE_TASK]
                                                    [-fixedCands LOCAL_HUMAN_CANDIDATES_FILE] [--single-turn SINGLE_TURN]
    
    Interactive chat with a model
    
    optional arguments:
      -h, --help
            show this help message and exit
      -d, --display-examples DISPLAY_EXAMPLES
      --display-prettify DISPLAY_PRETTIFY
            Set to use a prettytable when displaying examples with text candidates (default: False)
      --display-ignore-fields DISPLAY_IGNORE_FIELDS
            Do not display these fields (default: label_candidates,text_candidates)
      -it, --interactive-task INTERACTIVE_TASK
            Create interactive version of task (default: True)
    
    Main ParlAI Arguments:
      -o, --init-opt INIT_OPT
            Path to json file of options. Note: Further Command-line arguments override file-based options. (default: None)
      -v, --show-advanced-args
            Show hidden command line options (advanced users only) (default: False)
      -t, --task TASK
            ParlAI task(s), e.g. "babi:Task1" or "babi,cbt" (default: interactive)
      -dt, --datatype {train,train:stream,train:ordered,train:ordered:stream,train:stream:ordered,train:evalmode,train:evalmode:stream,train:evalmode:ordered,train:evalmode:ordered:stream,train:evalmode:stream:ordered,valid,valid:stream,test,test:stream}
            choose from: train, train:ordered, valid, test. to stream data add ":stream" to any option (e.g., train:stream). by
            default: train is random with replacement, valid is ordered, test is ordered. (default: train)
      -nt, --numthreads NUMTHREADS
            number of threads. Used for hogwild if batchsize is 1, else for number of threads in threadpool loading, (default: 1)
      -bs, --batchsize BATCHSIZE
            batch size for minibatch training schemes (default: 1)
      -dp, --datapath DATAPATH
            path to datasets, defaults to {parlai_dir}/data (default: None)
    
    ParlAI Model Arguments:
      -m, --model MODEL
            the model class name. can match parlai/agents/<model> for agents in that directory, or can provide a fully specified
            module for `from X import Y` via `-m X:Y` (e.g. `-m parlai.agents.seq2seq.seq2seq:Seq2SeqAgent`) (default: None)
      -mf, --model-file MODEL_FILE
            model file name for loading and saving models (default: None)
      -im, --init-model INIT_MODEL
            load model weights and dict from this file (default: None)
    
    Local Human Arguments:
      -fixedCands, --local-human-candidates-file LOCAL_HUMAN_CANDIDATES_FILE
            File of label_candidates to send to other agent (default: None)
      --single-turn SINGLE_TURN
            If on, assumes single turn episodes. (default: False)

eval_model
----------
.. automodule:: parlai.scripts.eval_model

CLI help
~~~~~~~~


.. code-block:: text

    usage: python -m parlai.scripts.eval_model [-h] [-o INIT_OPT] [-v] [-t TASK]
                                               [-dt {train,train:stream,train:ordered,train:ordered:stream,train:stream:ordered,train:evalmode,train:evalmode:stream,train:evalmode:ordered,train:evalmode:ordered:stream,train:evalmode:stream:ordered,valid,valid:stream,test,test:stream}]
                                               [-nt NUMTHREADS] [-bs BATCHSIZE] [-dp DATAPATH] [-m MODEL] [-mf MODEL_FILE]
                                               [-im INIT_MODEL] [-pyt PYTORCH_TEACHER_TASK] [-pytd PYTORCH_TEACHER_DATASET]
                                               [-ne NUM_EXAMPLES] [-d DISPLAY_EXAMPLES] [-ltim LOG_EVERY_N_SECS]
                                               [-micro AGGREGATE_MICRO] [-mcs METRICS] [-tblog TENSORBOARD_LOG]
    
    Evaluate a model
    
    optional arguments:
      -h, --help
            show this help message and exit
      -ne, --num-examples NUM_EXAMPLES
      -d, --display-examples DISPLAY_EXAMPLES
      -ltim, --log-every-n-secs LOG_EVERY_N_SECS
      -micro, --aggregate-micro AGGREGATE_MICRO
            If multitasking, average metrics over the number of examples. If false, averages over the number of tasks. (default:
            False)
      -mcs, --metrics METRICS
            list of metrics to show/compute, e.g. all, default,or give a list split by , like ppl,f1,accuracy,hits@1,rouge,bleuthe
            rouge metrics will be computed as rouge-1, rouge-2 and rouge-l (default: default)
    
    Main ParlAI Arguments:
      -o, --init-opt INIT_OPT
            Path to json file of options. Note: Further Command-line arguments override file-based options. (default: None)
      -v, --show-advanced-args
            Show hidden command line options (advanced users only) (default: False)
      -t, --task TASK
            ParlAI task(s), e.g. "babi:Task1" or "babi,cbt" (default: None)
      -dt, --datatype {train,train:stream,train:ordered,train:ordered:stream,train:stream:ordered,train:evalmode,train:evalmode:stream,train:evalmode:ordered,train:evalmode:ordered:stream,train:evalmode:stream:ordered,valid,valid:stream,test,test:stream}
            choose from: train, train:ordered, valid, test. to stream data add ":stream" to any option (e.g., train:stream). by
            default: train is random with replacement, valid is ordered, test is ordered. (default: valid)
      -nt, --numthreads NUMTHREADS
            number of threads. Used for hogwild if batchsize is 1, else for number of threads in threadpool loading, (default: 1)
      -bs, --batchsize BATCHSIZE
            batch size for minibatch training schemes (default: 1)
      -dp, --datapath DATAPATH
            path to datasets, defaults to {parlai_dir}/data (default: None)
    
    ParlAI Model Arguments:
      -m, --model MODEL
            the model class name. can match parlai/agents/<model> for agents in that directory, or can provide a fully specified
            module for `from X import Y` via `-m X:Y` (e.g. `-m parlai.agents.seq2seq.seq2seq:Seq2SeqAgent`) (default: None)
      -mf, --model-file MODEL_FILE
            model file name for loading and saving models (default: None)
      -im, --init-model INIT_MODEL
            load model weights and dict from this file (default: None)
    
    PytorchData Arguments:
      -pyt, --pytorch-teacher-task PYTORCH_TEACHER_TASK
            Use the PytorchDataTeacher for multiprocessed data loading with a standard ParlAI task, e.g. "babi:Task1k" (default: None)
      -pytd, --pytorch-teacher-dataset PYTORCH_TEACHER_DATASET
            Use the PytorchDataTeacher for multiprocessed data loading with a pytorch Dataset, e.g. "vqa_1" or "flickr30k" (default:
            None)
    
    Tensorboard Arguments:
      -tblog, --tensorboard-log TENSORBOARD_LOG
            Tensorboard logging of metrics, default is False

build_pytorch_data
------------------
.. automodule:: parlai.scripts.build_pytorch_data

CLI help
~~~~~~~~


.. code-block:: text

    usage: python -m parlai.scripts.build_pytorch_data [-h] [-o INIT_OPT] [-v] [-t TASK]
                                                       [-dt {train,train:stream,train:ordered,train:ordered:stream,train:stream:ordered,train:evalmode,train:evalmode:stream,train:evalmode:ordered,train:evalmode:ordered:stream,train:evalmode:stream:ordered,valid,valid:stream,test,test:stream}]
                                                       [-nt NUMTHREADS] [-bs BATCHSIZE] [-dp DATAPATH] [-m MODEL] [-mf MODEL_FILE]
                                                       [-im INIT_MODEL] [-pyt PYTORCH_TEACHER_TASK] [-pytd PYTORCH_TEACHER_DATASET]
    
    Builds a pytorch data file.
    
    optional arguments:
      -h, --help
            show this help message and exit
    
    Main ParlAI Arguments:
      -o, --init-opt INIT_OPT
            Path to json file of options. Note: Further Command-line arguments override file-based options. (default: None)
      -v, --show-advanced-args
            Show hidden command line options (advanced users only) (default: False)
      -t, --task TASK
            ParlAI task(s), e.g. "babi:Task1" or "babi,cbt" (default: None)
      -dt, --datatype {train,train:stream,train:ordered,train:ordered:stream,train:stream:ordered,train:evalmode,train:evalmode:stream,train:evalmode:ordered,train:evalmode:ordered:stream,train:evalmode:stream:ordered,valid,valid:stream,test,test:stream}
            choose from: train, train:ordered, valid, test. to stream data add ":stream" to any option (e.g., train:stream). by
            default: train is random with replacement, valid is ordered, test is ordered. (default: train)
      -nt, --numthreads NUMTHREADS
            number of threads. Used for hogwild if batchsize is 1, else for number of threads in threadpool loading, (default: 1)
      -bs, --batchsize BATCHSIZE
            batch size for minibatch training schemes (default: 1)
      -dp, --datapath DATAPATH
            path to datasets, defaults to {parlai_dir}/data (default: None)
    
    ParlAI Model Arguments:
      -m, --model MODEL
            the model class name. can match parlai/agents/<model> for agents in that directory, or can provide a fully specified
            module for `from X import Y` via `-m X:Y` (e.g. `-m parlai.agents.seq2seq.seq2seq:Seq2SeqAgent`) (default: None)
      -mf, --model-file MODEL_FILE
            model file name for loading and saving models (default: None)
      -im, --init-model INIT_MODEL
            load model weights and dict from this file (default: None)
    
    PytorchData Arguments:
      -pyt, --pytorch-teacher-task PYTORCH_TEACHER_TASK
            Use the PytorchDataTeacher for multiprocessed data loading with a standard ParlAI task, e.g. "babi:Task1k" (default: None)
      -pytd, --pytorch-teacher-dataset PYTORCH_TEACHER_DATASET
            Use the PytorchDataTeacher for multiprocessed data loading with a pytorch Dataset, e.g. "vqa_1" or "flickr30k" (default:
            None)

profile_train
-------------
.. automodule:: parlai.scripts.profile_train

CLI help
~~~~~~~~


.. code-block:: text

    usage: python -m parlai.scripts.profile_train [-h] [-o INIT_OPT] [-v] [-t TASK]
                                                  [-dt {train,train:stream,train:ordered,train:ordered:stream,train:stream:ordered,train:evalmode,train:evalmode:stream,train:evalmode:ordered,train:evalmode:ordered:stream,train:evalmode:stream:ordered,valid,valid:stream,test,test:stream}]
                                                  [-nt NUMTHREADS] [-bs BATCHSIZE] [-dp DATAPATH] [-m MODEL] [-mf MODEL_FILE]
                                                  [-im INIT_MODEL] [-et EVALTASK] [-eps NUM_EPOCHS] [-ttim MAX_TRAIN_TIME]
                                                  [-vtim VALIDATION_EVERY_N_SECS] [-stim SAVE_EVERY_N_SECS] [-sval SAVE_AFTER_VALID]
                                                  [-veps VALIDATION_EVERY_N_EPOCHS] [-vp VALIDATION_PATIENCE] [-vmt VALIDATION_METRIC]
                                                  [-vmm {max,min}] [-micro AGGREGATE_MICRO] [-mcs METRICS] [-tblog TENSORBOARD_LOG]
                                                  [-pyt PYTORCH_TEACHER_TASK] [-pytd PYTORCH_TEACHER_DATASET] [--torch TORCH]
                                                  [--torch-cuda TORCH_CUDA] [--debug DEBUG]
    
    cProfile a training run
    
    optional arguments:
      -h, --help
            show this help message and exit
    
    Main ParlAI Arguments:
      -o, --init-opt INIT_OPT
            Path to json file of options. Note: Further Command-line arguments override file-based options. (default: None)
      -v, --show-advanced-args
            Show hidden command line options (advanced users only) (default: False)
      -t, --task TASK
            ParlAI task(s), e.g. "babi:Task1" or "babi,cbt" (default: None)
      -dt, --datatype {train,train:stream,train:ordered,train:ordered:stream,train:stream:ordered,train:evalmode,train:evalmode:stream,train:evalmode:ordered,train:evalmode:ordered:stream,train:evalmode:stream:ordered,valid,valid:stream,test,test:stream}
            choose from: train, train:ordered, valid, test. to stream data add ":stream" to any option (e.g., train:stream). by
            default: train is random with replacement, valid is ordered, test is ordered. (default: train)
      -nt, --numthreads NUMTHREADS
            number of threads. Used for hogwild if batchsize is 1, else for number of threads in threadpool loading, (default: 1)
      -bs, --batchsize BATCHSIZE
            batch size for minibatch training schemes (default: 1)
      -dp, --datapath DATAPATH
            path to datasets, defaults to {parlai_dir}/data (default: None)
    
    ParlAI Model Arguments:
      -m, --model MODEL
            the model class name. can match parlai/agents/<model> for agents in that directory, or can provide a fully specified
            module for `from X import Y` via `-m X:Y` (e.g. `-m parlai.agents.seq2seq.seq2seq:Seq2SeqAgent`) (default: None)
      -mf, --model-file MODEL_FILE
            model file name for loading and saving models (default: None)
      -im, --init-model INIT_MODEL
            load model weights and dict from this file (default: None)
    
    Training Loop Arguments:
      -et, --evaltask EVALTASK
            task to use for valid/test (defaults to the one used for training) (default: None)
      -eps, --num-epochs NUM_EPOCHS
      -ttim, --max-train-time MAX_TRAIN_TIME
      -vtim, --validation-every-n-secs VALIDATION_EVERY_N_SECS
            Validate every n seconds. Saves model to model_file (if set) whenever best val metric is found (default: -1)
      -stim, --save-every-n-secs SAVE_EVERY_N_SECS
            Saves the model to model_file.checkpoint after every n seconds (default -1, never). (default: -1)
      -sval, --save-after-valid SAVE_AFTER_VALID
            Saves the model to model_file.checkpoint after every validation (default False).
      -veps, --validation-every-n-epochs VALIDATION_EVERY_N_EPOCHS
            Validate every n epochs. Saves model to model_file (if set) whenever best val metric is found (default: -1)
      -vp, --validation-patience VALIDATION_PATIENCE
            number of iterations of validation where result does not improve before we stop training (default: 10)
      -vmt, --validation-metric VALIDATION_METRIC
            key into report table for selecting best validation (default: accuracy)
      -vmm, --validation-metric-mode {max,min}
            how to optimize validation metric (max or min) (default: None)
      -micro, --aggregate-micro AGGREGATE_MICRO
            If multitasking, average metrics over the number of examples. If false, averages over the number of tasks. (default:
            False)
      -mcs, --metrics METRICS
            list of metrics to show/compute, e.g. all, default,or give a list split by , like ppl,f1,accuracy,hits@1,rouge,bleuthe
            rouge metrics will be computed as rouge-1, rouge-2 and rouge-l (default: default)
    
    Tensorboard Arguments:
      -tblog, --tensorboard-log TENSORBOARD_LOG
            Tensorboard logging of metrics, default is False
    
    PytorchData Arguments:
      -pyt, --pytorch-teacher-task PYTORCH_TEACHER_TASK
            Use the PytorchDataTeacher for multiprocessed data loading with a standard ParlAI task, e.g. "babi:Task1k" (default: None)
      -pytd, --pytorch-teacher-dataset PYTORCH_TEACHER_DATASET
            Use the PytorchDataTeacher for multiprocessed data loading with a pytorch Dataset, e.g. "vqa_1" or "flickr30k" (default:
            None)
    
    Profiler Arguments:
      --torch TORCH
            If true, use the torch profiler. Otherwise use cProfile. (default: False)
      --torch-cuda TORCH_CUDA
            If true, use the torch cuda profiler. Otherwise use cProfile. (default: False)
      --debug DEBUG
            If true, enter debugger at end of run. (default: False)

data_stats
----------
.. automodule:: parlai.scripts.data_stats

CLI help
~~~~~~~~


.. code-block:: text

    usage: python -m parlai.scripts.data_stats [-h] [-o INIT_OPT] [-v] [-t TASK]
                                               [-dt {train,train:stream,train:ordered,train:ordered:stream,train:stream:ordered,train:evalmode,train:evalmode:stream,train:evalmode:ordered,train:evalmode:ordered:stream,train:evalmode:stream:ordered,valid,valid:stream,test,test:stream}]
                                               [-nt NUMTHREADS] [-bs BATCHSIZE] [-dp DATAPATH] [-pyt PYTORCH_TEACHER_TASK]
                                               [-pytd PYTORCH_TEACHER_DATASET] [-ltim LOG_EVERY_N_SECS] [--agent {0,1}]
                                               [--new-line-new-utt NEW_LINE_NEW_UTT] [--ignore-tokens IGNORE_TOKENS]
    
    Lint for ParlAI tasks
    
    optional arguments:
      -h, --help
            show this help message and exit
      -ltim, --log-every-n-secs LOG_EVERY_N_SECS
      --agent {0,1}
            Use teacher (agent 0) or model (agent 1) (default: 0)
      --new-line-new-utt NEW_LINE_NEW_UTT
            New lines treat substrings as separate utterances. (default: False)
      --ignore-tokens IGNORE_TOKENS
            ignore tokens containings these substrings (comma-separated) (default: )
    
    Main ParlAI Arguments:
      -o, --init-opt INIT_OPT
            Path to json file of options. Note: Further Command-line arguments override file-based options. (default: None)
      -v, --show-advanced-args
            Show hidden command line options (advanced users only) (default: False)
      -t, --task TASK
            ParlAI task(s), e.g. "babi:Task1" or "babi,cbt" (default: None)
      -dt, --datatype {train,train:stream,train:ordered,train:ordered:stream,train:stream:ordered,train:evalmode,train:evalmode:stream,train:evalmode:ordered,train:evalmode:ordered:stream,train:evalmode:stream:ordered,valid,valid:stream,test,test:stream}
            choose from: train, train:ordered, valid, test. to stream data add ":stream" to any option (e.g., train:stream). by
            default: train is random with replacement, valid is ordered, test is ordered. (default: train:ordered)
      -nt, --numthreads NUMTHREADS
            number of threads. Used for hogwild if batchsize is 1, else for number of threads in threadpool loading, (default: 1)
      -bs, --batchsize BATCHSIZE
            batch size for minibatch training schemes (default: 1)
      -dp, --datapath DATAPATH
            path to datasets, defaults to {parlai_dir}/data (default: None)
    
    PytorchData Arguments:
      -pyt, --pytorch-teacher-task PYTORCH_TEACHER_TASK
            Use the PytorchDataTeacher for multiprocessed data loading with a standard ParlAI task, e.g. "babi:Task1k" (default: None)
      -pytd, --pytorch-teacher-dataset PYTORCH_TEACHER_DATASET
            Use the PytorchDataTeacher for multiprocessed data loading with a pytorch Dataset, e.g. "vqa_1" or "flickr30k" (default:
            None)

