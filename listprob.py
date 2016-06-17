# -*- coding: cp936 -*-
#list the problems int the .md file

import os
import sys
import re

def read_file(file):
    lf = []
    f = open(file, 'r')
    for line in f:
        print line
        item = ()

        #id-num
        match = re.match('[0-9]+', line)
        #print match.span(), match.group()
        item = item + (int(match.group()),)
        #print item

        #problem name
        line = line[match.span()[1]:].strip()
        match = re.match('[\D]+', line)
        #print match.span(),
        oname = match.group().strip()
        name = match.group().strip().lower()
        name = re.sub('[\(\)]', '', name)
        name = name.replace(' ', '-')
        #print "name : ", name
        item = item + (oname, name)
        

        #problem correct
        line = line[match.span()[1]:].strip()
        match = re.match('[0-9]+\.[0-9]+', line)
        #print match.span(), match.group().strip()
        item = item + (match.group().strip() + '%',)

        #easy hard
        line = line[match.span()[1] + 1:].strip()
        match = re.match('[a-zA-Z]+', line)
        #print match.span(), match.group().strip()
        item = item + (match.group().strip(),)

        #print item
        lf.append(item)
    
    lf.sort()
    f.close()
    print lf
    return lf



if __name__ == '__main__':
    lf = read_file('problems.txt')

    md = open('README.md', 'w')
    md.write('#leetcode\n')
    md.write('| # | 题目 | Solution|\n')
    md.write('|----|:----|------|\n')
    
    for item in lf:
        sline = '|' + str(item[0]) + '|[' + item[1] + '](https://leetcode.com/problems/' + item[2] + ')|' + '[Solution ' + str(item[0]) + '](' + 'https://github.com/cedarz/ltcode/blob/master/' + str(item[0]) + '.cpp)|\n'
        md.write(sline)
    md.close()
