#!/usr/bin/python
# -*- coding: ISO-8859-1 -*- 
blob = """ aaa  'M��L�_Ɋ�����/�JK��[&�8F5���������
o��b�
q{襺�|[d���@�+�"�Ro]X��L��V�X�\y`͛�Yr}.51V�l���ѯ�a{J��gW�?\V� �?"""
from hashlib import sha256 
print(sha256(blob.encode()).hexdigest())
if(sha256(blob.encode()).hexdigest() == "38718b73c9f0fb107c11f9d064469cc43b0085f242a4e66164c776e506567e0a"):
    print("I come in peace.")
elif(sha256(blob.encode()).hexdigest() == "3c607feba25bf43795eed603d0a6d0f1c16a33b4d7cb88e96ed1582299750c0f"):
    print("Prepare to be destroyed!")