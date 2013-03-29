#!/usr/bin/python3

import os, subprocess, time, argparse

def print_time(sec):
    h = int(sec / (60 * 60))
    sec -= h * (60 * 60)
    m = int(sec / 60)
    sec -= m * 60
    s = int(sec)
    ms  = int((sec - s) * 100)
    print('encode time : {0:02}:{1:02}:{2:02}.{3:02}'.format(h, m, s, ms))

def create_cmd(fps, codec, bitrate, output):
    input = "-i bbb-png-big/output_%05d.png "

    f = " -r {0}".format(fps)

    c = " -codec:v "
    if (codec == "XVID"): c += "libxvid -q:v 4 -qp 1 -vtag xvid "
    if (codec == "H264"): c += "libx264 -preset placebo "
    if (codec == "WebM"): c += "libvpx -deadline best -crf 2 -cpu-used 0 -f webm -qmax=63 -qmin=0 "

    b = " -b:v {0}".format(bitrate)

    return input + "{0} {1} {2} {3} -threads 8 -stats ".format(f, c, b, output)

def run_ffmpeg(cmd, only_print):
    start = time.time()
    print("\nffmpeg " + cmd + '\n')
    if only_print == False:
        #subprocess.getoutput('ffmpeg ' + cmd)
        os.system('ffmpeg ' + cmd)
    finish = time.time()
    print_time(finish - start)

def main():
    parser = argparse.ArgumentParser(description='create video with FFmpeg.')
    parser.add_argument('-f', '--fps', type=float, default=30.0,
                        help='set fps for creating video')
    parser.add_argument('-o', '--output', type=str, default="output.mkv",
                        help='set name of output video file')
    parser.add_argument('-b', '--bitrate', type=str, default="15M",
                        help='set bitrate for output video file')
    parser.add_argument('-c', '--codec', choices=['XVID', 'H264', 'WebM'],
                        default='H264', help='set fps for creating video')
    parser.add_argument('-n', type=bool, default=False, help='print cmd donnt run')
    args = parser.parse_args()

    run_ffmpeg(" -version", False)
    run_ffmpeg(create_cmd(args.fps, args.codec, args.bitrate, args.output) + " -pass 1 -an -y /dev/null ", args.n)
    run_ffmpeg(create_cmd(args.fps, args.codec, args.bitrate, args.output) + " -pass 2 -y ", args.n)
    pass

if __name__ == "__main__":
    main()
