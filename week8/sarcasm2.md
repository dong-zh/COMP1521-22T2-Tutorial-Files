# Sarcasm 2, Electric Boogaloo

## Background

Hong Duang has been promoted from a Twitter troll to a full time Redditor. Without the 280 character limit holding him back, he now writes his ramblings in a text file. The original sarcasm program doesn't cut it any more, and he wants to use his new knowledge of files to sarcasise entire text files.

To recap, sarcasm can be conveyed online by alternating the casing on a sentence.

Normal:

```text
NFTs are a great investment!!11!!!
```

Sarcastic:

```text
nFtS ArE A GrEaT InVeStMeNt!!11!!!
```

## Task

Write a C program that reads in an entire file and writes the sarcasised output into another file. The program should take 2 command line arguments: the input filename and the output filename.

```bash
./sarcasise2 input.txt output.txt
```

Create the output file if it doesn't exist, and overwrite it if it does. The program do basic error handling.
