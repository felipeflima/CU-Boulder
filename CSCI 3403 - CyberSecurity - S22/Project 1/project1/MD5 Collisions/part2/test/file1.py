#!/usr/bin/python
# -*- coding: ISO-8859-1 -*- 
blob = """      oG�?hh^�%��Pe���s�[TIr����� ����D��\���G(�I����!:��u�нޠ-���?<#*�ƙQ:I#� b����� ]"�&�2��g����\�w�CC�M���ҼV򌺹"""
from hashlib import sha256 
print(sha256(blob.encode()).hexdigest())