
f = open("C:\\Programming\\Учеба\\СиАОД\\ru-mirea-siaod\\siaod5.1\\output.txt")

lines = [f.readline() for i in range(10)]
f.close()
lines = [lines[i][0:10] + lines[i][lines[i].rfind(" ",2):len(lines[i])] for i in range(10)]

f = open("C:\\Programming\\Учеба\\СиАОД\\ru-mirea-siaod\\siaod5.1\\data10.txt", "w")
for i in range(10):
    print(lines[i])
    f.write(lines[i])