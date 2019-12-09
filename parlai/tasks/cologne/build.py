import parlai.core.build_data as build_data
import os

def build(opt):
    # get path to data directory
    dpath = os.path.join(opt['datapath'], 'cologne')
    print(dpath)
    # define version if any
    version = 'None'


    # check if data had been previously built
    if not build_data.built(dpath, version_string=version):
        from shutil import copyfile
        print('[building data: ' + dpath + ']')

        # make a clean directory if needed
        if build_data.built(dpath):
            # an older version exists, so remove these outdated files.
            build_data.remove_dir(dpath)
        build_data.make_dir(dpath)

        copyfile("/home/schaub/Documents/Akio/dev_parlai/parlai/data/PMC/pmctestparlai.txt","/home/schaub/Documents/Akio/dev_parlai/parlai/data/cologne/pmctestparlai.txt")
        # mark the data as built
        build_data.mark_done(dpath, version_string=version)