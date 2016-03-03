#coding=utf8
#!/bin/python

import sys, getopt, datetime

'''user msgs'''
USER = "cxgAlleria"
EMAIL = "cxgAlleria@gmail.com"

'''variables'''
DIR= "."
CLASSNAME = "Untitled"
FILENAME = ""
FILED= [[], [], []]
AM = ["public", "protected", "private"]
PRIMITIVETYPES = ["bool", "char", "short", "int", "long", "float", "double", "long long"]

def USAGE() :
    '''The usage description'''
    print "Usgae: $(pathToAccess)/generateModel [OPTIONS]\n \
            -c,\t\t\t\tspecify the classname you want to create(default 'Untitled')\n \
            -d,\t\t\t\tspecify the directory you want to put the created class in\n \
            -f,\t\t\t\tspecify the filename the created class resides in\n \
            -h,\t\t\t\tgive the help list\n \
            -a,\t\t\t\t[[+-#]attribute1[:[+-#]attribute2]]]\n\n"

def create() :
    '''class builder'''
    assert len(FILENAME) > 0 and (FILENAME.endswith("h") or FILENAME.endswith("hpp"))
    HFILENAME = DIR + FILENAME
    fp = open(HFILENAME, "w")
    fp.write("#ifndef _" + CLASSNAME.upper() + "_H_\n#define _" + CLASSNAME.upper() + "_H_\n\n")
    fp.write("/**\n  *@file\t\t" + FILENAME + "\n  *\n  *@author\t\t" + USER + "\n  *\n  *@brief\t\t\n  *\n  *@date\t\t" + datetime.datetime.now().strftime("%Y-%m-%d %H:%M") + "\n  *\n  *@history\n  *\n  */\n\n")
    fp.write("typedef class " + CLASSNAME.upper() + "{\n")
    fp.write("\t/*FIELDS*/\n")
    for amIndex in range(3):
        if len(FILED[amIndex]) > 0:
            fp.write(AM[amIndex] + ":\n")
        for iterator in range(len(FILED[amIndex])):
            fp.write("\t" + FILED[amIndex][iterator][0] + " m_" + FILED[amIndex][iterator][1] + ";\n")
    fp.write("\t/*METHODS*/\n")
    fp.write("public:\n")
    for amIndex in range(1, 3):
        for iterator in range(len(FILED[amIndex])):
            _at, _an = FILED[amIndex][iterator]
            fp.write("\t" + _at + " get" + _an.title() + "() const{\n\t\treturn this->m_" + _an + ";\n\t}\n")
            fp.write("\tvoid set" + _an.title() + "(");
            if _at in PRIMITIVETYPES:
                fp.write(_at + " " + _an)
            else:
                fp.write("const " + _at + " & " +  _an)
            fp.write(") {\n\t\t//Validate the arg if necessary\n\t\tthis->m_" + _an + " = " + _an + ";\n\t}\n")
    fp.write("\t/*CON(DE)STRUTURES*/\n")
    fp.write("protected:\n")
    Header = "\t" + CLASSNAME.upper() + "("
    InitList = ")\n\t\t: "
    CreateList = ""
    ArgList = ""
    firstArg = True
    for amIndex in range(3):
        for iterator in range(len(FILED[amIndex])):
            _at, _an = FILED[amIndex][iterator]
            if firstArg == False:
                Header += ", "
                InitList += ", "
                CreateList += ", "
                ArgList += ", "
            else:
                firstArg = False
            if _at in PRIMITIVETYPES :
                Header += _at + " " + _an
                CreateList += _at + " " + _an
            else:
                Header += "const " + _at + " & " + _an
                CreateList += "const " + _at + " & " + _an
            InitList += "m_" + _an + "(" + _an + ")"
            ArgList += _an
    InitList += " {\n\t\t//your own implementation\n\t}"
    fp.write(Header + InitList)
    fp.write("\n\tvirtual ~" + CLASSNAME.upper() + "() {}")
    fp.write("\npublic:\n\t/*STATIC INTERFACES*/")
    fp.write("\n\tstatic " + CLASSNAME.upper() + " * create(" + CreateList + ") {\n\t\treturn new " + CLASSNAME.upper() + "(" + ArgList + ");\n\t}")
    fp.write("\n\tstatic void release(" + CLASSNAME.upper() + "** handler) {\n\t\tif((*handler) != nullptr) {\n\t\t\tdelete (* handler);\n\t\t\t(* handler) = nullptr;\n\t\t}\n\t}")
    fp.write("\n} * " + CLASSNAME + ";\n")
    fp.write("\n#endif// !_" + CLASSNAME.upper() + "_H_\n")
    fp.close()

'''main'''
if len(sys.argv) == 1:
    USAGE()
else:
    opts, args = getopt.getopt(sys.argv[1:], "hc:f:d:a:")
    for op, value in opts:
        if op == "-h":
            USAGE()
        elif op == "-c":
            CLASSNAME = value
        elif op == "-f":
            FILENAME = value
        elif op == "-d":
            DIR = value
        elif op == "-a":
            _TOKENS = value.split(":")
            for token in _TOKENS:
                _al = token.split(" ")
                assert len(_al) == 3 and _al[0] in ["+", "-", "#"]
                amIndex = 1
                if _al[0] == "+":
                    amIndex = 0
                elif _al[0] == "-":
                    amIndex = 2
                FILED[amIndex].append((_al[1], _al[2]))
        else:
            print "Unknown option: " + op + " with value: " + value
if DIR.endswith("/") == False:
    DIR += "/"
create()
