import os, sys

def main():
    excepted_outputs1 = []
   
    commands = []
    outputs1 = []
    inputs = []

    error = ""

 
    file = open("commands.txt", "r")
    for line in file:
        commands.append(line.strip())
    file.close

    file = open("inputdata.txt", "r")
    for line in file:
       inputs.append(line.strip())
    file.close
  
    file = open("output1.txt", "r")
    for line in file:
        excepted_outputs1.append(line.strip())
    file.close
       
   
    for line in os.popen(commands[0]).read().strip().split('\n'):
        outputs1.append(line.strip()) 

    for line in os.popen(inputs[0]).read().strip().split('\n'):
        inputs.append(line.strip())     

    
    for i in range(len(outputs1)):
        if outputs1[i] != excepted_outputs1[i]:
            error += "Found some error...\n"   
    

    for i in commands:
        os.system("valgrind --leak-check=full --error-exitcode=5 " + i)
        if (os.system("echo $?") == 5):
            print("Memory leak...\n")
            sys.exit(5)
    
    if len(error) == 0: 
        sys.exit(0)
    else: 
        sys.exit(1)

if __name__ == "__main__":
    main()