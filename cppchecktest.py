import sys

txt = open("cppcheck_for_artifact.txt","r")
txt_content = txt.read()
if(("error" in txt_content) or ("warning" in txt_content)):
    sys.exit(1)
else:
    sys.exit(0)
txt.close()