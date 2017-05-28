# -*- coding: cp936 -*-
#list the problems in the .md file

import os
import sys
import re
import codecs
from abnormal import *

def read_file(file):
    lf = []
    f = open(file, 'r')
    for line in f:
        print line
        item = ()

        x = line[2]
        #print int(ord(x))
        #id-num
        match = re.match('[0-9]+', line)
        #print match.span(), match.group()
        algo_num = int(match.group())
        item = item + (int(match.group()),)
        #print item

        #problem name
        line = line[match.span()[1]:].strip()
        match = re.match('[ \(\)\-,\w\']+', line)  ##here why the regex works is that the \t char exists
        #print match.span(),
        oname = match.group().strip()
        name = match.group().strip().lower()
        name = re.sub('[\(\)]', '', name)
        name = name.replace(' ', '-')
        print "name : ", name
        if algo_num in Abnormal.keys():
            name = Abnormal[algo_num]
        item = item + (oname, name)
        

        #problem correct
        line = line[match.span()[1]:].strip()
        match = re.match('[0-9]+\.[0-9]+', line)
        #print match.span(), match.group().strip()
        print line
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

def read_locks(lock_file):
    lock_f = open(lock_file, 'r')
    ret = []
    for one in lock_f:
        one = one.strip()
        ret.append(int(one))
    return ret


if __name__ == '__main__':
    lf = read_file('problems.txt')
    locks = read_locks('lock_problems.txt')

    ##create the table
    #md = codecs.open('README.md', 'w', 'utf-8')
    md = open('README.md', 'w')
    md.write('# leetcode\n')
    md.write(u'| # | problem | Solution|\n')
    md.write('|:-----:|:-----|:------:|\n')


    for item in lf:
        if int(item[0]) in locks:
            lock_ = '![](lock.png)'
        else :
            lock_ = ''
        sline = '|' + str(item[0]) + '|[' + item[1] + '](https://leetcode.com/problems/' + lock_ + item[2] + ')|'
        if item[0] <= 170:
            ext = '.cpp'
            if item[0] in pys:
                ext = '.py'
            sline += '[Solution ' + str(item[0]) + '](' + 'https://github.com/cedarz/ltcode/blob/master/' + str(item[0]) + ext + ')|\n'
        else:
            sline += 'Solution ' + str(item[0]) + '|\n'
        md.write(sline)
    md.close()
