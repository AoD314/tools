#!/usr/bin/env python3

import os

fps = ['30', '60', '120']
bitrate = ['20M', '40M', '60M', '80M']
codec = ['XVID', 'WebM', 'H264']

for c in codec:
    for b in bitrate:
        for f in fps:
            cmd = "./ffmpeg.py -f " + f + "  -b " + b + " -c " + c + " -o output_" + c.lower() + "_" + f + "fps_" + b + ".mkv"
            os.system(cmd)
