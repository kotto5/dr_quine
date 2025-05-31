C_DIR = ./C
Colleen = ${C_DIR}/Colleen/Colleen
Grace = ${C_DIR}/Grace/Grace
Sully = ${C_DIR}/Sully/Sully
ASM_DIR = ./ASM
Colleen_ASM = ${ASM_DIR}/Colleen/Colleen
Grace_ASM = ${ASM_DIR}/Grace/Grace
Sully_ASM = ${ASM_DIR}/Sully/Sully


all: ${Colleen} ${Grace} ${Sully} ${Colleen_ASM} ${Grace_ASM} ${Sully_ASM}

${Colleen}: ${C_DIR}/Colleen/Colleen.c 
	gcc -Wall -Wextra -Werror $^ -o $@

${Grace}: ${C_DIR}/Grace/Grace.c 
	gcc -Wall -Wextra -Werror $^ -o $@

${Sully}: ${C_DIR}/Sully/Sully.c 
	gcc -Wall -Wextra -Werror $^ -o $@

${Colleen_ASM}: ${ASM_DIR}/Colleen/Colleen.s
	nasm -f elf64 $^ -o $@.o && gcc $@.o -o $@

${Grace_ASM}: ${ASM_DIR}/Grace/Grace.s
	nasm -f elf64 $^ -o $@.o && gcc $@.o -o $@

${Sully_ASM}: ${ASM_DIR}/Sully/Sully.s
	nasm -f elf64 $^ -o $@.o && gcc $@.o -o $@



test1:
	nasm -f elf64 Colleen.s && gcc -pie -o Colleen Colleen.o && ./Colleen > outfile && diff Colleen.s outfile

test2:
	nasm -f elf64 Grace.s && gcc -pie -o Grace Grace.s && ./Grace && diff Grace.s Grace_kid.s
# nasm -f elf64 Grace.s && gcc -pie -o Grace Grace.s && ./Grace
