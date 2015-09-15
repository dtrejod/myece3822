#!/bin/sh

# Program Input Arguements
# $1 - Aurgement One: The directory containing mp3 files you want to play

# Part 1: Program that randomly plays one song in directory
# Part 2: Randomly select the songs
# Part 3: Gaurantee all 100 songs are played once before playing it again
# Part 4: Automatically go from one song to the next
# Part 5: Keep track of status so you ca resume where you left off if you kill
#     the program
# Part 6: When all songs have been played once you start another pass. Order
#     must be randomized
# Part 7: Coded in shell
# Part 8: Must run from terminal

# Check if input arugment passed
if [ $# -lt 1 ]; then
  echo 1>&2 "$0: not enough arguments"
  exit 2
elif [ $# -gt 1 ]; then
  echo 1>&2 "$0: too many arguments"
  exit 2
fi

# Play forever
while true
do
    # Check if a playlist exsits already. If not generate one.
    if [ ! -s .tmp_mp3playlist ]
    then
        # Create a playlist of '.mp3' files
        find $1 -iname "*.mp3" > .tmp_mp3list
        # Randomly sort the playlist
        shuf .tmp_mp3list > .tmp_mp3playlist
    fi

    # Play song
    PLAYSONG=$(head -n 1 .tmp_mp3playlist)
    # echo $PLAYSONG
    # We use mpg123 to play the mp3 file
    #     -q : quiet option so song plays in the background with no stdout.
    mpg123 -q $PLAYSONG
    
    # Delete the first line of the playlist (remove the last played song)
    sed -n '1d' .tmp_mp3playlist

    # Check to see if playlist is empty and delete file if true
    if [ -s .tmp_mp3playlist ]
    then
        # Cleanup and so next pass playlist regenerates
        rm .tmp_mp3playlist .tmp_mp3list
        #echo "Generating new playlist"
    fi
done

