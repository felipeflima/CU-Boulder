#!/usr/bin/python
# -*- coding: ISO-8859-1 -*- 
blob = """ aaa  ���%f���jU�����&�jC��J�{r1�ܾ����U���E��9�2�czi�g|��J���v>ډ���{6�(���+����5�����F�g�+�����3E�eh6D0�-�*5[x��HI�"""
from hashlib import sha256 
if(sha256(blob.encode()).hexdigest() == "38718b73c9f0fb107c11f9d064469cc43b0085f242a4e66164c776e506567e0a"):
    print("I come in peace.")
elif(sha256(blob.encode()).hexdigest() == "3c607feba25bf43795eed603d0a6d0f1c16a33b4d7cb88e96ed1582299750c0f"):
    print("Prepare to be destroyed!")