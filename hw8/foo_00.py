#!/usr/bin/env python
import os
import sys
import string
from collections import Counter
import pandas as pd

# wordCounts class
#
class wordCounts():

    # Initialize Variables
    #
    def __init__(self):
        # Define the column names
        #
        self.cols = ['Filename', 'Contents']
        
        # Initialize dataframe
        #
        self.massWord = pd.DataFrame(columns=self.cols)


    def read(self, fileName):
        # Check if file exsits
        #
        try:
            file = open(fileName, 'r')
        
        # Run this code if the open function throws an IOError
        #
        except IOError:
            print('There was an error opening the file \''+fileName+'\'')
            sys.exit(1)
        
        # Check if file is a pickle (already created dataFrame). Load
        # the dataFrame directly and skip reading in text file operation
        #
        if (fileName[-3:] == "pkl"):
            self.loadData(fileName)
            return

        # Build the list of files leading/lagging characters especailly
        # that pesky new line character
        #
        listFiles = []
        with open(fileName) as f:
            listFiles = [tmp.strip() for tmp in f.readlines()]
        
        # Open each file and store the contents of files into a column=contents
        # We also have another column that stores the filename
        
        # read in each file into a dataframe
        #
        df_list = []
        df_list = [pd.DataFrame({self.cols[0] : str(fName),\
                self.cols[1] : open(fName, 'r').read()},\
                columns=self.cols, index={1})\
                for fName in listFiles]

        # Combine all the dataframes in the df_list into one dataframe
        #
        self.massWord = pd.concat(df_list).reset_index()
        
        # The combined datframe has an outdate index column that we drop
        #
        self.massWord.drop('index',  axis=1, inplace=True)
                 
    def myPrint(self):
        print(self.massWord)
    
    # This function looks for files that contain the whole special word
    # (any case). Appends a column containing true/false.
    # If drop == true it will remove any rows that don't contain the special
    # word
    #
    def dropNotContain(self, specialWord, drop):
        # Define our search pattern using regex
        #
        searPat = r'\b'+specialWord+r'\b'

        # Append a column to dataframe containing true/false if the contents
        # column contains the search pattern defined above
        #
        self.massWord['Contains ' + specialWord]\
                = self.massWord[self.cols[1]].str.contains(\
                searPat, case=False, na=False)
        # If drop == true it will remove any rows that don't contain the
        # special word
        #           
        if(drop==True):
            self.massWord = self.massWord[self.massWord['Contains ' + \
                    specialWord]==True]

        # Print the number of files left
        #
        print("A total of " + str(len(self.massWord[self.massWord['Contains '+\
                specialWord]==True])) + \
               " contain the word " + specialWord + ".")

    # Create a span word histogram of all words in the dictionary
    #
    def createHistogram(self, span):
        # Using collections we can create histogram.
        # We join together all entry columns containing contents. We also
        # reaplce all non-alphanumeric characters with spaces as not to ruin
        # our results using a regex. If needed we combine words over the span.
        #
        words = " ".join(self.massWord[self.cols[1]].replace({\
                '[^0-9a-zA-Z]+': ' '}, regex=True)).split()
        if(span != 1):
            words = [" ".join(words[i:i+span]) for i in range(0, \
                len(words), span)]
        word_counts = Counter(words)
        #word_counts = Counter(" ".join(self.massWord[self.cols[1]]).split())

        # We convert the dictionary back to a dataframe allowing us to sort
        # by frequency
        #
        df = pd.DataFrame.from_dict(word_counts, orient='index')
        df.sort(columns=df.columns[0],inplace=True, ascending=False)
        print(df)
 
    # Save the contents of the dataframe to a file
    #
    def saveData(self, fName):
        self.massWord.to_pickle(fName)
    
    # Load the contents of a previous run into dataframe
    #
    def loadData(self,fName):
        self.massWord = pd.read_pickle(fName)


