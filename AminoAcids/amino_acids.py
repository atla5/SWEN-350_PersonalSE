# @author:AidanSawyer-[aks5238]
# language: python3
# 


START_CODON = "aug"
STOP_CODONS = ["uaa","uag","uga"]
RNA_TO_AAs = {"aug":"Met","uuu":"Phe", "uuc":"Phe", "uua":"Leu", "uug":"Leu", "cuc":"Leu","cug":"Leu","auu":"Ile", "auc":"Ile", "aua":"Ile", "guu":"Val", "guc":"Val", "gua":"Val", "gug":"Val", "ucu":"Ser", "ucc":"Ser", "uca":"Ser", "ucg":"Ser", "ccu":"Pro", "ccc":"Pro", "cca":"Pro", "ccg":"Pro", "acu":"Thr", "acc":"Thr", "aca":"Thr", "acg":"Thr", "gcu":"Ala", "gcc":"Ala", "gca":"Ala", "gcg":"Ala", "uau":"Tyr", "uac":"Tyr", "cau":"His", "cac":"His", "caa":"Gln", "cag":"Gln", "aau":"Asn", "aac":"Asn", "aaa":"Lys", "aag":"Lys", "gau":"Asp", "gac":"Asp", "gaa":"Glu", "gag":"Glu", "ugu":"Cys", "ugc":"Cys", "ugg":"Trp", "cgu":"Arg", "cgc":"Arg", "cga":"Arg", "cgg":"Arg", "agu":"Ser", "agc":"Ser", "aga":"Arg", "agg":"Arg", "ggu":"Gly", "ggc":"Gly", "gga":"Gly", "ggg":"Gly" }



